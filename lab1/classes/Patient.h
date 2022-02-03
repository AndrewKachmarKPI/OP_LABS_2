#include <string>
#include <iostream>
using namespace std;
class Patient {
private:
    int id;
    string lastName;
    string lastVisit;
    string visitTime;
public:
    Patient();
    Patient(int id,string lastName, string lastVisit, string visitTime);
    int getId();
    string getLastName();
    string getLastVisit();
    string getVisitTime();
    void setId(int id);
    void setLastName(string name);
    void setLastVisit(string visit);
    void setTime(string time);
    void printPatient();
};


