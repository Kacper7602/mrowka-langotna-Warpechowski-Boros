#ifndef ANT_H
#define ANT_H

typedef struct {
    int dir;
    char *charDir;
    int curColor;
    int curBlock;
    int nextBlock;
} Ant;

char* setCharDir(int dir);

void changeDirect(Ant *ant, int newDir, int rows);

void move(Ant *ant, char *board, int rows);

#endif