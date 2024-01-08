#include <iostream>
#include <vector>
#include "snake.hh"

using namespace std;

class Map{
    public:
        Map();
        // ~Map();
        void printMap();
        void snakeGoRight();
        void snakeGoUp();
        void snakeGoLeft();
        void snakeGoDown();
        char getSnakeCurrent();
        int getGameOver();
    private:
        char snakeCurrent = 'r';
        void addSnake(int x,int y);
        void removeSnake();
        void gameOver();
        int game = 1;
        int map[16][16]={0};
        vector <Snake> snake;
    

};

