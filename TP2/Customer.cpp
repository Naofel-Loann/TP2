#include "Customer.h"

Customer::Customer(std::string nom, std::string prenom) : _nom(nom), _prenom(prenom)
{
	_id = _prenom[0] + _nom;
}

std::string Customer::getId()
{
	return _id;
}

std::string Customer::getNom()
{
	return _nom;
}

std::string Customer::getPrenom()
{
	return _prenom;
}

std::ostream& operator<<(std::ostream& flux, Customer& client)
{
	flux << "ID : " << client.getId() << "   Nom : " << client.getNom() << "   Prenom : " << client.getPrenom() << std::endl;
	return flux;
}
