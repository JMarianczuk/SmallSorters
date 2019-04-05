CREATE INDEX IF NOT EXISTS ind ON stats (s, ss, a, i, c);
CREATE TABLE IF NOT EXISTS "normalSort" as select * from stats where s like '%-N%';
CREATE TABLE IF NOT EXISTS "inrowSort" as select * from stats where s like '%-I%';
CREATE TABLE IF NOT EXISTS "sampleSort" as select * from stats where s like '%-S%';
CREATE TABLE IF NOT EXISTS "completeSort" as select * from stats where s like '%-C%';