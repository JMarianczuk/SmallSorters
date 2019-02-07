sqlplot import-data -D sqlite:db_test.sqlite stats output_2019-02-07_15-13-10.txt
sqlite3 db_test.sqlite < create_index.sql