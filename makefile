all: server.exe client.exe
	
WIN_LIBS = -lwsock32 -lws2_32
#it with MinGW Distro nuwen
	
#dirbin:
#	mkdir bin -p

server.exe: server.cpp
	g++  server.cpp  $(WIN_LIBS) -lboost_system -o ./server

client.exe: client.cpp
	g++ client.cpp $(WIN_LIBS) -lboost_system -o ./client