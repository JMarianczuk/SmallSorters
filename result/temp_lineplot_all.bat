call temp_lineplot.bat small_sorters_result.sqlite 129_2 129 A
call temp_lineplot.bat small_sorters_result.sqlite 130_2 130 B
call temp_lineplot.bat small_sorters_result.sqlite 133_2 133 C
call temp_lineplot.bat small_sorters_result.sqlite 144_2 144 D "--unit=nanoseconds"

Rscript FourLineplot.R --dbName="small_sorters_result.sqlite" --tableName="normalSortDeviation129_2" --filePostfix="normal-legend" --filter="((s like '%%POp%%' or s like '%%4Cm%%' or s like '%%4CS%%' or s like '%%Def%%' or s like '%%CPr%%') and s not like '%%BN-P%%' and s not like '%%BNPL%%')" --legend=TRUE
Rscript FourLineplot.R --dbName="small_sorters_result.sqlite" --tableName="inrowSortDeviation129" --filePostfix="inrow-legend" --filter="((s like '%%POp%%' or s like '%%4Cm%%' or s like '%%4CS%%' or s like '%%Def%%' or s like '%%CPr%%') and s not like '%%BN-P%%' and s not like '%%BNPL%%')" --legend=TRUE