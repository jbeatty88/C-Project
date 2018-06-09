CPP = g++
DEBUG = -ggdb
CPPFLAGS = -Wall -Werror $(DEBUG)
#LDFLAGS = -lm
EXE = lexical_analyzer
OBJS = main.o Token.o InputStream.o Lexer.o

.C.o:
	$(CPP) $< -c $(CPPFLAGS)
$(EXE): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $(OBJS)


.PHONY: clean
clean:
	rm -f $(OBJS)
	rm -f $(EXE)
