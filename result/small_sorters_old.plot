# IMPORT-DATA stats *.txt

set terminal pdf size 28cm,18cm linewidth 2.0
set output "small_sorters_old_eval.pdf"

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
## FROM stats WHERE metric LIKE "Cpu Cycles" AND commit_id LIKE "41a9f99" GROUP BY MULTIPLOT,x ORDER BY MULTIPLOT,x
plot \
    'small_sorters_old-data.txt' index 0 title "sorter=Insertion Sort Key-Reference-Tuple" with linespoints, \
    'small_sorters_old-data.txt' index 1 title "sorter=Network Key-Reference-ClangVersion" with linespoints, \
    'small_sorters_old-data.txt' index 2 title "sorter=Network Key-Reference-FourCmovTemp" with linespoints, \
    'small_sorters_old-data.txt' index 3 title "sorter=Network Key-Reference-JumpXchg" with linespoints, \
    'small_sorters_old-data.txt' index 4 title "sorter=Network Key-Reference-SixCmovRegisterTemp" with linespoints, \
    'small_sorters_old-data.txt' index 5 title "sorter=Network Key-Reference-SixCmovVolatileTempl" with linespoints, \
    'small_sorters_old-data.txt' index 6 title "sorter=Network Key-Reference-Tuple" with linespoints

