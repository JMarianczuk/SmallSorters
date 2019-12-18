PRAGMA case_sensitive_like=ON;
select 
	lef.s, lef.average, rig.s, rig.average, 
	lef.average / rig.average as leftPerRight, 1 - lef.average / rig.average as su, rig.a
	from sampleSortDeviation129 lef, 
		sampleSortDeviation129 rig 
	where
		(rig.s like '%IS%Def%' or rig.s like '%Std%') and lef.average in (
			SELECT min(average) from sampleSortDeviation129 where s like '%SN%' group by a
		) and rig.a = lef.a
	order by leftPerRight