/*
Kalin Richardson and Halle Broadnax
2431656 & 2431044
kalrichardson@chapman.edu & broadnax@chapman.edu
CPSC350 - 04
PA2 - Not So Mario Bros.
*/

#include "FileProcessor.h"
#include "World.h"
#include "Mario.h"
#include <iostream>
#include <fstream>
#include <string>

FileProcessor::FileProcessor(){ //default constructor
}

FileProcessor::~FileProcessor(){ //deconstsructor
}

void FileProcessor::processFile(std::string inputFile, int* fileInputs)
{
    std::ifstream fileToRead; 
    
    std::string fileLine;
    int fileSize = 8; // set size because we know the amount of lines in the file

    fileToRead.open(inputFile);

    if (!fileToRead.is_open()) //if file can't be opened
    {
        std::cout << "Couldn't open " << inputFile << std::endl;
        return;
    }
   
    if(fileToRead.is_open()) 
    {
        for (int i = 0; i < fileSize; i++) //read line by line into array of file inputs
        {
            fileToRead >> fileInputs[i];
        }
    }

    fileToRead.close();
}