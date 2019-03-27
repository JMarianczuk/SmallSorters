sqlplot import-data -D sqlite:small_sorters_result.sqlite stats data/output_2019-03-26_16-01-26.txt
sqlite3 small_sorters_result.sqlite < create_index.sql