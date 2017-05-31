//
// Created by Tincho on 24-May-17.
//

#include <stdlib.h>
#include <stdio.h>
#include "Person.h"
#include "Library.h"

Library* createLibrary(int maxCapacityOfMaterial, int maxCapacityOfPerson){
    Library* newLibrary = malloc(sizeof(Library));

    newLibrary->maxCapacityOfMaterials = maxCapacityOfMaterial;
    newLibrary->maxCapacityOfPersons = maxCapacityOfPerson;

    return newLibrary;
};

void printLibrary(Library* library){
    if (library->amountOfMaterials != 0){
        printf("----- Materials -----");
        for (int i = 0; i < library->amountOfMaterials; ++i) {
            printMaterial(library->materials[i]);
        }
    }

    if (library->amountOfPersons == 0){
        printf("----- Persons -----");
        for (int i = 0; i < library->amountOfPersons; ++i) {
            printPerson(library->persons[i]);
        }
    }
};

/*
 * Function: addPerson
 * Description: adds a person to a library.
 * Returns: --
 */
void addPerson(Library* library, Person* newperson){
    if (library->amountOfPersons == library->maxCapacityOfPersons){
        library->persons = realloc(library->persons, sizeof(Person*)*library->maxCapacityOfPersons*2);
        library->maxCapacityOfPersons = library->maxCapacityOfPersons*2;
    }

    library->persons[library->amountOfPersons] = newperson;
    library->amountOfPersons++;
}

/*
 * Function: addMaterial
 * Description: adds a material to a library.
 * Returns: --
 */
void addMaterial(Library* library, Material* newMaterial){
    if (library->amountOfMaterials == library->maxCapacityOfMaterials){
        library->materials = realloc(library->materials, sizeof(Material*)*library->maxCapacityOfMaterials*2);
        library->maxCapacityOfMaterials = library->maxCapacityOfMaterials*2;
    }

    library->materials[library->amountOfMaterials] = newMaterial;
    library->amountOfMaterials++;
}

/*
 * Function: destroyLibrary
 * Description: frees all memory of a library.
 * Returns: --
 */
void destroyLibrary(Library* library){
    for (int i = 0; i < library->amountOfMaterials; ++i) {
        destroyMaterial(library->materials[i]);
    }
    for (int j = 0; j < library->amountOfPersons; ++j) {
        destroyPerson(library->persons[j]);
    }
    free(library);
}
