REM call temp_lineplot.bat small_sorters_result.sqlite 129 A
REM call temp_lineplot.bat small_sorters_result.sqlite 130 B
REM call temp_lineplot.bat small_sorters_result.sqlite 133 C
REM call temp_lineplot.bat small_sorters_result.sqlite 144 D "--unit=nanoseconds"

Rscript FourLineplot.R --dbName="small_sorters_result.sqlite" --tableName="normalSortDeviation129" --filePostfix="normal-legend" --filter="((s like '%%POp%%' or s like '%%4Cm%%' or s like '%%4CS%%' or s like '%%Def%%' or s like '%%CPr%%') and s not like '%%BN-P%%' and s not like '%%BNPL%%')" --legend=TRUE
Rscript FourLineplot.R --dbName="small_sorters_result.sqlite" --tableName="inrowSortDeviation129" --filePostfix="inrow-legend" --filter="((s like '%%POp%%' or s like '%%4Cm%%' or s like '%%4CS%%' or s like '%%Def%%' or s like '%%CPr%%') and s not like '%%BN-P%%' and s not like '%%BNPL%%')" --legend=TRUE