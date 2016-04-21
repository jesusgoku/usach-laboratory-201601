#include <stdlib.h>

#include "lettersoup.h"

Board *createBoard(int w, int h, int difficulty, code *statusCode)
{
    Board *board = NULL;

    if (w < LS_MIN_BOARD_W_SIZE || h < LS_MIN_BOARD_H_SIZE) {
        *statusCode = ERR_ILEGAL_BOARD_SIZE;
        return NULL;
    }

    return board;
}
