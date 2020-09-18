# LeetCode 183: Customers Who Never Order
SELECT Name AS Customers
FROM Customers
WHERE NOT EXISTS (
    SELECT * FROM Orders
    WHERE Orders.CustomerId = Customers.Id
);