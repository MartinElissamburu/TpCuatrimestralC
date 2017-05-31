

#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "Loan.h"

/*
 * Function: createLoan
 * Description: allocates memory for a Loan and all its components.
 * Returns: Loan pointer
 */
Loan* createLoan(int numberOfLoan, int code, char* id, char* fechaDeEntrega, char* fechaDeDevolucion, Material* material){
    Loan* newLoan = malloc(sizeof(Loan));

    newLoan->id = malloc(sizeof(char)*(strlen(code)+1));
    strcpy(newLoan->id,id);

    newLoan->code = code;

    newLoan->fechaDeEntrega = malloc(sizeof(char)*(strlen(fechaDeEntrega)+1));
    strcpy(newLoan->fechaDeEntrega,fechaDeEntrega);

    newLoan->fechaDeDevolucion = malloc(sizeof(char)*(strlen(fechaDeDevolucion)+1));
    strcpy(newLoan->fechaDeDevolucion,fechaDeDevolucion);

    newLoan->numberOfLoan = numberOfLoan;

    newLoan->material = material;

    return newLoan;
}

void printLoan(Loan* loan){
    printf("----- Loan -----");
    printf("Code: %s \n", loan->code);
    printf("Id: %s \n", loan->id);
    printf("Rental day: %s \n", loan->fechaDeEntrega);
    printf("Return date: %s \n", loan->fechaDeDevolucion);
    printf("Material title: %s \n", loan->material->title);
};

/*
 * Function: destroyLoan
 * Description: frees all memory of a college.
 * Returns: -------
 */
void destroyLoan(Loan* loan){
    loan->material->status = 1;
    free(loan->id);
    free(loan->fechaDeDevolucion);
    free(loan->fechaDeEntrega);
    free(loan);
}