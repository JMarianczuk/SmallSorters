Rscript RPlot.R --tableName="sampleSortWithout$2" --dbName="$1" --filter="s like '%Best%' and s like '%-S%'" --filePostfix="sample-sort-best-$2" --complete=TRUE --title="SampleSort"
Rscript RPlot.R --tableName="sampleSortWithout$2" --dbName="$1" --filter="s like '%BNLo%' and s like '%-S%'" --filePostfix="sample-sort-bosenelson-locality-$2" --complete=TRUE --title="SampleSort"
Rscript RPlot.R --tableName="sampleSortWithout$2" --dbName="$1" --filter="s like '%BNPL%' and s like '%-S%'" --filePostfix="sample-sort-bosenelson-parl-$2" --complete=TRUE --title="SampleSort"
Rscript RPlot.R --tableName="sampleSortWithout$2" --dbName="$1" --filter="s like '%BNPM%' and s like '%-S%'" --filePostfix="sample-sort-bosenelson-param-$2" --complete=TRUE --title="SampleSort"
Rscript RPlot.R --tableName="sampleSortWithout$2" --dbName="$1" --filter="s like '%I%' and s like '%-S%'" --filePostfix="sample-sort-insertionsort-$2" --complete=TRUE --title="SampleSort"

Rscript RPlot.R --tableName="sampleSortWithout$2" --dbName="$1" --filter="s like '%-s332%'" --filePostfix="sample-sort-332-$2" --complete=TRUE --title="SampleSort" --percentAxis="IS      -s332 Def"

for a in {1..5}
do
    Rscript RPlot.R --tableName="sampleSortWithout$2" --dbName="$1" --filter="s like '%-S3$a%'" --filePostfix="sample-sort-3$a-$2" --complete=TRUE --title="SampleSort"
done

for a in {1..5}
do
    Rscript RPlot.R --tableName="sampleSortWithout$2" --dbName="$1" --filter="s like '%-S3_$a%'" --filePostfix="sample-sort-3_$a-$2" --complete=TRUE --title="SampleSort"
done