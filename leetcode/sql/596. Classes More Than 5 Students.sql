# Write your MySQL query statement below
select class 
from (
    select distinct * from courses
) as A
group by class having count(class)>=5
