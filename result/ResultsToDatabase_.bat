sqlplot import-data -D sqlite:small_sorters_result.sqlite stats%2 data/%1
sqlite3 small_sorters_result.sqlite < createTypeColumn.sql
sqlite3 small_sorters_result.sqlite < copyToSpecialTables.sql
sqlite3 small_sorters_result.sqlite < temptransform.sql
call MakeDeviationTables.bat
