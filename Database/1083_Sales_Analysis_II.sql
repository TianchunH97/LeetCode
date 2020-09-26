# LeetCode 1083: Sales Analysis II

SELECT DISTINCT
    S.buyer_id
FROM
    Sales S, Product P
WHERE
    S.product_id = P.product_id
AND P.product_name = 'S8'
AND NOT EXISTS (SELECT S2.buyer_id
                FROM Sales S2, Product P2
                WHERE S2.buyer_id = S.buyer_id
                AND P2.product_id = S2.product_id
                AND P2.product_name = 'iPhone')