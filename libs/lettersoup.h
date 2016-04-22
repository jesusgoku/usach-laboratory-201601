/**
 * Lettersoup.h
 *
 * @author Jesus Urrutia <jesus.urrutia@gmail.com>
 */

#ifndef __LETTERSOUP_H__
#define __LETTERSOUP_H__

// -- Constants

#define LS_MIN_BOARD_W_SIZE 10
#define LS_MIN_BOARD_H_SIZE 10

#define LS_DIFFICULT_EASY 0
#define LS_DIFFICULT_MEDIUM 1
#define LS_DIFFICULT_HARD 2

// -- Data Structures

typedef char ** BoardGrid;
typedef char * BoardRow;
typedef char BoardCell;

typedef struct {
    int w;
    int h;
    BoardGrid board;
} Board;

typedef struct {
    Board *board;
} Game;

typedef struct {
    int row;
    int col;
} Position;

typedef enum code {
    OK,
    ERR_FILE_NOT_FOUND,
    ERR_FILE_NOT_PERMISSION,
    ERR_ILEGAL_BOARD_SIZE,
    ERR_NO_MEMORY_ALLOCATE
} code;

// -- Function Prototypes (Obligatory)

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
Board *createBoard(int w, int h, int difficulty, code *statusCode);

void saveBoard(Board *board, int *id, code *statusCode);

Board *loadBoard(int id, code *statusCode);

int checkBoard(Board *board, code *statusCode);

void play(Board *board, Position *positions, int length, code *statusCode);

void saveGame(Game *game, int *id, code *statusCode);

Game *loadGame(int id, code *statusCode);

void print(Board *board, code *statusCode);

void saveGameHistory(Game *game, int *id, code *statusCode);

Game *loadGameHistory(int id, code *statusCode);

int getScore(Game *game);

// -- Function Prototypes (Utilities)

/**
 * Create empty board
 *
 * @param  w          width of board
 * @param  h          height of board
 * @param  statusCode pointer to write an error status code
 *
 * @return            pointer to new board
 */
Board *createEmptyBoard(int w, int h, code *statusCode);

#endif // __LETTERSOUP_H__
