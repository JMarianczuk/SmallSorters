CommandLineToolBox statisticalTable --database=%1 --outputFormat=latex --main=s --mainGroup=t --mainGroupSep="\smallskip \\\\" --secondaries=a --secondaryAliases="Array Size" --value="cycles/n" --mainFont="\verb+{0}+" --metric=average --table=normalSortWithout%2 --out=normalSortAvgTable%2.tex --printAbsoluteValues %3
CommandLineToolBox statisticalTable --database=%1 --outputFormat=latex --main=s --mainGroup=t --mainGroupSep="\smallskip \\\\" --secondaries=a --secondaryAliases="Array Size" --value="cycles/n" --mainFont="\verb+{0}+" --metric=average --table=inrowSort%2 --out=inrowSortAvgTable%2.tex --printAbsoluteValues %4