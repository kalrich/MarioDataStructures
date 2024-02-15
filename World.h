/*
Kalin Richardson and Halle Broadnax
2431656 & 2431044
kalrichardson@chapman.edu & broadnax@chapman.edu
CPSC350 - 04
PA2 - Not So Mario Bros.
*/

#ifndef WORLD_H
#define WORLD_H


class World
{
    public:
        World(int givenLevels, int gridSize, int numLives, int percentCoins, int percentNothing,
              int percentGoomba, int percentKoopa, int percentMush);
        ~World();
        void generateWorld();
        int getDimension();
        char getPlace(int currentLevel, int row, int col);
        void replace(int currentLevel, int row, int col, char value);
        void displayWorld(int level, int marioRow, int marioCol);
        void addWarpPipe(int level);
        void addBoss(int level);
        
    private:
        int numLevels;
        int dimensions;
        char*** levels; //3D array
        int chanceOfC;
        int chanceOfX;
        int chanceOfG;
        int chanceOfK;
        int chanceOfM;
        int marioRow;
        int marioCol;
};

#endif