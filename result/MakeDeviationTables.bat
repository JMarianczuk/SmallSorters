cltb statisticalFunctions  --database=small_sorters_result.sqlite --table=normalSortWithout%1 --out=normalSortDeviation%1 --value="cycles/n" --groups s a --functions average median variance
cltb statisticalFunctions  --database=small_sorters_result.sqlite --table=inrowSort%1 --out=inrowSortDeviation%1 --value="cycles/n" --groups s a --functions average median variance
cltb statisticalFunctions  --database=small_sorters_result.sqlite --table=sampleSortWithout%1 --out=sampleSortDeviation%1 --value="cycles/n" --groups s a --functions average median variance
cltb statisticalFunctions  --database=small_sorters_result.sqlite --table=completeSortWithout%1 --out=completeSortDeviation%1 --value="cycles/n" --groups s a --functions average median variance
cltb statisticalFunctions  --database=small_sorters_result.sqlite --table=ipsoSortWithout%1 --out=ipsoSortDeviation%1 --value="cycles/n" --groups s a --functions average median variance