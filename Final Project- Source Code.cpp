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
        vector<string> departments = {"Humanity", "Business", "IT", "Maintenance"};
        string employeeDepartment;
        float baseSalary;
    public:
        Employee(char* n, char* l, int id, int dep, float baseSal){
            strcpy(firstname, n);
            strcpy(lastname, l);
            employeeID= id;
            employeeDepartment= departments[dep];
            baseSalary= baseSal;
        }
        virtual float calculateGrossSalary(){
            float grossSal= baseSalary;
            return grossSal;
        };//function type can be changed
        virtual float calculateNetSalary(){
            float netSal= baseSalary;
            return netSal;
        }; //

        virtual void displayInfo(){
            cout<<"Name: "<<firstname<<" "<<lastname<<endl;
            cout<<"ID: "<<employeeID<<endl;
            cout<<"Department: "<<employeeDepartment<<endl;
            cout<<"Gross Salary: "<<calculateGrossSalary()<<endl;
            cout<<"Net Salary: "<<calculateNetSalary()<<endl;
        };//displaying info ogf the Employee Class

        float calculateTax(float grossSal){
            if(grossSal<=3000){
                return grossSal*0.10; 
            }else if(grossSal<=7000){
                return grossSal*0.20;
            }else if(grossSal>7000){
                return grossSal*0.30;
            }
        };//Calculating gross Salary

};
//Inherited Class containing its attributes and methods/attributes from Employee Class. 
class SalariedEmployee: public Employee{
    private:
        float monthlysalary; 
        float annualBonus;
    public:
    SalariedEmployee(char* n, char* l, int id, int dep, float baseSal, float monthSal, float bonus): Employee(n, l, id, dep, baseSal),monthlysalary(monthSal), annualBonus(bonus){}
    float calculateGrossSalary() override{ 
        return monthlysalary + (annualBonus / 12);
    } 
    float calculateNetSalary() override{
        float grossSal= calculateGrossSalary();
        return grossSal -calculateTax(grossSal);
    }
};

//Hourly Employee Class 
class HourlyEmployee: public Employee{
    private:
        float hourlyRate, overtimeRate; 
        int hourWorked; 
    public: 
    HourlyEmployee()
};

//Commission Emloyee Class derived from employee
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
    Payroll myPayroll("Tech Innovations");

    // Adding employees
    myPayroll.addEmployee(Employee("Alice", 5000)); // Salaried employee
    myPayroll.addEmployee(Employee("Bob", 20, 160)); // Hourly employee (20/hour for 160 hours)
    myPayroll.addEmployee(Employee("Charlie", 0.10, 10000)); // Commission-based employee (10% commission on $10,000 sales)

    // Display all employees and calculate salaries
    myPayroll.displayAllEmployees();
    myPayroll.calculateAllSalaries();

    // Calculate total annual payroll cost
    double totalCost = myPayroll.totalAnnualPayrollCost();
    std::cout << "Total Annual Payroll Cost: $" << std::fixed << std::setprecision(2) << totalCost << "\n";
    return 0; 
}
