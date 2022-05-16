#!/bin/bash

file=lora.data
rm -rf $file
make

for ((c = 1; c <= 100; ++c)); do
	echo -ne "\rSimulation pour K = $c"
	./simulation_release $c >> $file
done

echo

R CMD BATCH study.R