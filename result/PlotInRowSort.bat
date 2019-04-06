for /l %%a in (2, 1, 16) do (
    Rscript RPlot.R --array_size=%%a --tableName="inrowSort" --filePostfix="in_row"
)