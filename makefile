project: bankms.o
	cc bankms.o -o project
bankms.o: bankms.c bankms.h
	cc -Wall -c bankms.c
