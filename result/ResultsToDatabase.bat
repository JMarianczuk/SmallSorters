sqlplot import-data -D sqlite:small_sorters_result.sqlite stats data/output_2019-04-13_15-37-39.txt
sqlite3 small_sorters_result.sqlite < create_index.sql
sqlite3 small_sorters_result.sqlite < copyToSpecialTables.sql