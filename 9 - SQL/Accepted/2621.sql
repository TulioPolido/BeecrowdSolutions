SELECT pd.name
FROM products pd 
INNER JOIN providers pv ON pd.id_providers = pv.id
WHERE pd.amount > 9 
AND pd.amount < 21
AND pv.name LIKE 'P%';