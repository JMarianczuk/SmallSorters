sqlite3 small_sorters_result.sqlite -batch -cmd "ALTER TABLE sampleSortWithout%1 ADD COLUMN sorting REAL;" < sqlite.quit
sqlite3 small_sorters_result.sqlite -batch -cmd "UPDATE sampleSortWithout%1 AS wo SET sorting = (SELECT average FROM sampleSortDeviation%2 dev WHERE wo.s = dev.s);" < sqlite.quit