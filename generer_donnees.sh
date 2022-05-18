#!/bin/bash

make
rm -rf *.data

file=lora1.data
./simulation_release --all 5 >> $file
echo 'lora1 terminé !'

file=lora2.data
echo "Génération des données de $file"
for ((i = 1; i <= 50; ++i)); do
	./simulation_release --all 5 >> $file
done
echo 'lora 2 terminé !'

file=lora3.data
echo "Génération des données de $file"
for ((k = 1; k <= 100; ++k)); do
	./simulation_release $k >> $file
	echo -ne "\r$k %"
done
echo -e '\rlora3 terminé !'

echo 'Génération du PDF'
R CMD BATCH study.R
