//
// Created by Tincho on 24-May-17.
//

#ifndef TPC_PERSON_H
#define TPC_PERSON_H
#include "Material.h"
#include "Loan.h"

typedef struct person{
    int type;//if is 1 is student, if 0 teacher
    int dni;
    char* name;
    char* surname;
    char* email;
    int phoneNumber;
    int booksTaken;
    double debt;

    Loan** loans;
    int amountOfLoans;
    int maxCapacityOfLoans;

}Person;

Person* createStudent(int dni, char *name, char *surname, char *email, int phoneNumber);
Person* createTeacher(int dni, char *name, char *surname, char *email, int phoneNumber);

void printLessPerson(Person* person);
void printPerson(Person* person);
void destroyPerson(Person* person);

void takeMaterial(Loan* newLoan, Person* person);
int returnMaterial(int numberOfLoan, Person* person);

#endif //TPC_PERSON_H
