#include "Room.h"

Room::Room(int numero, std::string type, double prix) : _numero(numero), _type(type), _prix(prix)
{
}

int Room::getNumero()
{
	return _numero;
}

std::string Room::getType()
{
	return _type;
}

double Room::getPrix()
{
	return _prix;
}

void Room::updatePrix(int prix)
{
	_prix = prix;
}

std::ostream& operator<<(std::ostream& flux, Room& room)
{
	flux << "Chambre numero " << room.getNumero() << "   Type : " << room.getType() << "   Prix : " << room.getPrix() << std::endl;
	return flux;
}
