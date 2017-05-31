//
// Created by Tincho on 24-May-17.
//

#ifndef TPC_MATERIAL_H
#define TPC_MATERIAL_H

typedef struct material{

    int type;//if is 1 is book, if 0 magazine
    int code;
    char* author;
    char* title;
    int year;
    int status;// 1 available, 0 not available
    char* editorial;


}Material;

Material* createMagazine(int code, char* author, char* title, int year);
Material* createBook(int code, char* author, char* title, int year, char* editoria);

void printLessMaterial(Material* material);
void printMaterial(Material* material);
Material* materialTaken(Material* material);
void materialReturn(Material* material);

void destroyMaterial(Material* material);

#endif //TPC_MATERIAL_H
