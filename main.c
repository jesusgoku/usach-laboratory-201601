#include <stdio.h>

#include "libs/lettersoup.h"


int main(int argc, char *argv[])
{
    code statusCode = OK;
    Board *board = NULL;

	board = createBoard(30, 15, LS_DIFFICULT_EASY, &statusCode);

    if (OK != statusCode) {
        printf("%d\n", statusCode);
    }

    printBoard(board);

    int id;
    saveBoard(board, &id, &statusCode);

	return 0;
}
