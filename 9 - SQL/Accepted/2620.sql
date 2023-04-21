  SELECT c.name, o.id
  FROM customers c, orders o 
  WHERE o.id_customers = c.id
  AND o.orders_date >= '2016/01/01'
  AND o.orders_date <= '2016/06/30';