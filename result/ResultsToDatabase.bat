sqlplot import-data -D -1 sqlite:small_sorters_result.sqlite stats%2 data/%1
sqlite3 small_sorters_result.sqlite -batch -cmd "ALTER TABLE stats%2 ADD COLUMN t VARCHAR; UPDATE stats%2 SET t = substr(s, 0, 10);" < sqlite.quit
call CopyToSpecialTables.bat %2
call MakeDeviationTables.bat %2