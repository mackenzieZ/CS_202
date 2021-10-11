//Purpose: Practice C++ I/O implementation
//Name: proj1.cpp
//Author: Mackenzie Zappe
//Date:1/27/2020

#include <iostream>
#include <fstream>
using namespace std;

#define FILE_MAX 100

const int NUM_NAMES = 10;
const int NUM_LETTERS = 999;

void readNames(ifstream & input, char array[][NUM_LETTERS], int counterA[NUM_NAMES]);
void printNamesTerminal(const char array[NUM_NAMES][NUM_LETTERS], const int countA[NUM_NAMES]);
void printNamesFile(ofstream & output, const char arr[NUM_NAMES][NUM_LETTERS], const int counter[NUM_NAMES]);

void sortNamesAlphabetic(char arr[NUM_NAMES][NUM_LETTERS], int countArr[NUM_NAMES]);
void sortNamesByLength(char arr[NUM_NAMES][NUM_LETTERS], int countArr[NUM_NAMES]);

void strcpy (char dest[NUM_LETTERS], const char src[NUM_LETTERS]);
int strcmp (const char array1[], const char array2[]);
int strlen(const char array[]);



int main(){
char inputDoc[FILE_MAX], outputDoc[FILE_MAX];
ifstream input;
ofstream output;


cout << "Enter an input file name:";
cin >> inputDoc;
cout << "Enter an output file name:";
cin >> outputDoc;

input.open(inputDoc);
output.open(outputDoc);


//unsorted info gathered/displayed
char names[NUM_NAMES][NUM_LETTERS];
int counterArr[NUM_NAMES];

readNames(input, names, counterArr);

cout << "Unordered Data (Original Input Order and Name)" << endl;
for(int i = 0; i < 28; ++i){
    cout << "=";
}
cout << endl;
printNamesTerminal(names, counterArr);

//Alphetically sorted and displayed
char namesAlpha[NUM_NAMES][NUM_LETTERS];
int counterAlpha[NUM_NAMES];

for(int i = 0; i < NUM_NAMES; i++){
    for(int j = 0; j < NUM_LETTERS; j++){
        namesAlpha[i][j] = names [i][j];
        counterAlpha [i] = counterArr[i];
    }
}

sortNamesAlphabetic(namesAlpha, counterAlpha);

cout << "Alphabetically Sorted Data (Original Input Order and Name)" << endl;
for(int i = 0; i < 28; ++i){
    cout << "=";
}
cout << endl;
printNamesTerminal(namesAlpha, counterAlpha);

//By Length sorted and displayed
char namesLen[NUM_NAMES][NUM_LETTERS];
int counterLen[NUM_NAMES];

for(int i = 0; i < NUM_NAMES; i++){
    for(int j = 0; j < NUM_LETTERS; j++){
        namesLen[i][j] = names [i][j];
        counterLen [i] = counterArr[i];
    }
}

sortNamesByLength(namesLen, counterLen);

cout << "By Length Sorted Data (Original Input Order and Name)" << endl;
for(int i = 0; i < 28; ++i){
    cout << "=";
}
cout << endl;
printNamesTerminal(namesLen, counterLen);

//Printing to File
output << "Unordered Data (Original Input Order and Name)" << endl;
    printNamesFile(output,names,counterArr);
output << "Alphabetically Sorted Data (Original Input Order and Name)" << endl;
    printNamesFile(output,namesAlpha,counterAlpha);

output << "By Length Sorted Data (Original Input Order and Name)" << endl;
    printNamesFile(output,namesLen,counterLen);



input.close();
output.close();
return 0; 
}

//Function Definitions
//Reads names from file and stores info into respective arrays 
void readNames(ifstream & input, char array[][NUM_LETTERS], int counterA[NUM_NAMES]){
    int counter = 0; 
    while(!input.eof()){
        for(int i = 0; i< NUM_NAMES; i++){
            int j=0;
            if(i > 0){
            input.ignore(1);
            }
            counterA[i] = counter;
            for(; input.peek() != '\n' && j < NUM_LETTERS; j++){
                input >> array[i][j];
            }
        array[i][j]= '\0';
        counter++;
        }
    }
}
//->
//prints arrays to terminal
void printNamesTerminal(const char array[][NUM_LETTERS], const int countA[NUM_NAMES]){
    for(int i = 0; i <NUM_NAMES; i++){
        cout << countA[i] << ' ';
        for(int j = 0; array[i][j]; j++){
           cout << array[i][j];
        }
    cout << endl;
    }
}
//->
//copies one string into the spot of another
void strcpy (char  dest[NUM_LETTERS], const char src[NUM_LETTERS]){
    int i = 0;
    while(i < strlen(src)+1){
        dest[i] = src[i];
        i++;
    }
}
//->
//compares the similarity of strings 
int strcmp (const char array1[], const char array2[]){
    for (int i = 0; array1[i] != strlen(array1) || array2[i] != strlen(array2);i++ ){
        if(array1[i] != array2[i]){
            return array1[i] - array2[i]; 
        }
    }
    return 0;
}
//->
//gets the length of a string
int strlen(const char array[]){
    int counter =0;
    int i = 0;
    while(array[i] != '\0'){
        counter++;
        i++;
    }
return counter;
}
//->
//uses selection sort to order names alphebetically
void sortNamesAlphabetic(char arr[NUM_NAMES][NUM_LETTERS], int countArr[NUM_NAMES]){
    for (int i=0; i < NUM_NAMES; i++){
        for (int j=i; j < NUM_NAMES; j++){
            if(strcmp(arr[i], arr[j]) > 0){
                char temp[NUM_LETTERS];
                strcpy(temp,arr[i]);
                strcpy(arr[i],arr[j]);
                strcpy(arr[j],temp);

                int tempC = countArr[i];
                countArr[i] = countArr[j];
                countArr[j] = tempC;
            }
        }
    }
}
//->
//uses selection sort to order names alphebetically
void sortNamesByLength(char arr[NUM_NAMES][NUM_LETTERS], int countArr[NUM_NAMES]){
      for (int i=0; i < NUM_NAMES; i++){
        for (int j=i; j < NUM_NAMES; j++){
            if(strlen(arr[i]) > strlen(arr[j])){
                char temp[NUM_LETTERS];
                strcpy(temp,arr[i]);
                strcpy(arr[i],arr[j]);
                strcpy(arr[j],temp);

                int tempC = countArr[i];
                countArr[i] = countArr[j];
                countArr[j] = tempC;

            }else if(strlen(arr[i]) == strlen(arr[j])){
                if(strcmp(arr[i], arr[j]) > 0){
                    char temp[NUM_LETTERS];
                    strcpy(temp,arr[i]);
                    strcpy(arr[i],arr[j]);
                    strcpy(arr[j],temp);

                    int tempC = countArr[i];
                    countArr[i] = countArr[j];
                    countArr[j] = tempC;
                }
            }
        }
    }
}
//->
//prints names to file
void printNamesFile(ofstream & output, const char arr[NUM_NAMES][NUM_LETTERS], const int counter[NUM_NAMES]){
    for(int i = 0; i <NUM_NAMES; i++){
        output << counter[i] << ' ';
        for(int j = 0; arr[i][j]; j++){
           output << arr[i][j];
        }
    output << endl;
    }
}