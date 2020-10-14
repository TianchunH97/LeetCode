# LeetCode 1205: Monthly Transactions II
# Approach: UNION ALL

WITH temp AS (
(SELECT
    T.id,
    T.country,
    'chargeback' AS state,
    T.amount,
    C.trans_date
FROM
    Transactions T
INNER JOIN
    Chargebacks C
ON
    T.id = C.trans_id)
UNION ALL
(SELECT
    *
FROM 
    Transactions T2
WHERE
    T2.state = 'approved'))
SELECT
    LEFT(trans_date, 7) AS month,
    country,
    SUM(CASE WHEN state='approved' THEN 1 ELSE 0 END) AS approved_count,
    SUM(CASE WHEN state='approved' THEN amount ELSE 0 END) AS approved_amount,
    SUM(CASE WHEN state='chargeback' THEN 1 ELSE 0 END) AS chargeback_count,
    SUM(CASE WHEN state='chargeback' THEN amount ELSE 0 END) AS chargeback_amount
FROM
    temp
GROUP BY
    month, country