/*
Kalin Richardson and Halle Broadnax
2431656 & 2431044
kalrichardson@chapman.edu & broadnax@chapman.edu
CPSC350 - 04
PA2 - Not So Mario Bros.
*/

#ifndef MARIO_H
#define MARIO_H


class Mario
{
    public:
        Mario(int givenLives, int levelDimension);
        ~Mario();
        int getLives();
        int getRow();
        int getCol();
        void setRow(int r);
        void setCol(int c);
        void placeMario();
        void move();
        void collectCoins();
        int getPowerLevel();
        int getCoins();
        bool checkForWin(int winProbability);
        void increasePowerLevel();
        void losePowerLevel();
        void collectShroom();
        bool encounterGoomba();
        bool encounterKoopa();
        bool encounterBoss();
  
    private:
        int lives; 
        int coins;
        int powerLevel;
        int row;
        int col;
        int dimension;
};

#endif