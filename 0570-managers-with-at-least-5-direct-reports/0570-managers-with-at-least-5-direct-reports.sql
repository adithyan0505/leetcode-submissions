# Write your MySQL query statement below
select e.name
FROM Employee AS e 
INNER JOIN Employee AS m ON e.id=m.managerId
group by e.id
having count(m.id) >= 5