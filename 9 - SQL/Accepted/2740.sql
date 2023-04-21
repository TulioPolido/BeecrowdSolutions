(SELECT Concat('Podium: ',team) as name
FROM league
ORDER BY position
LIMIT 3)
UNION ALL
(SELECT Concat('Demoted: ',team) as name
FROM league
WHERE position = 14 OR position = 15
ORDER BY position);