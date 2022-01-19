#include "Reservation.h"

Reservation::Reservation(Date date, int nombreNuit, Hotel hotel, Room room, Customer client) : _dateStart(date), _nombreNuits(nombreNuit), _idHotel(hotel.getId()), _idRoom(room.getNumero()), _idCustomer(client.getId())
{
	_montantTotal = room.getPrix() * _nombreNuits;
}

Date Reservation::getDateStart()
{
	return _dateStart;
}

int Reservation::getNombreNuit()
{
	return _nombreNuits;
}

std::string Reservation::getIdHotel()
{
	return _idHotel;
}

int Reservation::getIdRoom()
{
	return _idRoom;
}

std::string Reservation::getIdCustomer()
{
	return _idCustomer;
}

double Reservation::getMontantTotal()
{
	return _montantTotal;
}

void Reservation::updateDate(Date newDate)
{
	_dateStart = newDate;
}

void Reservation::updateNuit(int newNuit)
{
	int prix = _montantTotal / _nombreNuits;
	_nombreNuits = newNuit;
	_montantTotal = prix * _nombreNuits;
}
