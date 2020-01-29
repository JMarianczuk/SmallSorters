Rscript RPlot.R --dbName="%1" --tableName="ipsoSortWithout%2" --filePostfix="ipso-%2-cm" --filter="s not like '%%StdSort%%'" --complete=TRUE --title="IPSSSSo" --secondAxis="L1 instruction cache misses in thousands" --secondAxisAdaptationScale=6.9 --secondAxisAdaptationLinear=24606198 --axisFactor=1000
REM 129: * 1.25, + 30606198
REM 130: * 4, + 27056198
REM 133: * 6.9, + 24606198