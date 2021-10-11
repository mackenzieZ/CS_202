//Purpose: header file for RentalCar class declaration
//Name: rentalCar.h
//Author: Mackenzie Zappe
//Date: 2/10/2020

#define MAX_ARRAY_SIZE 256

class RentalCar{
    public:
    RentalCar();
    RentalCar(int year, char * make, char * model, float price, bool available = false);

    void setYear(int yr);
    void setMake(const char * str);
    void setModel(const char * str);
    void setPrice(float price);
    void setAvailable(bool open);

    int getYear() const;
    const char * getMake() const;
    const char * getModel() const;
    float getPrice() const;
    bool getAvailability() const; 

    void print() const;
    float estimateCost(int days);


    private:
    int m_year;
    char m_make[MAX_ARRAY_SIZE];
    char m_model[MAX_ARRAY_SIZE];
    float m_price;
    bool m_available;



};