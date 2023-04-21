SELECT l.name, (Round(1.618*l.omega,3)) as FatorN
FROM life_registry l JOIN dimensions d
ON l.dimensions_id = d.id
WHERE (d.name = 'C774' OR d.name = 'C875')
AND l.name LIKE 'Richard%';