sqlplot import-data -D sqlite:db_test.sqlite stats data/output_2019-04-10_17-22-53.txt
sqlite3 db_test.sqlite < create_index.sql