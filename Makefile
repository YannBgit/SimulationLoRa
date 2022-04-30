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

### compile ###
compile: dir
	$(CC) $(CFLAGS) $(SRC) -o $(TRG) $(MATH)

### run ###
run: compile
	./$(TRG)

### Création du répertoire target ###
dir:
	mkdir -p $(TRG_DIR)

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
	tar -czvf BARBIER_CONOR_SOURSOU.tar.gz SimulationLoRa
