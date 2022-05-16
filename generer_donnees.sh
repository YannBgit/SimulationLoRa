#!/bin/bash

file=lora.data
rm -rf $file
for ((c = 1; c <= 100; ++c)); do
	echo -ne "\rSimulation pour K = $c"
	./simulation_release $c >> $file
done
echo
