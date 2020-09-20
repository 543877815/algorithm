# Write your MySQL query statement below
select * 
from cinema 
where description != "boring" and id & 1
order by rating desc