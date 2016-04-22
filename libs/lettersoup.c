#include <stdlib.h>

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

    return board;
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

    for (int k = 0; k < w; ++k) {
        boardGrid[k] = (BoardRow) malloc(sizeof(BoardCell) * w);

        if (NULL == boardGrid[k]) {
            *statusCode = ERR_NO_MEMORY_ALLOCATE;
            return NULL;
        }
    }

    board->board = boardGrid;

    return board;
}
