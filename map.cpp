#include "map.hh"

using namespace  std;



Map::Map(){

    addSnake(0,0);
    addSnake(0,1);
    addSnake(0,2);
    cout << snake.front().getx() << snake.front().gety()<<endl;
    cout << snake.back().getx() << snake.back().gety()<<endl;
    

}

// Map::~Map()
// {
// }

void Map::printMap(){
    for(int i=0;i<17;i++){
        for (int j = 0; j < 17; j++)
        {
            if (i==0)
                cout << j << " ";
            else if (j==0)
                if (i>9)
                    cout << i ;
                else
                cout<< i << " ";
            if(i>0 && j>0)
                if (j>=9)
                cout << map[i-1][j-1] << "  ";
                else
                    cout << map[i-1][j-1] << " ";
        }
        
        cout << endl;
        
    }
    cout << endl <<endl;
}

void Map::addSnake(int x,int y)
{
    Snake s(x,y);
    snake.push_back(s); 
    if(map[x][y]==1){
        gameOver();
        return;
    }
    map[x][y]=1  ;
}

void Map::removeSnake()
{
    int x=snake.front().getx();
    int y = snake.front().gety();
    map[x][y]=0;
    // ToDo delete object pointer -> snake.back().~Snake();
    snake.erase(snake.begin());
}

void Map::snakeGoRight()
{
    int y=snake.back().gety();
    if (y+1 > 15){
        gameOver();
        return;
    }
    int x=snake.back().getx();
    addSnake(x,y+1);
    snakeCurrent='r';
// ToDo if !doone 
    removeSnake();
    
}

void Map::snakeGoUp()
{
    
    int x=snake.back().getx();
    if (x-1 < 0 ){
        gameOver();
        return;
    }
    int y=snake.back().gety();
    
    addSnake(x-1,y);
    snakeCurrent='u';
// ToDo if !doone 
    removeSnake();

}

void Map::snakeGoLeft()
{
    int y=snake.back().gety();
    if (y-1 < 0){
        gameOver();
        return;
    }
    int x=snake.back().getx();
    addSnake(x,y-1);
    snakeCurrent='l';
// ToDo if !doone 
    removeSnake();
}

void Map::snakeGoDown()
{
    int x=snake.back().getx();
    if (x+1 > 15){
        gameOver();
        return;
    }
    int y=snake.back().gety();
    addSnake(x+1,y);
    snakeCurrent='d';
// ToDo if !doone 
    removeSnake();
}

char Map::getSnakeCurrent()
{

    return this->snakeCurrent;
}

void Map::gameOver()
{
    this->game=0;
}

int Map::getGameOver()
{
    return this->game;
}
