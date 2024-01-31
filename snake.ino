#include <LiquidCrystal.h>
#include <Wire.h>
#include "map.hh"
#include <MD_MAX72xx.h>
#include <LinkedList.h>

#define mapsize 16
#define up_key 12
#define down_key 11
#define left_key 10
#define right_key 9
#define clk_pin 13
#define din0_pin 7
#define ld0_pin 6
#define din1_pin 5
#define ld1_pin 4
#define MAX_DEVICES	2
#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define DELAY 500


MD_MAX72XX max1 = MD_MAX72XX(HARDWARE_TYPE, din0_pin, clk_pin, ld0_pin,MAX_DEVICES);
MD_MAX72XX max2 = MD_MAX72XX(HARDWARE_TYPE, din1_pin, clk_pin, ld1_pin, MAX_DEVICES);

Map game_map;

int timer = 0;

void gameOver(){
  for(int i=0;i<DELAY;i++){
    for (int x=0;x<mapsize;x++)
      for (int y=0;y<mapsize;y++)
        set_point(x,y,true);
      
    clearMatrix();
  }
  return 0;
}

void clearMatrix(){

    for (int x=0;x<mapsize;x++)
      for (int y=0;y<mapsize;y++)
        set_point(x,y,false);
        
      
}

void show_game2(){
  
  for (int i=0;i<game_map.snake.size();i++){
    int x = game_map.snake.get(i)->getx();
    int y = game_map.snake.get(i)->gety();
    set_point(x,y,true);
  }

  int time = millis();
  if (time - game_map.timer>DELAY/5){
    game_map.dooone = !game_map.dooone;
    set_point(game_map.xdoone,game_map.ydoone,game_map.dooone);
    game_map.timer = millis();
  }
}

void show_game(){
  int state ;

  for (int i=0 ;i<mapsize;i++){
    for (int j=0 ; j<mapsize ; j++){
      
      state = game_map.get_map_state_at(i,j);
      if(i<8){
        if (state == 2){
          int time = millis();
          
          if (time - game_map.timer>5){
            game_map.dooone = !game_map.dooone;
            max1.setPoint(i,j,game_map.dooone);
            game_map.timer = millis();
          }
          else {

              continue;
          }

        }

        else if(state == 1){
          max1.setPoint(i,j,true);
        }

        else if (state == 0){
          if (max1.getPoint(i, j))
            delay(200);
          max1.setPoint(i,j,false);
        }

      }

      else if(i>=8){
        if (state == 2){
          int time = millis();
          
          if (time - game_map.timer>10){
            game_map.dooone = !game_map.dooone;
            max2.setPoint(i-8,j,game_map.dooone);
            game_map.timer = millis();
          }
          else 
            continue;
        }

        else if(state == 1){
          max2.setPoint(i-8,j,true);
        }

        else if (state == 0){
          if (max2.getPoint(i, j))
            delay(200);
          max2.setPoint(i-8,j,false);
        }

      }
        
    }
  }
}



void printmap(){
 
 for(int i=0;i<mapsize+1;i++){
        for (int j = 0; j < mapsize+1; j++)
        {
            if (i==0){
             Serial.print(j);
             Serial.print(' ');
            }
            else if (j==0){
                if (i>9){
                   Serial.print(i);
                }
                else{
                   Serial.print(i);
                   Serial.print(' ');
                }
            }
            if(i>0 && j>0){
                if (j>=9){
       
                 Serial.print(game_map.map[i-1][j-1]);
                 Serial.print("  ");
                }
                else{
                   Serial.print(game_map.map[i-1][j-1]);
                   Serial.print(' ');
                }
            }
        }
        
       Serial.println();
        
    }
   Serial.println();
   Serial.println();


}


void setup() {
  
  if (!max1.begin())
   Serial.println("\nMD_MAX72XX 1 initialization failed");
  if (!max2.begin())
   Serial.println("\nMD_MAX72XX 1 initialization failed");
  
  Serial.begin(9600);
  
  pinMode(up_key,INPUT_PULLUP);
  pinMode(down_key,INPUT_PULLUP);
  pinMode(right_key,INPUT_PULLUP);
  pinMode(left_key,INPUT_PULLUP);
  
  game_map.setMap();

}

void set_point(int x,int y,bool state){


  if (x<8){
    
    max1.setPoint(x, y, state);
    
  }
  else if (x>=8){


    max2.setPoint(x-8, y, state);

  }
  
}



void loop() {
  
  // printmap();
  // show_game();
  show_game2();
  
  if (!game_map.getGameOver()){
    gameOver(); 
    return;
  }

  if (digitalRead(up_key)==LOW){
    game_map.snakeCurrent='u';
  }
  
  if (digitalRead(down_key)==LOW){
    game_map.snakeCurrent='d';
  }

  if (digitalRead(left_key)==LOW){
    game_map.snakeCurrent='l';
  }

  if (digitalRead(right_key)==LOW){
    game_map.snakeCurrent='r';
  }

  int time = millis();
  Snake* sn;
  switch (game_map.getSnakeCurrent()){
        case 'u':
            if (time - timer>DELAY){
              game_map.snakeGoUp();
              if (!game_map.ate_doone){
                  sn=game_map.removeSnake();
                  set_point(sn->getx(),sn->gety(),false);
                  free(sn);
              }
              timer = millis();
            }
            if(game_map.ate_doone){
                  sn=game_map.snake.get(game_map.snake.size()-1);
                  set_point(sn->getx(),sn->gety(),false);
                  
                  game_map.ate_doone=0;
                  game_map.createdoone();
              }
            break;
        
        case 'r':
            if (time - timer>DELAY){
              game_map.snakeGoRight();
              if (!game_map.ate_doone){
                  sn=game_map.removeSnake();
                  set_point(sn->getx(),sn->gety(),false);
                  free(sn);
              }
              timer = millis();
            }
            if(game_map.ate_doone){
                  sn=game_map.snake.get(game_map.snake.size()-1);
                  set_point(sn->getx(),sn->gety(),false);
                  
                  game_map.ate_doone=0;
                  game_map.createdoone();
              }
            
            break;
        
        case 'l':
            if (time - timer>DELAY){
              game_map.snakeGoLeft();
              if (!game_map.ate_doone){
                  sn=game_map.removeSnake();
                  set_point(sn->getx(),sn->gety(),false);
                  free(sn);
              }
              timer = millis();
            }
            if(game_map.ate_doone){
                  sn=game_map.snake.get(game_map.snake.size()-1);
                  set_point(sn->getx(),sn->gety(),false);
                  game_map.ate_doone=0;
                  game_map.createdoone();
              }
            break;
        
        case 'd':
            if (time - timer>DELAY){
              game_map.snakeGoDown();
              if (!game_map.ate_doone){
                  sn=game_map.removeSnake();
                  set_point(sn->getx(),sn->gety(),false);
                  free(sn);
              }
              timer = millis();
            }
            if(game_map.ate_doone){
                  sn=game_map.snake.get(game_map.snake.size()-1);
                  set_point(sn->getx(),sn->gety(),false);
                  game_map.ate_doone=0;
                  game_map.createdoone();
              }
            break;
        
        default:
            break;
    }
    
}








