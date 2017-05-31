//
// Created by Tincho on 24-May-17.
//

#ifndef TPC_LOAN_H
#define TPC_LOAN_H
#include "Material.h"

typedef struct loan{
    int numberOfLoan;
    int code;
    char* id;
    char* fechaDeEntrega;
    char* fechaDeDevolucion;
    Material* material;

}Loan;

Loan* createLoan(int numberOfLoan, int code, char* id, char* fechaDeEntrega, char* fechaDeDevolucion, Material* material);

void printLoan(Loan* loan);
void destroyLoan(Loan* loan);

#endif //TPC_LOAN_H
