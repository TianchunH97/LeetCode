# Leetcode 1112: Highest Grade For Each Student
# Key point: select first lines of each group after GROUP BY
# Approach: use RANK() with subquery

WITH temp AS (
SELECT
    *,
    RANK() OVER (PARTITION BY student_id ORDER BY grade DESC, course_id) AS rk
FROM
    Enrollments)
SELECT
    student_id,
    course_id,
    grade
FROM temp
WHERE temp.rk = 1