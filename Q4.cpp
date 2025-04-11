#include <iostream>
#include <vector>
using namespace std;

class Flight
{
private:
    string flightNumber, departure, arrival, capacity;
    vector<int> economySeats;
    vector<int> businessSeats;
public:
    Flight(string fN, string d, string a, string c) : flightNumber(fN), departure(d), arrival(a), capacity(c) {
        economySeats.resize(10);
        for(int i=0; i<economySeats.size(); i++) {
            economySeats[i] = 0;
        }
        businessSeats.resize(10);
        for(int i=0; i<businessSeats.size(); i++) {
            businessSeats[i] = 0;
        }
    }
    ~Flight() {};

    void bookSeat(int i, string type) {
        if (type == "business") {
            businessSeats[i] = 1;
        }   else if (type == "economy")    {
            economySeats[i] = 1;
        }
    }
    void cancelSeat(int i, string type) {
        if (type == "business") {
            businessSeats[i] = 0;
        }   else if (type == "economy")    {
            economySeats[i] = 0;
        }
    }
    void upgradeSeat(int i) {
        economySeats[i] = 0;
        int count = 0;
        while (businessSeats[i+count] == 1) {
            count++;
        }
        businessSeats[i+count] = 1;     // finding the next available seat
    }

};

class Passenger {
    string ID, name;

    public:
    Passenger(string id, string n) : ID(id), name(n) {}

    void requestBooking(Flight& flight) {

    }

};

int main() {
    Passenger p1;
    Passenger p2;
    Passenger p3;

    Flight f1;
    Flight f2;
    Flight f3;

    p1.requestBooking(f2);
    p3.requestBooking(f1);
}