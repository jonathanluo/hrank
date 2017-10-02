-- https://stackoverflow.com/questions/10024771/calling-a-stored-procedure-in-oracle-with-in-and-out-parameters
-- plsql stored procedure cursor example
-- pl sql stored procedure cursor out parameter

-- Using PL/SQL Stored Procedures and REF CURSORs
--    https://docs.oracle.com/cd/E17781_01/appdev.112/e18751/procedures_plsql.htm#TDPNG60040

-- Example: Returning a REF CURSOR from a procedure (PL/SQL)
--    https://www.ibm.com/support/knowledgecenter/en/SS6NHC/com.ibm.swg.im.dashdb.apdv.plsql.doc/doc/c0053892.html


-- 09/20/17
set serveroutput on;
CREATE OR REPLACE PROCEDURE SP_GET_EMPLOYEES(V_EMPID IN NUMBER, V_OUT OUT SYS_REFCURSOR)
AS
BEGIN 
  OPEN V_OUT FOR
--  SELECT * FROM EMPLOYEES WHERE EMPLOYEE_ID = V_EMPID; -- okay
--  SELECT * FROM EMPLOYEES WHERE EMPLOYEE_ID in (V_EMPID); -- okay
-- 'SELECT FIRST_NAME, LAST_NAME, EMPLOYEE_id FROM EMPLOYEES WHERE EMPLOYEE_ID = V_EMPID'; -- runtime error: 00904. 00000 -  "%s: invalid identifier"
--  SELECT FIRST_NAME, LAST_NAME FROM EMPLOYEES WHERE EMPLOYEE_ID = V_EMPID;
  SELECT FIRST_NAME, LAST_NAME, EMPLOYEE_id FROM EMPLOYEES;
  
END; 

CREATE OR REPLACE PROCEDURE SP_GET_EMPLOYEES_2(V_EMPID IN EMPLOYEES.EMPLOYEE_ID%type, V_OUT OUT SYS_REFCURSOR)
AS
BEGIN 
  OPEN V_OUT FOR
    SELECT FIRST_NAME, LAST_NAME, EMPLOYEE_id FROM EMPLOYEES;
END;

-- Query 1
-- https://stackoverflow.com/questions/6781916/how-to-test-an-oracle-stored-procedure-with-refcursor-return-type
DECLARE
    v_OUT SYS_REFCURSOR; -- case insensitive for variables, must match SP IN and OUT paramters by name 
    V_EMPID NUMBER(6,0); -- or NUMBER
    f_name VARCHAR2(20);
    l_name VARCHAR2(20);

BEGIN
    V_EMPID:=206;
    SP_GET_EMPLOYEES(V_EMPID => V_EMPID, V_OUT => V_OUT);
    LOOP
        FETCH V_OUT INTO f_name, L_name, V_EMPID;
        EXIT WHEN V_OUT%NOTFOUND;
        dbms_output.put_line(V_EMPID || ' ' || f_name || ' - ' || l_name);
    END LOOP;
END;

-- Query 2
DECLARE
    v_OUT SYS_REFCURSOR;
    V_EMPID NUMBER(6,0); -- or NUMBER
    f_name VARCHAR2(20);
    l_name VARCHAR2(20);

BEGIN
    V_EMPID := 101;
    SP_GET_EMPLOYEES_2(V_EMPID => V_EMPID, V_OUT => V_OUT);
    LOOP
        FETCH V_OUT INTO f_name, L_name, V_EMPID;
        EXIT WHEN V_OUT%NOTFOUND;
        dbms_output.put_line(V_EMPID || ' ' || f_name || ' - ' || l_name);
    END LOOP;
END;
