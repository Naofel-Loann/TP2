#ifndef RESERVATION_H
#define RESERVATION_H

#include "Date.h"
#include "Hotel.h"
#include "Customer.h"
#include <string>

class Reservation
{
public:
	Reservation(Date date, int nombreNuit, Hotel hotel, Room room, Customer client);
	Date getDateStart();
	void setDateStart(Date d);
	int getNombreNuit();
	void setNombreNuit(int nombreNuit);
	std::string getIdHotel();
	int getIdRoom();
	void setRoomId(int roomId);
	std::string getIdCustomer();
	double getMontantTotal();
	void updateDate(Date newdate);
	int getId();

private:
	Date _dateStart;
	int _nombreNuits;
	std::string _idHotel;
	int _idRoom;
	std::string _idCustomer;
	double _montantTotal;
	int _reservation_id;
};

std::ostream& operator<<(std::ostream& flux, Reservation& reservation);

#endif