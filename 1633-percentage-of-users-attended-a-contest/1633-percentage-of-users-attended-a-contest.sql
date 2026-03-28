# Write your MySQL query statement below
select r.contest_id, round(((count(r.contest_id))*100/(select count(*) from users)), 2) as percentage
from
Users u 
right join
Register r
on u.user_id = r.user_id
group by
contest_id
order by
percentage desc,contest_id ASC
