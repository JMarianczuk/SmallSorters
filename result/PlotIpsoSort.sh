Rscript RPlot.R --dbName="$1" --tableName="ipsoSortWithout$2" --filePostfix="ipso-$2" --filter="s not like '%StdSort%'" --complete=TRUE --title="IPSSSSo" --percentBy=2 --secondAxis="L1 instr. cache misses"
#--percentAxis="I       -4 16_000 KR Def"
