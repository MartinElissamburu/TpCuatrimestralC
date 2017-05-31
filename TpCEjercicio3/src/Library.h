//
// Created by Tincho on 24-May-17.
//

#ifndef TPC_LIBRARY_H
#define TPC_LIBRARY_H


#include "Material.h"
#include "Person.h"

typedef struct library{
    Material** materials;
    int amountOfMaterials;
    int maxCapacityOfMaterials;

    Person** persons;
    int amountOfPersons;
    int maxCapacityOfPersons;

}Library;

Library* createLibrary(int maxCapacityOfMaterial, int maxCapacityOfPerson);

void printLibrary(Library* library);
void addPerson(Library* library,Person* newPerson);
void addMaterial(Library* library, Material* newMaterial);

void destroyLibrary(Library* library);

#endif //TPC_LIBRARY_H
