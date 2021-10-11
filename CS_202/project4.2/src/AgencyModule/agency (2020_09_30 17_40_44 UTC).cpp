//Purpose: Agency class source file
//Name: agency.cpp
//Author: Mackenzie Zappe
//Date: 2/23/2020

#include <AgencyModule/agency.h>
//#include <CarModule/car.h>
//#include <SensorModule/sensor.h>
#include <StringModule/my_string.h>
#include<iostream>
#include<fstream>

#define FILE_MAX 256
Agency:: Agency(){

}

Agency:: Agency(char * str, int zip){
    strcpy(m_name, str);
    m_zipCode = zip;
}
Agency :: Agency(const Agency & a1){
    strcpy(m_name, a1.m_name);
    m_zipCode = a1.m_zipCode;
}
void Agency:: setName(char * str){
    strcpy(m_name, str);
}
void Agency :: setZip(int zip){
    m_zipCode = zip;
}
char * Agency:: getName(){
    return m_name;
}
int Agency :: getZip() const{
    return m_zipCode;
}
Car * Agency :: getInventory(){
    return carInventory;
}
Car & Agency:: operator[](int index) {
    return carInventory[index];
}
//I modified the Code sent by TA for the readAllData Function
//Below is my attempt for reading the data;however, I could not get it to work which is why it is commented out
//The resetAll() is written by me and can be found in sensor.h
void Agency:: readAllData(){
    char inputDoc[FILE_MAX]; 
    ifstream input;
    cout << "Enter the input file name" << endl;
    cin >> inputDoc;
    input.open(inputDoc);
    if(!input){
    cout << "Invalid File Name!" << endl;
    return;
    }
    int year;
	char make[256], model[256], trash, tempstr[256];
	char * tempstr_pt = tempstr;
	float baseprice;
	bool available;
	Car * inventory_pt = carInventory;
	input >> m_name >> m_zipCode;
	input >> year;
	for (int i = 0; i < 5; ++i, ++inventory_pt)
	{
        
		input >> make >> model >> baseprice >> trash;
		Sensor sensors[3];
		Sensor * sensors_ptr = sensors;
        /*
        char  tempStr[MAX_SIZE];
        char * tempStr_pt = tempstr;
        input.getline(tempStr,256,'}');
        //cout << tempStr;
        
        for(int i = 0; i< 3; i++){
        if(*tempStr_pt == 'g'){
            sensors_ptr->setType("gps");
            sensors_ptr->resetAll("gps");
            sensors_ptr++;
            tempstr_pt +=3;
        }else
        if(*tempStr_pt == 'c'){
            sensors_ptr->setType("camera");
            sensors_ptr->resetAll("camera");
            sensors_ptr++;
            tempstr_pt +=6;
        }else
        if(*tempStr_pt == 'l'){
            sensors_ptr->setType("lidar");
            sensors_ptr->resetAll("lidar");
            sensors_ptr++;
            tempstr_pt +=5;
        }else
        if(*tempStr_pt == 'r'){
            sensors_ptr->setType("radar");
            sensors_ptr->resetAll("radar");
            sensors_ptr++;
            tempstr_pt +=3;
        }else{
            sensors_ptr->setType("none");
        }
        }

    */
   Car tempcar(year, make, model, baseprice);
		while (trash != '}')
		{
			input >> tempstr;
                trash = *(tempstr_pt + (strlen(tempstr) - 1));
                tempstr_pt += strlen(tempstr) - 1;
                if (trash == '}')
                {
                    *tempstr_pt = '\0';
                    tempstr_pt = tempstr;
                    sensors_ptr->setType(tempstr_pt);
                    sensors_ptr->resetAll(tempstr_pt);
                    tempcar + *sensors_ptr;
                    sensors_ptr++;
                }
                else
                {
                    tempstr_pt = tempstr;
                    sensors_ptr->setType(tempstr_pt);
                    sensors_ptr->resetAll(tempstr_pt);
                    tempcar + *sensors_ptr;
                    sensors_ptr++;
                }
            
		}
		
		*inventory_pt = tempcar;
		input >> available;
		inventory_pt->setAvailable(available);
		input >> tempstr;
        
		if (*tempstr_pt >= '0' && *tempstr_pt <= '9')
		{
			year = (*tempstr_pt % 48) * 1000;
			++tempstr_pt;
			year += *tempstr_pt % 48 * 100;
			++tempstr_pt;
			year += *tempstr_pt % 48 * 10;
			++tempstr_pt;
			year += *tempstr_pt % 48;
			tempstr_pt = tempstr;
		}
		else
		{
			*inventory_pt + tempstr_pt;
			input >> year;
		}
        
    }
    
    /*
    char make[MAX_CHARS], model[MAX_CHARS], str[MAX_CHARS];
    int yr;
    float b_price;
    bool available;
    Car * inventoryPtr = getInventory();
    char * str_ptr = str; 
    //Sensor * sensorPtr = inventoryPtr->getSensors(0);
        //reading in Agencies info
        file >> m_name >> m_zipCode;
        //reading in car info
        for(int i = 0; i < MAX_CARS; i++, inventoryPtr++){
            char tempChar;
            file >> yr >> make >> model >> b_price >> tempChar;
            //reading in sensor info
            Sensor sensorInventory[MAX_SENSORS];
            Sensor * sensorPtr = sensorInventory;
            while(tempChar != '}'){
                file >> str_ptr; 
                tempChar = *(str_ptr + (strlen(str) -1));
                str_ptr += strlen(str) - 1;
                if(tempChar == '}'){
                    *str_ptr = '\0';
                    str_ptr = str;
                    sensorPtr -> setType (str_ptr);
                    sensorPtr->resetAll(str_ptr);
                    ++sensorPtr;
                }else{
                    str_ptr = str;
                    sensorPtr -> setType(str_ptr);
                    sensorPtr->resetAll(str_ptr);
                    ++sensorPtr;

                }
            }
            sensorPtr = sensorInventory;
            Car tempCar(yr,make,model,b_price,sensorPtr);
            *inventoryPtr = tempCar;
            file >> available;
            inventoryPtr->setAvailable(available);
            if(tempCar.getAvailable() == 0 ){
                char owner[256];
                file >> owner;
                inventoryPtr->setOwner(owner);    
            }

        }
    }*/
    input.close();
}

void Agency:: printActiveSensors() const{
    cout << "Active Sensors:";
    cout << "{camera} " << Sensor::getCameraCt() ;
    cout << " {radar} " << Sensor::getRadarCt();
    cout << " {gps} " << Sensor ::getGpsCt();
    cout << " {lidar} " << Sensor :: getLidarCt() << endl;
}


void Agency :: printData() {
    cout << m_name << " " << m_zipCode << endl;
    printActiveSensors();

}

void Agency :: printAllCars(){
    Car * carPtr = carInventory;
    int i = 1;
    for(; i < 6; i++, carPtr++){
        cout << "[" << i <<"] ";
        carPtr -> printCar();
    }
}

void Agency :: printAvailableCars(){
    Car * carPtr = carInventory;
    int i = 1;
    for(; i < 6; i++, carPtr++){
        if(carPtr -> getAvailable() == 1){
        cout << "[" << i <<"] ";
        carPtr -> printCar();
        }
    }
}

void Agency:: reserveOne(){
        int choice;
        cout << "Which Car would you like to rent?" << endl;
        printData();
        printAllCars();
        cin >>  choice; 
    Car * carPtr = carInventory;
    for(int i = 0; i < choice; i++, carPtr++){
        if(!carPtr->getAvailable()){
            cout << "Car unavailable"<<endl;
            return;
        }else{
            carPtr->setAvailable(0);
            char newOwner[MAX_SIZE];
            cout << "Enter the name of the lessee:";
            cin >> newOwner;
            carPtr->setOwner(newOwner);
        }
    }
    printData();
    printAllCars();
}