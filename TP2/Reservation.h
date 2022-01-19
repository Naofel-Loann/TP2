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
	int getNombreNuit();
	std::string getIdHotel();
	int getIdRoom();
	std::string getIdCustomer();
	double getMontantTotal();
	void updateDate(Date newdate);
	void updateNuit(int newnight);

private:
	Date _dateStart;
	int _nombreNuits;
	std::string _idHotel;
	int _idRoom;
	std::string _idCustomer;
	double _montantTotal;

};

#endif