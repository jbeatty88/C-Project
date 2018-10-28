CPP = g++
DEBUG = -ggdb
CPPFLAGS = -g -Wall -Werror -std=c++17 $(DEBUG)
#LDFLAGS = -lm
EXE = lab3_1
OBJS = main.o Interpreter.o Token.o InputStream.o Lexer.o Parser.o DatalogProgram.o Predicate.o Parameter.o Rule.o Expression.o

.C.o:
	$(CPP) $< -c $(CPPFLAGS)
$(EXE): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $(OBJS)


.PHONY: clean
clean:
	rm -f $(OBJS)
	rm -f $(EXE)
	
.PHONY: pmccabe
pmccabe:
	pmccabe -v *cpp

.PHONY: zip
zip:
	zip lab3pt1 *cpp *h makefile

.PHONY: run
run:
	./$(EXE) program1.txt

