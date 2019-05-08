PRAGMA case_sensitive_like=ON;
select 
	lef.s, lef.average, rig.s, rig.average, 
	lef.average / rig.average as leftPerRight, 1 - lef.average / rig.average as su, rig.a
	from ipsoSortDeviation133 lef, 
		ipsoSortDeviation133 rig 
	where
		(rig.average in (
			SELECT min(average) from ipsoSortDeviation133 where s like '%I%-4 16 KR Def%' group by a
		) or rig.s like '%Std%') and lef.average in (
			SELECT min(average) from ipsoSortDeviation133 where s like '%N%' group by a
		) and rig.a = lef.a
	order by leftPerRight