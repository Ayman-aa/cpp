#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& databaseFile)
{
    parseDatabase(databaseFile);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : database(other.database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        database = other.database;
    return *this;
}

// parsing the database file and storing the data in a map
void BitcoinExchange::parseDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if(!file.is_open())
       throw std::runtime_error("Could not open database file");
    
    std::string line;
    std::getline(file, line);

    while(std::getline(file,line))
    {
        try
        {
            std::pair<std::string, float> entry = parseLine(line, ',');
            database[entry.first] = entry.second;
        }
        catch(std::exception& e)
        {
            std::cerr << "Warning: Skipping invalid database entry: " << line << std::endl;
        }
    }
}

// checking if the date is valid the bitcoin exchange rate data is available from 2009 to 2022
bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if(date.length() != 10) return false;
    if(date[4] != '-' || date[7] != '-') return false;
    
    int year, month, day;
    char dash1, dash2;
    std::istringstream stream(date);
    stream >> year >> dash1 >> month >> dash2 >> day;

    if(year < 2009 || year > 2023) return false;
    if(month < 1 || month > 12) return false;
    if(day < 1 || day > 31) return false;

    if (month == 2 && day > 29) return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;

    return true;
}

// checking if the price is valid the price should be a positive number and less than 1000
bool BitcoinExchange::isValidPrice(const float price) const { return price >= 0 && price <= 1000; }

// finding the closest date to the given date in the database using the upper_bound method
// in which the iterator points to the first element that is greater than the given date
std::string BitcoinExchange::findClosestDate(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it = database.upper_bound(date);
    if(it == database.begin()) return it->first;
    --it;
    return it->first;
}

// parsing a line from the database file and returning a pair of date and price 
std::pair<std::string, float> BitcoinExchange::parseLine(const std::string& line, const char delimiter) const
{
    std::stringstream stream(line);
    std::string date;
    std::string price;
    std::getline(stream, date, delimiter);
    std::getline(stream, price);
    
    // removing leading and trailing whitespaces
    date.erase(0, date.find_first_not_of(" \t"));
    date.erase(date.find_last_not_of(" \t") + 1);
    price.erase(0, price.find_first_not_of(" \t"));
    price.erase(price.find_last_not_of(" \t") + 1);

    // checking if the date and price are valid
    if(!isValidDate(date))
        throw std::runtime_error("Invalid date format");
    if (price.find(' ') != std::string::npos)
        throw std::runtime_error("Invalid price format");
    char *end;
    float priceValue = std::strtof(price.c_str(), &end);
    if(*end != '\0')
        throw std::runtime_error("Invalid price format");

    // return the date and price as a pair
    return std::make_pair(date, priceValue);
}

// getting the exchange rate for a given date if the date is not found in the database, the closest date is returned
float BitcoinExchange::getExchangeRate(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it = database.find(date);

    if(it == database.end())
    {
        std::string closestDate = findClosestDate(date);
        return database.at(closestDate);
    }
    return it->second;
}

// processing the input file and calculating the exchange rate for each entry in the file
void BitcoinExchange::processFile(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if(!file.is_open())
        throw std::runtime_error("Could not open input file");
    
    std::string line;

    if(std::getline(file, line))
        if(line != "date | value")
            throw std::runtime_error("Invalid input file header");

    bool done = false;
    while(std::getline(file, line))
    {
        try
        {
            std::pair<std::string, float> entry = parseLine(line, '|');

            if(!isValidPrice(entry.second))
                {
                    if(entry.second < 0)
                        std::cerr << "Error: not a positive number." << std::endl;
                    else
                        std::cerr << "Error: too large a number." << std::endl;
                    continue;
                }
            // calculating the exchange rate for the entry rate = value(database) * exchange rate(input)
            float rate = getExchangeRate(entry.first);
            float result = entry.second * rate;
            std::cout << entry.first <<" => " << entry.second << " = " << result << std::endl;
            done = true;
        }
        catch(const std::exception& e)
        {
            if(line.empty())
                std::cerr << "Error: Empty line." << std::endl;
            else{
                std::cerr << "Error: Bad input => " << line << std::endl;
                std::cerr << "Descriptive error : "  << e.what() << std::endl;
            }
        } 
    }
    if(!done)
        throw std::runtime_error("No valid input");
}