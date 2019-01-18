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
set xlabel 'Number of elements'
set ylabel 'Cpu cycles needed per element'

## MULTIPLOT(sorter) SELECT Real.array_size AS x, Avg((Real.value - Compensation.value) / Real.number_of_iterations) / Real.array_size AS y, Real.MULTIPLOT
## FROM stats Real, stats Compensation WHERE Real.sorter = Compensation.sorter AND Real.array_size = Compensation.array_size AND Real.metric = Compensation.metric AND Real.computer_name = Compensation.computer_name AND Real.struct_size = Compensation.struct_size and Real.number_of_iterations = Compensation.number_of_iterations And Real.compensation_measurement = 0 AND Compensation.compensation_measurement = 1
## AND Real.metric LIKE "Cpu Cycles" AND Real.commit_id LIKE "2bcf6e1" GROUP BY Real.MULTIPLOT,x ORDER BY Real.MULTIPLOT,x
plot \
    'small_sorters-data.txt' index 0 title "sorter=Insertion Sort Key-Reference-PointerOptimized" with linespoints, \
    'small_sorters-data.txt' index 1 title "sorter=Insertion Sort Key-Reference-StlVersion" with linespoints, \
    'small_sorters-data.txt' index 2 title "sorter=Insertion Sort Key-Reference-Tuple" with linespoints, \
    'small_sorters-data.txt' index 3 title "sorter=Network Sort Key-Reference-ClangVersion" with linespoints, \
    'small_sorters-data.txt' index 4 title "sorter=Network Sort Key-Reference-FourCmovTemp" with linespoints, \
    'small_sorters-data.txt' index 5 title "sorter=Network Sort Key-Reference-FourCmovTemp-Split" with linespoints, \
    'small_sorters-data.txt' index 6 title "sorter=Network Sort Key-Reference-JumpXchg" with linespoints, \
    'small_sorters-data.txt' index 7 title "sorter=Network Sort Key-Reference-SixCmovRegisterTemp" with linespoints, \
    'small_sorters-data.txt' index 8 title "sorter=Network Sort Key-Reference-Tuple" with linespoints

