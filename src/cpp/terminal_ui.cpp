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
        std::cout << "|    7 - Quit\n";
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
    std::cout << "|    " << dep->getDepName() << " Page\n";
    int rate;
    while (true)
    {
        int answer;
        std::cout << "|    1 - Show employees\n";
        std::cout << "|    2 - Show department statics\n";
        std::cout << "|    3 - Increase all employee salarys\n";
        // TODO: Daha duzgun bir sey yazmak lazim
        std::cout << "|    4 - Increase the title salarys\n";
        std::cout << "|    5 - Add employee\n";
        std::cout << "|    6 - Back to main menu\n";
        std::cout << "|    Enter the action number :";
        std::cin >> answer;
        switch (answer)
        {
        case 1:
        {
            // Calisanlari ve calisanlar uzerinde yapilacak islemlerin
            // oldugu sayfayi aciyor
            std::cout << std::string(5, '\n');
            showDepEmployees(dep);
            break;
        }
        case 2:
        {
            // Departmanin istatistiklerini gosteren fonksiyon cagriliyor
            std::cout << std::string(5, '\n');
            // TODO: Fonksiyonu cpp file da tanimlamak lazim
            acc.showDepartmentStats(dep);
            break;
        }
        case 3:
        {
            // Departmandaki tum calisanlarin maaslarini %n miktarda
            // arttiran kisim input alinip fonksiyon cagriliyor
            std::cout << std::string(5, '\n');
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
            std::cout << std::string(5, '\n');
            int answer;
            Title *title;
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
                    title->setTitle("Manager");
                    control = false;
                    break;
                case 2:
                    title->setTitle("Senior Worker");
                    control = false;
                    break;
                case 3:
                    title->setTitle("Junior Worker");
                    control = false;
                    break;
                default:
                    std::cout << "Invalid number\n";
                    break;
                }
            }
            std::cout << "|\n";
            std::cout << "|    Enter the increase rate (%) : ";
            std::cin >> rate;
            acc.increaseTitleSalary(title, rate);
            break;
        }
        case 5:
        {
            // TODO: addemployee fonksiyonunun ici dolacak
            addEmployee();
        }

        case 6:
        {
            // Geri ana menuye gecmek icin 'ui' fonksiyonu calistiriliyor
            std::cout << std::string(5, '\n');
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
            // TODO: Maas odeme fonksiyonu adapte edilecek
            break;
        }
        case 2:
        {
            // TODO: Maas arttirma fonksiyonu adapte edilecek
            break;
        }
        case 3:
        {
            // Alinan calisan id'sine sahip calisana alinan miktar
            // kadar odeme yapiliyor.
            int emp_id;
            double payment_amount;
            std::cout << "Enter the employee id :";
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
// TODO: ici dolacak
void addEmployee(){}