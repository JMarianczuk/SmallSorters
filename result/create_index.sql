ALTER TABLE stats ADD COLUMN t VARCHAR;
UPDATE stats SET t = substr(s, 0, 8);
CREATE INDEX IF NOT EXISTS ind ON stats (s, ss, a, i, c);