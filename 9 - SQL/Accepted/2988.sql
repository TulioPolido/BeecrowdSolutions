SELECT t.name,
Count(t.name) as matches,
Count(CASE WHEN (m.team_1 = t.id AND team_1_goals > team_2_goals) OR (m.team_2 = t.id AND team_2_goals > team_1_goals) THEN 1 END) as victories,
Count(CASE WHEN (m.team_1 = t.id AND team_1_goals < team_2_goals) OR (m.team_2 = t.id AND team_2_goals < team_1_goals) THEN 1 END) as defeats,
Count(CASE WHEN (m.team_1 = t.id AND team_1_goals = team_2_goals) OR (m.team_2 = t.id AND team_2_goals = team_1_goals) THEN 1 END) as draws,
(Count(CASE WHEN (m.team_1 = t.id AND team_1_goals > team_2_goals) OR (m.team_2 = t.id AND team_2_goals > team_1_goals) THEN 1 END)*3) +
(Count(CASE WHEN (m.team_1 = t.id AND team_1_goals = team_2_goals) OR (m.team_2 = t.id AND team_2_goals = team_1_goals) THEN 1 END)) as score
FROM teams t INNER JOIN matches m 
ON t.id = m.team_1
OR t.id = m.team_2
GROUP BY t.name
ORDER BY score desc;