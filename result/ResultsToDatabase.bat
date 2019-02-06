sqlplot import-data -D sqlite:db_test.sqlite stats output_2019-02-06_21-04-33.txt
sqlite3 db_test.sqlite < create_index.sql