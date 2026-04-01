CC = g++
CFLAGS = -Wall

# Platform-specific linker flags
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
LDFLAGS = -framework OpenGL -framework GLUT
else
LDFLAGS = -lglut -lGL -lGLU
endif

OBJS = main.o program.o repeat.o forward.o jump.o left.o right.o

all: logo

logo: $(OBJS)
	$(CC) $(OBJS) -o logo $(LDFLAGS)

main.o: main.cpp program.h command.h
	$(CC) $(CFLAGS) -c main.cpp

program.o: program.cpp program.h command.h forward.h jump.h left.h right.h repeat.h
	$(CC) $(CFLAGS) -c program.cpp

repeat.o: repeat.cpp repeat.h command.h program.h
	$(CC) $(CFLAGS) -c repeat.cpp

forward.o: forward.cpp forward.h command.h
	$(CC) $(CFLAGS) -c forward.cpp

jump.o: jump.cpp jump.h command.h
	$(CC) $(CFLAGS) -c jump.cpp

left.o: left.cpp left.h command.h
	$(CC) $(CFLAGS) -c left.cpp

right.o: right.cpp right.h command.h
	$(CC) $(CFLAGS) -c right.cpp

clean:
	rm -f *.o logo
