#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "textView.h"

class Controller {
    private: 

    // Game interface
    TextView game;

    public:

    inline Controller() {}

    /**
     * @brief Starts the game and controls the different game phases
    */
    void startPlaying();
    
};

#endif // controller.h