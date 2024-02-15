/*
Kalin Richardson and Halle Broadnax
2431656 & 2431044
kalrichardson@chapman.edu & broadnax@chapman.edu
CPSC350 - 04
PA2 - Not So Mario Bros.
*/

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>

class FileProcessor
{
    public:
        FileProcessor();
        ~FileProcessor();
        void processFile(std::string inputFile, int* fileInputs);

    private:
        int* fileInputs; //array to store value of each line in file
};

#endif