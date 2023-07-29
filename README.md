# Connect4
Code for playing Connect 4 in a console

Compile by using the makefile.

How to play: execute the Connect4 executable file that will be located in the ./bin folder and start playing

You can play against another human or vs an AI.
You can even simulate a match between 2 AI.

Game rules:

X pieces represent player 1
O pieces represent player 2

First player to connect 4 of its pieces in horizontal, vertical or diagonal, wins

Each turn, players choose a column to put a piece on, which will fall to the lowest empty space of that column.

Example:

--     Connect 4     --     

Player 1 -> X  |  Player 2 -> O
Turn: 10
Current player: P2

  1  2  3  4  5  6  7  
| -  -  -  -  -  -  - |
| -  -  -  -  -  -  - |
| -  -  -  -  -  -  - |
| -  -  -  -  X  -  - |
| -  -  X  O  O  -  - |
| -  -  O  X  X  X  O |
\---------------------
