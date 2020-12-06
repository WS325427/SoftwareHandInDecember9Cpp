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
    double _dHourlyPay;
public:
    int getID() { return _iEmployeeId; };
    void setID(int iEmployeeId) { _iEmployeeId = iEmployeeId; };
    string getName() { return _sFirstName + " " + _sLastName; };
    void setName(string sFirstName, string sLastName);
    string getDepartment() { return _sDepartment; };
    void setDepartment(string sDepartment) { _sDepartment = sDepartment; };
    string getJobGrade() { return _sJobGrade; };
    void setJobGrade(string sJobGrade) { _sJobGrade = sJobGrade; };
    double getHourlyPay() { return _dHourlyPay; };
    void setHourlyPay(double dHourlyPay) { _dHourlyPay = dHourlyPay; };
    void setClsEmployee(int iEmployeeId, string sFirstName, string sLastName, string sDepartment, string sJobGrade, double dHourlyPay);
};

void clsEmployee::setName(string sFirstName, string sLastName) {
    _sFirstName = sFirstName;
    _sLastName = sLastName;
};

void clsEmployee::setClsEmployee(int iEmployeeId, string sFirstName, string sLastName, string sDepartment, string sJobGrade, double dHourlyPay) {
    _iEmployeeId = iEmployeeId;
    _sFirstName = sFirstName;
    _sLastName = sLastName;
    _sDepartment = sDepartment;
    _sJobGrade = sJobGrade;
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

int main()
{
    cout << "Starting Program....\n";
    startupScreen();
};

void startupScreen() {
    cout << "Working";
};