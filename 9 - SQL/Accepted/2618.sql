  SELECT pd.name, pv.name, c.name 
  FROM providers pv 
  INNER JOIN products pd ON pv.id = pd.id_providers
  INNER JOIN categories c ON c.id = pd.id_categories
  WHERE pv.name = 'Sansul SA'
  AND c.name = 'Imported';