CXXFLAGS = -Wall -g
all: main.o imageio.o tasks.o
	g++ ${CXXFLAGS} -o main main.o imageio.o tasks.o

main: main.o imageio.o tasks.o
	g++ ${CXXFLAGS} -o main main.o imageio.o tasks.o

main.o: main.cpp imageio.h
tasks.o: tasks.cpp tasks.h
imageio.o: imageio.cpp imageio.h


clean:
	rm -f *.o
