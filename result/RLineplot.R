
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

query <- paste("select average / a as avg, median / a as med, variance / a as var, s as sorter, a as arraySize from", options$tableName, "where s not like '%JXc%' and s not like '%6Cm%' and s not like '%QMa%'")
if (options$filter != "") {
    query <- paste(query, "and", options$filter)
}
res <- dbGetQuery(con, query)

filename <- paste("plots/lineplot-", options$filePostfix, sep="", collapse="")
filenameExt <- paste(filename, ".pdf", sep="", collapse="")

thisplot <- ggplot(res, aes(x = reorder(arraySize, as.integer(arraySize)), y = med, group=sorter, color=substr(sorter, 14, 17), shape=substr(sorter, 0, 8))) + 
    labs(x = "Array Size", y = "Cpu Cycles per element") +
    geom_line() +
    geom_point() +
    #geom_errorbar(aes(ymin = med - sqrt(var), ymax = med + sqrt(var))) +
    theme(legend.position=c(0,1), legend.justification=c(0, 1), legend.title=element_blank(), legend.text = element_text(colour="black", size=7, family="Courier"), legend.key.size = unit(4, "mm"))

ggsave(filenameExt, thisplot, width=18, height=11, units="cm")
