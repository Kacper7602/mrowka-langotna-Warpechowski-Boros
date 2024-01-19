#include <stdio.h>
#include <stdlib.h>
#include "ant.h"

char* setCharDir(int dir){
    switch (dir) {
        case 1: return "^"; break;
        case 2: return ">"; break;
        case 3: return "v"; break;
        case 4: return "<"; break;
        default: return ""; break;
    }
}

void changeDirect(Ant *ant, int newDir, int rows) {
    // printf("Newdir: %d \n", newDir);
    if (newDir == 0) {
        ant->dir = 4;
    } 
    else if (newDir == 5) {
        ant->dir = 1;
    } 
    else {
        ant->dir = newDir;
    }


    switch (ant->dir) {
        case 1: 
            ant->nextBlock = ant->curBlock - rows; 
            break;
        case 2:
            ant->nextBlock = ant->curBlock + 1; 
            break;
        case 3:
            ant->nextBlock = ant->curBlock + rows; 
            break;
        case 4:
            ant->nextBlock = ant->curBlock - 1; 
            break;
        
        default: ; break;
    }
    ant->charDir = setCharDir(ant->dir);
}

void move(Ant *ant, char *board, int rows) {
    //change direction
    if (ant->curColor == 0){
        // turn right
        changeDirect(ant, ant->dir + 1, rows);
    } 
    else{
        // turn left
        changeDirect(ant, ant->dir - 1, rows);
    }

    //changing color to opposite
    if(ant->curColor == 0){
            ant->curColor = 1;
            board[ant->curBlock] = '1';
    }
    else if(ant->curColor == 1){
            ant->curColor = 0;
            board[ant->curBlock] = '0';
    }
        

    //switching to next block
    ant->curBlock = ant->nextBlock;
    char temp[2];
    snprintf(temp, sizeof(temp), "%c", board[ant->curBlock]);
    ant->curColor = atoi(temp);


    //switching color looking to mouse looking on next block
    board[ant->curBlock] = ant->charDir[0];
}