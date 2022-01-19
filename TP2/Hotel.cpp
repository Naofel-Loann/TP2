#include "Hotel.h"

Hotel::Hotel(std::string id, std::string nom, std::string ville) : _id(id), _nom(nom), _ville(ville)
{
}

std::string Hotel::getId()
{
    return _id;
}

std::string Hotel::getNom()
{
    return _nom;
}

std::string Hotel::getVille()
{
    return _ville;
}

std::vector<Room> Hotel::getRoomVector()
{
    return _roomVector;
}

void Hotel::addRoom(Room room)
{
    _roomVector.push_back(room);
}

void Hotel::delRoom(Room room)
{
    for (int i = 0; i < _roomVector.size(); i++)
    {
        if (_roomVector[i].getNumero() == room.getNumero())
            _roomVector.erase(_roomVector.begin() + i);
    }
}


std::ostream& operator<<(std::ostream& flux, Hotel& hotel)
{
    flux << "ID : " << hotel.getId() << "   Nom : " << hotel.getNom() << "   Ville : " << hotel.getVille() << std::endl;
    for (int i = 0; i < hotel.getRoomVector().size(); i++)
        std::cout << hotel.getRoomVector()[i];

    return flux;
}
