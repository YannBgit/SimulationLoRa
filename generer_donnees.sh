#!/bin/bash

# Compilation du programme
make

printf "Démarrage des simulations\n"

for ((c = 0; c < 50; c++)); do
	echo c
	./main
done