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
