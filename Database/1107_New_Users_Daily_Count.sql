# LeetCode 1107: New Users Daily Count

# Write your MySQL query statement below
/*
WITH temp2 AS
(SELECT
    user_id,
    activity_date
FROM (SELECT
    user_id,
    activity_date,
    RANK() OVER (PARTITION BY user_id ORDER BY activity_date) AS rk
FROM
    Traffic
WHERE
    activity = 'login') AS temp
WHERE rk = 1 AND DATEDIFF('2019-06-30', activity_date) < 91)
SELECT
    activity_date AS login_date,
    COUNT(user_id) AS user_count
FROM temp2
GROUP BY activity_date
ORDER BY activity_date
*/

WITH first_logins AS
(SELECT
    user_id,
    MIN(activity_date) AS login_date
FROM
    Traffic
WHERE
    activity = 'login'
GROUP BY
    user_id)
SELECT
    login_date,
    COUNT(user_id) AS user_count
FROM
    first_logins
WHERE
    DATEDIFF('2019-06-30', login_date) < 91
GROUP BY
    login_date