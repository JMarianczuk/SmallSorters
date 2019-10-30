Rscript RPlot.R --tableName="sampleSortWithout%2" --dbName="%1" --filter="s like '%%Best%%' and s like '%%-S%%'" --filePostfix="sample-sort-best-%2" --complete=TRUE --title="SampleSort"
Rscript RPlot.R --tableName="sampleSortWithout%2" --dbName="%1" --filter="s like '%%BN-L%%' and s like '%%-S%%'" --filePostfix="sample-sort-bosenelson-locality-%2" --complete=TRUE --title="SampleSort"
Rscript RPlot.R --tableName="sampleSortWithout%2" --dbName="%1" --filter="s like '%%BN-P%%' and s like '%%-S%%'" --filePostfix="sample-sort-bosenelson-parl-%2" --complete=TRUE --title="SampleSort"
#Rscript RPlot.R --tableName="sampleSortWithout%2" --dbName="%1" --filter="s like '%%BNPM%%' and s like '%%-S%%'" --filePostfix="sample-sort-bosenelson-param-%2" --complete=TRUE --title="SampleSort"
Rscript RPlot.R --tableName="sampleSortWithout%2" --dbName="%1" --filter="s like '%%IS%%' and s like '%%-S%%'" --filePostfix="sample-sort-insertionsort-%2" --complete=TRUE --title="SampleSort"

Rscript RPlot.R --tableName="sampleSortWithout%2" --dbName="%1" --filter="s like '%%-s332%%'" --filePostfix="sample-sort-332-%2" --complete=TRUE --title="SampleSort" --percentAxis="IS      -s332 STL"

for /l %%a in (1, 1, 5) do (
    Rscript RPlot.R --tableName="sampleSortWithout%2" --dbName="%1" --filter="s like '%%-S3%%a%%'" --filePostfix="sample-sort-3%%a-%2" --complete=TRUE --title="SampleSort"
)

for /l %%a in (1, 1, 5) do (
    Rscript RPlot.R --tableName="sampleSortWithout%2" --dbName="%1" --filter="s like '%%-S3_%%a%%'" --filePostfix="sample-sort-3_%%a-%2" --complete=TRUE --title="SampleSort"
)
