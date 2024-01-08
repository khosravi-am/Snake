#include "map.hh"
#include <iostream>
#include <stdio.h>
#include "time.h"

int main(){

    Map test;
    char  input;
    
   
    cout << "press enter to start" << endl;
    input = getchar();
    cout << "press 'w' to up , 'd' right , 's' down , 'a' left : " << endl;
    test.printMap();
     
    
    while (test.getGameOver()){
        //  ToDo:
        //time.dalay()
        // if (press up button)
        // {
        //     if(test.getSnakeCurrent()!= 'u' )
        //         test.snakeGoUp();
        // }
        
        // if (press right button)
        // {
        //     if(test.getSnakeCurrent()!= 'r')
        //         test.snakeGoRight();
        // }
        
        // if (press down button)
        // {
        //     if(test.getSnakeCurrent()!= 'd' )
        //         test.snakeGoDown();
        // }
        
        // if (press left button)
        // {
        //     if(test.getSnakeCurrent()!= 'l' )
        //         test.snakeGoLeft();
        // }
        
        
        

        switch (test.getSnakeCurrent())
        {
        case 'u':
            test.snakeGoUp();
            break;
        
        case 'r':
            test.snakeGoRight();
            break;
        
        case 'l':
            test.snakeGoLeft();
            break;
        
        case 'd':
            test.snakeGoDown();
            break;
        
        default:
            
            test.printMap();
            break;
        }

        test.printMap();

    }

    cout << endl <<"game over !!";




}
