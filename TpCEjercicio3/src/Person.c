
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "Person.h"

/*
 * Function: createStudent
 * Description: allocates memory for a Person and all its components.
 * Returns: Person pointer
 */
Person* createStudent(int dni, char *name, char *surname, char *email, int phoneNumber){
    Person* newPerson = malloc(sizeof(Person));

    newPerson->name = malloc(sizeof(char)*(strlen(name)+1));
    strcpy(newPerson->name,name);

    newPerson->dni = dni;

    newPerson->surname = malloc(sizeof(char)*(strlen(surname)+1));
    strcpy(newPerson->surname,surname);

    newPerson->email = malloc(sizeof(char)*(strlen(email)+1));
    strcpy(newPerson->email,email);

    newPerson->phoneNumber = phoneNumber;

    newPerson->booksTaken = 0;
    newPerson->debt = 0;
    newPerson->type = 1;
    newPerson->amountOfLoans = 0;
    newPerson->maxCapacityOfLoans = 10;

    return newPerson;
}

void printLessPerson(Person* person){
    if (person->type == 1){
        printf("----- Student -----");
    } else{
        printf("----- Teacher -----");
    }
    printf("Name: %s %s \n", person->name, person->surname);
    printf("Dni: %d \n", person->dni);
};

void printPerson(Person* person){
    if (person->type == 1){
        printf("----- Student -----");
    } else{
        printf("----- Teacher -----");
    }
    printf("Name: %s \n", person->name);
    printf("Surname: %s \n", person->surname);
    printf("Dni: %d \n", person->dni);
    printf("Email: %s \n", person->email);
    printf("Phone number: %d \n", person->phoneNumber);
    printf("Books taken: %d \n", person->booksTaken);
    printf("Amount of loans: %d \n", person->amountOfLoans);
    printf("Debt: %f \n", person->debt);
};

/*
 * Function: createTeacher
 * Description: allocates memory for a Person and all its components.
 * Returns: Person pointer
 */
Person* createTeacher(int dni, char *name, char *surname, char *email, int phoneNumber){
    Person* newPerson = malloc(sizeof(Person));

    newPerson->name = malloc(sizeof(char)*(strlen(name)+1));
    strcpy(newPerson->name,name);

    newPerson->dni = dni;

    newPerson->surname = malloc(sizeof(char)*(strlen(surname)+1));
    strcpy(newPerson->surname,surname);

    newPerson->email = malloc(sizeof(char)*(strlen(email)+1));
    strcpy(newPerson->email,email);

    newPerson->phoneNumber = phoneNumber;

    newPerson->booksTaken = 0;
    newPerson->debt = 0;
    newPerson->type = 0;
    newPerson->amountOfLoans = 0;
    newPerson->maxCapacityOfLoans = 10;

    return newPerson;
}

/*
 * Function: destroyPerson
 * Description: frees all memory of a person.
 * Returns: --
 */
void destroyPerson(Person* person){
    for (int i = 0; i < person->amountOfLoans; ++i) {
        destroyLoan(person->loans[i]);
    }
    free(person->name);
    free(person->surname);
    free(person->email);
    free(person);
}


/*
* Function: takeMaterial
* Description: receive a loan and locate it on a Person loans.
* Returns: -----------
*/
void takeMaterial(Loan* newLoan, Person* person){
    if(person->amountOfLoans == person->maxCapacityOfLoans){
        person->loans = realloc(person->loans, sizeof(Loan*)*person->maxCapacityOfLoans*2);
        person->maxCapacityOfLoans = person->maxCapacityOfLoans*2;
    }

    person->loans[person->amountOfLoans] = newLoan;
    person->amountOfLoans++;
    materialTaken(newLoan->material);
}

/*
* Function: returnMaterial
* Description: gets a person and a numberOfLoan, search the loan on the loans of the person and remove it.
* Returns: returns 1 if it's found and returned and 0 if isn't found.
*/
int returnMaterial(int numberOfLoan, Person* person){
    for (int i = 0; i < person->amountOfLoans; i++) {
        if(person->loans[i]->numberOfLoan == numberOfLoan){
            materialReturn(person->loans[i]->material);
            destroyLoan(person->loans[i]);
            for (;i < person->amountOfLoans ; i++) {
                person->loans[i] = person->loans[i+1];
            }
            person->amountOfLoans--;
            return 1;
        }
    }
    return 0;
}

