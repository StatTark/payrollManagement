#ifndef ACCOUNTANT_H
#define ACCOUNTANT_H

#include "title.h"
#include "departments.h"
#include "employee.h"
#include "database.h"
class Accountant 
{
public:
    DatabaseWorker db = DatabaseWorker();
    // Zam yapma fonksiyonu
    // Zam yapilacak kisinin id'si ve %'de kac zam yapilacagini parametre olarak aliyor
    // Eger zam yapildiysa true yapilirken sikinti cikti ise false donuyor
    bool increaseSalary(int employee_id, double rate_of_rise);
    // Bir departmandaki herkesin maasina zam yapma
    // Parametre olarak zam yapilacak departmani ve % kac zam yapilacagini aliyor
    bool increaseSpeDepSalary(Departments *department, double rate_of_rise);
    // Sirketteki ayni isi yapanlara zam yapma fonksiyonu
    // Parametre olarak title pointer'i (JuniorWorker, SeniorWorker yollanacak) ve
    // zam orani alir.
    // TODO: departman parametresi eklenecek
    bool increaseTitleSalary(Departments *dep,std::string title, double rate_of_rise);
    // Herkese zam yapma fonksiyonu
    // Zam oranini aliyor
    bool increaseAllSalarys(double rate_of_rise);
    // Sirketin odeyecegi vergilerin toplamini hesaplar
    // %8 KDV, %15 Yıllık gelir vergisi, %22 kurumlar vergisi
    // double calcTaxes();
    // Sirketin toplam giderleri hesaplanir
    // Vergiler + Maaslar 
    double calcTotalExpense();
    // Herkese ikramiye verme fonksiyonu
    // Verilecek ikramiye miktarini parametre olarak alir
    bool bonusPaymentToAll(double payment_amount);
    // Sadece bir calisana ikramiye verilecek ise kullanilacak ikramiye verme fonksiyonu
    // Calisanin id'si ver verilecek ikramiye miktarini parametre olarak alir
    bool bonusPaymentToEmployee(int employee_id, double payment_amount);
    // Bir departmana ikramiye vermek icin kullanilan fonksiyon
    // Ikramiye verilecek departman'i ve ikramiye miktarini parametre olarak alir
    bool bonusPaymentToDepartments(Departments *department, double payment_amount);
    // Bir calisanin maasi odenir
    bool paySalary(int emp_id);
    // Tum calisanlarin maas odemelerini yapan fonksiyon
    bool paySalarys();
    // Yapilan gecmis odemeleri listeler
    void showPaymentLogs();
    // Yeni bir calisan alindiysa sisteme giren fonksiyon
    // Parametre olarak ise girdigi departman ve kisisel bilgilerini aliyor
    bool addEmployee(Employee &employee);
    // Calisani isten cikartmak icin kullanilan fonksiyon
    bool fireEmployee(int employee_id);
    // Departmanlari listeleyen fonksiyon
    void showDepartments();
    // Departmandaki calisanlari gosteren fonksiyon
    void showDepartmentsEmployees(int depID);
    // Ayni seviyedeki calisanlari listeler
    void showSameTitleEmployees(std::string title);
    // Departman istatistiklerini gosteren fonksiyon
    void showDepartmentStats(Departments *department);
    // Sirketteki departmanlari departmanlarda calisan kisi sayisini
    // Departman giderlerini
    // Toplam vergi ve maas giderlerini gosterir.
    void showCompanyStats();



    Accountant()=default;
};

#endif