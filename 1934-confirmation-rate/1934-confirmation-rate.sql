# Write your MySQL query statement below
select 
    s.user_id, 
    IFNULL(round(AVG(c.action = 'confirmed'),2),0) as confirmation_rate
from 
    Signups as s left outer join Confirmations as c
on 
    s.user_id = c.user_id
group by 
    s.user_id