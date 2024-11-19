//Patrick Acuña & Allyn Novelo 
#include <iostream>
#include <cstring>
using namespace std;
//Base class containing Employee methods and attributes
class Employee{
    protected:
        char firstname[15];
        char lastname[15];
        int employeeID;
        string department [10] = {"Humanity", "Business", "IT", "Maintenance"};
        float baseSalary;
    public:

};
//Inherited Class containing its attributes and methods/attributes from Employee Class. 
class SalariedEmployee: public Employee{
    private:
        float monthlysalary; 
        float annualsalary;
    public:
};
int main(){
    return 0; 
}
