sqlplot import-data -D sqlite:small_sorters_result.sqlite stats output_2019-03-05_21-30-24.txt
sqlite3 small_sorters_result.sqlite < create_index.sql