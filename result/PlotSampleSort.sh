Rscript RPlot.R --tableName="sampleSortWithout" --dbName="$1" --filter="s like '%Best%' and s like '%-S%'" --filePostfix="sample-sort-best" --complete=TRUE --title="SampleSort"
Rscript RPlot.R --tableName="sampleSortWithout" --dbName="$1" --filter="s like '%BNLo%' and s like '%-S%'" --filePostfix="sample-sort-bosenelson-locality" --complete=TRUE --title="SampleSort"
Rscript RPlot.R --tableName="sampleSortWithout" --dbName="$1" --filter="s like '%BNPL%' and s like '%-S%'" --filePostfix="sample-sort-bosenelson-parl" --complete=TRUE --title="SampleSort"
Rscript RPlot.R --tableName="sampleSortWithout" --dbName="$1" --filter="s like '%BNPM%' and s like '%-S%'" --filePostfix="sample-sort-bosenelson-param" --complete=TRUE --title="SampleSort"
Rscript RPlot.R --tableName="sampleSortWithout" --dbName="$1" --filter="s like '%I%' and s like '%-S%'" --filePostfix="sample-sort-insertionsort" --complete=TRUE --title="SampleSort"

Rscript RPlot.R --tableName="sampleSortWithout" --dbName="$1" --filter="s like '%-s332%'" --filePostfix="sample-sort-332" --complete=TRUE --title="SampleSort"

for a in {1..5}
do
    Rscript RPlot.R --tableName="sampleSortWithout" --dbName="$1" --filter="s like '%-S3$a%'" --filePostfix="sample-sort-3$a" --complete=TRUE --title="SampleSort"
done

for a in {1..5}
do
    Rscript RPlot.R --tableName="sampleSortWithout" --dbName="$1" --filter="s like '%-S3_$a%'" --filePostfix="sample-sort-3_$a" --complete=TRUE --title="SampleSort"
done