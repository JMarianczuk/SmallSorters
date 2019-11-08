library(RSQLite)
library(optparse)
library(ggplot2)
library(magrittr)
library(ggpubr)

option_list = list(
    make_option(c("--dbName"), type="character", default="small_sorters_result.sqlite", help="name of the database to get the data from"),
    make_option(c("--tableName"), type="character", default="normalSortWithout", help="name of table to get data from"),
    make_option(c("--filter"), type="character", default=""),
    make_option(c("--filePostfix"), type="character"),
    make_option(c("--legend"), type="logical", default=FALSE),
    make_option(c("--machine"), type="character", default="A"),
    make_option(c("--unit"), type="character", default="CPU cycles", help="if cycles or cache misses were measured")
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

y.range = range(res$med)

thisplot <- ggplot(res, aes(x = reorder(arraySize, as.integer(arraySize)), y = med, group=sorter, color=substr(sorter, 9, 13), shape=substr(sorter, 0, 8))) + 
    labs(x = "Array Size", y = paste(options$unit, "per element")) +
    geom_line() +
    geom_point() + 
    annotate("label", x = 2, y = y.range[2] * (9/10), label=options$machine, size=10)

if (options$legend) {
    thisplot <- thisplot + theme(legend.position="top" ,
                                 legend.title=element_blank(),
                                 legend.text = element_text(colour="black", size=8, family="Courier"),
                                 legend.key.size = unit(4, "mm"))
    leg <- get_legend(thisplot)
    ggsave(filenameExt, leg, width=12, height=1, units="cm")
} else {
    thisplot <- thisplot + theme(legend.position="none",
                                 plot.title = element_text(family="Times", size=12),
                                 text = element_text(family="Times", size=10))
    ggsave(filenameExt, thisplot, width=9, height=6, units="cm")
}