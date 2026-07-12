CREATE OR REPLACE FUNCTION NthHighestSalary(N INT) RETURNS TABLE (Salary INT) AS $$
BEGIN
IF N>=1 THEN
  RETURN QUERY (
   
select distinct e.salary
from employee e
order by e.salary desc
limit 1 offset N-1
   
  );
  END IF;
END;
$$ LANGUAGE plpgsql;