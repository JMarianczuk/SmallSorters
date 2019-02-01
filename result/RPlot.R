# library(DBI)
# con <- dbConnect(RSQLite:SQLite(), "db.sqlite")


library(RSQLite)
library(optparse)

option_list = list(
    make_option(c("-s", "--array_size"), type="numeric", default=16, help="size of array to plot")
)
opt_parser = OptionParser(option_list = option_list)
options = parse_args(opt_parser)

con <- dbConnect(SQLite(), "db.sqlite")

query <- paste("select (value / number_of_iterations) as normalized_value, sorter from stats where array_size =", options$array_size, "and compensation_measurement = 0")
res <- dbGetQuery(con, query)

array_size_string <- paste(options$array_size)
if (options$array_size < 10) {
    array_size_string <- pase("0", array_size_string, sep="", collapse="")
}
filename <- paste("boxplot-array_size", array_size_string, ".png", sep = "", collapse = "")
png(file = filename, width=550, height=800)

par(mar=c(27,5,2,1))
boxplot(normalized_value ~ sorter, data = res, xlab = "Sorter", ylab = "Cycles", main = "Sorter speed", las=2)
