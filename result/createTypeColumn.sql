ALTER TABLE stats ADD COLUMN t VARCHAR;
UPDATE stats SET t = substr(s, 0, 8);