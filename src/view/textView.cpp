#include "textView.h"
#include <iostream>

using namespace std;

int TextView::requestAdding(){
    int column;
    int player = game.getCurrentTurn() == turnP1 ? 1 : 2;

    cout << endl << "It's player " << player << "'s turn." << endl;
    cout << "Choose a column to add a piece:" << endl;
    cin >> column;

    if(column > NCOLUMNS or column < 1){
        do{
            cout << "Column number must be between 1 and " << NCOLUMNS << endl;
            cout << "Choose a column to add a piece:" << endl;
            cin >> column;
        }while(column > NCOLUMNS or column < 1);
    }

    if(!game.addPiece(column-1)){
        do{
            cout << "That column is full!" << endl;
            cout << "Choose a column to add a piece:" << endl;
            cin >> column;
        }while(!game.addPiece(column-1));
    }

    return column;
}

int TextView::requestAdding(int column){
    int player = game.getCurrentTurn() == turnP1 ? 1 : 2;

    cout << endl << "It's player " << player << "'s turn." << endl;
    cout << "Choose a column to add a piece:" << endl;
    cout << "The AI chooses: " << column;

    game.addPiece(column);

    /*
    if(column > NCOLUMNS or column < 1){
        do{
            cout << "Column number must be between 1 and " << NCOLUMNS << endl;
            cout << "Choose a column to add a piece:" << endl;
            cin >> column;
        }while(column > NCOLUMNS or column < 1);
    }
    
    if(!game.addPiece(column-1)){
        do{
            cout << "That column is full!" << endl;
            cout << "Choose a column to add a piece:" << endl;
            cin >> column;
        }while(!game.addPiece(column-1));
    }
   */

    return column;
}

void TextView::showBoard(){
    vector<vector<cell>> board = game.getBoard();
    int player = game.getCurrentTurn() == turnP1 ? 1 : 2;
    
    cout << endl;

    cout << "     --     Connect 4     --     " << endl << endl;
    cout << "Player 1 -> X  |  Player 2 -> O" << endl;
    cout << "Turn: " << game.getNTurn() << endl;
    cout << "Current player: P" << player << endl << endl;

    cout << "  1  2  3  4  5  6  7  " << endl;
    for(int i = 0; i < NROWS; i++){
        cout << "|";
        for(int j = 0; j < NCOLUMNS; j++){
            string s = " - ";
            if(board[i][j] == X){
                s = " X ";
            } else if(board[i][j] == O){
                s = " O ";
            }
            cout << s;
        }
        cout << "|" << endl;
    }

    cout << "-----------------------" << endl;
}

int TextView::displayMenu(){
    int option; 

    cout << "     --     Connect 4     --     " << endl << endl;
    cout << "Main menu" << endl;
    int n = 1;
    cout << n++ << "- Player vs Player" << endl;
    cout << n++ << "- Player vs AI" << endl;
    cout << n++ << "- AI vs Player" << endl;
    cout << n++ << "- AI vs AI" << endl;

    cout << "0- Help" << endl;

    do{
        cout << "Choose an option: " << endl;
        cin >> option;
    }while(option < 0 or option >= n);

    return option;
}

int TextView::displayAIMenu(){
    cout << endl << "     --     AI menu     --     " << endl << endl;

    int n = 1;
    cout << n++ << "- Easy" << endl;
    cout << n++ << "- Medium" << endl;
    cout << n++ << "- Hard" << endl;
    cout << n++ << "- Very hard" << endl;

    int option;
    do{
        cout << "Choose a difficulty level: " << endl;
        cin >> option;
    }while(option <= 0 or option >= n);

    return option;
}

void TextView::displayHelp(){
    cout << "     --     Connect 4 Quick guide     --     " << endl << endl;

    cout << "1. Pieces are represented by X for player 1 and O for player 2" << endl;
    cout << "2. In your turn, choose a column between 1 and 7 to add a piece to that column" << endl;
    cout << "3. First player connecting 4 pieces in horizontal, vertical or diagonal, " << endl <<
    "wins the game." << endl;

}

void TextView::showEndGame(int ending){
    cout << "     --     GAME OVER     --     " << endl << endl;

    switch(ending){
        case 1:
        {
            cout << "Player 1 wins!" << endl;
        }
        break;

        case 2:
        {
            cout << "Player 2 wins!" << endl;
        }
        break;

        case 3:
        {
            cout << "That's a draw!" << endl;
        }
        break;
    }

}