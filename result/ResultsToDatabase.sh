sqlplot import-data -D sqlite:small_sorters_result.sqlite stats$2 data/$1
sqlite3 small_sorters_result.sqlite -batch -cmd "ALTER TABLE stats$2 ADD COLUMN t VARCHAR; UPDATE stats$2 SET t = substr(s, 0, 10);" < sqlite.quit
./CopyToSpecialTables.sh $2
#./MakeDeviationTables.sh $2