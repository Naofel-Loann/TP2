#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include <vector>
#include <ostream>
#include <iostream>
#include "Room.h"
#include "Customer.h"

class Hotel
{
public:
	Hotel(std::string id, std::string nom, std::string ville);
	std::string getId();
	std::string getNom();
	std::string getVille();
	std::vector<Room> getRoomVector();
	void addRoom(Room room);
	void delRoom(Room room);

private:
	std::string _id;
	std::string _nom;
	std::string _ville;
	std::vector <Room> _roomVector;
};

std::ostream& operator<<(std::ostream& flux, Hotel& hotel);

#endif