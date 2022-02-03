#include "Patient.h"

Patient::Patient(){
    id=0;
    lastName=lastVisit=visitTime="";
};
Patient::Patient(int id,string lastName, string lastVisit, string visitTime){
    this->id = id;
    this->lastName = lastName;
    this->lastVisit = lastVisit;
    this->visitTime = visitTime;
}
int Patient::getId(){
    return this->id;
}
string Patient::getLastName(){
    return lastName;
}
string Patient::getLastVisit(){
    return lastVisit;
}
string Patient::getVisitTime(){
    return visitTime;
}
void Patient::setId(int id){
    this->id = id;
}
void Patient::setLastName(string name){
    this->lastName = name;
}
void Patient::setLastVisit(string visit){
    this->lastVisit = visit;
}
void Patient::setTime(string time){
    this->visitTime = time;
}
void Patient::printPatient(){
    cout<<"Patient (id="+to_string(id)+",lastName="+lastName+",lastVisit="+lastVisit+", visitTime="+visitTime+")";
}