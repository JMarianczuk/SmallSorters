CREATE INDEX ind ON stats (s, ss, a, i, c);
insert into normalSort select * from stats where s like '%-N%'
insert into inrowSort select * from stats where s like '%-I%'
insert into sampleSort select * from stats where s like '%-S%'
insert into completeSort select * from stats where s like '%-C%'