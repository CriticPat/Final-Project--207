//Patrick Acuña & Allyn Novel
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
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
    HourlyEmployee(char* n, char* l, int id, int dep, float baseSal, float rate, float overrate, int hours):Employee(n, l, id, dep, baseSal), hourlyRate(rate), overtimeRate(overrate), hourWorked(hours){}
    float calculateGrossSalary() override{
        float OverTimeHours = (hourWorked>40)?(hourlyRate-40): 0; //Calulates overtime hours
        float RegularHours= (hourWorked<=40)?(hourWorked): 40;//Calulated regular hours
        return (hourlyRate*RegularHours)+(overtimeRate*OverTimeHours);
    }
    float calculateNetSalary() override{
        float grossSal= calculateGrossSalary();
        return grossSal -calculateTax(grossSal);
    }
};

//Commission Emloyee Class derived from employee
class CommissionEmployee: public Employee{
    private: 
        float commissionRate, salesAmount; 
    public: 
    CommissionEmployee(char* n, char* l, int id, int dep, float baseSal, float sales, float rate): Employee(n, l ,id, dep, baseSal), salesAmount(sales), commissionRate(rate){}
    float calculateGrossSalary() override{
        return baseSalary + (salesAmount*commissionRate);
    }
    float calculateNetSalary() override{
        float grossSal= calculateGrossSalary();
        return grossSal - calculateTax(grossSal);
    }
};

//Payroll class
class Payroll{
    private: 
        char companyName[20];
        list<Employee*> employees; //Using list to store employees object
    public:
    Payroll(const char*cname){
        strcpy(companyName,cname);
    }
    void addEmployee(Employee*employee){//Creates a variable pointer, employee, to the Employee object
        employees.push_back(employee);//Pushes the object to the employee list
    }
    void calculateAllSalaries(){
        int totalEmployees=0;
        float totalGrossSalaries=0;
        float totalNetSalaries=0;
        for (Employee* employee : employees) {
            totalEmployees++;
            totalGrossSalaries += employee->calculateGrossSalary();
            totalNetSalaries += employee->calculateNetSalary();//Add the Gross Salary calculated at each object
        }
    cout << "Total number of employees: " << totalEmployees << endl;
    cout << "Sum of gross salaries: " << totalGrossSalaries << endl;
    }
    void displayAllEmployees(){
        for(Employee*employee: employees){//for each employee, dislpayInfo() will be used
            employee->displayInfo();
            cout<<"=========================="<<endl;
        }
    }
    void totalAnnualPayRollCost(){
        float AnnualPayroll= 0;
        for(Employee*employee: employees){
            AnnualPayroll += employee->calculateGrossSalary() * 12; // For each caluclateGrossSalary()its going to multiply by 12 and added to AnnualPayRoll
        }
    }
};
class AnnualPerformanceBonus: public SalariedEmployee, CommissionEmployee, HourlyEmployee{
    private:
        //have no clue how to do thi
    public:
};
int main(){
    Payroll myPayroll("Tech Innovations");
    return 0; 
}
