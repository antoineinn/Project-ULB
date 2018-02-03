STD = -std=c++11
FILES4 = matchwrapper.cpp
FILES5 = ranking.cpp
FILES6 = lobby.cpp
FILES7 = matchmaking.cpp
FILES8 = server.c matchwrapper matchmaking lobby ranking
all: etape4 etape5 etape6 etape7 etape8


etape4:
	g++ $(STD) -c $(FILES4) -o matchwrapper
etape5:
	g++ $(STD) -c $(FILES5) -o ranking
etape6: $(FILES6)
	g++ $(STD) -c $(FILES6) -o lobby

etape7: $(FILES7)
	g++ $(STD) -c $(FILES7) -o matchmaking

etape8: $(FILES8)
	g++ $(STD) $(FILES8) -lpthread -o server

clean:
	rm -f server matchwrapper ranking lobby matchmaking ranking 
