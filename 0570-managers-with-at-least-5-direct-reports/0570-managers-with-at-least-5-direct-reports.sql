# Write your MySQL query statement below
select e.name 
from 
    (select managerId
    from Employee
    group by managerId
    having count(id) >= 5) as m
join 
    Employee as e
on 
    e.id = m.managerId