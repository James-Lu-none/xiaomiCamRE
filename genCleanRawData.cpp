#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int main()
{
    string inputFilePath = "../flashRawData/flash1.txt";
    string outputFilePath = "../generatedFiles/cleanRawData";

    ifstream inputFile(inputFilePath);
    ofstream outputFile(outputFilePath);

    if (!inputFile.is_open())
    {
        cerr << "Error opening input file!" << endl;
        return EXIT_FAILURE;
    }

    if (!outputFile.is_open())
    {
        cerr << "Error opening output file!" << endl;
        inputFile.close();
        return EXIT_FAILURE;
    }

    string line;
    uint64_t prevAddr = 0;
    uint32_t counter = 0;
    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            if (line.substr(0, 5) == "Start")
            { // Assuming "Start" is 5 characters long
                counter++;
                istringstream iss(line);
                string startToken;
                string hexNumber;
                if (iss >> startToken >> startToken >> hexNumber)
                {
                    // Convert hexadecimal string to integer
                    unsigned int hexValue;
                    stringstream ss;
                    ss << hex << hexNumber;
                    ss >> hexValue;
                    if (hexValue - prevAddr != 1024)
                    {
                        cout << hexValue << ',' << hexNumber << endl;
                    }
                    prevAddr = hexValue;
                }
            }
            else{
                // line.pop_back();
                outputFile << line;
            }
        }
    }
    else
    {
        cerr << "Unable to open file!" << endl;
    }
    cout << counter << endl;
    
    inputFile.close();
    outputFile.close();

    return EXIT_SUCCESS;
}