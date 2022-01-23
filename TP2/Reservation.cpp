#include "Reservation.h"

Reservation::Reservation(Date date, int nombreNuit, Hotel hotel, Room room, Customer client) : _dateStart(date), _nombreNuits(nombreNuit), _idHotel(hotel.getId()), _idRoom(room.getNumero()), _idCustomer(client.getId())
{
	_montantTotal = room.getPrix() * _nombreNuits;
	static int _id = 1;
	_reservation_id = _id++;
}


int Reservation::getId()
{
	return _reservation_id;
}

Date Reservation::getDateStart()
{
	return _dateStart;
}

void Reservation::setDateStart(Date d)
{
	_dateStart = d;
}

int Reservation::getNombreNuit()
{
	return _nombreNuits;
}

void Reservation::setNombreNuit(int nombreNuit)
{
	int prix = _montantTotal / _nombreNuits;
	_nombreNuits = nombreNuit;
	_montantTotal = prix * _nombreNuits;
}

std::string Reservation::getIdHotel()
{
	return _idHotel;
}

int Reservation::getIdRoom()
{
	return _idRoom;
}

void Reservation::setRoomId(int roomId)
{
	_idRoom = roomId;
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


std::ostream& operator<<(std::ostream& flux, Reservation& reservation)
{
	flux << "Date de debut de la reservation : " << toString(reservation.getDateStart()) << "	Chambre numero " << reservation.getIdRoom() << "   Nombre de nuits : " << reservation.getNombreNuit() << "   Montant total : " << reservation.getMontantTotal() << std::endl;
	return flux;
}
