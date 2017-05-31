//
// Created by Tincho on 24-May-17.
//
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include "Material.h"

/*
 * Function: createMagazine
 * Description: allocates memory for a Material and all its components.
 * Returns: Material pointer
 */
Material* createMagazine(int code, char* author, char* title, int year){
    Material* newMaterial = malloc(sizeof(Material));

    newMaterial->code = code;

    newMaterial->author = malloc(sizeof(char)*(strlen(author)+1));
    strcpy(newMaterial->author,author);

    newMaterial->title = malloc(sizeof(char)*(strlen(title)+1));
    strcpy(newMaterial->title,title);

    newMaterial->year = year;

    newMaterial->status = 1;
    newMaterial->type = 0;

    return newMaterial;
}

void printLessMaterial(Material* material){
    if(material->type == 1){
        printf("----- Book -----");
    }   else{
        printf("----- Magazine -----");
    }
    printf("Title: %s \n", material->title);
    printf("Author: %s \n", material->author);
    printf("Code: %d \n", material->code);
};

void printMaterial(Material* material){
    if(material->type == 1){
        printf("----- Book -----");
    }   else{
        printf("----- Magazine -----");
    }

    printf("Title: %s \n", material->title);
    printf("Author: %s \n", material->author);
    printf("Year: %d \n", material->year);
    printf("Editorial: %s \n", material->editorial);
    printf("Code: %d \n", material->code);
    printf("Status(1 available, 0 not available): %d \n", material->status);
};

/*
 * Function: createBook
 * Description: allocates memory for a Material and all its components.
 * Returns: Material pointer
 */
Material* createBook(int code, char* author, char* title, int year,  char* editorial){
    Material* newMaterial = malloc(sizeof(Material));

    newMaterial->code = code;

    newMaterial->author = malloc(sizeof(char)*(strlen(author)+1));
    strcpy(newMaterial->author,author);

    newMaterial->title = malloc(sizeof(char)*(strlen(title)+1));
    strcpy(newMaterial->title,title);

    newMaterial->editorial = malloc(sizeof(char)*(strlen(editorial)+1));
    strcpy(newMaterial->editorial, editorial);

    newMaterial->year = year;

    newMaterial->status = 1;
    newMaterial->type = 1;

    return newMaterial;
}

/*
 * Function: materialTaken
 * Description: it turns status of the material from available, 1, to not available, 0.
 * Returns: Material pointer
 */
Material* materialTaken(Material* material){
    material->status = 0;
    return material;
}

/*
 * Function: materialReturn
 * Description: it turns status of the material from not available, 0, to available, 1.
 * Returns: ----------
 */
void materialReturn(Material* material){
    material->status = 1;
}

/*
 * Function: destroyMaterial
 * Description: frees all memory of a material.
 * Returns: --
 */
void destroyMaterial(Material* material){
    free(material->editorial);
    free(material->author);
    free(material->title);
    free(material);
}
