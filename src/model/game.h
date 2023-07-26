#ifndef GAME_H
#define GAME_h

#include <vector>

class Game {
    private:
    // Board cells
    enum cell {empty , X , O};
    // 6rows*7columns board
    std::vector<std::vector<cell>> board;

    const int NROWS = 6;
    const int NCOLUMNS = 7;

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
     * @brief Adds a piece to a column of the board
     * @return Ture if added correctly, false otherwise
    */
    bool addPiece(int column, cell piece);

    inline std::vector<std::vector<cell>> getBoard() { return board; }

};

#endif //GAME_H




