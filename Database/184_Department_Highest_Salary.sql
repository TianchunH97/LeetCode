# LeetCode 184: Department Highest Salary

SELECT D.Name AS Department, E.Name AS Employee, E.Salary AS Salary
FROM Department D, Employee E
WHERE D.Id = E.DepartmentId 
AND (D.Id, E.Salary) IN (
    SELECT DepartmentId, MAX(Salary)
    FROM Employee
    GROUP BY DepartmentId
);