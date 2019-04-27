select 
	lef.s, lef.average, rig.s, rig.average, 
	lef.average / rig.average as leftPerRight 
	from completeSortDeviation lef, 
		completeSortDeviation rig 
	where
		(rig.average = (
			SELECT min(average) from completeSortDeviation where s like '%I%'
		) or rig.s like '%Std%') and lef.average = (
			SELECT min(average) from completeSortDeviation
		) 
	order by leftPerRight