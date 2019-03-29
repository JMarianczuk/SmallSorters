# library(DBI)
# con <- dbConnect(RSQLite:SQLite(), "db.sqlite")


library(RSQLite)
library(optparse)
library(ggplot2)

option_list = list(
    make_option(c("-s", "--array_size"), type="numeric", default=16, help="size of array to plot"),
    make_option(c("-f", "--filter"), type="character", default="", help="additional optional filter"),
    make_option(c("-p", "--filePostfix"), type="character", default="normal", help="postfix for output file"),
    make_option(c("-c", "--complete"), type="logical", default=FALSE, help="If plot is to be made for complete measurement"),
    make_option(c("-t", "--title"), type="character", default="", help="Title for the diagram")
)
opt_parser = OptionParser(option_list = option_list)
options = parse_args(opt_parser)

con <- dbConnect(SQLite(), "small_sorters_result.sqlite")

query <- ""
if (!options$complete) {
    query <- paste("select (v / n) as normalized_value, s as sorter from stats where a =", options$array_size, "and c = 0");
} else {
    query <- paste("select (v / n) as normalized_value, s as sorter from stats where c = 0");
}

if (options$filter != "") {
    query <- paste(query, "and", options$filter)
}
query <- paste(query, "and s not like '%Xchg%' and s not like '%Six%'")
res <- dbGetQuery(con, query)

array_size_string <- paste(options$array_size)
if (options$array_size < 10) {
    array_size_string <- paste("0", array_size_string, sep="", collapse="")
}
filename <- paste("plots/boxplot-", options$filePostfix, sep="", collapse="")
if (!options$complete) {
    filename <- paste(filename, "-array_size", array_size_string, sep="", collapse="")
}
filename <- paste(filename, ".pdf", sep = "", collapse = "")

if (options$title == "") {
    plot_title <- paste("ArraySize = ", options$array_size, sep = "", collapse = "")
} else {
    plot_title <- options$title
}
thisplot <- ggplot(res, aes(x = sorter, y = normalized_value)) +
    labs(x = "Sorting algorithm", y = "Cpu cycles needed", title = plot_title) +
    geom_boxplot() +
    coord_flip() + 
    theme(axis.text.y = element_text(family="Courier"))

ggsave(filename, thisplot, width=18, height=11, units="cm")
