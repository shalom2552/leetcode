SELECT C.email AS Email
FROM 
    (SELECT email, COUNT(email) as c
    FROM Person P
    GROUP BY email) AS C
WHERE C.c > 1
