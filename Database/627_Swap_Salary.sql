# LeetCode 627: Swap Salary

UPDATE salary
SET sex = CASE sex
    WHEN 'm' THEN 'f'
    ELSE 'm' END;