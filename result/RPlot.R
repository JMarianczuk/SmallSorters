
library(RSQLite)
library(optparse)
library(ggplot2)

option_list = list(
    make_option(c("-s", "--array_size"), type="numeric", default=16, help="size of array to plot"),
    make_option(c("--dbName"), type="character", default="small_sorters_result.sqlite", help="name of the database to get the data from"),
    make_option(c("--tableName"), type="character", default="normalSortWithout", help="name of table to get data from"),
    make_option(c("-f", "--filter"), type="character", default="", help="additional optional filter"),
    make_option(c("-p", "--filePostfix"), type="character", default="normal", help="postfix for output file"),
    make_option(c("-c", "--complete"), type="logical", default=FALSE, help="If plot is to be made for complete measurement"),
    make_option(c("-t", "--title"), type="character", default="", help="Title for the diagram"),
    make_option(c("--facetOut"), type="logical", default = FALSE, help="put some value group into a different facet on the left/right"),
    make_option(c("--percentAxis"), type="character", default = "", help="name of the sorter to use as 100%"),
    make_option(c("--percentFilter"), type="character", default="", help="name extra filter in case s is not enough"),
    make_option(c("--secondAxis"), type="character", default="", help="name of the axis if second values are plotted"),
    make_option(c("--secondAxisAdaptationScale"), type="numeric", default=70000),
    make_option(c("--secondAxisAdaptationLinear"), type="numeric", default=30000),
    make_option(c("--percentBy"), type="numeric", default=10, help="percent steps on the axis"),
    make_option(c("--missesBy"), type="numeric", default=20, help="percent steps on the axis"),
    make_option(c("--unit"), type="character", default="CPU cycles", help="if cycles or cache misses were measured"),
    make_option(c("--alternativeValues"), type="character", default=""),
    make_option(c("--alternativeOrdering"), type="character", default="", help="column of which to extract the alternative ordering"),
    make_option(c("--plotColor"), type="character", default="black"),
    make_option(c("--logScale"), type="logical", default=FALSE),
    make_option(c("--axisFactor"), type="numeric", default=1)
)
opt_parser = OptionParser(option_list = option_list)
options = parse_args(opt_parser)

# if (options$)

con <- dbConnect(SQLite(), options$dbName)
someRes <- dbExecute(con, "PRAGMA case_sensitive_like=ON;")

getQuery <- function(value, facet) {
    query <- paste("select", value, "as normalized_value, s as sorter, t as sortergroup,", facet, "as facet, cachemisses") 
    if (options$alternativeOrdering != "")
    {
        query <- paste(query, ", ", options$alternativeOrdering, " as alternativeOrdering", sep="", collapse="")
    }
    query <- paste(query, "from", options$tableName, "where s not like '%JXc%' and s not like '%6Cm%' and s not like '%QMa%'")
    if (!options$complete) {
        query <- paste(query, "and a =", options$array_size)
    }

    if (options$filter != "") {
        query <- paste(query, "and", options$filter)
    }
    query
}

if (options$alternativeValues != "") {
    query <- getQuery(options$alternativeValues, 1)
} else {
    query <- getQuery("(cycles / n)", 1)
}
if (options$facetOut)
{
    query <- paste(query, "UNION", getQuery("(cachemisses / n)", 2))
}
res <- dbGetQuery(con, query)

array_size_string <- paste(options$array_size)
if (options$array_size < 10) {
    array_size_string <- paste("0", array_size_string, sep="", collapse="")
}
filename <- paste("plots/boxplot-", options$filePostfix, sep="", collapse="")
if (!options$complete) {
    filename <- paste(filename, "-array_size", array_size_string, sep="", collapse="")
}
filenameExt <- paste(filename, ".pdf", sep = "", collapse = "")

if (options$title == "") {
    plot_title <- paste("ArraySize =", options$array_size)
} else {
    plot_title <- options$title
}

ylab <- paste(options$unit, "per iteration")
if (options$axisFactor == 1000) {
    ylab <- paste(ylab, "in thousands")
}
ylab2 <- paste("cache misses per iteration")

if (options$alternativeOrdering != "") {
    thisplot <- ggplot(res, aes(x = reorder(sorter, -alternativeOrdering), y = normalized_value / options$axisFactor))
} else {
    thisplot <- ggplot(res, aes(x = reorder(sorter, -normalized_value), y = normalized_value / options$axisFactor))
}

thisplot <- thisplot +
    labs(x = "Sorting algorithm", y = ylab, title = plot_title) +
    geom_boxplot(color = options$plotColor)
if (options$secondAxis != "") {
    multiply <- options$secondAxisAdaptationScale
    addition <- options$secondAxisAdaptationLinear
    thisplot <- thisplot + geom_boxplot(mapping = aes(x = reorder(sorter, -normalized_value), y = (cachemisses * multiply + addition) / options$axisFactor), color = "blue")
}
thisplot <- thisplot + 
    coord_flip() + 
    theme(
          axis.text.x = element_text(family="Times", size=10),
          axis.text.y = element_text(family="Courier", size=9),
          strip.background = element_blank(),
          strip.text.y = element_blank(),
          strip.text.x = element_blank(),
          plot.title = element_text(family="Times", size=12, hjust = 0.5),
          text = element_text(family="Times", size=10))

if (options$facetOut) {
    thisplot <- thisplot + facet_grid(rows = vars(sortergroup), cols = vars(facet), scales = "free", space="free_y", labeller=labeller(.cols=c(ylab, ylab2)))
} else {
    thisplot <- thisplot + facet_grid(rows = vars(sortergroup), scales = "free", space = "free")
}

if (options$logScale) {
    thisplot <- thisplot + scale_y_log10()
}

if (options$percentAxis != "") {
    percentQuery <- paste("select avg(cycles / n) / ", options$axisFactor, " as avg from ", options$tableName, " where s = '", options$percentAxis, "'", sep="")
    if (options$percentFilter != "") {
        percentQuery <- paste(percentQuery, "and", options$percentFilter)
    }
    percentQuery <- paste(percentQuery, " group by s", sep="");
    percentRes <- dbGetQuery(con, percentQuery)
    breaks <- seq(0, 5000, by=options$percentBy)
    thisplot <- thisplot + scale_y_continuous(sec.axis = sec_axis(~. * 100 / percentRes[1]$avg, name = paste("Value in relation to '", options$percentAxis, "'", sep="", collapse=""), breaks = breaks, labels = paste(breaks, "%", sep=""))) 
} else if (options$secondAxis != "") {
    divide <- options$secondAxisAdaptationScale
    subtract <- options$secondAxisAdaptationLinear / (divide * options$axisFactor)
    thisplot <- thisplot + scale_y_continuous(sec.axis = sec_axis(~. / divide - subtract, name = options$secondAxis)) + 
    theme(axis.title.x.top = element_text(color="blue"), axis.text.x.top = element_text(color="blue"))
}

ggsave(filenameExt, thisplot, width=17, height=10, units="cm")
