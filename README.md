# 🎮 so_long

so_long is a small 2D game developed as part of the 42 curriculum.  
The goal of the project is to create a simple game using a graphics library while handling window management, events, and map parsing.

---

## 📖 About the Project

In this game the player must collect all collectibles on the map and then reach the exit.

The map is read from a file and displayed as a grid where each character represents a different element such as walls, collectibles, or the player.

This project focuses on:

- Graphics programming
- Event handling
- Map parsing
- Game loop logic

---

## 🎮 Gameplay

The player must:

- Collect all collectibles (`C`)
- Avoid walls (`1`)
- Reach the exit (`E`) after collecting everything

The player is represented by `P`.

Each movement is counted and displayed.

The player can be moved with W, A, S, D.

---

## 🎨 Sprites

All game sprites used in this project were **created by me**.

---

## 🎥 Gameplay Video

Example gameplay of the project.

[so_long.webm](https://github.com/user-attachments/assets/021fbcd4-ab54-41c1-9653-a2d99517ee38)

---

## 📦 Installation

Clone the repository:

```bash
git clone https://github.com/Mert5558/so_long.git
cd so_long
```

Compile the project:

```bash
make
```

---

## 🚀 Usage

Run the game with a map file:

```bash
./so_long maps/map1.ber
```

---

## 🗺 Map Format

The map must follow these rules:

- Must be rectangular
- Must be surrounded by walls
- Must contain exactly **1 player**
- Must contain at least **1 collectible**
- Must contain **1 exit**

Example:

```
111111
1P0C01
100001
1C00E1
111111
```

---
