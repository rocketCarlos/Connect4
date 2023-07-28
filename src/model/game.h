#ifndef GAME_H
#define GAME_h

#include <vector>

 // P1 uses X, P2 uses O
    enum turn {turnP1, turnP2};
    
    // Board cells
    enum cell {empty , X , O};
    
    const int NROWS = 6;
    const int NCOLUMNS = 7;

class Game {
    private:
    
    // 6rows*7columns board
    std::vector<std::vector<cell>> board;

    int nTurn;
    turn currentTurn;

    public:

    /**
     * @brief Default constructor
    */
    Game();

    /**
     * @brief Indicates if game has ended
     * @return 0 if not ended, 1 if player 1 won and 2 if player 2 won
    */
    int gameEnded();

    /**
     * @brief Adds a piece to a column of the board. The piece is X or O depending on current turn.
     * Turn pases from P1 to P2 and vice versa after the piece is correctly added.
     * @param column The column where the piece is being added
     * @return Ture if added correctly, false otherwise
    */
    bool addPiece(int column);

    inline std::vector<std::vector<cell>> getBoard() { return board; }

    inline turn getCurrentTurn() { return currentTurn; }

    inline int getNTurn() { return nTurn; }

};

#endif //GAME_H




