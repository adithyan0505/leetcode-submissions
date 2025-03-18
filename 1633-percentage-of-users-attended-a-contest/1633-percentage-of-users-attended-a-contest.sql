# Write your MySQL query statement below
select 
    r.contest_id, 
    round((count(u.user_id) * 100 / (select count(*) from Users)), 2) as percentage
from 
    Users as u join Register as r
on 
    u.user_id = r.user_id
group by 
    contest_id
order by 
    percentage desc,
    r.contest_id asc