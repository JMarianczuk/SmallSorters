# library(DBI)
# con <- dbConnect(RSQLite:SQLite(), "db.sqlite")


library(RSQLite)
library(optparse)
library(ggplot2)

option_list = list(
    make_option(c("-s", "--array_size"), type="numeric", default=16, help="size of array to plot")
)
opt_parser = OptionParser(option_list = option_list)
options = parse_args(opt_parser)

con <- dbConnect(SQLite(), "small_sorters_result.sqlite")

query <- paste("select (v / n) as cycles, s as sorter from stats where a =", options$array_size, "and c = 0 and s not like '%InRow%'")
res <- dbGetQuery(con, query)

array_size_string <- paste(options$array_size)
if (options$array_size < 10) {
    array_size_string <- paste("0", array_size_string, sep="", collapse="")
}
filename <- paste("boxplot-array_size", array_size_string, ".png", sep = "", collapse = "")
# png(file = filename, width=550, height=750)

par(mar=c(22,5,2,1))
ggplot(res, aes(x=sorter, y=cycles)) +
    geom_boxplot() +
    coord_flip()

ggsave(filename, width=6, height=4)
