#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string inputFilePath = "../generatedFiles/cleanRawData";
    string outputFilePath = "../generatedFiles/a.bin";
    ifstream inputFile(inputFilePath, ios::in);
    ofstream outputFile(outputFilePath, ios::out | ios::binary);

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

    string hex;
    
    while (inputFile >> hex)
    {
        outputFile << char(stoi(hex, nullptr, 16));
    }

    inputFile.close();
    outputFile.close();

    cout << "Conversion complete!" << endl;

    return EXIT_SUCCESS;
}