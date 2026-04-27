
SELECT P.product_id, 
    COALESCE(
        ROUND(
            SUM(P.price * US.units) / NULLIF(SUM(US.units), 0), 
        2), 
    0) as average_price
FROM Prices P
LEFT JOIN UnitsSold US
ON 
    P.product_id = US.product_id
    AND P.start_date <= US.purchase_date
    AND P.end_date >= US.purchase_date
GROUP BY P.product_id
