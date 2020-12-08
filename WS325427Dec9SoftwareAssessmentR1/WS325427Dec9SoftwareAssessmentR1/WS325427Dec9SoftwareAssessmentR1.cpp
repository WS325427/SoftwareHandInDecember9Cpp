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
    double _dHoursPerWeek;
    int _iWeeksPerYear;
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
    void setClsEmployee(int iEmployeeId, string sFirstName, string sLastName, string sDepartment, string sJobGrade, string sAssignedProject, double dHourlyPay, double dHoursPerWeek, int iWeeksPerYear);
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
void clsEmployee::setClsEmployee(int iEmployeeId, string sFirstName, string sLastName, string sDepartment, string sJobGrade, string sAssignedProject, double dHourlyPay, double dHoursPerWeek, int iWeeksPerYear) {
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
    void setClsProject(string sProjectName, int iProjectDurationDays, double dProjectFee, string sProjectStatus);
};

void clsProject::setClsProject(string sProjectName, int iProjectDurationDays, double dProjectFee, string sProjectStatus) {
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
vector <clsEmployee> readEmployeeCSV();
void updateStaffListMenu();
void updateStaffListChoice(int *iUserChoice);
void breakdownEmployeeCosts();
void viewProjectDetails();
vector <clsProject> readProjectCSV();
void updateProjectDetails();
void addStaffConfirmation();
void collectStaffDetails();
void addToStaffCSV(clsSalariedEmployee* clsAddSalariedEmployee);
void addToStaffCSV(clsContractEmployee* clsAddEmployee);
void removeStaff();
void updateStaffDetails();
void exitProgram();
void FILL();

/// </prototypes>
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
    vector <clsEmployee> vClsEmployee = readEmployeeCSV();
   // for (int i = 0; i < vClsEmployee.size(); i++) 
    //supposedly a faster version of looping
    // i = 1;         vs              i = 1;
    // j = ++i;                      j = i++;
    // (i is 2, j is 2)             (i is 2, j is 1)
    clearScreen();
    cout << "This is the details of Staff currrently in the system" << endl;
    cout << "(best viewed on a larger screen)" << endl;
        for (size_t i = 0, ilen = vClsEmployee.size(); i < ilen; ++i) {
                cout << "Employee ID: " << vClsEmployee[i].getID() << "\t";
                cout << "First Name: " << vClsEmployee[i].getFirstName() << "\t";
                cout << "Last Name: " << vClsEmployee[i].getLastName() << "\t";
                cout << "Job Grade: " << vClsEmployee[i].getJobGrade() << "\t";
                cout << "Project: " << vClsEmployee[i].getAssignedProject() << "\t";
                cout << "Hourly Pay: " << char(156) << vClsEmployee[i].getHourlyPay() << "\n";
    }
    cout << "The total number of staff employed on Project: " << vClsEmployee.size()<< " people" << endl;
    cout << "\nPress any button to return to Project Management Screen";
    _getch();
    startupScreen();
};

vector <clsEmployee> readEmployeeCSV() {
    ifstream employeeData;
    vector <clsEmployee> vClsEmployee;
    int iCount=0;
    string sEmployeeId, sFirstName, sLastName, sGrade, sDepartment, sProject, sHourlyPay, sHoursPerWeek, sWeeksPerYear;
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
    clsSalariedEmployee clsAddSalariedEmployee;
    clsContractEmployee clsAddContractEmployee;
    int iEmployeeId, iUserChoice, iWeeksPerYear;
    string sFirstName, sLastName,sDepartment,sJobGrade,sAssignedProject ="non-project";
    double dHourlyPay, dHoursPerWeek;
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
        break;
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
        cout << "\nHow many hours per week?(max 20): ";
        cin >> dHoursPerWeek;
        cout << "\nHow many weeks per year?(max30): ";
        cin >> iWeeksPerYear;
        break;
    default:
        cout << "\nError Inputs, Please try again\n";
        collectStaffDetails();
        break;
    }

    cout << "Enter hourly pay: "<<char(156);
    cin >> dHourlyPay;
    if (sJobGrade == "Senior" || sJobGrade == "Junior") {
        clsAddSalariedEmployee.setClsEmployee(iEmployeeId, sFirstName, sLastName, sDepartment, sJobGrade, sAssignedProject, dHourlyPay);
        clearScreen();
        //could imporove by adding getDetails() if time;
        cout << "6 digit Staff ID: " << clsAddSalariedEmployee.getID() << "\n";
        cout << "Name: " << clsAddSalariedEmployee.getName() << "\n";
        cout << "Job Grade: " << clsAddSalariedEmployee.getJobGrade() << "\n";
        cout << "Department: " << clsAddSalariedEmployee.getDepartment() << "\n";
        cout << "Hourly Pay: " << char(156) << clsAddSalariedEmployee.getHourlyPay() << "\n";
    }
    else if (sJobGrade == "Contracted") {
        clsAddContractEmployee.setClsEmployee(iEmployeeId, sFirstName, sLastName, sDepartment, sJobGrade, sAssignedProject, dHourlyPay);
        clsAddContractEmployee.setHoursPerWeek(dHoursPerWeek);
        clsAddContractEmployee.setWeekPerYear(iWeeksPerYear);
        clearScreen();
        cout << "6 digit Staff ID: " << clsAddContractEmployee.getID() << "\n";
        cout << "Name: " << clsAddContractEmployee.getName() << "\n";
        cout << "Job Grade: " << clsAddContractEmployee.getJobGrade() << "\n";
        cout << "Department: " << clsAddContractEmployee.getDepartment() << "\n";
        cout << "Hourly Pay: " << char(156) << clsAddContractEmployee.getHourlyPay() <<"\n";
        cout << "Hours Per Week: " << clsAddContractEmployee.getHoursPerWeek() << "\n";
        cout << "Weeks Per Year: " << clsAddContractEmployee.getWeeksPerYear() << "\n";
    };

    cout << "\nConfirm Details:  1) Yes   2) Cancel(return to Project Management Screen) (select number)\n";
    cin >> iUserChoice;
    switch (iUserChoice)
    {
    case 1:
        if (sJobGrade == "Senior" || sJobGrade == "Junior") {
            addToStaffCSV(&clsAddSalariedEmployee);
        }
        else if (sJobGrade == "Contracted") {
            addToStaffCSV(&clsAddContractEmployee);
        }
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
void addToStaffCSV(clsSalariedEmployee* clsAddSalariedEmployee) {
    ofstream employeeData;
    employeeData.open("employeeData.csv", ios::app);
    employeeData << clsAddSalariedEmployee->getID() << "," << clsAddSalariedEmployee->getFirstName() << "," << clsAddSalariedEmployee->getLastName() << "," << clsAddSalariedEmployee->getJobGrade() << "," << clsAddSalariedEmployee->getDepartment() << "," << clsAddSalariedEmployee->getAssignedProject() << "," << clsAddSalariedEmployee->getHourlyPay() << "," << clsAddSalariedEmployee->getHoursPerWeek() << "," << clsAddSalariedEmployee->getWeeksPerYear() << endl;
    employeeData.close();
    cout << "\nSUCCESSFUL\n";
    startupScreen();
};

void addToStaffCSV(clsContractEmployee* clsAddContractEmployee) {
    ofstream employeeData;
    employeeData.open("employeeData.csv", ios::app);
    employeeData << clsAddContractEmployee->getID() << "," << clsAddContractEmployee->getFirstName() << "," << clsAddContractEmployee->getLastName() << "," << clsAddContractEmployee->getJobGrade() << "," << clsAddContractEmployee->getDepartment() << "," << clsAddContractEmployee->getAssignedProject() << "," << clsAddContractEmployee->getHourlyPay() << "," << clsAddContractEmployee->getHoursPerWeek() << "," << clsAddContractEmployee->getWeeksPerYear() << endl;
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

//priority outpts requirements
void breakdownEmployeeCosts() {
    vector <clsContractEmployee> vClsContractEmployees;
    vector <clsSalariedEmployee> vClsSalariedEmployees;
    FILL();
};

void viewProjectDetails() {
    vector <clsProject> vClsProjectData = readProjectCSV();
    int iOpenProjectCount = 0, iClosedProjectCount=0;
    for (size_t i = 0, ilen = vClsProjectData.size(); i < ilen; ++i) {
        cout << "Project Name: " << vClsProjectData[i].getProjectName() << "\t";
        cout << "Project Duration(Days): " << vClsProjectData[i].getProjectDurationDays()<< "\t";
        cout << "Project Fee: " << char(156) << vClsProjectData[i].getProjectFee() << "\t";
        cout << "Project Status: " << vClsProjectData[i].getProjectStatus() << "\n";
        if (vClsProjectData[i].getProjectStatus() == "open") {
            iOpenProjectCount++;
        }
        if (vClsProjectData[i].getProjectStatus() == "closed") {
            iClosedProjectCount++;
        }
    }
        cout << "The total number projects ongoing: " << iOpenProjectCount << " projects" << endl;
        cout << "The total number projects closed: " << iClosedProjectCount << " projects" << endl;

    cout << "\nPress any button to return to Project Management Screen";
    _getch();
    startupScreen();
};
vector <clsProject> readProjectCSV() {
    ifstream projectData;
    vector <clsProject> vClsProjectData;
    string sProjectName, sProjectDurationDays, sProjectFee, sProjectStatus;
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