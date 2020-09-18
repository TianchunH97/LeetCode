# LeetCode 175: Combine Two Tables

SELECT P.FirstName, P.LastName, A.City, A.State
FROM Person P
LEFT JOIN Address A
ON P.PersonId = A.PersonId