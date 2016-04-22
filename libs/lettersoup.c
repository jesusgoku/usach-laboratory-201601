#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "lettersoup.h"

/**
 * Create board with sizes
 *
 * @param  w          width of board
 * @param  h          height of board
 * @param  difficulty difficult of board
 * @param  statusCode pointer to write an error status code
 *
 * @return            pointer to new board
 */
Board *createBoard(int w, int h, int difficulty, code *statusCode)
{
    Board *board = createEmptyBoard(w, h, statusCode);

    if (NULL == board || OK != *statusCode) {
        return NULL;
    }

    for (int j = 0; j < board->h; ++j) {
        for (int k = 0; k < board->w; ++k) {
            board->board[j][k] = ' ';
        }
    }

    *statusCode = OK;

    return board;
}

/**
 * Save board to a file
 *
 * @param board      board to persist
 * @param id         pointer to write id of saved files
 * @param statusCode pointer to write an error status code
 */
void saveBoard(Board *board, int *id, code *statusCode)
{
    FILE *fp;
    int generatedID;
    char filePath[100];

    srand(time(NULL));

    do {
        generatedID = rand();
        sprintf(filePath, "saved_games/%d.%s", generatedID, "txt");
    } while (file_exists(filePath));

    fp = fopen(filePath, "w");

    if (NULL == fp) {
        *statusCode = ERR_FILE_NOT_FOUND;
        return;
    }

    fprintf(fp, "%d %d\n", board->w, board->h);

    for (int j = 0; j < board->h; ++j) {
        for (int k = 0; k < board->w; ++k) {
            fprintf(fp, "%c ", board->board[j][k]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    *id = generatedID;
    *statusCode = OK;
}

Board *loadBoard(int id, code *statusCode)
{

}

/**
 * Create empty board
 *
 * @param  w          width of board
 * @param  h          height of board
 * @param  statusCode pointer to write an error status code
 *
 * @return            pointer to new board
 */
Board *createEmptyBoard(int w, int h, code *statusCode)
{
    Board *board = NULL;
    BoardGrid boardGrid = NULL;

    if (w < LS_MIN_BOARD_W_SIZE || h < LS_MIN_BOARD_H_SIZE) {
        *statusCode = ERR_ILEGAL_BOARD_SIZE;
        return NULL;
    }

    board = (Board *) malloc(sizeof(Board));

    if (NULL == board) {
        *statusCode = ERR_NO_MEMORY_ALLOCATE;
        return NULL;
    }

    board->w = w;
    board->h = h;

    boardGrid = (BoardGrid) malloc(sizeof(BoardRow) * h);

    if (NULL == boardGrid) {
        *statusCode = ERR_NO_MEMORY_ALLOCATE;
        return NULL;
    }

    for (int k = 0; k < h; ++k) {
        boardGrid[k] = (BoardRow) malloc(sizeof(BoardCell) * w);

        if (NULL == boardGrid[k]) {
            *statusCode = ERR_NO_MEMORY_ALLOCATE;
            return NULL;
        }
    }

    board->board = boardGrid;

    *statusCode = OK;

    return board;
}

/**
 * Print to stdout board
 *
 * @param board board to print
 */
void printBoard(Board *board)
{
    for (int j = 0; j < board->h; ++j) {
        for (int k = 0; k < board->w; ++k) {
            printf("%c ", board->board[j][k]);
        }
        printf("\n");
    }
}

/**
 * Check if file exists
 *
 * @param  filename file name to check
 *
 * @return          true if file exists
 */
bool file_exists(const char *filename)
{
    FILE *fp = fopen(filename, "r");

    if (NULL != fp) {
        fclose(fp);
        return true;
    }

    return false;
}
