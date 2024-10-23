#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>

/*
    BitcoinExchange class
    This class is used to store and process exchange rate data.
    The exchange rate data is stored in a map with the date as the key and the exchange rate as the value
        and that's the reason behind choosing map as a container.
    The class provides methods to process a file containing exchange rate data and to get the exchange rate for a given date.
*/
class BitcoinExchange
{
    private:
        BitcoinExchange();
        std::map<std::string, float> database;
        bool isValidDate(const std::string& date) const;
        bool isValidPrice(const float price) const;
        std::string findClosestDate(const std::string& date) const;
        void parseDatabase(const std::string& filename);
        std::pair<std::string, float> parseLine(const std::string& line, const char delimiter) const;

    public:
        BitcoinExchange(const std::string& databaseFile = "data.csv");
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        void processFile(const std::string& filename);
        float getExchangeRate(const std::string& date) const;
};

#endif