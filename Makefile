cpexittime_reminder: exittime
	cp ./src/exittime_reminder ./build/exittime_reminder

exittime: exittime.o
	g++ -o ./build/exittime ./build/exittime.o

exittime.o: mkdir
	g++ -c ./src/main.cpp -o ./build/exittime.o

mkdir: clean
	mkdir build

clean:
	rm -rf ./build
