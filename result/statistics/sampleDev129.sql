PRAGMA case_sensitive_like=ON;
select 
	lef.s, lef.average, rig.s, rig.average, 
	lef.average / rig.average as leftPerRight, 1 - lef.average / rig.average as su
	from sampleSortDeviation129 lef, 
		sampleSortDeviation129 rig 
	where
		(rig.average = (
			SELECT min(average) from sampleSortDeviation129 where s like '%I%' and s like '%-s%'
		) or rig.s like '%Std%') and lef.average = (
			SELECT min(average) from sampleSortDeviation129 where s like '%-s%'
		) 
	order by leftPerRight