#ifndef MAZE_H
#define MAZE_H

#define WIDTH 10
#define HEIGHT 10
#define CELL_SIZE 10

typedef struct {
    int x1, x2;
    int y1, y2;
    int wall;
} Cell;

typedef struct {
    Cell grid[HEIGHT][WIDTH];
} Maze;

void initMaze(Maze *m);
void printMaze(Maze *m);
void divide(Maze *m, int x, int y, int w, int h);

#endif