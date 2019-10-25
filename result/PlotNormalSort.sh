for a in {2..16}
do
    Rscript RPlot.R --dbName="$1" --array_size=$a --tableName="normalSortWithout$2" --filePostfix="normal-$2" 
done