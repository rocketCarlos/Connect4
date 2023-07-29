#ifndef TEXTVIEW_H
#define TEXTVIEW_H

#include "game.h"

class TextView {
    private: 

    // representation of the game
    Game game;
    
    public:

    inline TextView() {}

    /**
     * @brief Displays the initial menu of the game
     * @return Index of the selected option
    */
    int displayMenu();

    /**
     * @brief Displays the AI level selection menu
     * @return Selected level
    */
    int displayAIMenu();

    /**
     * @brief Displays a quick help guide
    */
    void displayHelp();

    /**
     * @brief Asks the user the column where he wants his piece to be added
     * @return The column where the piece is being added
    */
    int requestAdding();

    /**
     * @brief Directly adds a piece on a specific column
     * @param column The column where the piece is being added
     * @return If succesful, the column where the piece is being added
    */
    int requestAdding(int column);

    /**
     * @brief Displays a view of the board
    */
    void showBoard();

    /**
     * @brief Displays the endgame statistics
     * @param ending The result of the game. 1 -> p1 wins, 2 -> p2 wins, 3 -> draw
    */
   void showEndGame(int ending);

    /**
     * @brief Returns the Game object
     * @return The game object
    */
    inline Game getGame() { return game; }
    
};

#endif // textView.h