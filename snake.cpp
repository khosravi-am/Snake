#include "snake.hh"


using namespace std;

Snake::Snake(int x , int y){
    this->x=x;
    this->y=y;
}

int Snake::getx(){
    return this->x;
}

int Snake::gety(){
    return this->y;
}

Snake::~Snake()
{
}
