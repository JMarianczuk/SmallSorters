
library(RSQLite)
library(optparse)
library(ggplot2)

option_list = list(
    make_option(c("--dbName"), type="character", default="small_sorters_result.sqlite", help="name of the database to get the data from"),
    make_option(c("--tableName"), type="character", default="normalSortWithout", help="name of table to get data from"),
    make_option(c("--filter"), type="character", default=""),
    make_option(c("--filePostfix"), type="character")
)
opt_parser = OptionParser(option_list = option_list)
options = parse_args(opt_parser)

con <- dbConnect(SQLite(), options$dbName)
someRes <- dbExecute(con, "PRAGMA case_sensitive_like=ON;")

query <- paste("select avg(v / n) as normalized_value, s as sorter, t as sortergroup, a as arraySize from", options$tableName, "where s not like '%JXc%' and s not like '%6Cm%'")
if (options$filter != "") {
    query <- paste(query, "and", options$filter)
}
query <- paste(query, "group by s, a")
res <- dbGetQuery(con, query)

filename <- paste("plots/lineplot-", options$filePostfix, sep="", collapse="")
filenameExt <- paste(filename, ".pdf", sep="", collapse="")

thisplot <- ggplot(res, aes(x = arraySize, y = normalized_value, group=sorter, color=sorter)) + 
    geom_line()

ggsave(filenameExt, thisplot, width=18, height=11, units="cm")
