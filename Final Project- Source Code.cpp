//Patrick Acuña & Allyn Novel
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
//Base class containing Employee methods and attributes
class Employee{
    protected:
        char firstname[15];
        char lastname[15];
        int employeeID;
        vector<string> department = {"Humanity", "Business", "IT", "Maintenance"};
        float baseSalary;
    public:
        Employee();
        virtual void calculateGrossSalary();//function type can be changed
        virtual void calculateNetSalarry(); //function type can be changed
        virtual void displayInfo();//function type can be changed
        void calculateTax();//function type can be changed

};
//Inherited Class containing its attributes and methods/attributes from Employee Class. 
class SalariedEmployee: public Employee{
    private:
        float monthlysalary; 
        float annualsalary;
    public:
};
class HourlyEmployee: public Employee{
    private:
        float hourlyRate, overtimeRate; 
        int hourWorked; 
    public: 
};
class CommissionEmployee: public Employee{
    private: 
        int salesAmount;
        float commissionRate, baseSalary; 
    public: 
};
class Payroll: public Employee{
    private: 
        char companyName[20];//more attributes can be added
    public:

};
class AnnualPerformanceBonus: public SalariedEmployee, CommissionEmployee, HourlyEmployee{
    private:
        //have no clue how to do this
    public:
};
class TaxCalculationSystem{

};
int main(){
    return 0; 
}
