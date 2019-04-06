Rscript RPlot.R --tableName="sampleSort" --filter="s like '%%Best%%'" --filePostfix="sample-sort-best" --complete=TRUE --title="SampleSort"
Rscript RPlot.R --tableName="sampleSort" --filter="s like '%%BoNeP%%'" --filePostfix="sample-sort-bosenelson-parl" --complete=TRUE --title="SampleSort"
Rscript RPlot.R --tableName="sampleSort" --filter="s like '%%BoNeM%%'" --filePostfix="sample-sort-bosenelson-param" --complete=TRUE --title="SampleSort"
Rscript RPlot.R --tableName="sampleSort" --filter="s like '%%I%%'" --filePostfix="sample-sort-insertionsort" --complete=TRUE --title="SampleSort"

for /l %%a in (1, 1, 5) do (
    Rscript RPlot.R --tableName="sampleSort" --filter="s like '%%-S3%%a%%'" --filePostfix="sample-sort-3%%a" --complete=TRUE --title="SampleSort"
)

for /l %%a in (1, 1, 5) do (
    Rscript RPlot.R --tableName="sampleSort" --filter="s like '%%-S3_%%a%%'" --filePostfix="sample-sort-3_%%a" --complete=TRUE --title="SampleSort"
)
