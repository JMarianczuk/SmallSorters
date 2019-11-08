# $1 db name, $2 machine number, $3 percent axis complete, $4 percent by, $5 percent axis ipso
mkdir plots
./PlotSampleSort.sh $1 $2
./PlotCompleteSort.sh $1 $2 $3 $4
./PlotNormalSort.sh $1 $2
./PlotInRowSort.sh $1 $2
./PlotIpsoSort.sh $1 $2 $5