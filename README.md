# Snake Game in C++

This is a simple console-based **Snake Game** implemented in C++ using basic programming concepts. The game involves navigating a snake on a 20x20 grid to collect food while avoiding collisions with walls or the snake's own body.

---

## How to Run

### Prerequisites
- A C++ compiler such as `g++`.
- A console or terminal environment (Windows, Linux, or Mac).

### Steps to Compile and Run
1. Save the game code in a file named `snake_game.cpp`.
2. Open a terminal or command prompt in the file's directory.
3. Compile the code using the command:
   ```bash
   g++ snake_game.cpp -o snake_game
How to Play
Objective
Guide the snake to collect food (O) and grow as long as possible.
Controls
Use W to move UP.
Use A to move LEFT.
Use S to move DOWN.
Use D to move RIGHT.
Game Rules
The snake starts in the middle of the grid and grows longer each time it eats food.
Avoid hitting:
Walls (#).
The snake's own body (o).
The game ends if a collision occurs.
Game Mechanics
Snake Movement
The snake moves continuously in the current direction.
Use the controls to change its direction.
Food Generation
Food appears randomly within the grid.
The snake grows longer when it eats food.
Collision Detection
The game ends if the snake:
Hits the boundary of the grid.
Runs into its own body.
Scoring
Your score is the length of the snake minus one (the starting length).
Demo Output
Game Start
shell
Copy code
####################
#                  #
#                  #
#                  #
#                  #
#                  #
#                  #
#                  #
#                  #
#         o        #
#                  #
#                  #
#                  #
#                  #
#        O         #
#                  #
#                  #
#                  #
#                  #
####################
Snake Growing
shell
Copy code
####################
#                  #
#                  #
#                  #
#                  #
#                  #
#                  #
#                  #
#                  #
#         o        #
#         o        #
#         o        #
#                  #
#                  #
#        O         #
#                  #
#                  #
#                  #
#                  #
####################
Game Over
mathematica
Copy code
Game Over! Your score: 5
Key Features
Dynamic Gameplay: The snake grows longer as you progress.
Collision Logic: Detects collisions with walls and itself.
Simple and Intuitive Controls: Easy to play using keyboard keys.
Enhancements

