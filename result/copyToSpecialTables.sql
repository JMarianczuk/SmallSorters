CREATE TABLE IF NOT EXISTS "normalSort" as select * from stats where s like '%-N%';
CREATE TABLE IF NOT EXISTS "inrowSort" as select * from stats where s like '%-I%';
CREATE TABLE IF NOT EXISTS "sampleSort" as select * from stats where s like '%-S%';
CREATE TABLE IF NOT EXISTS "completeSort" as select * from stats where s like '%-C%' or s like '%-c%';
CREATE TABLE IF NOT EXISTS "normalSortWithout" as select lef.s as s, lef.v - rig.v as v, lef.a as a, lef.n as n, lef.t as t from normalSort lef, normalSort rig where lef.s = rig.s and lef.a = rig.a and lef.n = rig.n and lef.i = rig.i and lef.c = 0 and rig.c = 1;
CREATE TABLE IF NOT EXISTS "sampleSortWithout" as select lef.s as s, lef.v - rig.v as v, lef.a as a, lef.n as n, lef.t as t from sampleSort lef, sampleSort rig where lef.s = rig.s and lef.a = rig.a and lef.n = rig.n and lef.i = rig.i and lef.c = 0 and rig.c = 1;
CREATE TABLE IF NOT EXISTS "completeSortWithout" as select lef.s as s, lef.v - rig.v as v, lef.a as a, lef.n as n, lef.t as t from completeSort lef, completeSort rig where lef.s = rig.s and lef.a = rig.a and lef.n = rig.n and lef.i = rig.i and lef.c = 0 and rig.c = 1;