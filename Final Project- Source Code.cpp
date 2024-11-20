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
        string employeeDepartment;
        float baseSalary;
    public:
        Employee(char* n, char* l, int id, int dep, float baseSal){
            strcpy(firstname, n);
            strcpy(lastname, l);
            employeeID= id;
            employeeDepartment= department[dep];
            baseSalary= baseSal;
        }
        virtual float calculateGrossSalary(){
            float grossSal= baseSalary;
            return grossSal;
        };//function type can be changed
        virtual float calculateNetSalarry(){
            float netSal= baseSalary;
            return netSal;
        }; //function type can be changed
        virtual void displayInfo(){
            cout<<"Name: "<<firstname<<" "<<lastname<<endl;
            cout<<"ID: "<<employeeID<<endl;
            cout<<"Department: "<<employeeDepartment<<endl;
            cout<<"Gross Salary: "<<calculateGrossSalary()<<endl;
            cout<<"Net Salary: "<<calculateNetSalarry()<<endl;
        };//function type can be changed
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
        //have no clue how to do thi
    public:
};
class TaxCalculationSystem{

};
int main(){
    return 0; 
}
