# Write your MySQL query statement below
select t1.product_id, t1.year as first_year, t1.quantity, t1.price
from Sales t1
join
(select product_id, min(year) as first_year from Sales
group by product_id) t
on t1.product_id = t.product_id where t1.year = t.first_year;
