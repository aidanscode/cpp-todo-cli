todo: main.o
	g++ main.o -o todo

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *.o todo
