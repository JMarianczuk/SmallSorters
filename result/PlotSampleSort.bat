Rscript RPlot.R --tableName="sampleSortWithout%2" --dbName="%1" --filter="s like '%%Best%%' and stype like '%%-S%%'" --filePostfix="sample-sort-best-%2" --complete=TRUE --title="SampleSort" %3
Rscript RPlot.R --tableName="sampleSortWithout%2" --dbName="%1" --filter="s like '%%BN-L%%' and stype like '%%-S%%'" --filePostfix="sample-sort-bosenelson-locality-%2" --complete=TRUE --title="SampleSort" %3
Rscript RPlot.R --tableName="sampleSortWithout%2" --dbName="%1" --filter="s like '%%BN-P%%' and stype like '%%-S%%'" --filePostfix="sample-sort-bosenelson-parl-%2" --complete=TRUE --title="SampleSort" %3
Rscript RPlot.R --tableName="sampleSortWithout%2" --dbName="%1" --filter="s like '%%BN-R%%' and stype like '%%-S%%'" --filePostfix="sample-sort-bosenelson-rec-%2" --complete=TRUE --title="SampleSort" %3
Rscript RPlot.R --tableName="sampleSortWithout%2" --dbName="%1" --filter="s like '%%IS%%' and stype like '%%-S%%'" --filePostfix="sample-sort-insertionsort-%2" --complete=TRUE --title="SampleSort" %3

Rscript RPlot.R --tableName="sampleSortWithout%2" --dbName="%1" --filter="s like '%%332%%' and stype like '%%-s%%' and s not like '%%Tie%%'" --filePostfix="sample-sort-332-%2" --complete=TRUE --title="SampleSort" --percentAxis="IS      332 Def " %3

for /l %%a in (1, 1, 5) do (
    Rscript RPlot.R --tableName="sampleSortWithout%2" --dbName="%1" --filter="s like '%%3%%a%%' and stype like '%%-S%%'" --filePostfix="sample-sort-3%%a-%2" --complete=TRUE --title="SampleSort" %3
)

for /l %%a in (1, 1, 5) do (
    Rscript RPlot.R --tableName="sampleSortWithout%2" --dbName="%1" --filter="s like '%%3_%%a%%' and stype like '%%-S%%'" --filePostfix="sample-sort-3_%%a-%2" --complete=TRUE --title="SampleSort" %3
)
