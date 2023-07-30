#ifndef AI_H
#define AI_H

#include "game.h"
#include <vector>

class AI{
    private:

    int AIplayer;
    int level;

    /**
     * @brief Calculates the heuristic value for a board. Positive values are favorable for P1 
     * and negative values are favorable for P2.
     * @return The heuristic value for the board.
    */
    int heuristic(const std::vector<std::vector<cell>> & board);

    public:

    /**
     * @brief Creates and initializes an AI object
     * @param  AIplayer AIplayer's turn (1 or 2)
     * @param level AI's level
    */
    AI(int AIplayer, int level);

    /**
     * @brief Gets the next move from the AI
     * @param board The game's current board
    */
    int getMove(const std::vector<std::vector<cell>> & board);

};

#endif //AI.h