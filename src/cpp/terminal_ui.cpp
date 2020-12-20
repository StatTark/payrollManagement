#include "../headers/terminal_ui.h"
Accountant acc = Accountant();
void ui()
{
    Departments *dep;
    std::cout << std::string(60, '=') << "Payroll Management System" << std::string(60, '=') << "\n";
    while (true)
    {
        int value;
        std::cout << "|    1 - Show IT department details\n";
        std::cout << "|    2 - Show Purchasing department details\n";
        std::cout << "|    3 - Show Human Resources department details\n";
        std::cout << "|    4 - Show Advertisement details\n";
        std::cout << "|    5 - Show Public Relations department details\n";
        std::cout << "|    6 - Show general statics\n";
        std::cout << "|    7 - Pay all salarys\n";
        std::cout << "|    8 - Quit\n";
        std::cout << "|    Enter the action number :";
        std::cin >> value;
        // Secilen departman objesi olusturulup depPage sayfasina parametre verilerek
        // yollaniyor
        switch (value)
        {
        case 1:
        {
            std::cout << std::string(5, '\n');
            IT it = IT();
            dep = &it;
            depPage(dep);
            break;
        }
        case 2:
        {
            std::cout << std::string(5, '\n');
            Purchasing pur = Purchasing();
            dep = &pur;
            depPage(dep);
            break;
        }
        case 3:
        {
            std::cout << std::string(5, '\n');
            HumanRes human = HumanRes();
            dep = &human;
            depPage(dep);
            break;
        }
        case 4:
        {
            std::cout << std::string(5, '\n');
            Advertisement ad = Advertisement();
            dep = &ad;
            depPage(dep);
            break;
        }
        case 5:
        {
            std::cout << std::string(5, '\n');
            PUBLIC_RELATIONS pub = PUBLIC_RELATIONS();
            dep = &pub;
            depPage(dep);
            break;
        }
        case 6:
        {
            // Direk sirket istatistiklerinin gosterildigi yer
            std::cout << std::string(2, '\n');
            acc.showCompanyStats();
            std::cout << std::string(2, '\n');
            break;
        }
        case 7:
        {
            // Tum calisanlara odeme yapiliyor
            acc.paySalarys();
            break;
        }
        case 8:
        {
            // Exit ile uygulamadan direk cikiyor
            exit(0);
            break;
        }
        default:
        {
            // [1-7] arasinda olan numaralardan biri yazilmazsa hata mesaji
            // yaziliyor
            std::cout << "Invalid number\n";
            break;
        }
        }
    }
}

void depPage(Departments *dep)
{
    std::cout << "\n\n|    " << dep->getDepName() << " Page\n\n";
    int rate;
    while (true)
    {
        int m_answer;
        std::cout << "|    1 - Show employees\n";
        std::cout << "|    2 - Show department statics\n";
        std::cout << "|    3 - Increase all employee salarys\n";
        std::cout << "|    4 - Increase the title salarys\n";
        std::cout << "|    5 - Pay bonuses to all employees: \n";
        std::cout << "|    6 - Add employee\n";
        std::cout << "|    7 - Back to main menu\n";
        std::cout << "|    Enter the action number :";
        std::cin >> m_answer;
        switch (m_answer)
        {
        case 1:
        {
            // Calisanlari ve calisanlar uzerinde yapilacak islemlerin
            // oldugu sayfayi aciyor
            std::cout << std::string(3, '\n');
            showDepEmployees(dep);
            break;
        }
        case 2:
        {
            std::cout << std::string(3, '\n');
            acc.showDepartmentStats(dep);
            break;
        }
        case 3:
        {
            // Departmandaki tum calisanlarin maaslarini %n miktarda
            // arttiran kisim input alinip fonksiyon cagriliyor
            std::cout << std::string(3, '\n');
            std::cout << "|    Enter the increase rate (%) : ";
            std::cin >> rate;
            acc.increaseSpeDepSalary(dep, rate);
            break;
        }
        case 4:
        {
            // Secilen pozisyondaki tum calisanlarin maaslarina
            // zam yapan kisim input alarak pozisyon bilgisini
            // ve % artis miktarini alip muhasebe fonksiyonu
            // cagriliyor
            std::cout << std::string(3, '\n');
            int answer;
            std::string title;
            bool control = true;
            while (control)
            {
                std::cout << "|    1 - Manager\n";
                std::cout << "|    2 - Senior Worker\n";
                std::cout << "|    3 - Junior Worker\n";
                std::cout << "|    Enter the title id :";
                std::cin >> answer;
                switch (answer)
                {
                case 1:
                {
                    title = "Manager";
                    control = false;
                    break;
                }
                case 2:
                {
                    title ="Senior Worker";
                    control = false;
                    break;
                }
                case 3:
                {
                    title = "Junior Worker";
                    break;
                }
                default:
                {
                    std::cout << "Invalid number\n";
                    break;
                }
                }
            }
            std::cout << "|\n";
            std::cout << "|    Enter the increase rate (%) : ";
            std::cin >> rate;
            acc.increaseTitleSalary(dep, title, rate);
            break;
        }
        case 5:
        {
            // Ikramiye miktarini alip ilgili muhasebe fonksiyonunu
            // cagiriyoruz.
            double payment_amount;
            std::cout << "|    Enter the payment amount ($) :";
            std::cin >> payment_amount;
            acc.bonusPaymentToDepartments(dep, payment_amount);
        }
        case 6:
        {
            // Gecerli departmana calisan eklemek isteniyorsa
            // bu fonksiyon kullanilir
            addEmployee(dep);
        }

        case 7:
        {
            // Geri ana menuye gecmek icin 'ui' fonksiyonu calistiriliyor
            std::cout << std::string(3, '\n');
            ui();
            break;
        }
        default:
        {
            // [1-6] arasinda olan rakamlardan birisi girilirse
            // hata mesaji basilip dongu basina geri donuluyor
            std::cout << "|    Invalid number\n";
            break;
        }
        }
    }
}

void showDepEmployees(Departments *dep)
{
    // Departmandaki calisanlar gosteriliyor
    acc.showDepartmentsEmployees(dep->getDepId());
    std::cout << "\n\n";
    int answer;
    // Yapilacak islemlerin oldugu dongu
    while (true)
    {
        std::cout << "|    1 - Pay salary\n";
        std::cout << "|    2 - Increase salary \n";
        std::cout << "|    3 - Pay bonus payment\n";
        std::cout << "|    4 - Fire employee\n";
        std::cout << "|    5 - Back\n";
        std::cout << "|    Enter the action number :";
        std::cin >> answer;
        switch (answer)
        {
        case 1:
        {
            int id;
            std::cout << "|    Enter the employee's id: ";
            std::cin >> id;
            acc.paySalary(id);
            break;
        }
        case 2:
        {
            int emp_id;
            double rise_rate;
            std::cout << "|    Enter employee's id : ";
            std::cin >> emp_id;
            std::cout << "\n";
            std::cout << "|    Enter the rate of rise (%) :";
            std::cin >> rise_rate;
            if (acc.increaseSalary(emp_id, rise_rate))
                std::cout << "Process successfull\n";
            else
                std::cout << "Process not successfull\n";
            break;
        }
        case 3:
        {
            // Alinan calisan id'sine sahip calisana alinan miktar
            // kadar odeme yapiliyor.
            int emp_id;
            double payment_amount;
            std::cout << "Enter the employee's id :";
            std::cin >> emp_id;
            std::cout << "Enter the payment amount ($) :\n";
            std::cin >> payment_amount;
            if (acc.bonusPaymentToEmployee(emp_id, payment_amount))
                std::cout << "Process successfull\n";
            else
                std::cout << "Process not successfull\n";
            break;
        }
        case 4:
        {
            // Girilen id'ye sahip calisan isten cikariliyor
            int emp_id;
            std::cout << "Enter the employee id :";
            std::cin >> emp_id;
            if (acc.fireEmployee(emp_id))
                std::cout << "Process successfull\n";
            else
                std::cout << "Process not successfull\n";

            break;
        }
        case 5:
        {
            // Geri gitmek icin depPage sayfasi icinde bulundugumuz
            // departman'la cagiriliyor
            depPage(dep);
            break;
        }

        default:
            // [1-5] arasinda olan rakamlardan birisi girilirse
            // hata mesaji basilip dongu basina geri donuluyor
            std::cout << "|    Invalid number\n";
            break;
        }
    }
}

void addEmployee(Departments *dep)
{
    // Veri tabanina calisan bilgilerini eklemek icin
    // emp objesinin gerekli member'larini kullanicidan
    // alip set ediyoruz.
    Employee emp = Employee();
    // Person class'i icin gerekli bilgiler
    std::string name;
    std::string dob;
    std::string gender;
    std::string number;
    std::string address;
    std::string email;
    // Person bilgilerin alinmasi
    std::cout << "|    Enter the employee's name and last name : ";
    // TODO: std::getline kullanilacak
    std::cin >> name;
    std::cout << "\n";
    std::cout << "|    Enter the employee's date of birth : ";
    std::cin >> dob;
    std::cout << "\n";
    std::cout << "|    Enter the employee's gender:";
    std::cin >> gender;
    std::cout << "\n";
    std::cout << "|    Enter the employee's phone number:";
    std::cin >> number;
    std::cout << "\n";
    std::cout << "|    Enter the employee's email:";
    std::cin >> email;
    std::cout << "\n";
    std::cout << "|    Enter the employee's address:";
    // TODO: std::getline kullanilacak
    std::cin >> address;
    std::cout << "\n";
    // Bilgilerin set edilmesi
    emp.setName(name);
    emp.setDateOfBirth(dob);
    emp.setGender(gender);
    emp.setPhoneNumber(number);
    emp.setAddress(address);
    emp.setEmail(email);
    // Title class'i icin gerekli bilgiler
    double phc;
    double whpm;
    int t_ans;
    // Title bilgisinin alinmasi
    for (;;)
    {
        std::cout << "|    1 - Manager\n";
        std::cout << "|    2 - Senior Worker\n";
        std::cout << "|    3 - Junior Worker\n";
        std::cout << "|    Choose one of the job positions [1-3]: ";
        std::cin >> t_ans;
        if (t_ans == 1)
        {
            emp.setTitle("Manager");
            break;
        }
        else if (t_ans == 2)
        {
            emp.setTitle("Senior Worker");
            break;
        }
        else if (t_ans == 3)
        {
            emp.setTitle("Junior Worker");
            break;
        }
        else
        {
            std::cout << "Invalid key\n";
            continue;
        }
    }
    // Saatlik ucreti ve aylik toplam calisma saatinin alinmasi
    std::cout << "|    Enter the hourly wage the employee will receive:";
    std::cin >> phc;
    std::cout << "\n";
    std::cout << "|    Enter the employee's monthly working hours:";
    std::cin >> whpm;
    std::cout << "\n";
    // Saatlik ucretin ve aylik toplam calisma saatinin eklenmesi
    emp.setPerHourCost(phc);
    emp.setSumOfHoursM(whpm);
    // Eklenecegi departmanin id'sinin verilmesi
    emp.setDepartmentId(dep->getDepId());
    // Calisanin alacagi maasin set edilmesi
    emp.setSalary(emp.getPerHourCost() * emp.getSumOfHoursM());
    // Calisan database'e eklenir
    acc.addEmployee(emp);
}