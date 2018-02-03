#ifndef __MATCHWRAPPER_HPP
#define __MATCHWRAPPER_HPP

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Matchmaking Matchmaking;

Matchmaking* newMatchmaking();
int* Matchmaking_newPlayer(Matchmaking* v, int newSocket ,int mode);
#ifdef __cplusplus
}
#endif
#endif
