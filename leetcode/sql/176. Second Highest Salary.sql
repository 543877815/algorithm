select max(Salary) SecondHighestSalary
from employee
where salary < (select max(salary) from employee)