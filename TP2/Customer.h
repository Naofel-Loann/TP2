#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <ostream>
#include <iostream>


class Customer
{
public:
	Customer(std::string nom, std::string prenom);
	std::string getId();
	std::string getNom();
	std::string getPrenom();
private:
	std::string _id;
	std::string _nom;
	std::string _prenom;
};

std::ostream& operator<<(std::ostream& flux, Customer& customer);

#endif