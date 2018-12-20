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
set xlabel 'Number Of Items'
set ylabel 'Cpu Cycles Needed'

## MULTIPLOT(sorter) SELECT array_size AS x, AVG(value / number_of_iterations) AS y, MULTIPLOT
## FROM stats WHERE metric LIKE "Cpu Cycles" AND commit_id LIKE "b84d2a5" GROUP BY MULTIPLOT,x ORDER BY MULTIPLOT,x
plot \
    'small_sorters-data.txt' index 0 title "sorter=Insertion Sort Key-Only" with linespoints, \
    'small_sorters-data.txt' index 1 title "sorter=Insertion Sort Key-Reference-Tuple" with linespoints, \
    'small_sorters-data.txt' index 2 title "sorter=Network Key-JumpXchg" with linespoints, \
    'small_sorters-data.txt' index 3 title "sorter=Network Key-Reference-ClangVersion" with linespoints, \
    'small_sorters-data.txt' index 4 title "sorter=Network Key-Reference-FourCmovTemp" with linespoints, \
    'small_sorters-data.txt' index 5 title "sorter=Network Key-Reference-JumpXchg" with linespoints, \
    'small_sorters-data.txt' index 6 title "sorter=Network Key-Reference-SixCmovRegisterTemp" with linespoints, \
    'small_sorters-data.txt' index 7 title "sorter=Network Key-Reference-SixCmovVolatileTempl" with linespoints, \
    'small_sorters-data.txt' index 8 title "sorter=Network Key-Reference-Tuple" with linespoints, \
    'small_sorters-data.txt' index 9 title "sorter=Network Key-ThreeCmovRegisterTemp" with linespoints, \
    'small_sorters-data.txt' index 10 title "sorter=Network Key-ThreeCmovVolatileTempl" with linespoints, \
    'small_sorters-data.txt' index 11 title "sorter=Network Key-TwoCmovTemp" with linespoints

