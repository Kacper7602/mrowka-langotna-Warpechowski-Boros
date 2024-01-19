#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "ant.h"
#include <math.h>


void drawBoard(char *board, int rows, int columns, int stage){
    printf("Etap: %d \n", stage);
    for(int i = 0; i < columns; ++i) {
            for (int j = 1; j <= rows; ++j) {
                printf("%c ", board[(i*rows)+j]);
            }
            printf("\n");
    }

    printf("\n");
}

void drawBoardToFile(char *board, int rows, int columns, int stage, int iter, char *name) {
    char filename[100];
    sprintf(filename, "%s_%d.txt", name, iter);

    FILE *file = fopen(filename, "a");  // Użyj "a" zamiast "w" dla trybu dopisywania
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "Etap: %d\n", stage);

    for (int i = 0; i < columns; ++i) {
        for (int j = 1; j <= rows; ++j) {
            fprintf(file, "%c ", board[(i * rows) + j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
    fclose(file);
}


int main(int argc, char *argv[]){
    Ant ant;
    int rows = 5;
    int columns = 5;
    int iteration = 5;
    ant.dir = 1;
    int randomBoard = 0;
    char *file = "";
    int ifFile = 0;

    //reading user arguments
    int opt;
    while((opt = getopt(argc, argv, "r:c:i:d:l:f:")) != -1) {
        switch (opt) {
            case 'r':
                rows = atoi(argv[optind - 1]);
                break;
            case 'c':
                columns = atoi(argv[optind - 1]);
                break;
            case 'i':
                iteration = atoi(argv[optind - 1]);
                break;
            case 'd':
                ant.dir = atoi(argv[optind - 1]);
                break;
            case 'l':
                randomBoard = atoi(argv[optind - 1]);
                break;
            case 'f':
                file = argv[optind - 1];
                ifFile = 1;
                break;
            default:
                fprintf(stderr, "Użycie: %s -r liczba_wierszy -c liczba_kolumn -i liczba_iteracji\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    } 

    //allocating memory for board
    char *board = malloc(rows * columns * sizeof(char));
    if (board == NULL) {
        fprintf(stderr, "Błąd alokacji pamięci.\n");
        exit(EXIT_FAILURE);
    }
   
    //filling the board
    srand(time(NULL));
    if(randomBoard == 0){
        for (int i = 0; i < rows*columns+1; ++i) {
            board[i] = '0'; 
        }
    }
    if(randomBoard == 1){
        int randomNumber; 

        for (int i = 0; i < rows*columns+1; ++i) {
            randomNumber = rand() % 2;

            if(randomNumber == 0) board[i] = '0'; 
            else board[i] = '1'; 
        }
    }
    

    //default values for ant
    ant.charDir = setCharDir(ant.dir);
    ant.curBlock = round((rows*columns)/2)+1;    
    ant.curColor = board[ant.curBlock] - '0';
    board[ant.curBlock] = ant.charDir[0];
    


    //file or console
    if(ifFile == 0){
        drawBoard(board, rows, columns, 1);
        
        for(int i=2; i<=iteration; i++){
            move(&ant, board, rows);
            drawBoard(board, rows, columns, i);
        }
    }
    else if(ifFile ==1){
        drawBoardToFile(board, rows, columns, 1, iteration, file);

        for(int i=2; i<=iteration; i++){
            move(&ant, board, rows);
            drawBoardToFile(board, rows, columns, i, iteration, file);
        }
    }    


    free(board);
    return 0;
}
