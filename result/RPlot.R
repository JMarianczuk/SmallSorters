# library(DBI)
# con <- dbConnect(RSQLite:SQLite(), "db.sqlite")


library(RSQLite)
con <- dbConnect(SQLite(), "db.sqlite")

res <- dbGetQuery(con, "select * from stats where array_size = 16 and compensation_measurement = 0")

png(file = "boxplot.png", width=550, height=800)

par(mar=c(27,5,2,1))
boxplot(value ~ sorter, data = res, xlab = "Sorter", ylab = "Cycles", main = "Sorter speed", las=2)

dev.off()