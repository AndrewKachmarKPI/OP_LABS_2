////
//// Created by kachm on 07.02.2022.
////
//
//#include "PatientEntity.h"
//
//void PatientEntity::printData() {
//    cout << "Patient:{" + to_string(this->id) + "," + to_string(lastVisitDay) + "," + to_string(visitHour) + "}"
//         << endl;
//}
//
//
//int PatientEntity::getId() const {
//    return id;
//}
//
//void PatientEntity::setId(int id) {
//    PatientEntity::id = id;
//}
//
//
//int PatientEntity::getLastVisitDate() const {
//    return lastVisitDay;
//}
//
//void PatientEntity::setLastVisitDate(int lastVisitDay) {
//    PatientEntity::lastVisitDay = lastVisitDay;
//}
//
//int PatientEntity::getLastVisitMonth() const {
//    return lastVisitMonth;
//}
//
//void PatientEntity::setLastVisitMonth(int lastVisitMonth) {
//    PatientEntity::lastVisitMonth = lastVisitMonth;
//}
//
//int PatientEntity::getVisitTime() const {
//    return visitHour;
//}
//
//void PatientEntity::setVisitTime(int visitHour) {
//    PatientEntity::visitHour = visitHour;
//}
//
//int PatientEntity::getVisitMinutes() const {
//    return visitMinutes;
//}
//
//void PatientEntity::setVisitMinutes(int visitMinutes) {
//    PatientEntity::visitMinutes = visitMinutes;
//}
//
//PatientEntity::PatientEntity() {
//
//}
//
//PatientEntity::PatientEntity(int id, const string &lastName, int lastVisitDay, int lastVisitMonth, int visitHour,
//                             int visitMinutes) : id(id), lastName(lastName), lastVisitDay(lastVisitDay),
//                                                 lastVisitMonth(lastVisitMonth), visitHour(visitHour),
//                                                 visitMinutes(visitMinutes) {}
//
//const string &PatientEntity::getLastName() const {
//    return lastName;
//}
//
//void PatientEntity::setLastName(const string &lastName) {
//    PatientEntity::lastName = lastName;
//}
//
////const char *PatientEntity::getLastName() const {
////    return lastName;
////}
//
//
