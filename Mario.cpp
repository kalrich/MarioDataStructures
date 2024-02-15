/*
Kalin Richardson and Halle Broadnax
2431656 & 2431044
kalrichardson@chapman.edu & broadnax@chapman.edu
CPSC350 - 04
PA2 - Not So Mario Bros.
*/

#include "Mario.h"
#include "World.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

Mario::Mario(int givenLives, int levelDimension) //constructor
{
    lives = givenLives;
    dimension = levelDimension;
    coins = 0;
    powerLevel = 0;
    placeMario();
}

Mario::~Mario(){ //deconstructor
}

int Mario::getLives()
{
    return lives;
}

void Mario::collectCoins()
{
    coins++;

    if (coins == 20) //reset coins and increase life by 1 if coins = 20
    {
        lives++;
        coins = 0;
    }
}

void Mario::collectShroom()
{
    if (powerLevel == 2) //can't increase PL past 2
    {
        return;
    }
    else
    {
        powerLevel++;
    }
}

bool Mario::encounterGoomba()
{
    if (checkForWin(80)) //if Mario wins w/ 80% chance
    {
        std::cout << "and won. ";
        return true;
    } 
    else
    {
        if (powerLevel > 0) //lose PL if mario has any
        {
            powerLevel--;
        }
        else if(powerLevel == 0 && lives > 0) //lose life if PL = 0
        {
            lives--;
        }
        std::cout << "and lost. ";
        return false;
    }
}

bool Mario::encounterKoopa()
{
    if (checkForWin(65)) //Mario wins w/ 65% chance
    {
        std::cout << "and won. ";
        return true;
    }
    else
    {
        if (powerLevel > 0) //lose PL if mario has any
        {
            powerLevel--;
        }
        else if(powerLevel == 0 & lives > 0) //lose life if PL = 0
        {
            lives--;
        }
        std::cout << "and lost. ";
        return false;
    }
}

bool Mario::encounterBoss()
{
    if (checkForWin(50))
    { //if Mario wins w/ 50% chance
        std::cout << "and won. ";
        return true;
    } 
    else //if he loses
    {
        if(!(powerLevel == 2)) //if Mario is at PL0 or PL1
        {
            lives--;
        }
        else
        {
            powerLevel = powerLevel - 2;
        }
        std::cout << "and lost. ";
        return false;
    }
}

int Mario::getRow()
{
    return row;
}

int Mario::getCol()
{
    return col;
}

void Mario::setRow(int r)
{
    row = r;
}

void Mario::setCol(int c)
{
    col = c;
}

void Mario::placeMario()
{
    row = (rand() % dimension);
    col = (rand() % dimension);
}

int Mario::getPowerLevel()
{
    return powerLevel;
}

int Mario::getCoins()
{
    return coins;
}

bool Mario::checkForWin(int winProbability)
{
    int probability = 1 + (rand() % 100);
    if (probability <= winProbability) //0 - given probability is a win
    {
        return true;
    }
    else if (probability <= 100) //any thing else up to 100 is a loss
    {
        return false;
    }
    else
    {
        std::cout << "Error" <<  std::endl;
        return false;
    }
}
void Mario::move() {
    int randDir = (rand() % 4);
    if (randDir == 0) {
        // up
        if (row == 0) { 
            row = dimension - 1;
        } else {
            row--;
        }
        std::cout << "Mario will move UP.";
    } else if (randDir == 1) {
        // down
        if (row == dimension - 1) {
            row = 0;
        } else {
            row++;
        }
        std::cout << "Mario will move DOWN.";
    } else if (randDir == 2) {
        // left
        if (col == 0) {
            col = dimension - 1;
        } else {
            col--;
        }
        std::cout << "Mario will move LEFT.";
    } else {
        // right
        if (col == dimension - 1) {
            col = 0;
        } else {
            col++;
        }
        std::cout << "Mario will move RIGHT.";
    }
}


