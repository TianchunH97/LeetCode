# LeetCode 185: Department Top Three Salaries
# Approach: DENSE_RANK()

With temp AS (
SELECT
    E.Name,
    E.Salary,
    D.Name AS Department,
    DENSE_RANK() OVER (PARTITION BY D.Name ORDER BY E.Salary DESC) AS rk
FROM
    Employee E
INNER JOIN
    Department D
ON
    E.DepartmentId = D.Id)
SELECT
    Department,
    Name AS Employee,
    Salary
FROM
    temp
WHERE
    rk < 4