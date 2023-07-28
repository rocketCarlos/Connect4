#include "game.h"
#include <iostream>

using namespace std;

Game::Game(){
    // initialize board
    board.resize(NROWS);
    for(int i = 0; i < NROWS; i++){
        board[i].resize(NCOLUMNS);
        for(int j = 0; j < NCOLUMNS; j++){
            board[i][j] = cell::empty;
        }
    }

    currentTurn = turnP1;
    nTurn = 1;
}

int Game::gameEnded(){
    int result = 3; // 0 -> not ended, 1 -> p1 wins, 2 -> p2 wins, 3 -> draw

    //Check for a draw
    for(int i = 0; i < NCOLUMNS; i++){
        // if there is at least space for one disk, it's not a draw
        if(board[0][i] == cell::empty){
            result = 0;
        }
    }

    // Check for 4 connected disks in a row
    int i = 0;
    int j = 0;
    while(i < NROWS and result == 0){
        j = 0;
        // type of disk (X or O)
        cell checking = board[i][j];
        int connected = 1;
        // check for consecutive equal disks for each row
        while(j < (NCOLUMNS - 1) and result == 0){
            j++;
            if(board[i][j] == checking and checking != cell::empty){
                connected++;
                if(connected == 4){
                    // 4 connected disks results in endgame
                    result = checking == X ? 1 : 2;
                }
            } else{
                checking = board[i][j];
                connected = 1;
            }
        }
        i++;
    }

    // Check for 4 connected disks in a column

    i = 0;
    j = 0;
    while(j < NCOLUMNS and result == 0){
        i = 0;
        // type of disk (X or O)
        cell checking = board[i][j];
        int connected = 1;
        // check for consecutive equal disks for each column
        while(i < (NROWS - 1) and result == 0){
            i++;
            if(board[i][j] == checking and checking != cell::empty){
                connected++;
                if(connected == 4){
                    // 4 connected disks results in endgame
                    result = checking == X ? 1 : 2;
                }
            } else{
                checking = board[i][j];
                connected = 1;
            }
        }
        j++;
    }

    // Check for descending diagonals (in a physical sense)
    i = 0;
    j = 0;
    // type of disk (X or O)
    cell checking = board[i][j];
    int connected = 1;

    // check for consecutive equal disks for each descending diagonal

    // first check "main diagonal", where i == j
    while(i < (NROWS - 1) and result == 0){
        i++;
        j++;
        if(board[i][j] == checking and checking != cell::empty){
            connected++;
            if(connected == 4){
                // 4 connected disks results in endgame
                result = checking == X ? 1 : 2;
            }
        } else{
            checking = board[i][j];
            connected = 1;
        }
    }

    // now, diagonals starting in the first row
    i = 0;
    j = 1;
    while(j <= NCOLUMNS - 4 and result == 0){
        // starting point
        int ii = i;
        int jj = j;

        checking = board[ii][jj];
        connected = 1;

        // check the diagonal
        while(ii < (NROWS - 1) and jj < (NCOLUMNS - 1) and result == 0){
            ii++;
            jj++;
            if(board[ii][jj] == checking and checking != cell::empty){
                connected++;
                if(connected == 4){
                    // 4 connected disks results in endgame
                    result = checking == X ? 1 : 2;
                }
            } else{
                checking = board[ii][jj];
                connected = 1;
            }
        }
        j++;
    }

    // last, diagonals starting in the first column
    i = 1;
    j = 0;
    while(i <= NROWS - 4 and result == 0){
        // starting point
        int ii = i;
        int jj = j;

        checking = board[ii][jj];
        connected = 1;

        // check the diagonal
        while(ii < (NROWS - 1) and jj < (NCOLUMNS - 1) and result == 0){
            ii++;
            jj++;
            if(board[ii][jj] == checking and checking != cell::empty){
                connected++;
                if(connected == 4){
                    // 4 connected disks results in endgame
                    result = checking == X ? 1 : 2;
                }
            } else{
                checking = board[ii][jj];
                connected = 1;
            }
        }
        i++;
    }

    // Check for ascending diagonals (in a physical sense)
    i = NROWS - 1;
    j = 0;
    // type of disk (X or O)
    checking = board[i][j];
    connected = 1;

    // check for consecutive equal disks for each ascending diagonal

    // first check "main diagonal", where i == j
    while(i > 0 and result == 0){
        i--;
        j++;
        if(board[i][j] == checking and checking != cell::empty){
            connected++;
            if(connected == 4){
                // 4 connected disks results in endgame
                result = checking == X ? 1 : 2;
            }
        } else{
            checking = board[i][j];
            connected = 1;
        }
    }

    // now, diagonals starting in the last row
    i = NROWS - 1;
    j = 1;
    while(j <= NCOLUMNS - 4 and result == 0){
        // starting point
        int ii = i;
        int jj = j;

        checking = board[ii][jj];
        connected = 1;

        // check the diagonal
        while(ii > 0 and jj < (NCOLUMNS - 1) and result == 0){
            ii--;
            jj++;
            if(board[ii][jj] == checking and checking != cell::empty){
                connected++;
                if(connected == 4){
                    // 4 connected disks results in endgame
                    result = checking == X ? 1 : 2;
                }
            } else{
                checking = board[ii][jj];
                connected = 1;
            }
        }
        j++;
    }

    // last, diagonals starting in the first column
    i = NROWS - 2;
    j = 0;
    while(i > NROWS - 4 and result == 0){
        // starting point
        int ii = i;
        int jj = j;

        checking = board[ii][jj];
        connected = 1;

        // check the diagonal
        while(ii > 0 and jj < (NCOLUMNS - 1) and result == 0){
            ii--;
            jj++;
            if(board[ii][jj] == checking and checking != cell::empty){
                connected++;
                if(connected == 4){
                    // 4 connected disks results in endgame
                    result = checking == X ? 1 : 2;
                }
            } else{
                checking = board[ii][jj];
                connected = 1;
            }
        }
        i--;
    }

    return result;
}

bool Game::addPiece(int column){
    bool result = false;

    // piece is added if there is an empty cell in the column
    for(int i = (NROWS -1) ; i >= 0 and !result; i--){
        if(board[i][column] == cell::empty){
            if(currentTurn == turnP1){
                board[i][column] = X;
                currentTurn = turnP2;
            }
            else{
                board[i][column] = O;
                currentTurn = turnP1;
            }

            result = true;
            nTurn++;            
        }
    }

    return result;
}
