//Purpose: source code file w/ string function implementations
//Name:str.cpp
//Author: Mackenzie Zappe
//Date:1/31/2020
#include "str.h"

char * strcpy (char * dest, const char * src){
    int i = 0;
    while(i < strlen(src)+1){
        dest[i] = src[i];
        i++;
    }
}
int strcmp (const char * str1, const char *str2){
    for (int i = 0; str1[i] != strlen(str1) || str2[i] != strlen(str2); i++ ){
        if(str1[i] != str2[i]){
            return str1[i] - str2[i]; 
        }
    }
    return 0;
}
int strlen(const char * str){
    int counter =0;
    int i = 0;
    while(str[i] != '\0'){
        counter++;
        i++;
    }
return counter;
}
char * myStringCat(char * dest, char * src){
    int i = strlen(dest)+1;
    while(i< strlen(src)+1){
        dest[i] = src[i];
    }
}



