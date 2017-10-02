CREATE OR REPLACE PROCEDURE SP_GET_SALARY(V_EMPID IN NUMBER, salary OUT NUMBER)
AS BEGIN
    SELECT SALARY INTO salary FROM EMPLOYEES WHERE EMPLOYEE_ID in (V_EMPID);
END;

-- query
DECLARE
    V_EMPID NUMBER;
    salary NUMBER;
BEGIN
    V_EMPID:=115;
    SP_GET_SALARY(salary => salary, V_EMPID => V_EMPID);
    --PROC1(V_EMPID, salary);--ok
    --PROC1(201, salary);--ok
    --execute PROC1(V_EMPID, salary); -- error
    dbms_output.put_line(salary);
END;
