#!/bin/bash
echo -n 'ee24b035   '
ping www.iitm.ac.in -c 5000 > pingout.txt
awk '{print $7}' pingout.txt | sed 's/time=//' > ping1.txt
awk '{sum += $1; sum1 += $1*$1; stddev = sqrt((sum1/NR)-((sum/NR)*(sum/NR)))} END {print NR, sum/NR, stddev}' ping1.txt
rm -f pingout.txt
rm -f ping1.txt

