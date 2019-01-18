library(DBI)
con <- dbConnect(RSQLite:SQLite(), "db.sqlite")

res <- dbSendQuery(con, "SELECT * FROM ex1")
dbFetch(res)

boxplot(res)

dbClearResult(res)

dbDisconnect(con)
