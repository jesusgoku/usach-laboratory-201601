#include <stdio.h>

typedef struct {

} Board;

typedef struct {
    Board *board;
} Game;

typedef struct {

} Position;

typedef enum code {OK, ERR_FILE_NOT_FOUND, ERR_FILE_NOT_PERMISSION} code;

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

int main(int argc, char *argv[])
{
	printf("%s\n", argv[0]);
	return 0;
}
