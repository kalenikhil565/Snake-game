#include <iostream>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <chrono>
#include <thread>
#include <algorithm>

using namespace std;

// Constants
const int mapWidth = 20, mapHeight = 20;
enum Direction { UP, DOWN, LEFT, RIGHT };

// Game Variables
vector<pair<int, int>> snake;  // Snake's body positions
pair<int, int> food;           // Food position
Direction currentDirection = RIGHT; // Initial direction
bool running = true;           // Game status

// Function Declarations
void initializeGame();
void drawMap();
void moveSnake();
void generateFood();
bool checkCollision();
void changeDirection(char key);

int main() {
    initializeGame();

    while (running) {
        if (_kbhit()) { // Check for keypress
            changeDirection(_getch());
        }

        moveSnake();
        if (checkCollision()) break;

        system("cls"); // Clear screen
        drawMap();
        this_thread::sleep_for(chrono::milliseconds(200)); // Game speed
    }

    cout << "Game Over! Score: " << snake.size() - 1 << endl;
    return 0;
}

void initializeGame() {
    snake.push_back({ mapWidth / 2, mapHeight / 2 }); // Snake starts at center
    generateFood();
}

void drawMap() {
    for (int y = 0; y < mapHeight; ++y) {
        for (int x = 0; x < mapWidth; ++x) {
            if (x == 0 || x == mapWidth - 1 || y == 0 || y == mapHeight - 1) {
                cout << '#'; // Walls
            } else if (x == food.first && y == food.second) {
                cout << 'O'; // Food
            } else {
                bool isSnakePart = false;
                for (auto segment : snake) {
                    if (segment.first == x && segment.second == y) {
                        isSnakePart = true;
                        break;
                    }
                }
                cout << (isSnakePart ? 'o' : ' '); // Snake or empty space
            }
        }
        cout << endl;
    }
}

void moveSnake() {
    pair<int, int> head = snake.front(); // Current head position
    switch (currentDirection) {
    case UP:    head.second--; break;
    case DOWN:  head.second++; break;
    case LEFT:  head.first--; break;
    case RIGHT: head.first++; break;
    }

    snake.insert(snake.begin(), head); // Add new head position

    if (head == food) {
        generateFood(); // New food
    } else {
        snake.pop_back(); // Remove tail if no food eaten
    }
}

void generateFood() {
    do {
        food = { rand() % (mapWidth - 2) + 1, rand() % (mapHeight - 2) + 1 };
    } while (any_of(snake.begin(), snake.end(), [&](auto segment) {
        return segment == food;
    }));
}

bool checkCollision() {
    pair<int, int> head = snake.front();
    if (head.first <= 0 || head.first >= mapWidth - 1 ||
        head.second <= 0 || head.second >= mapHeight - 1) {
        return true; // Wall collision
    }
    return count(snake.begin() + 1, snake.end(), head) > 0; // Self-collision
}

void changeDirection(char key) {
    switch (key) {
    case 'w': if (currentDirection != DOWN) currentDirection = UP; break;
    case 's': if (currentDirection != UP) currentDirection = DOWN; break;
    case 'a': if (currentDirection != RIGHT) currentDirection = LEFT; break;
    case 'd': if (currentDirection != LEFT) currentDirection = RIGHT; break;
    }
}
