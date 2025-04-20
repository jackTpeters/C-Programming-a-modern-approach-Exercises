rpn: rpn.o stackADT.o
	gcc -o rpn rpn.o stackADT.o

rpn.o: rpn.c stackADT.h
	gcc -c rpn.c

stackADT.o: stackADT.c stackADT.h
	gcc -c stackADT.c

