#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

void initMaze(Maze *m) {

    for(int y=0; y<HEIGHT; y++) {
        for(int x=0; x<WIDTH; x++) {

            m->grid[y][x].x1 = x * CELL_SIZE;
            m->grid[y][x].x2 = m->grid[y][x].x1 + CELL_SIZE;

            m->grid[y][x].y1 = y * CELL_SIZE;
            m->grid[y][x].y2 = m->grid[y][x].y1 + CELL_SIZE;

            m->grid[y][x].wall = 0;
        }
    }
}

void printMaze(Maze *m) {

    for(int y=0; y<HEIGHT; y++) {
        for(int x=0; x<WIDTH; x++) {

            printf("(%d,%d,%d,%d) ",
                m->grid[y][x].x1,
                m->grid[y][x].x2,
                m->grid[y][x].y1,
                m->grid[y][x].y2
            );
        }
        printf("\n\n");
    }
}

void divide(Maze *m, int x, int y, int w, int h) {

    if(w < 2 || h < 2)
        return;

    int horizontal = rand() % 2;

    if(horizontal) {

        int wy = y + rand() % h;
        int passage = x + rand() % w;

        for(int i=x; i<x+w; i++) {
            if(i != passage)
                m->grid[wy][i].wall = 1;
        }

        divide(m, x, y, w, wy-y);
        divide(m, x, wy+1, w, y+h-wy-1);
    }
    else {

        int wx = x + rand() % w;
        int passage = y + rand() % h;

        for(int i=y; i<y+h; i++) {
            if(i != passage)
                m->grid[i][wx].wall = 1;
        }

        divide(m, x, y, wx-x, h);
        divide(m, wx+1, y, x+w-wx-1, h);
    }
}