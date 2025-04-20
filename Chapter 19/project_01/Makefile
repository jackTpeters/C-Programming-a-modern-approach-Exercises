
paren: paren.o stackADT.o
	gcc -o paren paren.o stackADT.o

paren.o: paren.c stackADT.h
	gcc -c paren.c

stackADT.o: stackADT.c stackADT.h
	gcc -c stackADT.c

