# Write your MySQL query statement below
SELECT person_name
FROM (
    SELECT
        person_name, 
        weight,
        SUM(weight) OVER (ORDER BY Turn) AS total_weight
    FROM Queue
) as t
WHERE total_weight <= 1000
ORDER BY total_weight DESC
LIMIT 1;