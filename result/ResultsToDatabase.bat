sqlplot import-data -D sqlite:small_sorters_result.sqlite stats data/%1
sqlite3 small_sorters_result.sqlite < create_index.sql
sqlite3 small_sorters_result.sqlite < copyToSpecialTables.sql