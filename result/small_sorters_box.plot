# IMPORT-DATA stats smallout.txt

# SQL CREATE INDEX ind ON stats (s, a, m, ss, n);

set terminal pdf size 28cm,18cm linewidth 2.0
set output "small_sorters_box_eval.pdf"

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

## MULTIPLOT(s) SELECT Real.a AS x, AVG((Real.v - Compensation.v) / Real.n) / Real.a AS y, Real.MULTIPLOT
## FROM stats Real, stats Compensation WHERE Real.s = Compensation.s AND Real.a = Compensation.a AND Real.m = Compensation.m AND Real.ss = Compensation.ss and Real.n = Compensation.n And Real.c = 0 AND Compensation.c = 1
## AND Real.m LIKE "Cpu Cycles" GROUP BY Real.MULTIPLOT,x ORDER BY Real.MULTIPLOT,x
plot \
    'small_sorters_box-data.txt' index 0 title "s=Insertion Sort Key-Reference-PointerOptimized" with linespoints, \
    'small_sorters_box-data.txt' index 1 title "s=Insertion Sort Key-Reference-StlVersion" with linespoints, \
    'small_sorters_box-data.txt' index 2 title "s=Insertion Sort Key-Reference-Tuple" with linespoints, \
    'small_sorters_box-data.txt' index 3 title "s=Network Best Sort Key-Reference-ClangVersion" with linespoints, \
    'small_sorters_box-data.txt' index 4 title "s=Network Best Sort Key-Reference-FourCmovTemp" with linespoints, \
    'small_sorters_box-data.txt' index 5 title "s=Network Best Sort Key-Reference-FourCmovTemp-Split" with linespoints, \
    'small_sorters_box-data.txt' index 6 title "s=Network Best Sort Key-Reference-JumpXchg" with linespoints, \
    'small_sorters_box-data.txt' index 7 title "s=Network Best Sort Key-Reference-SixCmovRegisterTemp" with linespoints, \
    'small_sorters_box-data.txt' index 8 title "s=Network Best Sort Key-Reference-Tuple" with linespoints, \
    'small_sorters_box-data.txt' index 9 title "s=Network BoseNelson Sort Key-Reference-ClangVersion" with linespoints, \
    'small_sorters_box-data.txt' index 10 title "s=Network BoseNelson Sort Key-Reference-FourCmovTemp" with linespoints, \
    'small_sorters_box-data.txt' index 11 title "s=Network BoseNelson Sort Key-Reference-FourCmovTemp-Split" with linespoints, \
    'small_sorters_box-data.txt' index 12 title "s=Network BoseNelson Sort Key-Reference-JumpXchg" with linespoints, \
    'small_sorters_box-data.txt' index 13 title "s=Network BoseNelson Sort Key-Reference-SixCmovRegisterTemp" with linespoints, \
    'small_sorters_box-data.txt' index 14 title "s=Network BoseNelson Sort Key-Reference-Tuple" with linespoints

