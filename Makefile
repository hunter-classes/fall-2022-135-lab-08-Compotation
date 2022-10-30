CXXFLAGS = -Wall -g
all: sample.o imageio.o
	g++ ${CXXFLAGS} -o sample sample.o imageio.o

sample: sample.o imageio.o
	g++ ${CXXFLAGS} -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h


clean:
	rm -f sample.o imageio.o
