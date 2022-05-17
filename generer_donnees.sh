#!/bin/bash

make
rm -rf *.data

file=lora1.data
echo "Génération des données de $file"
for ((i = 1; i <= 10; ++i)); do
	./simulation_release --all 5 >> $file
done
echo 'Terminé !'
R CMD BATCH study.R
exit

file=lora2.data
echo "Génération des données de $file"
for ((k = 1; k <= 100; ++k)); do
	for ((i = 1; i <= 20; ++i)); do
		./simulation_release $k >> $file
	done
	echo -ne "\r$k %"
done
echo -e '\rTerminé !'

echo 'Génération du PDF'
R CMD BATCH study.R
