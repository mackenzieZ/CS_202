//Purpose: Menu header file
//Name:menu.h
//Author: Mackenzie Zappe
//Date: 2/25/2020


#ifndef MENU_H_
#define MENU_H_

#include <AgencyModule/agency.h>

int userMenuPrompt();
void readIn(Agency a1);
void printAll(Agency a1);
void printFiltered(Agency a1);
void reserveOne(Agency a1, int choice);

#endif