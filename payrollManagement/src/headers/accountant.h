#ifndef ACCOUNTANT_H
#define ACCOUNTANT_H

#include "title.h"
#include "departments.h"
#include "employee.h"
class Accountant : public Title
{
private:
    // Zam yapma fonksiyonu
    // Zam yapilacak kisinin id'si ve %'de kac zam yapilacagini parametre olarak aliyor
    // Eger zam yapildiysa true yapilirken sikinti cikti ise false donuyor
    bool increaseSalary(int employee_id, double rate_of_rise);
    // Bir departmandaki herkesin maasina zam yapma
    // Parametre olarak zam yapilacak departmani ve % kac zam yapilacagini aliyor
    bool increaseSpeDepSalary(Department department, double rate_of_rise);
    // Sirketteki ayni isi yapanlara zam yapma fonksiyonu
    // Parametre olarak title pointer'i (JuniorWorker, SeniorWorker yollanacak) ve
    // zam orani alir.
    bool increaseTitleSalary(Title *title, double rate_of_rise);
    // Herkese zam yapma fonksiyonu
    // Zam oranini aliyor
    bool increaseAllSalarys(double rate_of_rise);
    // Sirketin odeyecegi vergilerin toplamini hesaplar
    // %8 KDV, %15 Yıllık gelir vergisi, %22 kurumlar vergisi
    double calcTaxes();
    // Sirketin toplam giderleri hesaplanir
    // Vergiler + Maaslar + Sigortalar (450 lira calisan basi sigorta odemesi)
    double calcTotalExpense();
    // Herkese ikramiye verme fonksiyonu
    // Verilecek ikramiye miktarini parametre olarak alir
    bool bonusPaymentToAll(double payment_amount);
    // Sadece bir calisana ikramiye verilecek ise kullanilacak ikramiye verme fonksiyonu
    // Calisanin id'si ver verilecek ikramiye miktarini parametre olarak alir
    bool bonusPaymentToEmployee(int employee_id, double payment_amount);
    // Bir departmana ikramiye vermek icin kullanilan fonksiyon
    // Ikramiye verilecek departman'i ve ikramiye miktarini parametre olarak alir
    bool bonusPaymentToDepartment(Department department, double payment_amount);
    // Ayni seviyede calisanlara ikramiye vermek icin kullanilan fonksiyon
    // Title pointer parametresi (JuniorWorker, SeniorWorker ...) ve ikramiye miktarini parametre olarak alir
    bool bonusPaymentToSameTitles(Title *title, double payment_amount);
    // Tum calisanlarin sigorta odemelerini yapan fonksiyon
    bool payEnsures();
    // Tum calisanlarin maas odemelerini yapan fonksiyon
    bool paySalarys();
    // Yeni bir calisan alindiysa sisteme giren fonksiyon
    // Parametre olarak ise girdigi departman ve kisisel bilgilerini aliyor
    bool addEmployee(Department target_department, Employee employee);
    // Calisani isten cikartmak icin kullanilan fonksiyon
    bool fireEmployee(int employee_id);
    // Departmanlari listeleyen fonksiyon
    void showDepartments();
    // Departmandaki calisanlari gosteren fonksiyon
    void showDepartmentEmployees();
    // Ayni seviyedeki calisanlari listeler
    void showSameTitleEmployees();
    // Sirketteki departmanlari departmanlarda calisan kisi sayisini
    // Departman giderlerini
    // Toplam vergi, sigorta, maas giderlerini gosterir.
    void showCompanyStats();

public:
    Accountant();
    ~Accountant();

    std::string getTitle() const override;
    double getSumOfHoursM() const override;
    double getPerHourCost() const override;
};

#endif