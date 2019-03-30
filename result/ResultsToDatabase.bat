sqlplot import-data -D sqlite:small_sorters_result.sqlite stats data/output_2019-03-29_15-47-10.txt
sqlite3 small_sorters_result.sqlite < create_index.sql