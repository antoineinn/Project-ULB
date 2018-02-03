#ifndef __GAMEWRAPPER_HPP
#define __GAMEWRAPPER_HPP

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Game Game;

Game* newGame(int socket, int player, int mode);
void gameStart(Game* v);
void endGame(Game* v);
#ifdef __cplusplus
}
#endif
#endif
