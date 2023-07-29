#include "controller.h"
#include "AI.h"
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
        // player vs player
        case 1:
        {
            // Game's main loop
            game.showBoard();
            int ending = 0;
            do{
                game.requestAdding();
                game.showBoard();
                ending = game.getGame().gameEnded();
            }while(ending == 0);

            game.showEndGame(ending);
        }
        break;

        // Player vs AI
        case 2:{
            AI ai(2, game.displayAIMenu());

            // Game's main loop
            game.showBoard();
            int ending = 0;
            do{
                // Player's turn
                game.requestAdding();
                game.showBoard();
                ending = game.getGame().gameEnded();
                // AI's turn
                if(ending == 0){
                    game.requestAdding(ai.getMove(game.getGame().getBoard()));
                    game.showBoard();
                    ending = game.getGame().gameEnded();   
                }

            }while(ending == 0);

            game.showEndGame(ending);
        }
        break;

        // AI vs player
        case 3: {
            AI ai(2, game.displayAIMenu());

            // Game's main loop
            game.showBoard();
            int ending = 0;
            do{
                // AI's turn
                game.requestAdding(ai.getMove(game.getGame().getBoard()));
                game.showBoard();
                ending = game.getGame().gameEnded();
                // Player's turn
                if(ending == 0){
                    game.requestAdding();
                    game.showBoard();
                    ending = game.getGame().gameEnded();   
                }

            }while(ending == 0);

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