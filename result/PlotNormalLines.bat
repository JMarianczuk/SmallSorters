RScript RPlotContinuous.R --dbName="small_sorters_result.sqlite" --tableName="normalSortWithout" --filePostfix="normalIns" --filter="t like '%%I%%'"
RScript RPlotContinuous.R --dbName="small_sorters_result.sqlite" --tableName="normalSortWithout" --filePostfix="normalBest" --filter="t like '%%Best%%'"
RScript RPlotContinuous.R --dbName="small_sorters_result.sqlite" --tableName="normalSortWithout" --filePostfix="normalBoNeL" --filter="t like '%%BoNeL%%'"
RScript RPlotContinuous.R --dbName="small_sorters_result.sqlite" --tableName="normalSortWithout" --filePostfix="normalBoNeP" --filter="t like '%%BoNeP%%'"