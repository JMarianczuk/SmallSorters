sqlplot import-data -D sqlite:small_sorters_result.sqlite stats data/output_2019-04-12_11-38-24.txt
sqlite3 small_sorters_result.sqlite < create_index.sql
sqlite3 small_sorters_result.sqlite < copyToSpecialTables.sql