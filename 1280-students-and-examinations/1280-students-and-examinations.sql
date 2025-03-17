# Write your MySQL query statement below
select
    c.student_id,
    c.student_name,
    c.subject_name, 
    count(e.student_id) as attended_exams
from 
    (select * from Students as s cross join Subjects as sub) as c 
left outer join 
    Examinations as e
on 
    c.student_id = e.student_id and c.subject_name = e.subject_name
group by 
    c.subject_name, c.student_id
order by 
    c.student_id asc,
    c.subject_name asc