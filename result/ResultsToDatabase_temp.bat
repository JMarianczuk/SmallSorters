sqlplot import-data -D sqlite:db_test.sqlite stats data/output_2019-03-08_19-16-05.txt
sqlite3 db_test.sqlite < create_index.sql