#include <iostream>
#include <conio.h>
#include <vector>
#include <string.h>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class clsEmployee {
protected:
    int _iEmployeeId;
    string _sFirstName;
    string _sLastName;
    string _sDepartment;
    string _sJobGrade;
    string _sAssignedProject;
    double _dHourlyPay;
public:
    int getID() { return _iEmployeeId; };
    void setID(int iEmployeeId) { _iEmployeeId = iEmployeeId; };
    string getName() { return _sFirstName + " " + _sLastName; };
    void setName(string sFirstName, string sLastName);
    string getFirstName() { return _sFirstName; };
    void setFirstName(string sFirstName) {_sFirstName = sFirstName; };
    string getLastName() { return _sLastName; };
    void setLastName(string sLastName) { _sLastName = sLastName; };
    string getDepartment() { return _sDepartment; };
    void setDepartment(string sDepartment) { _sDepartment = sDepartment; };
    string getJobGrade() { return _sJobGrade; };
    void setJobGrade(string sJobGrade) { _sJobGrade = sJobGrade; };
    string getAssignedProject() { return _sAssignedProject; };
    void setAssignedProject(string sAssignedProject) { _sAssignedProject = sAssignedProject; };
    double getHourlyPay() { return _dHourlyPay; };
    void setHourlyPay(double dHourlyPay) { _dHourlyPay = dHourlyPay; };
    void setClsEmployee(int iEmployeeId, string sFirstName, string sLastName, string sDepartment, string sJobGrade,string sAssignedProject, double dHourlyPay);
};

void clsEmployee::setName(string sFirstName, string sLastName) {
    _sFirstName = sFirstName;
    _sLastName = sLastName;
};

void clsEmployee::setClsEmployee(int iEmployeeId, string sFirstName, string sLastName, string sDepartment, string sJobGrade, string sAssignedProject, double dHourlyPay) {
    _iEmployeeId = iEmployeeId;
    _sFirstName = sFirstName;
    _sLastName = sLastName;
    _sDepartment = sDepartment;
    _sJobGrade = sJobGrade;
    _sAssignedProject = sAssignedProject;
    _dHourlyPay = dHourlyPay;
}

class clsSalariedEmployee : public clsEmployee {
private:
    double _dBonus;
    double _dSalary;
public:
    void setBonus(double dBonus) { _dBonus = dBonus; };
    double getBonus() { return _dBonus; };
    void setSalary(double dSalary) { _dSalary = dSalary; };
    double getSalary() { return _dSalary; };
    double calculateBonus(double dSalary);
    double calculateHourlyPay(double dSalary);
};

class clsContractEmployee : public clsEmployee {
private:
    double _dTotalPay;
    double _dHoursPerWeek;
    int _iWeeksPerYear;
public:
    void setTotalPay(double dTotalPay) { _dTotalPay = dTotalPay; };
    double getTotalPay() { return _dTotalPay; };
    void setHoursPerWeek(double dHoursPerWeek) { _dHoursPerWeek = dHoursPerWeek; };
    double getHoursPerWeek() { return _dHoursPerWeek; };
    void setWeekPerYear(int iWeeksPerYear) { _iWeeksPerYear = iWeeksPerYear; };
    int getWeeksPerYear() { return _iWeeksPerYear; };
    double calculateTotalPay(double dHourlyPay, double dHoursPerWeek, int iWeeksPerYear);
};
class clsProject {
private:
    string _sProjectName;
    int _iProjectDurationDays;
    double _dProjectFee;
    string _sProjectStatus;
public:
    void setProjectName(string sProjectName) { _sProjectName = sProjectName; };
    string getProjectName() { return _sProjectName; };
    void setProjectDurationDays(int iProjectDurationDays) { _iProjectDurationDays = iProjectDurationDays; };
    int getProjectDurationDays() { return _iProjectDurationDays; };
    void setProjectFee(double dProjectFee) { _dProjectFee = dProjectFee; };
    double getProjectFee() { return _dProjectFee; };
    void setProjectStatus(string sProjectStatus) { _sProjectStatus = sProjectStatus; };
    string getProjectStatus() { return _sProjectStatus; };
};
void startupScreen();
void startupScreenUserSelection(int* iUserChoice);
void clearScreen();
int updateUserChoice(int* iUserChoice);
void viewFullStaffList();
void updateStaffListMenu();
void updateStaffListChoice(int *iUserChoice);
void breakdownEmployeeCosts();
void viewProjectDetails();
void updateProjectDetails();
void addStaffConfirmation();
void collectStaffDetails();
void addToStaffCSV(clsEmployee* clsAddEmployee);
void removeStaff();
void updateStaffDetails();
void exitProgram();
void FILL();

int main()
{
    clearScreen();
    cout << "Starting Program....\n";
    cout << "This program should help you ogranise your project fee a bit better!\n";
    cout << "Press any button to continue\n";
    _getch();
    startupScreen();
};

int updateUserChoice(int* iUserChoice) {
    //Allows for positive integers to be returned
    int iOption;
    cin >> iOption;
    while (!cin || iOption < 0)
    {
        cout << "Invalid Integer, Try Again!\n ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> iOption;
    }
    *iUserChoice = iOption;
    return *iUserChoice;
}
void startupScreen() {
    clearScreen();
    int iUserChoice;
    cout << "Welcome to the Project Management Menu\nWhat would you like to do?\n";
    cout << "   1)  View Full Staff on Project List\n";
    cout << "   2)	Update Staff List\n";
    cout << "   3)	Total Cost and Breakdown Costs of Employees \n";
    cout << "   4)	View Active Projects details\n";
    cout << "   5)	Update Projects\n";
    cout << "   6)	Exit Program\n";
    cout << "Enter Choice Number: ";
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
        cout << "\nError Inputs, Please try again\n";
        cout << "\nRe-enter your Option:";
        int iUserChoice = 0;
        updateUserChoice(&iUserChoice);
        startupScreenUserSelection(&iUserChoice);
        break;
    };
};
void viewFullStaffList() {
 //Logic for viewing registered employee list
    ifstream employeeData;
    string sEmployeeId, sFirstName, sLastName, sGrade, sDepartment, sProject, sHourlyPay;
    int iNumberOfStaff = 0;
    employeeData.open("employeeData.csv");
    if (employeeData.is_open())
    {
        clearScreen();
        cout << "This is a detailed list of the company employees\n(best viewed on wide screen)\n";
        while (getline(employeeData, sEmployeeId, ','))
        {
            cout << "Employee ID: " << sEmployeeId << "\t";
            getline(employeeData, sFirstName, ',');
            cout << "First Name: " << sFirstName << "\t";
            getline(employeeData, sLastName, ',');
            cout << "Last Name: " << sLastName << "\t";
            getline(employeeData, sGrade, ',');
            cout << "Job Grade: " << sGrade << "\t";
            getline(employeeData, sDepartment, ',');
            cout << "Department: " << sDepartment << "\t";
            getline(employeeData, sProject, ',');
            cout << "Project: " << sProject << "\t";
            getline(employeeData, sHourlyPay, '\n');
            cout << "Hourly Pay: " << char(156) << sHourlyPay << "\n";
            //cout << sEmployeeId << "\t" << sFirstName << "\t" << sLastName << "\t" << sGrade << "\t" << sDepartment << "\t" << sProject << "\t" << sHourlyPay << "\n";
            iNumberOfStaff++;
        };
        cout << "The total number of staff employed on Project: " << iNumberOfStaff << " people" << endl;
    }
    employeeData.close();
    cout << "\nPress any button to return to Project Management Screen";
    _getch();
    startupScreen();
};

void updateStaffListMenu() {
    clearScreen();
    int iUserChoice;
    cout << "Welcome to Staff List Update Menu\nWhat would you like to do?\n";
    cout << "   1)  Add Staff\n";
    cout << "   2)	Remove Staff\n";
    cout << "   3)	Update Staff Detail \n";
    cout << "   4)	Return to Project Management Menu\n";
    cout << "Enter Choice Number: ";
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
        cout << "\nError Inputs, Please try again\n";
        cout << "\nRe-enter your Option:";
        int iUserChoice = 0;
        updateUserChoice(&iUserChoice);
        updateStaffListChoice(&iUserChoice);
        break;
    };
};
void addStaffConfirmation() {
    clearScreen();
    cout << "You are about to add a new staff member!\n";
    cout << "This requires the following information...\n";
    cout << "   6 digit Staff ID\n";
    cout << "   First Name\n";
    cout << "   Last Name\n";
    cout << "   Job Grade\n";
    cout << "   Department\n";
    cout << "   Hourly Pay\n";
    cout << "Continue? 1) Yes   2) No   (select number)\n";

    int iUserChoice;
    cin >> iUserChoice;
    switch (iUserChoice)
    {
    case 1:
        collectStaffDetails();
        break;
    case 2:
        cout << "Returning back to the Project Management Menu";
        startupScreen();
        break;
    default:
        cout << "\nError Inputs, Please try again\n";
        addStaffConfirmation();
    };
};

//could turn to vector for multiple additions to csv at once if time
void collectStaffDetails() {
    clsEmployee clsAddEmployee;
    int iEmployeeId, iUserChoice;
    string sFirstName, sLastName,sDepartment,sJobGrade,sAssignedProject ="non-project";
    double _dHourlyPay;
    cout << "Enter 6 Digit ID: ";
    cin >> iEmployeeId;
    cout << "Enter First Name: ";
    cin >> sFirstName;
    cout << "Enter Last Name: ";
    cin >> sLastName;

    cout << "Choose Department\n";
    cout << "   1) Research\n";
    cout << "   2) Developer\n";
    cout << "   3) Analyst\n";
    cout << "   4) Marketing\n";
    cout << "   5) Other \n";
    cout << "Choice: ";
    cin >> iUserChoice;
    switch (iUserChoice)
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
    default:
        cout << "\nError Inputs, Please try again\n";
        collectStaffDetails();
        break;
    }

    cout << "Choose Job Grade\n";
    cout << "   1) Junior\n";
    cout << "   2) Senior\n";
    cout << "   3) Contracted\n";
    cout << "Choice: ";
    cin >> iUserChoice;
    switch (iUserChoice)
    {
    case 1:
        sJobGrade = "Junior";
        break;
    case 2:
        sJobGrade = "Senior";
        break;
    case 3:
        sJobGrade = "Contracted";
        break;
    default:
        cout << "\nError Inputs, Please try again\n";
        collectStaffDetails();
        break;
    }

    cout << "Enter hourly pay: "<<char(156);
    cin >> _dHourlyPay;
    clsAddEmployee.setClsEmployee(iEmployeeId, sFirstName, sLastName, sDepartment, sJobGrade, sAssignedProject, _dHourlyPay);
    clearScreen();
    cout << "6 digit Staff ID: "<<clsAddEmployee.getID()<<"\n";
    cout << "Name: "<<clsAddEmployee.getName()<<"\n";
    cout << "Job Grade: "<<clsAddEmployee.getJobGrade()<<"\n";
    cout << "Department: "<<clsAddEmployee.getDepartment()<<"\n";
    cout << "Assigned Project: "<<clsAddEmployee.getAssignedProject()<<"\n";
    cout << "Hourly Pay: " << char(156) <<clsAddEmployee.getHourlyPay(); "\n";
    cout << "\nConfirm Details:  1) Yes   2) Cancel(return to Project Management Screen) (select number)\n";
    cin >> iUserChoice;
    switch (iUserChoice)
    {
    case 1:
        addToStaffCSV(&clsAddEmployee);
        break;
    case 2:
        cout << "Returning back to the Project Management Menu";
        startupScreen();
        break;
    default:
        cout << "\nError Inputs, Please try again\n";
        collectStaffDetails();
    };
};
void addToStaffCSV(clsEmployee* clsAddEmployee) {
    ofstream employeeData;
    employeeData.open("employeeData.csv", ios::app);
    employeeData << clsAddEmployee->getID() << "," << clsAddEmployee->getFirstName() << "," << clsAddEmployee->getLastName() << "," << clsAddEmployee->getJobGrade() << "," << clsAddEmployee->getDepartment() << "," << clsAddEmployee->getAssignedProject() << "," << clsAddEmployee->getHourlyPay() << endl;
    employeeData.close();
    cout << "\nSUCCESSFUL\n";
    startupScreen();
};
void removeStaff() {
    FILL();
};
void updateStaffDetails() {
    FILL();
};
void breakdownEmployeeCosts() {
    FILL();
};
void viewProjectDetails() {

    ifstream projectData;
    string sProjectName, sProjectDurationDays, sProjectFee, sProjectStatus;
    int iNumberOfProjects = 0;
    projectData.open("projectData.csv");
    if (projectData.is_open())
    {
        while (getline(projectData, sProjectName, ','))
        {
            getline(projectData, sProjectDurationDays, ',');
            getline(projectData, sProjectFee, ',');
            getline(projectData, sProjectStatus, '\n');
            if (sProjectStatus == "open") {
                cout << "Project Name: " << sProjectName << "\t";
                cout << "Project Duration(Days): " << sProjectDurationDays << "\t";
                cout << "Project Fee: " << char(156) << sProjectFee << "\t";
                cout << "Project Status: " << sProjectStatus << "\n";
                iNumberOfProjects++;
            }
        };
        cout << "The total number projects ongoing: " << iNumberOfProjects << " people" << endl;
    }
    projectData.close();
    cout << "\nPress any button to return to Project Management Screen";
    _getch();
    startupScreen();
};

void updateProjectDetails() {
    FILL();
};
void exitProgram() {
    cout << "Thank you for using this program!\nExiting....";
    return;
};

void clearScreen(){//Allows for console screen to be cleared when moving to new screens
    cout << string(100, '\n');
}

void FILL(){//PLACEHOLDERS
    cout << "\n\nThis feature is not yet implemented! Will now return to Project Management Menu!";
    cout << "\nPress Any button to continue!";
    _getch();
    startupScreen();
}