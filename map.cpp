#include "map.hh"

using namespace  std;

#define doone  2;

Map::setMap(){

    addSnake(0,0);
    addSnake(0,1);
    addSnake(0,2);
    map[mapsize/2][mapsize/2]=2;
    xdoone = mapsize/2;
    ydoone = mapsize/2;
}

void Map::printsnake(){
   //Serial.println("SNAKE size: ");
   //Serial.println(snake.size());
   //Serial.print("[");
    for(int i=0 ;i< snake.size();i++){
     //Serial.print("(");
     //Serial.print(snake.get(i)->getx());
     //Serial.print(", ");
     //Serial.print(snake.get(i)->gety());
     //Serial.print("), ");
    }
   //Serial.println("]");

}

void Map::addSnake(int x,int y)
{
    Snake *s = new Snake(x,y);
    snake.add(s);
   //Serial.print("snake size: ");
   //Serial.println(snake.size()); 
    ////Serial.println(snake.getx());
    ////Serial.println(snake[0].gety());
    // printsnake();
    // printsnake();
   //Serial.print("map x,y: ");
   //Serial.print(map[x][y]);
    if(map[x][y]==1){
        gameOver();
        return;
    }
    else if(map[x][y] == 2){
        ate_doone=1;
    }
    
    map[x][y]=1  ;
}

Snake* Map::removeSnake()
{
    int x=snake.get(0)->getx();
    int y = snake.get(0)->gety();

    map[x][y]=0;
    return snake.shift();

}

void Map::createdoone()
{
    // int time = millis();
    // int dune = time % (mapsize*mapsize - snake.size());
    int dune = random(mapsize*mapsize - snake.size());
    for (size_t i = 0; i < mapsize; i++)
    {
        for (size_t j = 0; j < mapsize; j++)
        {
            if (map[i][j] == 1){
                continue;
            }
            else if(dune == 0){
                map [i][j] = 2;
                xdoone = i;
                ydoone = j;
                return;
            } else{
                dune--;
            }
        }
        
    }
    
}

void Map::snakeGoRight()
{
    
    int y=snake.get(snake.size() -1)->gety();
  if (y+1 > mapsize-1 ){
        gameOver();
        return;
    }
    int x=snake.get(snake.size() -1)->getx();
    addSnake(x,y+1);
    snakeCurrent='r';    
    
}

void Map::snakeGoUp()
{
    
    int x=snake.get(snake.size() -1)->getx();
    if (x-1 < 0 ){
        gameOver();
        return;
    }
    int y=snake.get(snake.size() -1)->gety();
    
    addSnake(x-1,y);
    snakeCurrent='u';

}

void Map::snakeGoLeft()
{
    int y=snake.get(snake.size() -1)->gety();
    if (y-1 < 0){
        gameOver();
        return;
    }
    int x=snake.get(snake.size() -1)->getx();
    addSnake(x,y-1);
    snakeCurrent='l';
}

void Map::snakeGoDown()
{
    int x=snake.get(snake.size() -1)->getx();
    if (x+1 > mapsize-1){
        gameOver();
        return;
    }
    int y=snake.get(snake.size() -1)->gety();
    addSnake(x+1,y);
    snakeCurrent='d';
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

void Map::printMap(){
    for(int i=0;i<mapsize+1;i++){
        for (int j = 0; j < mapsize+1; j++)
        {
            if (i==0){
                // cout << j << " ";
             //Serial.print(j);
             //Serial.print(' ');
            }
            else if (j==0){
                if (i>9){
                    // cout << i ;
                   //Serial.print(i);
                }
                else{
                    // cout<< i << " ";
                   //Serial.print(i);
                   //Serial.print(' ');
                }
            }
            if(i>0 && j>0){
                if (j>=9){
                // cout << map[i-1][j-1] << "  ";
                 //Serial.print(map[i-1][j-1]);
                 //Serial.print('  ');
                }
                else{
                    // cout << map[i-1][j-1] << " ";
                   //Serial.print(map[i-1][j-1]);
                   //Serial.print(' ');
                }
            }
        }
        
        // cout << endl;
       //Serial.println();
        
    }
    // cout << endl <<endl;
   //Serial.println();
   //Serial.println();
}



int Map::get_map_state_at(int x,int y){
  return map[x][y];
}
