#include "game.h"

using namespace std;

Game::Game(){
    // initialize board
    board.resize(NROWS);
    for(int i = 0; i < NROWS; i++){
        board[i].resize(NCOLUMNS);
        for(int j = 0; j < NCOLUMNS; j++){
            board[i][j] = empty;
        }
    }

    currentTurn = turnP1;
}

int Game::gameEnded(){
    int result = 0; // 0 -> not ended, 1 -> p1 wins, 2 -> p2 wins

    // Check for 4 connected disks in a row
    int i = 0;
    while(i < NROWS and result == 0){
        int j = 0;
        // type of disk (X or O)
        cell checking = board[i][j];
        int connected = 1;
        // check for consecutive equal disks for each row
        while(j < (NCOLUMNS - 1) and result == 0){
            j++;
            if(board[i][j] == checking and checking != empty){
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
    // now i is for columns and j for rows
    i = 0;
    while(i < NCOLUMNS and result == 0){
        int j = 0;
        // type of disk (X or O)
        cell checking = board[j][i];
        int connected = 1;
        // check for consecutive equal disks for each column
        while(j < (NROWS - 1) and result == 0){
            j++;
            if(board[j][i] == checking and checking != empty){
                connected++;
                if(connected == 4){
                    // 4 connected disks results in endgame
                    result = checking == X ? 1 : 2;
                }
            } else{
                checking = board[j][i];
                connected = 1;
            }
        }
        i++;
    }

    // Check for descending diagonals (in a physical sense)
    // now i is for columns and j for rows again
    i = 0;
    int j = 0;
    // type of disk (X or O)
    cell checking = board[j][i];
    int connected = 1;

    // check for consecutive equal disks for each descending diagonal

    // first check "main diagonal", where i == j
    while(i < NROWS - 1 and result == 0){
        i++;
        j++;
        if(board[i][j] == checking and checking != empty){
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
            if(board[ii][jj] == checking and checking != empty){
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
    while(1 <= NROWS - 4 and result == 0){
        // starting point
        int ii = i;
        int jj = j;

        checking = board[ii][jj];
        connected = 1;

        // check the diagonal
        while(ii < (NROWS - 1) and jj < (NCOLUMNS - 1) and result == 0){
            ii++;
            jj++;
            if(board[ii][jj] == checking and checking != empty){
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
    cell checking = board[j][i];
    int connected = 1;

    // check for consecutive equal disks for each ascending diagonal

    // first check "main diagonal", where i == j
    while(i < NROWS - 1 and result == 0){
        i--;
        j++;
        if(board[i][j] == checking and checking != empty){
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
    i = NROWS - 1;
    j = 1;
    while(j <= NCOLUMNS - 4 and result == 0){
        // starting point
        int ii = i;
        int jj = j;

        checking = board[ii][jj];
        connected = 1;

        // check the diagonal
        while(ii < (NROWS - 1) and jj < (NCOLUMNS - 1) and result == 0){
            ii--;
            jj++;
            if(board[ii][jj] == checking and checking != empty){
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
    while(1 <= NROWS - 4 and result == 0){
        // starting point
        int ii = i;
        int jj = j;

        checking = board[ii][jj];
        connected = 1;

        // check the diagonal
        while(ii < (NROWS - 1) and jj < (NCOLUMNS - 1) and result == 0){
            ii--;
            jj++;
            if(board[ii][jj] == checking and checking != empty){
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

    return result;
}

bool Game::addPiece(int column){
    bool result = false;

    // piece is added if there is an empty cell in the column
    for(int i = (NROWS -1) ; i >= 0; i--){
        if(board[i][column] == empty){
            if(currentTurn == turnP1){
                board[i][column] = X;
                currentTurn = turnP2;
            }
            else{
                board[i][column] = O;
                currentTurn = turnP1;
            }

            result = true;            
        }
    }

    return result;
}
