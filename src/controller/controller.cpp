#include "controller.h"
#include <iostream>
using namespace std;

void Controller::startPlaying(){
    // first, display the game menu
    int option = game.displayMenu();

    while(option == 0){
        game.displayHelp();
        cin.get();
        option = game.displayMenu();
    }   

    switch(option){
        case 1:
        {
            // Game's main loop
            game.showBoard();
            int ending = 0;
            do{
                game.requestAdding();
                game.showBoard();
                ending = game.getGame().gameEnded();
            }while( ending == 0);

            game.showEndGame(ending);
        }
        break;

        default: 
        {
            cout << "This gamemode is not available yet!" << endl;
        }
        break;

    }

    

}