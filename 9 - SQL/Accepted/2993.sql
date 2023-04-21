SELECT amount FROM value_table v
GROUP BY v.amount
ORDER BY count(amount) desc
LIMIT 1;