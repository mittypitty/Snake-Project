# Two-Player Snake Game

A two-player console-based implementation of the classic Snake game, developed in C++ as the final project for the **Introduction to Programming** course at **Shahid Beheshti University**.

## About the Project

The game allows two players to control separate snakes simultaneously on the same board. Players compete to collect fruits and increase their scores while avoiding walls, bombs, their own bodies, and the opposing snake.

The project was developed to practice fundamental programming concepts such as functions, arrays, pointers, control structures, input handling, and basic game-loop design.

## Features

- Two-player local gameplay
- Independent keyboard controls for each player
- Three game-speed options: Slow, Medium, and Fast
- Customizable snake colors
- Fruit collection and snake growth
- Bomb obstacles
- Collision detection
- Real-time score display
- Player scoreboard
- Score ranking using Bubble Sort
- Colored console interface using CLUI

## Controls

| Player | Up | Down | Left | Right |
|--------|----|------|------|-------|
| Player 1 | W | S | A/D | A/D |
| Player 2 | ↑ | ↓ | ← | → |

> Player 1 uses the WASD keys, while Player 2 uses the arrow keys.

## Game Rules

Each snake starts with a short initial body and moves continuously across the board.

Collecting a fruit:
- increases the player's score;
- increases the snake's length.

The game ends when a snake collides with:
- a wall;
- a bomb;
- its own body;
- the other snake.

The player with the higher score wins.

## Technologies

- C++
- CLUI
- Windows Console API
- MinGW / GCC

## Running the Project

The project was developed for Windows and uses Windows-specific console functionality.

Compile the source file using a compatible C++ compiler such as MinGW:

```bash
g++ "snake-sara shiri.cpp" -o snake
```

Then run:

```bash
./snake
```

Make sure `clui.h` is available in the same directory as the source file.

## Course Information

- **Course:** Introduction to Programming
- **University:** Shahid Beheshti University
- **Major:** Computer Engineering
- **Semester:** Fall 2023
- **Project Type:** Individual Final Project
