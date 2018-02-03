STD = -std=c++11
FILES = client.c
FILES1 = friend.cpp
FILES2 = menu.cpp
FILES3 = MyWrapper.cpp
FILES4 = matchwrapper.cpp
FILES5 = gamewrapper.cpp
FILES6 = lobby.cpp
FILES7 = matchmaking.cpp
FILES8 = serveur.c matchwrapper matchmaking lobby
FILES9 = friend matchmaking.o lobby.o client MyWrapper matchwrapper gamewrapper menu
all: etape1 etape etape2 etape3 etape4 etape5 etape6 etape7 etape8 etape9

etape: $(FILES1)
	g++ -c $(FILES1) -o friend

etape1: $(FILES)
	gcc -c $(FILES)  -o client
	
etape2: $(FILES2)
	g++ -c $(FILES2)  -o menu

etape3: $(FILES3)
	g++ -c $(FILES3)  -o MyWrapper

etape4:
	g++ $(STD) -c $(FILES4) -o matchwrapper

etape5:
	g++ $(STD) -c $(FILES5) -lncurses -o gamewrapper

etape6: $(FILES6)
	g++ $(STD) -c $(FILES6) -o lobby

etape7: $(FILES7)
	g++ $(STD) -c $(FILES7) -o matchmaking

etape8: $(FILES8)
	g++ $(STD) $(FILES8) -lpthread -o server

etape9: $(FILES9)
	g++ $(FILES9) -lncurses -o main

clean:
	RM *.o
	RM *gch
