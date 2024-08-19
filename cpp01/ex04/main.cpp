#include <iostream>
#include <fstream>
#include <sstream>

std::string findAndReplace(std::string inputLine, std::string target, std::string replacement)
{
    // Searching for the target index if found
    int position = inputLine.find(target);

    if (position == -1)
        return inputLine;
    
    // Deleting the target and replacing it with the replacement in the exact same position (index)
    inputLine.erase(position, target.length());
    inputLine.insert(position, replacement);
    return inputLine;
}

void replaceProcess(std::ofstream & outputFile, std::string currentLine, std::string target, std::string replacement)
{
    while (true) 
    {
        std::string originalLine = currentLine;

        currentLine = findAndReplace(currentLine, target, replacement);
        // When currentLine is the same as originalLine even after findAndReplace function then... there are no further changes to be made
        if (originalLine == currentLine)
            break;
    }
    // Printing the currentLine into the output file with a newline
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

    // Opening an input/output file stream, expected null-terminated string, a.k.a string.data()
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

    std::string currentLine;

    // Looping over the file, reading one line at a time until EOF is reached
    while (std::getline(inputFile, currentLine))
    {
        replaceProcess(outputFile, currentLine, target, replacement);
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Done. Review changes by typing cat " << inputFileName << ".replace" << std::endl;
    return 0;
}
