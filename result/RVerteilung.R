
library(RSQLite)
library(optparse)
library(ggplot2)

option_list = list(
    make_option(c("--dbName"), type="character", default="small_sorters_result.sqlite", help="name of the database to get the data from"),
    make_option(c("--tableName"), type="character", default="normalSortWithout", help="name of table to get data from"),
    make_option(c("-p", "--filePostfix"), type="character", default="normal", help="postfix for output file"),
    make_option(c("-t", "--title"), type="character", default="", help="Title for the diagram"),
    make_option(c("--axisBy"), type="numeric", default=16, help="percent steps on the axis")
)
opt_parser = OptionParser(option_list = option_list)
options = parse_args(opt_parser)

con <- dbConnect(SQLite(), options$dbName)

query <- paste("select bs from", options$tableName);
res <- dbGetQuery(con, query)

filename <- paste("plots/verteilung-", options$filePostfix, sep="")
filenameExt <- paste(filename, ".pdf", sep="")

br <- seq(0, 128, by=options$axisBy), seq(160, 1000, by=32))

thisplot <- ggplot(res, aes(x = bs)) + 
    labs(x = "Base Case Size", y = "Frequency") +
    geom_density() + 
    scale_x_continuous(breaks = br, labels=br)

ggsave(filenameExt, thisplot, width=18, height=11, units="cm")