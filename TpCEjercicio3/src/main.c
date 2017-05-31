#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Material.h"
#include "Loan.h"
#include "Library.h"

Person* newPerson(){
    printf("----- New person -----");
    int type = 0;
    char name[20];
    char surname[20];
    int dni = 0;
    char email[40];
    int phoneNumber = 0;

    printf("Enter 1 if is a student or 0 if is a teacher: ");
    scanf("%d", &type);
    printf("Enter persons's name: ");
    scanf("%s", name);
    printf("Enter person's surname: ");
    scanf("%s", surname);
    printf("Enter person's dni: ");
    scanf("%d", &dni);
    printf("Enter person's email: ");
    scanf("%s", email);
    printf("Enter person's phone: ");
    scanf("%d", &phoneNumber);

    if (type == 0){
        return createTeacher(dni,name,surname,email,phoneNumber);
    } else{
        return createStudent(dni,name,surname,email,phoneNumber);
    }
}

void getLibraryStatus(Library* library){
    printLibrary(library);
}

Loan* makeALoan(Library* library){
    printf("----- Persons -----");
    for (int j = 0; j < library->amountOfPersons; ++j) {
        printLessPerson(library->persons[j]);
    }
    int personSelected = 0;
    printf("Please enter person dni: ");
    scanf("%d", &personSelected);

    Person* person;
    for (int k = 0; k < library->amountOfPersons; ++k) {
        if (library->persons[k]->dni == personSelected){
            person = library->persons[k];
        }
    }


    printf("----- Materials -----");
    for (int i = 0; i < library->amountOfMaterials; ++i) {
        printLessMaterial(library->materials[i]);
    }
    int bookCode = 0;
    printf("Please enter material code: ");
    scanf("%d", &bookCode);

    Material* material;
    for (int s = 0; s < library->amountOfMaterials; ++s) {
        if(library->materials[s]->code == bookCode){
            material = library->materials[s];
            library->materials[s]->status = 0;
        }
    }

    int numberOfLoan;
    int code;
    char* id;
    char* fechaDeEntrega;
    char* fechaDeDevolucion;

    printf("Enter number of loan: ");
    scanf("%d", &numberOfLoan);
    printf("Enter loan's code: ");
    scanf("%d", code);
    printf("Enter loan's id: ");
    scanf("%s", id);
    printf("Enter loan's rental day: ");
    scanf("%s", fechaDeEntrega);
    printf("Enter loan's return day: ");
    scanf("%s", fechaDeDevolucion);
    printf("Enter person's phone: ");

    takeMaterial(createLoan(numberOfLoan,code,id,fechaDeEntrega,fechaDeDevolucion,material),person);
    return createLoan(numberOfLoan,code,id,fechaDeEntrega,fechaDeDevolucion,material);
}

Material* newMaterial(){
    printf("----- New material -----");
    int type;//if is 1 is book, if 0 magazine
    int code;
    char* author;
    char* title;
    int year;
    char* editorial;

    printf("Enter 1 if is a book or 0 if is a magazine: ");
    scanf("%d", &type);
    printf("Enter material's title: ");
    scanf("%s", title);
    printf("Enter material's author: ");
    scanf("%s", author);
    printf("Enter material's year: ");
    scanf("%d", &year);
    if (type == 1){
        printf("Enter material's editorial: ");
        scanf("%s", editorial);
    }
    printf("Enter material's code: ");
    scanf("%d", &code);

    if (type == 0){
        return createMagazine(code,author,title,year);
    } else{
        return createBook(code,author,title,year,editorial);
    }
};

Loan* returnLoan(Library* library){
    printf("----- Personas -----");
    for (int i = 0; i < library->amountOfPersons; ++i) {
        if (library->persons[i]->amountOfLoans != 0){
            printLessPerson(library->persons[i]);
        }
    }
    int dni = 0;
    printf("Enter persons's dni: ");
    scanf("%d", &dni);
    Person* person;
    for (int j = 0; j < library->amountOfPersons; ++j) {
        if (library->persons[j]->dni == dni){
            printf("----- Loans -----");
            for (int h = 0; h < library->persons[j]->amountOfLoans; ++h) {
                printLoan(library->persons[j]->loans[h]);
            }
            int loanCode = 0;
            printf("Enter loan's code: ");
            returnMaterial(loanCode,library->persons[j]);
        }
    }


};

int main() {
    Library* library = createLibrary(10,10);

    Person* anita = createStudent(36787261, "Anita", "Perez", "Anitaperez@hotmail.com", 1148703171);
    Person* juan = createStudent(41246876, "Juan", "Racca", "Juanracca@hotmail.com", 1148703172);
    Person* jose = createStudent(32546876, "Jose", "Perez", "Juanperez@hotmail.com", 1148703172);
    Person* martin = createTeacher(21289876, "Martin", "Arca", "Martinarca@hotmail.com", 1148703172);

    Material* book1 = createBook(123, "Julio Cortazar", "Rayuela", 1963, "Encarta");
    Material* book2 = createBook(1234, "Julio Cortazar", "Libro de Manuel", 1973, "Encarta");
    Material* magazine1 = createMagazine(12345, "Hola", "Revista del dia 23 de Febrero", 2010);

    addMaterial(library,book1);
    addMaterial(library,book2);
    addMaterial(library,magazine1);
    addPerson(library, anita);
    addPerson(library, juan);
    addPerson(library, jose);
    addPerson(library, martin);

    int option;

    do{
        printf(" 1. Get library status. \n 2. Make a loan. \n 3. Return a loan. \n 4. New person. \n"
                       "5. New material. \n 6. Exit. \n Choose an option: ");
        scanf("%d", &option);
        switch (option){
            case 1:
                getLibraryStatus(library);
                break;
            case 2:
                makeALoan(library);
                break;
            case 3:
                returnLoan(library);
                break;
            case 4:
                newPerson();
                break;
            case 5:
                newMaterial();
                break;
            case 6:
                printf("Thanks for using our library. \n");
                break;
            default:
                printf("Enter a valid operation. \n");
                break;
        }

    } while(option != 6);

    return 1;
};