main:main.o tabMat.o
	gcc  main.o tabMat.o -o prog
main.o:main.c
	gcc -c -Wall -Werror -pedantic main.c -o main.o
tabMat.o:tabMat.c
	gcc -c -Wall -Werror -pedantic tabMat.c -o tabMat.o