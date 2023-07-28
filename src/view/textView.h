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
     * @brief Displays a quick help guide
    */
    void displayHelp();

    /**
     * @brief Asks the user the column where he wants his piece to be added
     * @return The column where the piece is being added
    */
    int requestAdding();

    /**
     * @brief Displays a view of the board
    */
    void showBoard();

    /**
     * @brief Returns the Game object
     * @return The game object
    */
    inline Game getGame() { return game; }
    
};

#endif // textView.h