#include "AI.h"
#include <iostream>
#include <random>
#include <chrono>

using namespace std;

AI::AI(int AIplayer, int level):
    AIplayer(AIplayer),
    level(level)
{}

int AI::getMove(const vector<vector<cell>> & board){
    int column;

    switch(level){
        // Random move AI
        case 1: {
            unsigned seed = chrono::system_clock::now().time_since_epoch().count();
            mt19937 generator(seed);
            do{
                column = generator() % NCOLUMNS;
            }while(board[0][column] != cell::empty);
        }
        break;

        default: {
            cout << "This level is not available yet" << endl;
            column = -1;
        }
    }

    return column;
}