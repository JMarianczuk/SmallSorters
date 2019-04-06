sqlplot import-data -D sqlite:small_sorters_result.sqlite stats data/output_2019-04-06_15-40-23.txt
sqlite3 small_sorters_result.sqlite < create_index.sql