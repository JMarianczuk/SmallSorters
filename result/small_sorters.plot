# IMPORT-DATA stats *.txt

set terminal pdf size 28cm,18cm linewidth 2.0
set output "small_sorters_eval.pdf"

set pointsize 0.7
set style line 6 lc rgb "#f0b000"
set style line 15 lc rgb "#f0b000"
set style line 24 lc rgb "#f0b000"
set style line 33 lc rgb "#f0b000"
set style line 42 lc rgb "#f0b000"
set style line 51 lc rgb "#f0b000"
set style line 60 lc rgb "#f0b000"
set style increment user

set grid xtics ytics

set key top left

set title 'Sorting of small lists'
set xlabel 'Computer'
set ylabel 'Run Time per 16 elements'

## MULTIPLOT(sorter) SELECT substr(computer_name, 6) AS x, MEDIAN(value / number_of_iterations) AS y, MULTIPLOT
## FROM stats WHERE metric LIKE "Cpu Cycles" GROUP BY MULTIPLOT,x ORDER BY MULTIPLOT,x
plot \
    'small_sorters-data.txt' index 0 title "sorter=Insertion Sort" with linespoints, \
    'small_sorters-data.txt' index 1 title "sorter=Network Sort Naive" with linespoints, \
    'small_sorters-data.txt' index 2 title "sorter=Network Sort Optimised" with linespoints
