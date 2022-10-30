CXXFLAGS = -Wall -g
all: sample.o imageio.o tasks.o
	g++ ${CXXFLAGS} -o sample sample.o imageio.o tasks.o

sample: sample.o imageio.o tasks.o
	g++ ${CXXFLAGS} -o sample sample.o imageio.o tasks.o

sample.o: sample.cpp imageio.h
tasks.o: tasks.cpp tasks.h
imageio.o: imageio.cpp imageio.h


clean:
	rm -f *.o
