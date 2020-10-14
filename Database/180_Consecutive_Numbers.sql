# LeetCode 180: Consecutive Numbers

SELECT DISTINCT
    L1.Num AS ConsecutiveNums
FROM
    Logs L1, Logs L2, Logs L3
WHERE
    L1.Id = L2.Id-1
AND L2.Id = L3.Id-1
AND L1.Num = L2.Num
AND L2.Num = L3.Num