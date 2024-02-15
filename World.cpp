/*
Kalin Richardson and Halle Broadnax
2431656 & 2431044
kalrichardson@chapman.edu & broadnax@chapman.edu
CPSC350 - 04
PA2 - Not So Mario Bros.
*/

#include "World.h"
#include <iostream>
#include <ctime>
#include <cstdlib>


World::World(int givenLevels, int gridSize, int numLives, int percentCoins, int percentNothing,
             int percentGoomba, int percentKoopa, int percentMush)
{
    numLevels = givenLevels;
    dimensions = gridSize;
    levels = new char**[numLevels];
    
    //probabilities of environment
    chanceOfC = percentCoins;
    chanceOfX = percentNothing;
    chanceOfG = percentGoomba;
    chanceOfK = percentKoopa;
    chanceOfM = percentMush;

    for(int i = 0; i < numLevels; ++i) //create world
    {
        levels[i] = new char*[dimensions];
        for(int j = 0; j < dimensions; ++j)
        {
            levels[i][j] = new char[dimensions];
        }
    }

    generateWorld();
}

World::~World()
{
    for (int k = 0; k < numLevels; k++)
    {
        for (int j = 0; j < dimensions; j++)
        {
            delete[] levels[k][j];
        }
        delete[] levels[k];
    }

    delete[] levels;
}

void World::generateWorld() //fill world with environment pieces
{
    srand(time(NULL));
    for (int i = 0; i < numLevels; i++)
    {
        for (int j = 0; j < dimensions; j++)
        {
            for (int k = 0; k < dimensions; k++)
            {
                int probability = 1 + (rand() % 100);
                if (probability <= chanceOfC)
                {
                    levels[i][j][k] = 'c'; //coin
                }
                else if (probability <= (chanceOfC + chanceOfX))
                {
                    levels[i][j][k] = 'x'; //empty space
                }
                else if (probability <= (chanceOfC + chanceOfX + chanceOfG))
                {
                    levels[i][j][k] = 'g'; //goomba
                }
                else if (probability <= (chanceOfC + chanceOfX + chanceOfG + chanceOfK))
                {
                    levels[i][j][k] = 'k'; //koopa
                }
                else if (probability <= 100)
                {
                    levels[i][j][k] = 'm'; //mushroom
                }
                else
                {
                    std::cout << "Error" << std::endl;
                }
            }
        }

        addBoss(i);
        addWarpPipe(i);
    }
}

void World::displayWorld(int level, int marioRow, int marioCol) //print statement for world
{
    std::cout << "===============" << std::endl;
    for (int i = 0; i < dimensions; i++)
    {
        for (int j = 0; j < dimensions; j++)
        {
            if (i == marioRow && j == marioCol) {
                std::cout << " H "; //output mario in the world
            } else {
                std::cout << " " << levels[level][i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "===============" << std::endl;
}

void World::addWarpPipe(int level)
{
    if (level != (numLevels - 1)) //only place if the level isn't the last level
    {
        while(true)
        {
            //find a random place
            int randRow = (rand() % dimensions);
            int randCol = (rand() % dimensions); 

            if (levels[level][randRow][randCol] != 'b') //if the random place doesn't contain the boss
            {
                levels[level][randRow][randCol] = 'w';
                break;
            }
        }
    }
}

void World::addBoss(int level)
{
    //find a random place
    int randRow = (rand() % dimensions);
    int randCol = (rand() % dimensions);

    levels[level][randRow][randCol] = 'b';
}



int World::getDimension()
{
    return dimensions;
}

char World::getPlace(int currentLevel, int row, int col)
{
    return levels[currentLevel][row][col];
}

//to replace locations with empty spaces after interacting with them
void World::replace(int currentLevel, int row, int col, char value)
{
    levels[currentLevel][row][col] = value;
}

