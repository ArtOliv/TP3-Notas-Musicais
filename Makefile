PC = gcc
CFLAGS = -Wall
EXEC = tp3
OBJ = main.o in_out.o tons.o forca_bruta.o KMP.o BMH.o shift_and.o
INTERFACE = Interface/forca_bruta.h Interface/KMP.h Interface/BMH.h Interface/shift_and.h Interface/in_out.h Interface/tons.h
CAMINHO = ./Entrada_saida/Arquivos/

all: $(EXEC)

$(EXEC): $(OBJ)
	$(PC) $(OBJ) $(CFLAGS) -o $(EXEC)

main.o: Main/main.c $(INTERFACE)
	$(PC) $(CFLAGS) -c Main/main.c

in_out.o: Entrada_saida/in_out.c $(INTERFACE)
	$(PC) $(CFLAGS) -c Entrada_saida/in_out.c

tons.o: Entrada_saida/tons.c $(INTERFACE)
	$(PC) $(CFLAGS) -c Entrada_saida/tons.c

forca_bruta.o: Forca_bruta/forca_bruta.c $(INTERFACE)
	$(PC) $(CFLAGS) -c Forca_bruta/forca_bruta.c

KMP.o: KMP/KMP.c $(INTERFACE)
	$(PC) $(CFLAGS) -c KMP/KMP.c

BMH.o: Boyer_Moore/BMH.c $(INTERFACE)
	$(PC) $(CFLAGS) -c Boyer_Moore/BMH.c

shift_and.o: ShiftAndExato/shift_and.c $(INTERFACE)
	$(PC) $(CFLAGS) -c ShiftAndExato/shift_and.c

clean:
	rm -f *.o
	rm -f $(EXEC)

run1: $(EXEC)
	./$(EXEC) $(CAMINHO)entrada.txt 1

run2: $(EXEC)
	./$(EXEC) $(CAMINHO)entrada.txt 2

run3: $(EXEC)
	./$(EXEC) $(CAMINHO)entrada.txt 3

run4: $(EXEC)
	./$(EXEC) $(CAMINHO)entrada.txt 4