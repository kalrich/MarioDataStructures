/*
Kalin Richardson and Halle Broadnax
2431656 & 2431044
kalrichardson@chapman.edu & broadnax@chapman.edu
CPSC350 - 04
PA2 - Not So Mario Bros.
*/

#include "FileProcessor.h"
#include "Mario.h"
#include "World.h"
#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
 
    FileProcessor fp;
    std::string inputFileName = argv[1]; //command 1
    int fileInputs[8];
    fp.processFile(inputFileName, fileInputs);

    if ((fileInputs[3] + fileInputs[4] + fileInputs[5] + fileInputs[6] + fileInputs[7]) != 100) //check if sum of probabilities is 100
    {
        std::cout << "Percentages don't add up to 100. Change the values so they add up to 100." << std::endl;
        return -1;
    }
    World world(fileInputs[0], fileInputs[1], fileInputs[2], fileInputs[3],
                fileInputs[4], fileInputs[5], fileInputs[6], fileInputs[7]); //output the levels w/o mario

    Mario mario(fileInputs[2], fileInputs[1]);
    mario.placeMario(); //place mario in the world
    
    for (int i = 0; i < fileInputs[0]; ++i) //display world with Mario
    {
        world.displayWorld(i, -1, -1);
    }
    std::cout << "Mario is starting in position: (" << mario.getRow() << "," << mario.getCol() << ")." << std::endl;
    
    int totalLevels = fileInputs[0];
    int currentLevel = 0;

    // avoid infinite loops
    int max_moves = 1000;
    int moves = 0;

    bool warped = false;
    bool gameOver = false;

    while ((mario.getLives() > 0 && moves < max_moves) || gameOver == false) {
        world.displayWorld(currentLevel, mario.getRow(), mario.getCol());
        int row = mario.getRow();
        int col = mario.getCol();
        std::cout << "Level: " << currentLevel << ". ";
        std::cout << "Mario is at position (" << row << "," << col << "). ";
        std::cout << "Mario is at power level " << mario.getPowerLevel() << ". ";
        char currLoc = world.getPlace(currentLevel, row, col);
        
        switch (currLoc)
        {
        case 'm': //mushroom
            std::cout << "Mario ate a mushroom! ";
            mario.collectShroom();
            world.replace(currentLevel, row, col,'x');
            break;

        case 'c': //coin
            std::cout << "Mario collected a coin! ";
            mario.collectCoins();
            world.replace(currentLevel, row, col,'x');
            break;

        case 'g': //goomba
            std::cout << "Mario encountered a Goomba ";
            if (mario.encounterGoomba()) //if Mario wins, replace the space with an empty space
            {
                world.replace(currentLevel, row, col,'x');
            }
            break;

        case 'k': //koopa
            std::cout << "Mario encountered a Koopa "; 
            if (mario.encounterKoopa()) //if Mario wins, replace the space with an empty space
            {
                world.replace(currentLevel, row, col,'x');
            }
            break;

        case 'b': //boss
            std::cout << "Mario encountered a Boss ";
            if (mario.encounterBoss()) //if Mario wins, check
            {
                if (currentLevel < (totalLevels - 1)) //if it isn't the last level, move to next level
                {
                    currentLevel++;
                }
                else if(currentLevel == (totalLevels - 1)) //if it is the last level, game is over
                {
                    gameOver = true;
                }
                world.replace(currentLevel, row, col,'x'); //replace w/ empty space
            }
            break;
        
        case 'w': //warp pipe
            std::cout << "Mario encountered a warp pipe. ";
            currentLevel++; //move to next level
            warped = true;
            break;
        
        case 'x': //empty space
            std::cout << "Mario visited an empty space. ";
            break;
        }

        std::cout << "Mario has " << mario.getLives() << " lives left. ";
        std::cout << "Mario has " << mario.getCoins() << " coins. ";

        if (mario.getPowerLevel() == 0 && mario.getLives() == 0) //if mario is at PL0 and has no lives left, game is over
        {
            gameOver = true;
        }

        if(gameOver)
        {
            std::cout << "Mario will STAY PUT."; //mario will not move if game is over
            break;
        }
        else
        {
            if (warped == true)
            {
                std::cout << "Mario will WARP.";
                mario.placeMario(); //place mario in random spot on next level
                warped = false;
            }
            else
            {
                mario.move(); //move mario to next spot
            }
            std::cout << std::endl;
            ++moves;
        }
    }

    if (mario.getPowerLevel() == 0 && mario.getLives() == 0)//if mario's PL & lives = 0, then he lost
    {
        std::cout << std::endl << "YOU LOSE!" << std::endl;
    }
    else //any other case, Mario wins!
    {
        std::cout << std::endl << "WE BEAT THE GAME!" << std::endl;
    }
    
    return 0; 
}