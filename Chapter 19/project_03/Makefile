run: stackclient.o stackADT.o
	gcc -o run stackclient.o stackADT.o

stackclient.o: stackclient.c stackADT.h
	gcc -c stackclient.c

stackADT.o: stackADT.c stackADT.h
	gcc -c stackADT.c

