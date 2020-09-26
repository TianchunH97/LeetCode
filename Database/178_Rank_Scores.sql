# LeetCode 178: Rank Scores
# DENSE_RANK()

SELECT
    Score,
    DENSE_RANK() OVER (ORDER BY Score DESC) AS 'Rank'
FROM
    Scores