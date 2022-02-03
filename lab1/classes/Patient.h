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
    Patient(){
        lastName=lastVisit=visitTime="";
    };
    Patient(int id,string lastName, string lastVisit, string visitTime){
        this->id = id;
        this->lastName = lastName;
        this->lastVisit = lastVisit;
        this->visitTime = visitTime;
    }
    int getId(){
        return id;
    }
    string getLastName(){
        return lastName;
    }
    string getLastVisit(){
        return lastVisit;
    }
    string getVisitTime(){
        return visitTime;
    }
    void setId(int id){
        this->id = id;
    }
    void setLastName(string name){
        this->lastName = name;
    }
    void setLastVisit(string visit){
        this->lastVisit = visit;
    }
    void setTime(string time){
        this->visitTime = time;
    }
    void printPatient(){
        cout<<id<<"|"<<lastName<<"|"<<lastVisit<<"|"<<visitTime<<endl;
    }
};


