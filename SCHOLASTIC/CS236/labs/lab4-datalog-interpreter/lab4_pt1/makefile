CPP = g++
DEBUG = -ggdb
CPPFLAGS = -g -Wall -Werror -std=c++17 $(DEBUG)
#LDFLAGS = -lm
EXE = lab4_1
OBJS = main.o TestCase.o Relation.o Row.o Header.o Database.o

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
	zip lab4pt1 *cpp *h makefile



