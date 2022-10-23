#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
class Address{
private:
    string city;
    string street;
    unsigned int house;
    unsigned int flat;
public:
    string setCity(string city_) { city = city_; }
    string getCity() { return city; }
    string getStreet() { return street; }
    unsigned int getHouse() {return house; }
    unsigned int getFlat() { return flat; }
    Address (const string city = "unknown", const string street = "unknown", unsigned int house = 0, unsigned int flat = 0);
    Address (string, string, int, int);
};
Address::Address(const string city_, const string street_, unsigned int house_, unsigned int flat_){
    city = city_;
    street = street_;
    house = house_;
    flat = flat_;
}
int main() {
    string city;
    string street;
    unsigned int house;
    unsigned int flat;
    int size;
    ifstream filein("in.txt");
    if (!filein.is_open()){
        cout << "Error!" << endl;
    }
    else {
        ofstream fileout("out.txt");
        filein >> size;
        Address *array = new Address[size];
        for (int i = 0; i < size; ++i){
            filein >> city;
            filein >> street;
            filein >> house;
            filein >> flat;
            array[i] = Address(city, street, house, flat);
        }
        fileout << size << endl;
        for (int i = (size - 1); i >= 0; --i){
            fileout << array[i].getCity();
            fileout << ", ";
            fileout << array[i].getStreet();
            fileout << ", ";
            fileout << array[i].getHouse();
            fileout << ", ";
            fileout << array[i].getFlat();
            fileout << endl;
        }
        string buf1, buf2, temp;

        int count = 0;
        for (int i = 1; i < size; i++){
            for (int j = 0; j < size - 1; j++){
                if ((array[i].getCity().compare(array[j].getCity())) < 0){
                    temp = array[i].getCity();
                    array[i].getCity() = array[j].getCity();
                    array[j].getCity() = temp;
                    count ++;
                }
            }
        }
        for (int i=0; i<size; i++){
            cout << array[i].getCity() << endl;
        }
        cout << count;
    }
    filein.close();



}

