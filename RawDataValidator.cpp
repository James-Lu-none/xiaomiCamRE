#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int main()
{
    string filePath = "/home/james/projects/cProject/xiaomiCamRE/flashRawData/flash1.txt";
    ifstream inputFile(filePath); // Replace "file.txt" with your file path
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
        }
        inputFile.close();
    }
    else
    {
        cerr << "Unable to open file!" << endl;
    }
    cout << counter << endl;
    return 0;
}