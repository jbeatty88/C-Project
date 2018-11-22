CPP = g++
DEBUG = -ggdb
CPPFLAGS = -g -Wall -Werror -std=c++17 $(DEBUG)
#LDFLAGS = -lm
EXE = lab3_2
L_OBJS = Lexer.o InputStream.o Token.o
P_OBJS = DatalogProgram.o Parser.o Predicate.o Parameter.o Rule.o
R_OBJS = Interpreter.o Header.o Relation.o Row.o Database.o
OBJS = main.o TestCase.o $(L_OBJS) $(P_OBJS) $(R_OBJS)

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
	zip lab3pt2 *cpp *h makefile

.PHONY: run1
run1:
	./$(EXE) test1.txt

.PHONY: run2
run2:
	./$(EXE) test2.txt

.PHONY: run3
run3:
	./$(EXE) test3.txt

.PHONY: run4
run4:
	./$(EXE) test4.txt

.PHONY: run5
run5:
	./$(EXE) test5.txt

.PHONY: run6
run6:
	./$(EXE) test6.txt


