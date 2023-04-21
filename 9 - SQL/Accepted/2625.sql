SELECT Concat(Concat(Concat(Concat(Substring(CPF,1,3), '.'),Concat(Substring(CPF,4,3), '.')), Concat(Substring(CPF,7,3), '-')), Substring(CPF,10,2)) as CPF
FROM customers c INNER JOIN natural_person n
ON n.id_customers = c.id;
