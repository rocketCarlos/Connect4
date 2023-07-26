#include "game.h"

using namespace std;

int Game::gameEnded(){
    int result = 0;

    // Check for rows
    bool end = false;
    for(int i = 0; i < NROWS and !end; i++){
        // the kind of cell that we are checking (X for p1, O for p2)
        cell checking = board[i][0];
        int connected = 1;
        if(checking != empty){
           for(int j = 1; j < NCOLUMNS; j++){
            } 
        }
        
    }

}