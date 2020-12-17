#include "../headers/accountant.h"
#include "../headers/database.h"

void printDatas(std::vector<std::vector<std::string>> &vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        for (
            auto it = vect[i].begin();
            it != vect[i].end(); it++)
            std::cout << *it << "\t";
        std::cout << "\n";
    }
}

bool Accountant::increaseSalary(int employee_id, double rate_of_rise)
{

    std::string query = "UPDATE employees set salary=salary*(100+" + std::to_string(rate_of_rise) + ")/100 WHERE empId=" + std::to_string(employee_id);

    try
    {
        db.exec_query(query);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}

bool Accountant::increaseSpeDepSalary(Departments *department, double rate_of_rise)
{
    std::string query = "UPDATE employees set salary=salary*(100+" + std::to_string(rate_of_rise) + ")/100 WHERE depId=" + std::to_string(department->getDepId());
    try
    {
        db.exec_query(query);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}

bool Accountant::increaseTitleSalary(Title *title, double rate_of_rise)
{
    std::string title_id;
    std::vector<std::vector<std::string>> titleIDResult;
    std::string getTitleID_query = "SELECET titleId FROM titles WHERE titleName='" + title->getTitle() + "'";
    try
    {
        titleIDResult = db.exec_query(getTitleID_query);
        title_id = titleIDResult[0][0];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    std::string query = "UPDATE employees set salary=salary*(100+" + std::to_string(rate_of_rise) + ")/100 WHERE titId=" + title_id;
    try
    {
        db.exec_query(query);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}

bool Accountant::increaseAllSalarys(double rate_of_rise)
{
    std::string query = "UPDATE employees set salary=salary*(100+" + std::to_string(rate_of_rise) + ")/100";
    try
    {
        db.exec_query(query);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}

double Accountant::calcTotalExpense()
{
    std::string getSumOfSalarys_query = "SELECT SUM(salary) FROM employees ";
    std::vector<std::vector<std::string>> res;
    try
    {
        res = db.exec_query(getSumOfSalarys_query);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
    return std::stod(res[0][0]);
}

bool Accountant::bonusPaymentToAll(double payment_amount)
{
    std::string bonusPay_query = "INSERT INTO payments (empId, payment) SELECT e.empId, " + std::to_string(payment_amount) + " FROM employees e";
    try
    {
        db.exec_query(bonusPay_query);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}

bool Accountant::bonusPaymentToEmployee(int employee_id, double payment_amount)
{
    std::string bonusPayToEmp_query = "INSERT INTO payments (empId,payment) SELECT e.empId, " + std::to_string(payment_amount) + "FROM employees e WHERE e.empId=" + std::to_string(employee_id);
    try
    {
        db.exec_query(bonusPayToEmp_query);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}

bool Accountant::bonusPaymentToDepartments(Departments *department, double payment_amount)
{
    std::string bonusPayToDep_query = "INSERT INTO payments (empId, payment) SELECT e.empId, " + std::to_string(payment_amount) + "FROM employees e WHERE e.depId=" + std::to_string(department->getDepId());
    try
    {
        db.exec_query(bonusPayToDep_query);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}

bool Accountant::bonusPaymentToSameTitles(Title *title, double payment_amount)
{
    std::string title_id;
    std::vector<std::vector<std::string>> titleIDResult;
    std::string getTitleID_query = "SELECET titleId FROM titles WHERE titleName='" + title->getTitle() + "'";
    std::string bonusPayToSameTitle_query = "INSERT INTO payments (empId, payment) SELECT e.empId," + std::to_string(payment_amount) + " FROM employees e titles t WHERE e.titId=t.titleId AND t.titleName ='" + title->getTitle() + "'";
    try
    {
        titleIDResult = db.exec_query(getTitleID_query);
        title_id = titleIDResult[0][0];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    try
    {
        db.exec_query(bonusPayToSameTitle_query);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}

bool Accountant::paySalary(Employee employee)
{
    std::string pay_query = "INSERT INTO payments (empId, payment) VALUES(" + std::to_string(employee.getEmployeeId()) + "," + std::to_string(employee.getSalary()) + ")";
    try
    {
        db.exec_query(pay_query);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}

bool Accountant::paySalarys()
{
    std::string payall_query = "INSERT INTO payments (empId, payment) SELECT e.empId, e.salary FROM employees e";
    try
    {
        db.exec_query(payall_query);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}

bool Accountant::addEmployee(Employee employee)
{

    std::string person_query = "INSERT INTO person (dateOfBirth, gender, phoneNumber, address, email)"
                               "VALUES(" +
                               employee.getDateOfBirth() + ',' +
                               employee.getGender() + ',' +
                               employee.getPhoneNumber() + ',' +
                               employee.getAddress() + ',' +
                               employee.getEmail() + ")";

    std::string get_titleID_query = "SELECT titleId FROM titles WHERE titleName='" + employee.getTitle() + "'";

    std::vector<std::vector<std::string>> titleIDResult;

    try
    {
        titleIDResult = db.exec_query(get_titleID_query);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }

    try
    {
        db.exec_query(person_query);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }

    std::string addemployee_query = "INSERT INTO employees (empId, depId, titId, personId, startDate, sumOvertime, salary, timeOfFire) VALUES (" +
                                    std::to_string(employee.getDepartmentId()) +
                                    titleIDResult[0][0] +
                                    employee.getStartDate() +
                                    std::to_string(employee.getSumOfHoursM()) +
                                    std::to_string(employee.getSalary()) +
                                    employee.getTimeOffFire() +
                                    ")";

    try
    {
        db.exec_query(addemployee_query);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}

bool Accountant::fireEmployee(int employee_id)
{

    std::string fire_query = "DELETE FROM employees WHERE empId=" + std::to_string(employee_id);
    try
    {
        db.exec_query(fire_query);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}

void Accountant::showDepartments()
{

    std::string selecet_departments = "SELECT d.depId, p.name, d.depName FROM departments d, person p, employees e WHERE "
    "d.depId = e.depId AND e.personId = p.personId";
    std::vector<std::vector<std::string>> departments;
    try
    {
        departments = db.exec_query(selecet_departments);
    }
    catch (const std::exception &e)
    {
        std::cerr << "[ERROR] from Accountant::showDepartments\n";
        std::cerr << e.what() << '\n';
    }
    std::cout<<"Department ID\tManager Name\tDepartment Name\n";
    printDatas(departments);
}

void Accountant::showDepartmentsEmployees(int depID)
{
    std::string selecet_department_employees = "SELECT * FROM employees e WHERE e.depId=" + std::to_string(depID);
    std::vector<std::vector<std::string>> department_employees;
    try
    {
        department_employees = db.exec_query(selecet_department_employees);
    }
    catch (const std::exception &e)
    {
        std::cerr << "[ERROR] from Accountant::showDepartmentsEmployees\n";
        std::cerr << e.what() << '\n';
    }

    printDatas(department_employees);
}

void Accountant::showSameTitleEmployees(std::string title)
{
    std::string select_ste = "SELECT * FROM employees e, titles t WHERE t.titleName=" + title + " AND e.titId=t.titleId";
    std::vector<std::vector<std::string>> ste_employees;
    try
    {
        ste_employees = db.exec_query(select_ste);
    }
    catch (const std::exception &e)
    {
        std::cerr << "[ERROR] from Accountant::showSameTitleEmployees\n";
        std::cerr << e.what() << '\n';
    }

    printDatas(ste_employees);
}

void Accountant::showCompanyStats()
{
    std::string numof_deps_query = "SELECT COUNT(*) FROM depertments";
    std::string numof_employees_query = "SELECT COUNT(*) FROM employees";
    std::string numof_deps;
    std::string numof_employees;
    try
    {
        numof_deps = db.exec_query(numof_deps_query)[0][0];
    }
    catch (const std::exception &e)
    {
        std::cerr << "[ERROR] from Accountant::showCompanyStats\n";
        std::cerr << e.what() << '\n';
    }
    try
    {
        numof_employees = db.exec_query(numof_employees_query)[0][0];
    }
    catch (const std::exception &e)
    {
        std::cerr << "[ERROR] from Accountant::showCompanyStats\n";
        std::cerr << e.what() << '\n';
    }

    double totalexpense = calcTotalExpense();

    std::cout << "Total departments number :" + numof_deps + "\n";
    std::cout << "Total employee number :" + numof_employees + "\n";
    std::cout << "Total Expense : " + std::to_string(totalexpense) + "$ \n";
}

void Accountant::showPaymentLogs()
{
    std::string getLogs_query = "SELECT * FROM payments";
    std::vector<std::vector<std::string>> logs;
    try
    {
        logs = db.exec_query(getLogs_query);
    }
    catch (const std::exception &e)
    {
        std::cerr << "[ERROR] from Accountant::showPaymentLogs\n";
        std::cerr << e.what() << '\n';
    }
    printDatas(logs);
}