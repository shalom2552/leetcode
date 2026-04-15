# Select column product_id from Products 
# where both low_fats and recyclable equals to "Y"

SELECT product_id
FROM Products
WHERE low_fats = "Y" AND recyclable = "Y";