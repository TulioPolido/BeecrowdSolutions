SELECT pd.name, pv.name, pd.price 
FROM products pd, providers pv, categories c
WHERE pd.id_providers = pv.id
AND pd.id_categories = c.id
AND c.name = 'Super Luxury'
AND pd.price > 1000.0;