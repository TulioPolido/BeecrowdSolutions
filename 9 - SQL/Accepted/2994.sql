SELECT d.name, ROUND( SUM( ( (150.0 * a.hours) + (150.0 * a.hours * w.bonus / 100) ) ), 1) AS salary 
FROM doctors d, attendances a, work_shifts w
WHERE d.id = a.id_doctor
And a.id_work_shift = w.id
GROUP BY d.name
Order by salary desc