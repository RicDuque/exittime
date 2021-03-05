exittime: exittime.o
	g++ -o ./build/exittime ./build/exittime.o

exittime.o: mkdir
	g++ -c ./src/main.cpp -o ./build/exittime.o

mkdir: clean
	mkdir build

clean:
	rm -rf ./build
