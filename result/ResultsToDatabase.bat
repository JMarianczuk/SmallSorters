sqlplot import-data -D sqlite:small_sorters_result_04_04.sqlite stats data/output_2019-04-09_12-53-11.txt
sqlite3 small_sorters_result_04_04.sqlite < create_index.sql