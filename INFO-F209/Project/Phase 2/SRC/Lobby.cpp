#include "Lobby.hpp"

Lobby::Lobby(int ID, int mode): _lobbyID(ID), _lobbyMode(mode), _playersInLobby(0), _playerList{-1,-1,-1,-1} {}

bool Lobby::addPlayer(int playerID, int playerMode) {
    int i = _playersInLobby;
    // while the lobby is not full
    if (i+1 <= 4 && _lobbyMode == playerMode) {
        _playerList[i] = playerID; //playerID is socket
		_playersInLobby++;
        return true;
    }
    return false;
}


int Lobby::getPlayersInLobby() {
	return _playersInLobby;
}

int Lobby::getLobbyID() {
	return _lobbyID;
}

int Lobby::getMode() {
	return _lobbyMode;
}

int Lobby::getPlayerList() {
	return *_playerList;
}

bool Lobby::isFull() {
	return (_playersInLobby==4);
}
