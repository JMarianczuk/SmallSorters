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

query <- paste("select (v / n) as normalized_value, s as sorter from stats where a =", options$array_size, "and c = 0 and s not like '%InRow%'")
res <- dbGetQuery(con, query)

array_size_string <- paste(options$array_size)
if (options$array_size < 10) {
    array_size_string <- paste("0", array_size_string, sep="", collapse="")
}
filename <- paste("boxplot-array_size", array_size_string, ".pdf", sep = "", collapse = "")

thisplot <- ggplot(res, aes(x = sorter, y = normalized_value)) +
    labs(x = "Sorting algorithm", y = "Cpu cycles needed", title = paste("ArraySize = ", options$array_size, sep = "", collapse = "")) +
    geom_boxplot() +
    coord_flip()

ggsave(filename, thisplot, width=18, height=10, units="cm")
