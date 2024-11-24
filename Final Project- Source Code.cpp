//Patrick Acuña & Allyn Novel
#include <iostream>
#include <cstring>
#include <list>
using namespace std;

//Base class containing Employee methods and attributes
class Employee{
    protected:
        char firstname[15];
        char lastname[15];
        int employeeID;
        string department;
        float baseSalary;
    public:
        friend class Payroll;
        Employee(char* n, char* l, int id, string dep, float baseSal){
            strcpy(firstname, n);
            strcpy(lastname, l);
            employeeID= id;
            department= dep;
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
            cout<<"Department: "<<department<<endl;
        };//displaying info of the Employee Class
        float calculateTax(float grossSal){
            if(grossSal<=3000){
                return grossSal*0.10; 
            }else if(grossSal<=7000){
                return grossSal*0.20;
            }else if(grossSal>7000){
                return grossSal*0.30;
            }
            return 0.0f;
        }//Calculating gross Salary

};
//Inherited Class containing its attributes and methods/attributes from Employee Class. 
class SalariedEmployee: public Employee{
    private:
        float monthlysalary; 
        float annualBonus;
    public:
    SalariedEmployee(char* n, char* l, int id, string dep, float baseSal, float monthSal, float bonus): Employee(n, l, id, dep, baseSal),monthlysalary(monthSal), annualBonus(bonus){}
    float calculateGrossSalary() override{ 
        return monthlysalary + (annualBonus / 12);
    } 
    float calculateNetSalary() override{
        float grossSal= calculateGrossSalary();
        return grossSal -calculateTax(grossSal);
    }
    void displayInfo() override{
        Employee::displayInfo();
        cout<<"Gross Salary: "<<calculateGrossSalary()<<endl;
        cout<<"Net Salary: "<<calculateNetSalary()<<endl;
    }
};

//Hourly Employee Class 
class HourlyEmployee: public Employee{
    private:
        float hourlyRate, overtimeRate; 
        int hourWorked; 
    public: 
    HourlyEmployee(char* n, char* l, int id, string dep, float baseSal, float rate, float overrate, int hours):Employee(n, l, id, dep, baseSal), hourlyRate(rate), overtimeRate(overrate), hourWorked(hours){}
    float calculateGrossSalary() override{
        float OverTimeHours =(hourWorked > 40)?(hourWorked-40):0;//Calulates overtime hours
        float RegularHours= (hourWorked<=40)?(hourWorked): 40;//Calulated regular hours
        return (hourlyRate*RegularHours)+(overtimeRate*OverTimeHours);
    }
    float calculateNetSalary() override{
        float grossSal= calculateGrossSalary();
        return grossSal -calculateTax(grossSal);
    }
    void displayInfo() override{
        Employee::displayInfo();
        cout<<"Hourly Rate: "<<hourlyRate<<endl;
        cout<<"Hours worked: "<<hourWorked<<endl;
        cout<<"Gross Salary: "<<calculateGrossSalary()<<endl;
        cout<<"Net Salary: "<<calculateNetSalary()<<endl;
    }
};

//Commission Emloyee Class derived from employee
class CommissionEmployee: public Employee{
    private: 
        float commissionRate, salesAmount; 
    public: 
    CommissionEmployee(char* n, char* l, int id, string dep, float baseSal, float sales, float rate): Employee(n, l ,id, dep, baseSal), salesAmount(sales), commissionRate(rate){}
    float calculateGrossSalary() override{
        return baseSalary + (salesAmount*commissionRate);
    }
    float calculateNetSalary() override{
        float grossSal= calculateGrossSalary();
        return grossSal - calculateTax(grossSal);
    }
    void displayInfo() override{
        Employee::displayInfo();
        cout<<"Commission Rate: "<<commissionRate<<endl;
        cout<<"Sales amount: "<<salesAmount<<endl;
        cout<<"Gross Salary: "<<calculateGrossSalary()<<endl;
        cout<<"Net Salary: "<<calculateNetSalary()<<endl;
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
    int totalEmployees = 0;
    float totalGrossSalaries = 0;
    float totalNetSalaries = 0;
    for (Employee* employee : employees) {
        totalEmployees++;
        totalGrossSalaries += employee->calculateGrossSalary();
        totalNetSalaries += employee->calculateNetSalary(); 
    }
    cout << "Total number of employees: " << totalEmployees << endl;
    cout << "Sum of gross salaries: " << totalGrossSalaries << endl;
    cout << "Sum of net salaries: " << totalNetSalaries << endl;
    }
    void displayAllEmployees(){
        for(Employee*employee: employees){//for each employee, dislpayInfo() will be used
            cout<<"=========================="<<endl;
            employee->displayInfo();
            cout<<"=========================="<<endl;
        }
    }
    void totalAnnualPayRollCost(){
    float AnnualPayroll = 0;
    for(Employee* employee : employees){
        AnnualPayroll += employee->calculateGrossSalary() * 12; 
    }
    cout << "Total Annual Payroll Cost: " << AnnualPayroll << endl;
    }
    void menu(){
        int choice=0; 
        cout<<"Welcome to the "<<companyName<<" payroll system \n";
        do{
            cout<<"-----------------------------------------------"<<endl;
            cout<<"1. Create Employee\n"
                "2. Calculate Salaries\n"
                "3. Display all Employees\n"
                "4. Total Annual Payroll cost\n" 
                "5. Exit"<<endl;
            cout<<"Choose functions to operate: ";
            cin>>choice;
            switch (choice) {
                case 1: {
                    int type;
                    cout<<"-----------------------------------------------"<<endl;
                    cout<<"1. Salaried Employee\n"
                        "2. Hourly Employee\n"
                        "3. Commission Employee\n";
                    cout<<"Choose type of employee: ";
                    cin>>type;
                    cout<<"-----------------------------------------------"<<endl; 
                    char f[15], l[15]; 
                    int id;
                    string dep;
                    float baseSal = 0; // Initialize baseSal
                    cout<<"Enter First Name: ";
                    cin>>f; 
                    cout<<"Enter Last Name: ";
                    cin>>l;
                    cout<<"Enter department: ";
                    cin>>dep;
                    cout<<"Enter Employee ID: ";
                    cin>>id;
                    if(type==1){
                        float monthSal, bonus;
                        cout<<"Enter monthly salary: ";
                        cin>>monthSal;
                        cout<<"Enter Bonus: ";
                        cin>>bonus;
                        addEmployee(new SalariedEmployee(f, l, id, dep, baseSal, monthSal, bonus));
                    }else if(type==2){
                        float rate, overrate;
                        int hours; 
                        cout<<"Enter hours: ";
                        cin>>hours;
                        cout<<"Enter hourly rate: ";
                        cin>>rate;
                        overrate = rate*1.5; 
                        cout<<"Overtime rate: "<<overrate<<endl; 
                        addEmployee(new HourlyEmployee(f, l, id, dep, baseSal, rate, overrate, hours));

                    }else if(type==3){
                        int sales;
                        float rate; 
                        cout<<"Enter amount of sales: ";
                        cin>>sales;
                        cout<<"Enter sales rate: ";
                        cin>>rate; 
                        cout<<"Enter base salary: ";
                        cin>>baseSal;
                        addEmployee(new CommissionEmployee(f, l, id, dep, baseSal, sales, rate));
                    } else {
                        cout << "Invalid employee type." << endl;
                    }}
                    break;
                case 2:
                    calculateAllSalaries();
                    break;
                case 3:
                    displayAllEmployees();
                    break;
                case 4:
                    totalAnnualPayRollCost();
                    break;
                case 5:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout<<"Invalid option!"<<endl;
                    break;
            }
        } while (choice!=5);
    }
};
int main(){
    Payroll myPayroll("CoP Tech Advancements");
    myPayroll.menu(); 
    return 0; 
}