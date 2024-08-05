#include <iostream>
#include <fstream>
#include <sstream>

std::string findAndReplace(std::string inputLine, std::string target, std::string replacement)
{
    //seraching for target index if found
    int position = inputLine.find(target);

    if (position == -1)
        return inputLine;
    
    //deleting the target and replace it with replacememnt in the exact same position(index)
    inputLine.erase(position, target.length());
    inputLine.insert(position, replacement);
    return inputLine;
}

void replaceProcess(std::ifstream & inputFile, std::ofstream & outputFile, std::string target, std::string replacement)
{
    std::string currentLine;

    //storing line data from inputfile to currentline
    std::getline(inputFile, currentLine);
    while (true) 
    {
        std::string originalLine = currentLine;

        currentLine = findAndReplace(currentLine, target, replacement);
        //when currentline is the same as originalline even after findandreplace function then are no further changes to be made
        if (originalLine == currentLine)
            break;
    }
    //printing the currentline into output file with newline
    outputFile << currentLine << std::endl;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "./replace <filename> <find> <replace>" << std::endl;
        return 1;
    }

    std::string inputFileName = argv[1];
    std::string target = argv[2];
    std::string replacement = argv[3];

    if (inputFileName.empty() || target.empty() || replacement.empty())
    {
        std::cerr << "You can't insert empty arguments." << std::endl;
        return 1;
    }

    //opening an input/output file stream, expected null terminated string, a.k.a string.data()
    std::ifstream inputFile(inputFileName.data());
    if (!inputFile.is_open())
    {
        std::cerr << "Input file cannot be opened!" << std::endl;
        return 1;
    }

    std::ofstream outputFile((inputFileName + ".replace").data());
    if (!outputFile.is_open())
    {
        std::cerr << "Output file cannot be created!" << std::endl;
        return 1;
    }

    //looping on the file until we reach EOF
    while (!inputFile.eof())
        replaceProcess(inputFile, outputFile, target, replacement);

    inputFile.close();
    outputFile.close();

    std::cout << "Done. review changes by typing cat " << inputFileName <<".replace" << std::endl;
    return 0;
}
