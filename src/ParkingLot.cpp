/*

  Parking Lot

  Use Cases / Features:
    Get Parking Ticket
    Pay Parking Ticket
    Park Car
    # of Parking Spots Left
    # of Parking Floors
    Different Parking Spot Types

  Classes and Types
    Vehicle
    Account
    Admin: Account
    Parking Attendant: Account
    Parking Ticket
    Parking Spot
    Ticket Reader
    Free Spot Board

*/

#include <string>

using std::string;

class Account {
  string username;
  string password;
};

class Admin: public Account {
  
}

