all:	lista_seq_din.o	miniGoogle.o	main.o
	gcc	-g	lista_seq_din.o	miniGoogle.o	main.o	-o	miniGoogle	-Wall	-lm

lista_seq_din.o:
	gcc	-g	-c	lista_seq_din.c

miniGoogle.o:
	gcc	-g	-c	miniGoogle.c

main.o:
	gcc	-g	-c	main.c

clean:
	rm	*.o	miniGoogle	lista_seq_din

run:
	./miniGoogle
