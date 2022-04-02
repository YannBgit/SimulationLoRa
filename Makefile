### Chemins ###
SRC_DIR = src
TRG_DIR = target
TRG = $(TRG_DIR)/main

### Fichiers ###
SRC = $(wildcard $(SRC_DIR)/*.c)

### Compilateur ###
CC = gcc

### Flags ###
CFLAGS = -O3 -Wall -g
MATH = -lm

### run ###
run: dir compile
	./$(TRG)

dir:
	mkdir -p $(TRG_DIR)

compile:
	$(CC) $(CFLAGS) $(SRC) -o $(TRG) $(MATH)

### Suppression du répertoire cible ###
clean:
	rm -rf $(TRG_DIR)
	rm -f *.o
	clear

### Vérification de fuites de mémoire ###
memcheck: compile
	valgrind ./$(EXE)

### Deboguage GDB ###
gdb: compile
	gdb ${EXE}

### Archivage ###
archive: clean
	cd ../..
	tar -czvf BARBIER_Yann_21800844_AttaqueFauteDES.tar.gz AttaqueFauteDES