// testing lab1

#include <iostream>

using namespace std; 

void sumNUM(int * start_pt, int count, int & sum);

int main(){
    int numbers[]={1,2,3};
    int sum = 0;
    cout << sum;
return 0;
}
void sumNUM(int * start_pt, int count, int & sum){
    for(int i = 0; i < count; i++){
        sum += *start_pt;
        start_pt++;
    }
}