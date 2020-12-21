#include "../headers/accountant.h"
#include "../headers/database.h"
#include "../headers/helpers.h"

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
    std::string query = "UPDATE employees SET salary=salary*(100+" + std::to_string(rate_of_rise) + ")/100 WHERE depId=" + std::to_string(department->getDepId());
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

bool Accountant::increaseTitleSalary(Departments *dep, std::string title, double rate_of_rise)
// TODO: fonk'u str title gore duzenle -->duzenlendi
{
    std::cout << title<<"\n";
    std::cout << dep->getDepId()<<"\n";


    std::string query = "UPDATE employees INNER JOIN titles ON employees.titId = titles.titId AND employees.depId = " + std::to_string(dep->getDepId())+" AND titles.titleName='"+ title + "' SET salary = salary * (100+" + std::to_string(rate_of_rise) +")/100";
    //UPDATE employees INNER JOIN titles ON employees.titId = titles.titId AND employees.depId = 1 AND titles.titleName="Senior Worker" SET salary = salary * (100+10)/100
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
    std::string query = "UPDATE employees SET salary=salary*(100+" + std::to_string(rate_of_rise) + ")/100";
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

bool Accountant::bonusPaymentToSameTitles(Title *title,Departments *department, double payment_amount)
// TODO: departman parametresi eklenecek, ya da silinecek
{
    std::string title_id;
    std::vector<std::vector<std::string>> titleIDResult;
    std::vector<std::vector<std::string>> depIDResult;
    std::string getTitleID_query = "SELECET titleId FROM titles WHERE titleName='" + title->getTitle() + "'";
    std::string getDepID_query = "SELECET depId FROM departments WHERE depName='" + std::to_string(department->getDepId()) + "'";
    titleIDResult = db.exec_query(getTitleID_query);
    depIDResult = db.exec_query(getDepID_query);
    std::string bonusPayToSameTitle_query = "INSERT INTO payments (empId, payment) SELECT e.empId," + std::to_string(payment_amount) + " FROM employees e, WHERE e.titId="+titleIDResult[0][0]+"AND  e.depId = "+depIDResult[0][0]+"";
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

bool Accountant::paySalary(int emp_id)
{
    std::string pay_query = "INSERT INTO payments (empId, payment) SELECT e.empId,e.salary FROM employees e WHERE e.empId=" + std::to_string(emp_id);
    try
    {
        db.exec_query(pay_query);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    std::cout << "|    Payment has been made.\n";
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
    std::cout << "|    Payments has been made.\n";
    return true;
}

bool Accountant::addEmployee(Employee employee)
{

    std::string person_query = "INSERT INTO person (name,dateOfBirth, gender, phoneNumber, address, email)"
                               "VALUES(" +
                               employee.getName() + ',' +
                               employee.getDateOfBirth() + ',' +
                               employee.getGender() + ',' +
                               employee.getPhoneNumber() + ',' +
                               employee.getAddress() + ',' +
                               employee.getEmail() + ")";

    std::cout << employee.getTitle()<<"********\n";
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

    std::string addemployee_query = "INSERT INTO employees (depId, titId, personId, startDate, sumOvertime, salary, timeOfFire) VALUES (" +
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

    std::string selecet_departments = "SELECT d.depId, p.name, d.depName FROM departments d, person p, employees e WHERE d.depId = e.depId AND e.personId = p.personId";
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
    int arr[] = {15, 12, 17};
    std::cout << std::string(80, '-') << "\n";
    std::cout << "| Department ID" << std::string(18, ' ') << "Manager Name" << std::string(18, ' ') << "Department Name |\n";
    std::cout << std::string(80, '-') << "\n";
    printDatas(departments, arr, 80);
}

void Accountant::showDepartmentsEmployees(int depID)
{
    std::string selecet_department_employees = "SELECT e.empId,p.name,t.titleName,e.sumOveritme,e.salary FROM  person p, employees e,titles t WHERE " + std::to_string(depID) + "  = e.depId AND e.personId = p.personId AND t.titId = e.titId";
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
    int arr[] = {13, 4, 5, 21, 8};
    std::cout << "| Employee ID" << std::string(18, ' ') << "Name" << std::string(18, ' ') << "Title" << std::string(18, ' ') << "Monthly overtime hour" << std::string(18, ' ') << "Salary |\n";
    printDatas(department_employees, arr, 133);
}

void Accountant::showSameTitleEmployees(std::string title)
{
    std::string select_ste = "SELECT d.depName,p.name,t.titleName FROM departments d,person p,employees e, titles t WHERE t.titleName='" + title + "' AND e.titId=t.titId AND d.depId=e.depId AND p.personId=e.personId";
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
    int arr[] = {12, 4, 7};
    std::cout << "| Department" << std::string(18, ' ') << "Name" << std::string(18, ' ') << "Title |\n";
    printDatas(ste_employees, arr, 59);
}
void Accountant::showDepartmentStats(Departments *department)
{
    std::string total_salary_query = "SELECT SUM(salary) FROM employees WHERE depId=" + std::to_string(department->getDepId());
    std::string emp_count = "SELECT COUNT(*) FROM employees WHERE depId=" + std::to_string(department->getDepId());
    std::string manager_infos = "SELECT e.empId, p.name FROM employees e, person p, departments d WHERE e.personId = p.personId AND d.depId = e.depId AND d.managerId = e.empId AND e.depId=" + std::to_string(department->getDepId());
    double ts;
    int empc;
    std::vector<std::vector<std::string>> man_info;
    try
    {
        ts = std::stod(db.exec_query(total_salary_query)[0][0]);
        empc = std::stoi(db.exec_query(emp_count)[0][0]);
        man_info = db.exec_query(manager_infos);
        std::cout << "|    Manager ID        Manager Name\n";
        std::cout << "|    " << man_info[0][0] << std::string(8 + 10 - man_info[0][0].length(), ' ') << man_info[0][1] << "\n";
        std::cout << "|    Number of employees working in the department: " << empc << "\n";
        std::cout << "|    Total salary expenses of employees working in the department: " << ts << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Accountant::showCompanyStats()
{
    std::string com_name_query = "SELECT companyName FROM company";
    std::string numof_deps_query = "SELECT COUNT(*) FROM departments";
    std::string numof_employees_query = "SELECT COUNT(*) FROM employees";
    std::string com_name;
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
    try
    {
        com_name = db.exec_query(com_name_query)[0][0];
    }
    catch (const std::exception &e)
    {
        std::cerr << "[ERROR] from Accountant::showCompanyStats\n";
        std::cerr << e.what() << '\n';
    }

    double totalexpense = calcTotalExpense();

    std::cout << "Company Name : " + com_name + "\n";
    std::cout << "Total departments number : " + numof_deps + "\n";
    std::cout << "Total employee number : " + numof_employees + "\n";
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
    int arr = 4;
    std::cout << "Logs\n";
    printDatas(logs, &arr, 50); // 3. parametre degiscek
}
