## Variables
CC = g++
FLAGS = -Wall -g 
EXE_NAME = lexical_analyzer
OBJS = main.o Token.o InputStream.o Lexer.o

.C.o:
	$(CC) $< -c $(FLAGS) $(INC)
$(EXE_NAME): $(OBJS)
	$(CC) -o $@ $(OBJS) $(FLAGS) $(INC) $(LIBS) $(XLIBS) -lm


.PHONY: clean
clean:
	rm -f $(OBJS)
	rm -f $(EXE_NAME)
