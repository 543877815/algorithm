# Write your MySQL query statement below
delete from Person where Id in (
    select * from (
        select Id from Person where Email
        in (
            select Email from Person group by Email having count(Email) > 1
        ) and Id not in (
            select min(Id) from Person group by Email having count(Email) > 1
        )
    ) as copy
)