for a in {2..16} 
do
	Rscript RPlot.R --dbName="$1" --array_size=$a --tableName="inrowSort" --filePostfix="in_row"
done
