REM %1 db name, %2 machine number, %3 percent axis complete, %4 percent by, %5 percent axis ipso, %6 --unit switch
mkdir plots
call PlotSampleSort.bat %1 %2 %6
call PlotCompleteSort.bat %1 %2 %3 %4 %6
call PlotNormalSort.bat %1 %2 %6
call PlotInRowSort.bat %1 %2 %6
call PlotIpsoSort.bat %1 %2 %5 %6