CommandLineToolBox statisticalTable --database=small_sorters_result.sqlite --outputFormat=latex --main=s --mainGroup=t --mainGroupSep="\smallskip \\\\" --secondaries=a --secondaryAliases="Array Size" --value="v/n" --mainFont="\verb+{0}+" --metric=average --table normalSortWithout%1 normalSortWithout%2 normalSortWithout%3 --out=normalSortAvgTable%4.tex --printAbsoluteValues
CommandLineToolBox statisticalTable --database=small_sorters_result.sqlite --outputFormat=latex --main=s --mainGroup=t --mainGroupSep="\smallskip \\\\" --secondaries=a --secondaryAliases="Array Size" --value="v/n" --mainFont="\verb+{0}+" --metric=average --table inrowSort%1 inrowSort%2 inrowSort%3 --out=inrowSortAvgTable%4.tex --printAbsoluteValues