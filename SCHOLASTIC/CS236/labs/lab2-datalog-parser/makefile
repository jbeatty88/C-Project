CPP = g++
DEBUG = -ggdb
CPPFLAGS = -g -Wall -Werror -std=c++17 $(DEBUG)
#LDFLAGS = -lm
EXE = lab2
OBJS = main.o Token.o InputStream.o Lexer.o Parser.o DatalogProgram.o Predicate.o Parameter.o Rule.o Expression.o

.C.o:
	$(CPP) $< -c $(CPPFLAGS)
$(EXE): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $(OBJS)


.PHONY: clean
clean:
	rm -f $(OBJS)
	rm -f $(EXE)

.PHONY: firstClassTest
firstClassTest:
	./$(EXE) test1.txt

.PHONY: secondClassTest
secondClassTest:
	./$(EXE) test2.txt

.PHONY: testAll
testAll:
	./$(EXE) lab2pt1/test1.txt
	./$(EXE) lab2pt1/test2.txt
	./$(EXE) lab2pt1/test3.txt
	./$(EXE) lab2pt1/test4.txt
	./$(EXE) lab2pt1/test5.txt
	./$(EXE) lab2pt1/test6.txt
	./$(EXE) lab2pt1/test7.txt
	./$(EXE) lab2pt1/test8.txt
	./$(EXE) lab2pt1/test9.txt
	./$(EXE) lab2pt1/test10.txt
	
	
.PHONY: testSummary
testSummary:
	valgrind --leak-check=full ./$(EXE) test1.txt
	valgrind --leak-check=full ./$(EXE) test2.txt	
	pmccabe -v *cpp

.PHONY: pmccabe
pmccabe:
	pmccabe -v *cpp

.PHONY: zip
zip:
	zip lab2pt2 *cpp *h makefile

