for /l %%a in (2, 1, 16) do (
    Rscript RPlot.R --array_size=%%a --filter="s not like '%%InRow%%' and s not like '%%Complete%%'" --filePostfix="normal"
)
for /l %%a in (2, 1, 16) do (
    Rscript RPlot.R --array_size=%%a --filter="s like '%%InRow%%'" --filePostfix="in_row"
)

Rscript RPlot.R --filter="s like '%%Complete%%'" --filePostfix="complete" --complete=TRUE