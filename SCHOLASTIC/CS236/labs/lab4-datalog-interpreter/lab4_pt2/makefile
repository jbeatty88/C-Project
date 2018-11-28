CPP = g++
DEBUG = -ggdb
CPPFLAGS = -g -Wall -Werror -std=c++17 $(DEBUG)
#LDFLAGS = -lm
EXE = lab4_2
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
	zip lab4pt2 *cpp *h makefile

.PHONY: test1
test1:
	./$(EXE) input1.txt > rout1.txt 2>&1
	diff output1.txt rout1.txt

.PHONY: test2
test2:
	./$(EXE) input2.txt > rout2.txt 2>&1
	diff output2.txt rout2.txt

.PHONY: test3
test3:
	./$(EXE) input3.txt > rout3.txt 2>&1
	diff output3.txt rout3.txt

.PHONY: test4
test4:
	./$(EXE) input4.txt > rout4.txt 2>&1
	diff output4.txt rout4.txt

.PHONY: test5
test5:
	./$(EXE) input5.txt > rout5.txt 2>&1



