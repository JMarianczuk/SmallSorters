RScript RLineplot.R --dbName="small_sorters_result.sqlite" --tableName="normalSortWithout%1" --filePostfix="normalIns" --filter="t like '%%IS%%'"
RScript RLineplot.R --dbName="small_sorters_result.sqlite" --tableName="normalSortWithout%1" --filePostfix="normalBest" --filter="t like '%%Best%%'"
RScript RLineplot.R --dbName="small_sorters_result.sqlite" --tableName="normalSortWithout%1" --filePostfix="normalBN_L" --filter="t like '%%BN-L%%'"
RScript RLineplot.R --dbName="small_sorters_result.sqlite" --tableName="normalSortWithout%1" --filePostfix="normalBN_P" --filter="t like '%%BN-P%%'"
RScript RLineplot.R --dbName="small_sorters_result.sqlite" --tableName="normalSortWithout%1" --filePostfix="normalBN_R" --filter="t like '%%BN-R%%'"