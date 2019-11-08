REM Rscript RPlot.R --tableName="sampleSortWithout%2" --dbName="%1" --filter="s like '%%BN-R%%' and s like '%%-S%%'" --filePostfix="sample-sort-bosenelson-rec-%2" --complete=TRUE --title="SampleSort"
sqlite3 small_sorters_result.sqlite -batch -cmd "UPDATE %1%2 SET s = replace(s, ' -%3 ', ' ');" < sqlite.quit