for /l %%a in (2, 1, 16) do (
    Rscript RPlot.R --array_size=%%a --filter="s not like '%%InRow%%' and s not like '%%Complete%%' and s not like '%%Sample%%'" --filePostfix="normal"
)