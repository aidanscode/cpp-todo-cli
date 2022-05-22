todo: main.o command-handler.o fileio.o util.o
	g++ main.o command-handler.o fileio.o util.o -o todo

main.o: main.cpp
	g++ -c main.cpp

command-handler.o: command-handler.cpp command-handler.h
	g++ -c command-handler.cpp

fileio.o: fileio.cpp fileio.h
	g++ -c fileio.cpp

util.o: util.cpp util.h
	g++ -c util.cpp

clean:
	rm -rf *.o todo
