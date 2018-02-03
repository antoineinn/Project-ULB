#ifndef LOBBY_HPP
#define LOBBY_HPP


class Lobby {
public:
    // constructors
    Lobby(int ID, int mode);
    ~Lobby() = default;
    // functions
    bool addPlayer(int playerID, int playerMode);
    // getters
    int getPlayersInLobby();
    int getLobbyID();
    int getMode();
    int* getPlayerList();
    bool isFull();
private:
    int _lobbyID;
    int _lobbyMode;
    int _playersInLobby;
    int _playerList[4];
};

#endif // LOBBY_HPP
