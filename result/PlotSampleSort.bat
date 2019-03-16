Rscript RPlot.R --filter="s like '%%Sample%%' and s like '%%Best%%'" --filePostfix="sample-sort-best" --complete=TRUE --title="SampleSort"
Rscript RPlot.R --filter="s like '%%Sample%%' and s like '%%BN Parl%%'" --filePostfix="sample-sort-bosenelson" --complete=TRUE --title="SampleSort"
Rscript RPlot.R --filter="s like '%%Sample%%' and s like '%%BN Param%%'" --filePostfix="sample-sort-bosenelson" --complete=TRUE --title="SampleSort"
Rscript RPlot.R --filter="s like '%%Sample%%' and s like '%%Ins%%'" --filePostfix="sample-sort-insertionsort" --complete=TRUE --title="SampleSort"

for /l %%a in (1, 1, 5) do (
    Rscript RPlot.R --filter="s like '%%Sample%%' and s like '%% 3%%a%%'" --filePostfix="sample-sort-3%%a" --complete=TRUE --title="SampleSort"
)

for /l %%a in (1, 1, 5) do (
    Rscript RPlot.R --filter="s like '%%Sample%%' and s like '%% 3_%%a%%'" --filePostfix="sample-sort-3_%%a" --complete=TRUE --title="SampleSort"
)
