//Purpose: source file for string function implementations
//Name: my_string.cpp
//Author: Mackenzie Zappe
//Date: 2/10/2020

#include "my_string.h"

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