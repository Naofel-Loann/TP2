#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <ostream>

class Room
{
public:
	Room(int numero, std::string type, double prix);
	int getNumero();
	std::string getType();
	double getPrix();
	void updatePrix(int prix);

private:
	int _numero;
	std::string _type;
	double _prix;
};

std::ostream& operator<<(std::ostream& flux, Room& room);
#endif