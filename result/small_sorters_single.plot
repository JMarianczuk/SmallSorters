# IMPORT-DATA stats output_2019-01-23_13-04-23.txt

## CREATE INDEX ind ON stats (sorter, array_size, metric, struct_size, number_of_iterations, compensation_measurement);

set terminal pdf size 28cm,18cm linewidth 2.0
set output "small_sorters_eval_single.pdf"

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
set xlabel 'Number of elements'
set ylabel 'Cpu cycles needed per element'

## MULTIPLOT(sorter) SELECT array_size AS x, Avg(value / number_of_iterations) / array_size AS y, MULTIPLOT
## FROM stats WHERE sorter LIKE "%ClangVersion" AND compensation_measurement = 1 AND
## metric LIKE "Cpu Cycles" GROUP BY MULTIPLOT,x ORDER BY MULTIPLOT,x
plot \
    'small_sorters_single-data.txt' index 0 title "sorter=Network Best Sort Key-Reference-ClangVersion" with linespoints, \
    'small_sorters_single-data.txt' index 1 title "sorter=Network BoseNelson Sort Key-Reference-ClangVersion" with linespoints

