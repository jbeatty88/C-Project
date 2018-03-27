CC = g++
CFLAGS = -Wall -Wextra -g
SRC = main.cpp linkedList.cpp
DEPS = linkedList.h
OBJS = $(SRC:.cpp=.o)
EXE = main

all: $(EXE)
	@echo Make has finished

$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $@

.cpp.o:
	$(CC) $(CFLAGS)	-c $*.cpp

#default:main

#%.o:%.cpp
#	$(CC) $(CFLAGS) -c $<

#main:$(OBJS)
#	$(CC) $(CFLAGS) -o main $(OBJS)

#main: linkedList.cpp
run:
	./main

.phony:clean
clean:
#	rm main $(OBJS)
	$(RM) *.o *~ $(EXE)
