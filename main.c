#include <stdio.h>

#include "libs/lettersoup.h"


int main(int argc, char *argv[])
{
    code statusCode = OK;
    Board *board = NULL;

	board = createBoard(10, 10, LS_DIFFICULT_EASY, &statusCode);

    if (OK != statusCode) {
        printf("%d\n", statusCode);
    }

	return 0;
}
