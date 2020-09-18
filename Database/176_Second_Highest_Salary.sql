# Leetcode 176: Second Highest Salary
SELECT IFNULL(
    (SELECT Salary 
     FROM Employee
     WHERE Salary < (SELECT MAX(Salary) FROM Employee)
     ORDER BY Salary DESC
     LIMIT 1), NULL) AS SecondHighestSalary