# LeetCode 182: Duplicate Emails
SELECT DISTINCT P1.Email 
FROM Person P1, Person P2
WHERE P1.Email = P2.Email AND P1.Id <> P2.Id;