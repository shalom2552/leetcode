
SELECT name AS Employee
FROM Employee E
WHERE salary >
    (SELECT salary FROM Employee M
    WHERE E.managerId = M.id) 
