#include <iostream>
#include <conio.h>
#include <string.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

class clsEmployee {
protected:
    int _iEmployeeId;
    std::string _sFirstName;
    std::string _sLastName;
    std::string _sDepartment;
    std::string _sJobGrade;
    std::string _sAssignedProject;
    double _dHourlyPay;
    double _dHoursPerWeek;
    int _iWeeksPerYear;
public:
    int getID() { return _iEmployeeId; };
    void setID(int iEmployeeId) { _iEmployeeId = iEmployeeId; };
    std::string getName() { return _sFirstName + " " + _sLastName; };
    void setName(std::string sFirstName, std::string sLastName);
    std::string getFirstName() { return _sFirstName; };
    void setFirstName(std::string sFirstName) {_sFirstName = sFirstName; };
    std::string getLastName() { return _sLastName; };
    void setLastName(std::string sLastName) { _sLastName = sLastName; };
    std::string getDepartment() { return _sDepartment; };
    void setDepartment(std::string sDepartment) { _sDepartment = sDepartment; };
    std::string getJobGrade() { return _sJobGrade; };
    void setJobGrade(std::string sJobGrade) { _sJobGrade = sJobGrade; };
    std::string getAssignedProject() { return _sAssignedProject; };
    void setAssignedProject(std::string sAssignedProject) { _sAssignedProject = sAssignedProject; };
    double getHourlyPay() { return _dHourlyPay; };
    void setHourlyPay(double dHourlyPay) { _dHourlyPay = dHourlyPay; };
    void setClsEmployee(int iEmployeeId, std::string sFirstName, std::string sLastName, std::string sDepartment, std::string sJobGrade,std::string sAssignedProject, double dHourlyPay);
    void setClsEmployee(int iEmployeeId, std::string sFirstName, std::string sLastName, std::string sDepartment, std::string sJobGrade, std::string sAssignedProject, double dHourlyPay, double dHoursPerWeek, int iWeeksPerYear);
    double getHoursPerWeek() { return _dHoursPerWeek; };
    int getWeeksPerYear() { return _iWeeksPerYear; };
};

void clsEmployee::setName(std::string sFirstName, std::string sLastName) {
    _sFirstName = sFirstName;
    _sLastName = sLastName;
};

void clsEmployee::setClsEmployee(int iEmployeeId, std::string sFirstName, std::string sLastName, std::string sJobGrade, std::string sDepartment,  std::string sAssignedProject, double dHourlyPay) {
    _iEmployeeId = iEmployeeId;
    _sFirstName = sFirstName;
    _sLastName = sLastName;
    _sDepartment = sDepartment;
    _sJobGrade = sJobGrade;
    _sAssignedProject = sAssignedProject;
    _dHourlyPay = dHourlyPay;
}
void clsEmployee::setClsEmployee(int iEmployeeId, std::string sFirstName, std::string sLastName, std::string sJobGrade, std::string sDepartment, std::string sAssignedProject, double dHourlyPay, double dHoursPerWeek, int iWeeksPerYear) {
    _iEmployeeId = iEmployeeId;
    _sFirstName = sFirstName;
    _sLastName = sLastName;
    _sDepartment = sDepartment;
    _sJobGrade = sJobGrade;
    _sAssignedProject = sAssignedProject;
    _dHourlyPay = dHourlyPay;
    _dHoursPerWeek = dHoursPerWeek;
    _iWeeksPerYear = iWeeksPerYear;
}

class clsSalariedEmployee : public clsEmployee {
private:
    double _dBonus;
    double _dSalary;
    double _dHoursPerWeek = 40.0;
    int _iWeeksPerYear = 52;
public:
    void setBonus(double dBonus) { _dBonus = dBonus; };
    double getBonus() { return _dBonus; };
    void setSalary(double dSalary) { _dSalary = dSalary; };
    double getSalary() { return _dSalary; };
    double calculateBonus(double dSalary);
    double calculateHourlyPay(double dSalary);
    int getWeeksPerYear() { return _iWeeksPerYear; };
    double getHoursPerWeek() { return _dHoursPerWeek; };
    double calculateSalary(double dHourlyPay, double dHoursPerWeek, int iWeeksPerYear);
};

double clsSalariedEmployee::calculateSalary(double dHourlyPay, double dHoursPerWeek, int iWeeksPerYear) {
    return dHourlyPay * dHoursPerWeek * iWeeksPerYear;
}
class clsContractEmployee : public clsEmployee {
private:
    double _dTotalPay;
public:
    void setTotalPay(double dTotalPay) { _dTotalPay = dTotalPay; };
    double getTotalPay() { return _dTotalPay; };
    void setHoursPerWeek(double dHoursPerWeek) { _dHoursPerWeek = dHoursPerWeek; };
    double getHoursPerWeek() { return _dHoursPerWeek; };
    void setWeekPerYear(int iWeeksPerYear) { _iWeeksPerYear = iWeeksPerYear; };
    int getWeeksPerYear() { return _iWeeksPerYear; };
    double calculateTotalPay(double dHourlyPay, double dHoursPerWeek, int iWeeksPerYear);
};
double clsContractEmployee::calculateTotalPay(double dHourlyPay, double dHoursPerWeek, int iWeeksPerYear) {
    return dHourlyPay * dHoursPerWeek * iWeeksPerYear;
}
class clsProject {
private:
    std::string _sProjectName;
    int _iProjectDurationDays;
    double _dProjectFee;
    std::string _sProjectStatus;
public:
    void setProjectName(std::string sProjectName) { _sProjectName = sProjectName; };
    std::string getProjectName() { return _sProjectName; };
    void setProjectDurationDays(int iProjectDurationDays) { _iProjectDurationDays = iProjectDurationDays; };
    int getProjectDurationDays() { return _iProjectDurationDays; };
    void setProjectFee(double dProjectFee) { _dProjectFee = dProjectFee; };
    double getProjectFee() { return _dProjectFee; };
    void setProjectStatus(std::string sProjectStatus) { _sProjectStatus = sProjectStatus; };
    std::string getProjectStatus() { return _sProjectStatus; };
    void setClsProject(std::string sProjectName, int iProjectDurationDays, double dProjectFee, std::string sProjectStatus);
};

void clsProject::setClsProject(std::string sProjectName, int iProjectDurationDays, double dProjectFee, std::string sProjectStatus) {
    _sProjectName = sProjectName;
    _iProjectDurationDays = iProjectDurationDays;
    _dProjectFee = dProjectFee;
    _sProjectStatus = sProjectStatus;
}
/// <prototypes>

void startupScreen();
void startupScreenUserSelection(int* iUserChoice);
void clearScreen();
int updateUserChoice(int* iUserChoice);
void viewFullStaffList();
std::vector <clsEmployee> readEmployeeCSV();
std::vector <clsSalariedEmployee> filteredSalariedEmployeesCSV();
std::vector <clsContractEmployee> filteredContractedEmployeesCSV();
void updateStaffListMenu();
void updateStaffListChoice(int *iUserChoice);
void breakdownEmployeeCosts();
void viewProjectDetails();
std::vector <clsProject> readProjectCSV();
void updateProjectDetails();
void addStaffConfirmation();
void collectStaffDetails();
void addToStaffCSV(std::vector <clsSalariedEmployee> clsAddSalariedEmployee);
void addToStaffCSV(std::vector <clsContractEmployee> clsAddContractEmployee);
void overwriteToStaffCSV(std::vector <clsEmployee> vClsAddEmployee);
void removeStaff();
std::string inputMatchingProjectName(std::vector <clsProject> vClsProjectData);
void updateStaffDetails();
void exitProgram();
void FILL();

/// </prototypes>
int main()
{
    clearScreen();
    std::cout << "Starting Program....\n";
    std::cout << "This program should help you ogranise your project fee a bit better!\n";
    std::cout << "Press any button to continue\n";
    _getch();
    startupScreen();
};

int updateUserChoice(int* iUserChoice) {
    //Allows for positive integers only to be returned
    int iOption;
    std::cin >> iOption;
    //be careful with !std::cin?
    while (!std::cin || iOption < 0)
    {
        std::cout << "Invalid Integer, Try Again!\n ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> iOption;
    }
    *iUserChoice = iOption;
    return *iUserChoice;
}
void startupScreen() {
    clearScreen();
    int iUserChoice;
    std::cout << "Welcome to the Project Management Menu\nWhat would you like to do?\n";
    std::cout << "   1)  View Full Staff on Project List\n";
    std::cout << "   2)	Update Staff List\n";
    std::cout << "   3)	Total Cost and Breakdown Costs of Company \n";
    std::cout << "   4)	View Projects details\n";
    std::cout << "   5)	Update Projects\n";
    std::cout << "   6)	Exit Program\n";
    std::cout << "Enter Choice Number: ";
    updateUserChoice(&iUserChoice);
    startupScreenUserSelection(&iUserChoice);
};

void startupScreenUserSelection(int *iUserChoice) {
    switch (*iUserChoice) {
    case 1:
        viewFullStaffList();
        break;
    case 2:
        updateStaffListMenu();
        break;
    case 3:
        breakdownEmployeeCosts();
        break;
    case 4:
        viewProjectDetails();
        break;
    case 5:
        updateProjectDetails();
        break;
    case 6:
        exitProgram();
        break;
    default:
        std::cout << "\nError Inputs, Please try again\n";
        std::cout << "\nRe-enter your Option:";
        int iUserChoice = 0;
        updateUserChoice(&iUserChoice);
        startupScreenUserSelection(&iUserChoice);
        break;
    };
};
void viewFullStaffList() {
    std::vector <clsEmployee> vClsEmployee = readEmployeeCSV();
   // for (int i = 0; i < vClsEmployee.size(); i++) 
    // i = 1;         vs              i = 1;
    // j = ++i;                      j = i++;
    // (i is 2, j is 2)             (i is 2, j is 1)
    clearScreen();
    std::cout << "This is the details of Staff currrently in the system" << std::endl;
    std::cout << "(best viewed on a larger screen)" << std::endl;
    //supposedly a faster version of looping
        for (size_t i = 0, ilen = vClsEmployee.size(); i < ilen; ++i) {
                std::cout << "Employee ID: " << vClsEmployee[i].getID() << "\t";
                std::cout << "First Name: " << vClsEmployee[i].getFirstName() << "\t";
                std::cout << "Last Name: " << vClsEmployee[i].getLastName() << "\t";
                std::cout << "Job Grade: " << vClsEmployee[i].getJobGrade() << "\t";
                std::cout << "Project: " << vClsEmployee[i].getAssignedProject() << "\t";
                std::cout << std::fixed << std::setprecision(2) << "Hourly Pay: " << char(156) << vClsEmployee[i].getHourlyPay() << "\n";
    }
        // nts, formatting could do work, maybe force a max character limit and always hit it to keep things spaced evenly
    std::cout << "The total number of staff employed on Project: " << vClsEmployee.size()<< " people" << std::endl;
    std::cout << "\nPress any button to return to Project Management Screen";
    _getch();
    startupScreen();
};

std::vector <clsEmployee> readEmployeeCSV() {
    std::ifstream employeeData;
    std::vector <clsEmployee> vClsEmployee;
    int iCount=0;
    std::string sEmployeeId, sFirstName, sLastName, sGrade, sDepartment, sProject, sHourlyPay, sHoursPerWeek, sWeeksPerYear;
    employeeData.open("employeeData.csv");

    while (getline(employeeData, sEmployeeId, ',')) {
        getline(employeeData, sFirstName, ',');
        getline(employeeData, sLastName, ',');
        getline(employeeData, sGrade, ',');
        getline(employeeData, sDepartment, ',');
        getline(employeeData, sProject, ',');
        getline(employeeData, sHourlyPay, ',');
        getline(employeeData, sHoursPerWeek, ',');
        getline(employeeData, sWeeksPerYear, '\n');
        vClsEmployee.push_back(clsEmployee());
        vClsEmployee[iCount].setClsEmployee(stoi(sEmployeeId), sFirstName, sLastName, sGrade, sDepartment, sProject, stod(sHourlyPay), stod(sHoursPerWeek), stoi(sWeeksPerYear));
        iCount++;
    };
    employeeData.close();
    return vClsEmployee;
}

std::vector <clsSalariedEmployee> filteredSalariedEmployeesCSV() {
    std::vector <clsEmployee> vClsEmployee;
    std::vector <clsSalariedEmployee> vClsSalariedEmployees;
    vClsEmployee = readEmployeeCSV();
    int iSalariedEmployeeCount = 0;

    for (size_t i = 0, ilen = vClsEmployee.size(); i < ilen; ++i) {
        if (vClsEmployee[i].getJobGrade() == "Junior" || vClsEmployee[i].getJobGrade() == "Senior") {
            vClsSalariedEmployees.push_back(clsSalariedEmployee());
            //copy parent class to child class to access its functions, Note to self look into pointing methods
            //maybe better to just not have subclasses in this set up
            vClsSalariedEmployees[iSalariedEmployeeCount].setClsEmployee(vClsEmployee[i].getID(), vClsEmployee[i].getFirstName(), vClsEmployee[i].getLastName(), vClsEmployee[i].getJobGrade(), vClsEmployee[i].getDepartment(), vClsEmployee[i].getAssignedProject(), vClsEmployee[i].getHourlyPay(), vClsEmployee[i].getHoursPerWeek(), vClsEmployee[i].getWeeksPerYear());
            iSalariedEmployeeCount++;
        }
    };
    return vClsSalariedEmployees;
};
std::vector <clsContractEmployee> filteredContractedEmployeesCSV() {
    std::vector <clsEmployee> vClsEmployee;
    std::vector <clsContractEmployee> vClsContractEmployees;
    vClsEmployee = readEmployeeCSV();
    int iContractedEmployeeCount = 0;

    for (size_t i = 0, ilen = vClsEmployee.size(); i < ilen; ++i) {
        if (vClsEmployee[i].getJobGrade() == "Contracted"){
            vClsContractEmployees.push_back(clsContractEmployee());
            //copy parent class to child class to access its functions, Note to self look into pointing methods
            vClsContractEmployees[iContractedEmployeeCount].setClsEmployee(vClsEmployee[i].getID(), vClsEmployee[i].getFirstName(), vClsEmployee[i].getLastName(), vClsEmployee[i].getJobGrade(), vClsEmployee[i].getDepartment(), vClsEmployee[i].getAssignedProject(), vClsEmployee[i].getHourlyPay(), vClsEmployee[i].getHoursPerWeek(), vClsEmployee[i].getWeeksPerYear());
            iContractedEmployeeCount++;
        };
    };
    return vClsContractEmployees;
};


void updateStaffListMenu() {
    clearScreen();
    int iUserChoice;
    std::cout << "Welcome to Staff List Update Menu\nWhat would you like to do?\n";
    std::cout << "   1)  Add Staff\n";
    std::cout << "   2)	Remove Staff\n";
    std::cout << "   3)	Update Staff Detail \n";
    std::cout << "   4)	Return to Project Management Menu\n";
    std::cout << "Enter Choice Number: ";
    updateUserChoice(&iUserChoice);
    updateStaffListChoice(&iUserChoice);
};

void updateStaffListChoice(int *iUserChoice) {
    switch (*iUserChoice) {
    case 1:
        addStaffConfirmation();
        break;
    case 2:
        removeStaff();
        break;
    case 3:
        updateStaffDetails();
        break;
    case 4:
        startupScreen();
        break;
    default:
        std::cout << "\nError Inputs, Please try again\n";
        std::cout << "\nRe-enter your Option:";
        int iUserChoice = 0;
        updateUserChoice(&iUserChoice);
        updateStaffListChoice(&iUserChoice);
        break;
    };
};
void addStaffConfirmation() {
    clearScreen();
    std::cout << "You are about to add a new staff member!\n";
    std::cout << "This requires the following information...\n";
    std::cout << "   6 digit Staff ID\n";
    std::cout << "   First Name\n";
    std::cout << "   Last Name\n";
    std::cout << "   Job Grade\n";
    std::cout << "   Department\n";
    std::cout << "   Hourly Pay\n";
    std::cout << "Continue? 1) Yes   2) No   (select number)\n";

    int iUserChoice;
    switch (updateUserChoice(&iUserChoice))
    {
    case 1:
        collectStaffDetails();
        break;
    case 2:
        std::cout << "Returning back to the Project Management Menu";
        startupScreen();
        break;
    default:
        std::cout << "\nError Inputs, Please try again\n";
        addStaffConfirmation();
    };
};

//NEED TO CLEAN UP THIS FUNCTION
void collectStaffDetails() {
    std::vector <clsSalariedEmployee> clsAddSalariedEmployee;
    std::vector <clsContractEmployee> clsAddContractEmployee;
    std::vector <clsProject> vClsProjectData = readProjectCSV();
    int iEmployeeId, iUserChoice, iWeeksPerYear;
    std::string sFirstName, sLastName,sDepartment,sJobGrade,sAssignedProject ="non-project";
    double dHourlyPay, dHoursPerWeek;
    bool bFoundMatch = false;
    std::cout << "Enter 6 Digit ID: ";
    std::cin >> iEmployeeId;
    std::cout << "Enter First Name: ";
    std::cin >> sFirstName;
    std::cout << "Enter Last Name: ";
    std::cin >> sLastName;

    std::cout << "Choose Department\n";
    std::cout << "   1) Research\n";
    std::cout << "   2) Developer\n";
    std::cout << "   3) Analyst\n";
    std::cout << "   4) Marketing\n";
    std::cout << "   5) Other \n";
    std::cout << "Choice: ";
    switch (updateUserChoice(&iUserChoice))
    {
    case 1:
        sDepartment = "Research";
        break;
    case 2:
        sDepartment = "Developer";
        break;
    case 3:
        sDepartment = "Analyst";
        break;
    case 4:
        sDepartment = "Marketing";
        break;
    case 5:
        sDepartment = "Other";
        break;
    default:
        std::cout << "\nError Inputs, Please try again\n";
        collectStaffDetails();
        break;
    }

    std::cout << "Choose Job Grade\n";
    std::cout << "   1) Junior\n";
    std::cout << "   2) Senior\n";
    std::cout << "   3) Contracted\n";
    std::cout << "Choice: ";
    switch (updateUserChoice(&iUserChoice))
    {
    case 1:
        sJobGrade = "Junior";
        break;
    case 2:
        sJobGrade = "Senior";
        break;
    case 3:
        sJobGrade = "Contracted";
        std::cout << "\nHow many hours per week?(max 20): ";
        std::cin >> dHoursPerWeek;
        std::cout << "\nHow many weeks per year?(max30): ";
        std::cin >> iWeeksPerYear;
        break;
    default:
        std::cout << "\nError Inputs, Please try again\n";
        collectStaffDetails();
        break;
    }
    std::cout << "Enter hourly pay: "<<char(156);
    std::cin >> dHourlyPay;

    std::cout << "Would you like to add this employee on a project now?\n";
    std::cout << "   Press 1 to Assign, else press a button to continue...\n";
    switch (updateUserChoice(&iUserChoice))
    {
    case 1:
        sAssignedProject = inputMatchingProjectName(vClsProjectData);
        break;
    default:
        break;
    }


    if (sJobGrade == "Senior" || sJobGrade == "Junior") {
        clsAddSalariedEmployee.push_back(clsSalariedEmployee());
        clsAddSalariedEmployee[0].setClsEmployee(iEmployeeId, sFirstName, sLastName, sJobGrade, sDepartment, sAssignedProject, dHourlyPay);
        clearScreen();

        std::cout << "6 digit Staff ID: " << clsAddSalariedEmployee[0].getID() << "\n";
        std::cout << "Name: " << clsAddSalariedEmployee[0].getName() << "\n";
        std::cout << "Job Grade: " << clsAddSalariedEmployee[0].getJobGrade() << "\n";
        std::cout << "Department: " << clsAddSalariedEmployee[0].getDepartment() << "\n";
        std::cout << std::fixed << std::setprecision(2) << "Hourly Pay: " << char(156) << clsAddSalariedEmployee[0].getHourlyPay() << "\n";
    }
    else if (sJobGrade == "Contracted") {
        clsAddContractEmployee.push_back(clsContractEmployee());
        clsAddContractEmployee[0].setClsEmployee(iEmployeeId, sFirstName, sLastName, sJobGrade, sDepartment, sAssignedProject, dHourlyPay);
        clsAddContractEmployee[0].setHoursPerWeek(dHoursPerWeek);
        clsAddContractEmployee[0].setWeekPerYear(iWeeksPerYear);
        clearScreen();
        std::cout << "6 digit Staff ID: " << clsAddContractEmployee[0].getID() << "\n";
        std::cout << "Name: " << clsAddContractEmployee[0].getName() << "\n";
        std::cout << "Job Grade: " << clsAddContractEmployee[0].getJobGrade() << "\n";
        std::cout << "Department: " << clsAddContractEmployee[0].getDepartment() << "\n";
        std::cout << std::fixed << std::setprecision(2) << "Hourly Pay: " << char(156) << clsAddContractEmployee[0].getHourlyPay() <<"\n";
        std::cout << "Hours Per Week: " << clsAddContractEmployee[0].getHoursPerWeek() << "\n";
        std::cout << "Weeks Per Year: " << clsAddContractEmployee[0].getWeeksPerYear() << "\n";
    };
    if (sAssignedProject != "non-project") {
        std::cout << "Assigned Project to " << sAssignedProject << "\n";
    }
    else {
        std::cout << "No assigned project!  Please update when you can in Staff Update Details\n";
    }
    std::cout << "\nConfirm Details:  1) Yes   2) Cancel(return to Project Management Screen) (select number)\n";
    switch (updateUserChoice(&iUserChoice))
    {
    case 1:
        if (sJobGrade == "Senior" || sJobGrade == "Junior") {
            addToStaffCSV(clsAddSalariedEmployee);
        }
        else if (sJobGrade == "Contracted") {
            addToStaffCSV(clsAddContractEmployee);
        }
        break;
    case 2:
        std::cout << "Returning back to the Project Management Menu";
        startupScreen();
        break;
    default:
        std::cout << "\nError Inputs, Please try again\n";
        collectStaffDetails();
    };
};

//repeated for different intake of staff grade
void addToStaffCSV(std::vector <clsSalariedEmployee> clsAddSalariedEmployee) {
    std::ofstream employeeData;

    employeeData.open("employeeData.csv", std::ios::app);
    for (size_t i = 0, ilen = clsAddSalariedEmployee.size(); i < ilen; ++i) {
        employeeData << clsAddSalariedEmployee[i].getID() << "," << clsAddSalariedEmployee[i].getFirstName() << "," << clsAddSalariedEmployee[i].getLastName() << "," << clsAddSalariedEmployee[i].getJobGrade() << "," << clsAddSalariedEmployee[i].getDepartment() << "," << clsAddSalariedEmployee[i].getAssignedProject() << "," << clsAddSalariedEmployee[i].getHourlyPay() << "," << clsAddSalariedEmployee[i].getHoursPerWeek() << "," << clsAddSalariedEmployee[i].getWeeksPerYear() << std::endl;
    }
    employeeData.close();
    std::cout << "\nSUCCESSFUL\n";
    std::cout << "\nPress any button to continue";
    _getch();
    startupScreen();
};

void addToStaffCSV(std::vector <clsContractEmployee> clsAddContractEmployee) {
    std::ofstream employeeData;

    employeeData.open("employeeData.csv", std::ios::app);
    for (size_t i = 0, ilen = clsAddContractEmployee.size(); i < ilen; ++i) {
        employeeData << clsAddContractEmployee[i].getID() << "," << clsAddContractEmployee[i].getFirstName() << "," << clsAddContractEmployee[i].getLastName() << "," << clsAddContractEmployee[i].getJobGrade() << "," << clsAddContractEmployee[i].getDepartment() << "," << clsAddContractEmployee[i].getAssignedProject() << "," << clsAddContractEmployee[i].getHourlyPay() << "," << clsAddContractEmployee[i].getHoursPerWeek() << "," << clsAddContractEmployee[i].getWeeksPerYear() << std::endl;
    }
    employeeData.close();
    std::cout << "\nSUCCESSFUL\n";
    std::cout << "\nPress any button to continue";
    _getch();
    startupScreen();
};

void overwriteToStaffCSV(std::vector <clsEmployee> vClsAddEmployee) {
    std::ofstream employeeData;

    employeeData.open("employeeData.csv");
    for (size_t i = 0, ilen = vClsAddEmployee.size(); i < ilen; ++i) {
        employeeData << vClsAddEmployee[i].getID() << "," << vClsAddEmployee[i].getFirstName() << "," << vClsAddEmployee[i].getLastName() << "," << vClsAddEmployee[i].getJobGrade() << "," << vClsAddEmployee[i].getDepartment() << "," << vClsAddEmployee[i].getAssignedProject() << "," << vClsAddEmployee[i].getHourlyPay() << "," << vClsAddEmployee[i].getHoursPerWeek() << "," << vClsAddEmployee[i].getWeeksPerYear() << std::endl;
    }
    employeeData.close();
    std::cout << "\nSUCCESSFUL\n";
    std::cout << "\nPress any button to continue";
    _getch();
    startupScreen();
};

void removeStaff() {
    FILL();
};

std::string inputMatchingProjectName(std::vector <clsProject> vClsProjectData) {
    bool bFoundMatch = false;
    std::string sAssignedProjectInput;
    std::cout << "Current Projects Available:\n";
    for (size_t i = 0, ilen = vClsProjectData.size(); i < ilen; ++i) {
        std::cout << i + 1 << ") " << vClsProjectData[i].getProjectName() << "\n";
    }
    std::cout << "Please type the assigned project(case sensitive)\n";
    std::cin >> sAssignedProjectInput;
    for (size_t i = 0, ilen = vClsProjectData.size(); i < ilen; ++i) {
        if (sAssignedProjectInput == vClsProjectData[i].getProjectName()) {
            bFoundMatch = true;
            std::cout << "Succesfully Found Project  Click a button to continue\n";
            _getch();
            break;
        };
    }
    if (!bFoundMatch)
    {
        std::cout << "No matching project name.  Will now default to non-project.  Click a button to continue\n";
        sAssignedProjectInput = "non-project";
        _getch();
    }
    return sAssignedProjectInput;
}
void updateStaffDetails() {
    std::vector <clsEmployee> vClsEmployeeData = readEmployeeCSV();
    std::vector <clsProject> vClsProjectData = readProjectCSV();
    int iStaffId, iUserChoice;
    double dUpdatedHourlyPay;
    bool bFoundMatch = false, bUpdatedData = false;
    std::string sAssignedProjectInput;
    std::cout << "Please Enter the 6-digit ID of the staff you'd like to udpate: ";
    std::cin >> iStaffId;
    std::cout << "\nSearching........\n";
    for (size_t i = 0, ilen = vClsEmployeeData.size(); i < ilen; ++i) {
        if (vClsEmployeeData[i].getID() == iStaffId) {
            std::cout << "\n\n\Found!\n";
            bFoundMatch = true;
            std::cout << "Employee ID: " << vClsEmployeeData[i].getID() << "\n";
            std::cout << "First Name: " << vClsEmployeeData[i].getFirstName() << "\n";
            std::cout << "Last Name: " << vClsEmployeeData[i].getLastName() << "\n";
            std::cout << "Job Grade: " << vClsEmployeeData[i].getJobGrade() << "\n";
            std::cout << "Project: " << vClsEmployeeData[i].getAssignedProject() << "\n";
            std::cout << std::fixed << std::setprecision(2) << "Hourly Pay: " << char(156) << vClsEmployeeData[i].getHourlyPay() << "\n";
            std::cout << "Press a button to continue...";
            _getch();
            std::cout << "\n\n\nWhat would you like to update?\n";
            std::cout << "1) Project\n";
            std::cout << "2) Hourly Pay\n";
            switch (updateUserChoice(&iUserChoice))
            {
            case 1:
                sAssignedProjectInput = inputMatchingProjectName(vClsProjectData);
                vClsEmployeeData[i].setAssignedProject(sAssignedProjectInput);
                bUpdatedData = true;
                break;
            case 2:
                std::cout << "Please enter a new hourly pay: " << char(156);
                std::cin >> dUpdatedHourlyPay;
                vClsEmployeeData[i].setHourlyPay(dUpdatedHourlyPay);
                bUpdatedData = true;
                break;
            default:
                std::cout << "Not a valid option... will now return to Update Menu Staff.  Press a button to continue.";
                _getch();
                updateStaffListMenu();
                break;
            }
            if(bUpdatedData) {
                overwriteToStaffCSV(vClsEmployeeData);
                std::cout << "Update Successful!  Returning to Staff Uppdate Menu.  Press a button to continue";
                updateStaffListMenu();
                break;
            }
            _getch();
        }
    }
    if (!bFoundMatch) {
        std::cout << "No matching staff. Returning to Update Staff Menu.  Press a button to continue\n";
        _getch();
        updateStaffListMenu();
    }

};




//priority outpts requirements
void breakdownEmployeeCosts() {
    std::vector <clsContractEmployee> vClsContractEmployeesData = filteredContractedEmployeesCSV();
    std::vector <clsSalariedEmployee> vClsSalariedEmployeesData = filteredSalariedEmployeesCSV();
    std::vector <clsProject>  vClsProjectData = readProjectCSV();
    double dAllEmployeeSalary = 0, dSeniorSalary = 0, dJuniorSalary = 0, dContractedWages = 0, dProjectFeeGenerated=0;
    //- Total amount of salary to the senior staff
    //    - Total salary for the salaried staff
    //    - Total wages for the contract staff
    //    - Total payroll bill

    //salaried calculations
    for (size_t i = 0, ilen = vClsSalariedEmployeesData.size(); i < ilen; ++i) {
        dAllEmployeeSalary += vClsSalariedEmployeesData[i].calculateSalary(vClsSalariedEmployeesData[i].getHourlyPay(), vClsSalariedEmployeesData[i].getHoursPerWeek(), vClsSalariedEmployeesData[i].getWeeksPerYear());
        if (vClsSalariedEmployeesData[i].getJobGrade() == "Junior") {
            dJuniorSalary += vClsSalariedEmployeesData[i].calculateSalary(vClsSalariedEmployeesData[i].getHourlyPay(), vClsSalariedEmployeesData[i].getHoursPerWeek(), vClsSalariedEmployeesData[i].getWeeksPerYear());
        }
        if (vClsSalariedEmployeesData[i].getJobGrade() == "Senior") {
            dSeniorSalary+= vClsSalariedEmployeesData[i].calculateSalary(vClsSalariedEmployeesData[i].getHourlyPay(), vClsSalariedEmployeesData[i].getHoursPerWeek(), vClsSalariedEmployeesData[i].getWeeksPerYear());
        }
    };

    //contracted calculations
    for (size_t i = 0, ilen = vClsContractEmployeesData.size(); i < ilen; ++i) {
        dContractedWages += vClsContractEmployeesData[i].calculateTotalPay(vClsContractEmployeesData[i].getHourlyPay(), vClsContractEmployeesData[i].getHoursPerWeek(), vClsContractEmployeesData[i].getWeeksPerYear());
    };

    for (size_t i = 0, ilen = vClsProjectData.size(); i < ilen; ++i) {
        dProjectFeeGenerated += vClsProjectData[i].getProjectFee();
    };

    std::cout << std::fixed << std::setprecision(2) << "\n\nThe total cost of JUNIOR salaried employees per year: " << char(156) << dJuniorSalary;
    std::cout << std::fixed << std::setprecision(2) << "\nThe total cost of SENIOR salaried employees per year: " << char(156) << dSeniorSalary;
    std::cout << std::fixed << std::setprecision(2) << "\nThe total cost of ALL salaried employees per year: " << char(156) << dAllEmployeeSalary;
    std::cout << std::fixed << std::setprecision(2) << "\nThe total cost of CONTRACTED employees: " << char(156) << dContractedWages;
    std::cout << std::fixed << std::setprecision(2) << "\nThe total PAYROLL Bills per year: " << char(156) << dContractedWages + dAllEmployeeSalary;

    std::cout << std::fixed << std::setprecision(2) << "\nThe total Company Income from Open Projects: " << char(156) << dProjectFeeGenerated;

    std::cout << "\nPress anykey to continue";
    _getch();
    startupScreen();
};



void viewProjectDetails() {
    std::vector <clsProject> vClsProjectData = readProjectCSV();
    std::vector <clsSalariedEmployee> vClsSalariedEmployeeData = filteredSalariedEmployeesCSV();
    std::vector <clsContractEmployee> vClsContractedEmployeeData = filteredContractedEmployeesCSV();
    int iOpenProjectCount = 0, iClosedProjectCount = 0;
    double dDaysInYear = 365.0, dWorkDaysPerWeek = 5;
    //assume project duration is in work days
    clearScreen();
    std::cout << "This is the Project Details with fee available and cost from employees (vest viewed on large screen)\n\n";
    for (size_t i = 0, ilen = vClsProjectData.size(); i < ilen; ++i) {
        double dProjectCost = 0, dProjectCostOverBudgetMax, dProjectCostOverBudgetMin;
        int iNumberOfPeopleOnProject = 0;
        //need to calculate cost of salaried employees for project
        for (size_t j = 0, ilen = vClsSalariedEmployeeData.size(); j < ilen; ++j) {
            if (vClsSalariedEmployeeData[j].getAssignedProject() == vClsProjectData[i].getProjectName()) {
                //project cost = salary * projectduration(days)/days in year(365)
                dProjectCost += vClsSalariedEmployeeData[j].calculateSalary(vClsSalariedEmployeeData[j].getHourlyPay(), vClsSalariedEmployeeData[j].getHoursPerWeek(), vClsSalariedEmployeeData[j].getWeeksPerYear())*(vClsProjectData[i].getProjectDurationDays()/dDaysInYear);
                iNumberOfPeopleOnProject++;
            };
        };
        //need to calculate cost of contracted employees for project
        for (size_t j = 0, ilen = vClsContractedEmployeeData.size(); j < ilen; ++j) {
            if (vClsContractedEmployeeData[j].getAssignedProject() == vClsProjectData[i].getProjectName()) {
                //if the numbers of contracted weeks is longer than duration of project weeks, calculate the maximum time paid on project as the duration of the project instead
                if (vClsContractedEmployeeData[j].getWeeksPerYear() > vClsProjectData[i].getProjectDurationDays()/dWorkDaysPerWeek) {
                    vClsContractedEmployeeData[j].setWeekPerYear(vClsProjectData[i].getProjectDurationDays() / dWorkDaysPerWeek);
                };
                dProjectCost += vClsContractedEmployeeData[j].calculateTotalPay(vClsContractedEmployeeData[j].getHourlyPay(), vClsContractedEmployeeData[j].getHoursPerWeek(), vClsContractedEmployeeData[j].getWeeksPerYear());
                iNumberOfPeopleOnProject++;
            };
        };
        dProjectCostOverBudgetMax = dProjectCost * 1.35;
        dProjectCostOverBudgetMin = dProjectCost * 1.1;

        //std::fixed prevents scientific notation and set precision to 2 decimal places
        std::cout << "Project Name: " << vClsProjectData[i].getProjectName() << "\t";
        std::cout << "Project Duration(Days): " << vClsProjectData[i].getProjectDurationDays()<< "\t";
        std::cout << std::fixed << std::setprecision(2) << "Project Fee: " << char(156) << vClsProjectData[i].getProjectFee() << "\t";
        std::cout << "Project Status: " << vClsProjectData[i].getProjectStatus() << "\t";
        std::cout << std::fixed << std::setprecision(2) << "Project Cost: " << char(156) << dProjectCost<<"\t";
        std::cout << std::fixed << std::setprecision(2) << "OverBudget Cost 10%: " << char(156) << dProjectCostOverBudgetMin << "\t";
        std::cout << std::fixed << std::setprecision(2) << "OverBudget Cost 35%: " << char(156) << dProjectCostOverBudgetMax << "\n";
        std::cout << "Number of people on the project: " << iNumberOfPeopleOnProject << "\n";
        std::cout << std::fixed << std::setprecision(2) << "Remaining Project Budget (10%): " << char(156) << vClsProjectData[i].getProjectFee() - dProjectCostOverBudgetMin << "\n";
        std::cout <<std::fixed<<std::setprecision(2)<< "Remaining Project Budget (35%): " << char(156) << vClsProjectData[i].getProjectFee() - dProjectCostOverBudgetMax<< "\n\n";

        if (vClsProjectData[i].getProjectStatus() == "open") {
            iOpenProjectCount++;
        }
        if (vClsProjectData[i].getProjectStatus() == "closed") {
            iClosedProjectCount++;
        }
    }
        std::cout << "The total number projects ongoing: " << iOpenProjectCount << " projects" << std::endl;
        std::cout << "The total number projects closed: " << iClosedProjectCount << " projects" << std::endl;

    std::cout << "\nPress any button to return to Project Management Screen";
    _getch();
    startupScreen();
};
std::vector <clsProject> readProjectCSV() {
    std::ifstream projectData;
    std::vector <clsProject> vClsProjectData;
    std::string sProjectName, sProjectDurationDays, sProjectFee, sProjectStatus;
    int i = 0;
    projectData.open("projectData.csv");
    if (projectData.is_open())
    {
        while (getline(projectData, sProjectName, ','))
        {
            getline(projectData, sProjectDurationDays, ',');
            getline(projectData, sProjectFee, ',');
            getline(projectData, sProjectStatus, '\n');
            vClsProjectData.push_back(clsProject());
            vClsProjectData[i].setClsProject(sProjectName, stoi(sProjectDurationDays), stod(sProjectFee), sProjectStatus);
            i++;
        };
    }
    projectData.close();
    return vClsProjectData;
};


void updateProjectDetails() {
    FILL();
};
void exitProgram() {
    std::cout << "Thank you for using this program!\nExiting....";
    return;
};

void clearScreen(){//Allows for console screen to be cleared when moving to new screens
    std::cout << std::string(100, '\n');
}

void FILL(){//PLACEHOLDERS
    std::cout << "\n\nThis feature is not yet implemented! Will now return to Project Management Menu!";
    std::cout << "\nPress Any button to continue!";
    _getch();
    startupScreen();
}