PRAGMA case_sensitive_like=ON;
select 
	lef.s, lef.average, rig.s, rig.average, 
	lef.average / rig.average as leftPerRight, 1 - lef.average / rig.average as su
	from completeSortDeviation129 lef, 
		completeSortDeviation129 rig 
	where
		(rig.average = (
			SELECT min(average) from completeSortDeviation129 where s like '%I%'
		) or rig.s like '%Std%') and lef.average = (
			SELECT min(average) from completeSortDeviation129 where s not like '%-s%'
		) 
	order by leftPerRight