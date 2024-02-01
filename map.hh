#include <LiquidCrystal.h>
#include <Wire.h>
#include <LinkedList.h>
#include "snake.hh"
#include <SPI.h>


using namespace std;
#define mapsize 16

class Map{
    public:
        setMap();
        void printMap();
        void snakeGoRight();
        void snakeGoUp();
        void snakeGoLeft();
        void snakeGoDown();
        char getSnakeCurrent();
        int getGameOver();
        Snake* removeSnake();
        int ate_doone = 0;
        void createdoone();
        int get_map_state_at(int x,int y);
        bool dooone = false;
        unsigned long timer =0;
        int map[mapsize][mapsize]={0};
        void printsnake();
        char snakeCurrent = 'r';
        int xdoone;
        int ydoone;
        LinkedList<Snake*> snake  = LinkedList<Snake*>();

    private:
        
        void addSnake(int x,int y);
        void gameOver();
        int game = 1;
        
        
    

};

