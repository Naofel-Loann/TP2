#include <iostream>
#include <string>
#include <vector>

#include "Date.h"
#include "Customer.h"
#include "Room.h"
#include "Hotel.h"
#include "Reservation.h"

bool isCustomer(std::vector<Customer> &vectorCustomer);
void setReservation(std::vector<Reservation> &vectorReservation, std::vector<Room>& vectorRoom);



int main() {
	Hotel hotel("lc", "lacloche", "Dijon");
	std::vector <Room> vectorRoom;
	vectorRoom.push_back(Room(1, "Single", 100));
	vectorRoom.push_back(Room(2, "Single", 100));
	vectorRoom.push_back(Room(3, "Single", 100));
	vectorRoom.push_back(Room(4, "Double", 125));
	vectorRoom.push_back(Room(5, "Double", 125));
	vectorRoom.push_back(Room(6, "Double", 125));
	vectorRoom.push_back(Room(7, "Double", 125));
	vectorRoom.push_back(Room(8, "Double", 125));
	vectorRoom.push_back(Room(9, "Suite", 210));
	vectorRoom.push_back(Room(10, "Suite", 210));

	for (int i = 0; i < vectorRoom.size(); i++)
		hotel.addRoom(vectorRoom[i]);



	std::vector <Customer> vectorCustomer;
	vectorCustomer.push_back(Customer("El Alouani", "Naofel"));
	vectorCustomer.push_back(Customer("Kamli", "Younes"));
	vectorCustomer.push_back(Customer("Nomine", "Lea"));

	/*std::cout << isCustomer(vectorCustomer) << std::endl;
	std::cout << isCustomer(vectorCustomer) << std::endl;

	for (int i = 0; i < vectorCustomer.size(); i++)
		std::cout << vectorCustomer[i];*/

	std::vector <Reservation> vectorReservation;

	setReservation(vectorReservation, vectorRoom);

}

bool isCustomer(std::vector<Customer> &vectorCustomer)
{
	std::string nom, prenom;
	std::cout << "Entrez un nom : ";
	std::getline(std::cin, nom);
	std::cout << "Entrez un prenom : ";
	std::getline(std::cin, prenom);
	for (int i = 0; i < vectorCustomer.size(); i++)
		if (prenom == vectorCustomer[i].getPrenom() && nom == vectorCustomer[i].getNom())
			return true;
	vectorCustomer.push_back(Customer(nom, prenom));
	return false;
}

void setReservation(std::vector<Reservation>& vectorReservation, std::vector<Room>& vectorRoom) //Ajouter si pas ok
{
	int jour = 0, mois = 0, annee = 0, nombreNuit = 0;
	std::string type;
	std::cout << "Entrez un jour : ";
	std::cin >> jour;
	std::cout << "Entrez un mois : ";
	std::cin >> mois;
	std::cout << "Entrez une annee : ";
	std::cin >> annee;
	std::cout << "Entrez un nombre de nuit : ";
	std::cin >> nombreNuit;
	
	std::cout << "Entrez le type de chambre souhaité : ";
	std::cin >> type;
	bool find = 0;
	for (int i = 0; i < vectorRoom.size(); i++)
	{
		if (type == vectorRoom[i].getType())
			while (find == 0)
			{
				for (int j = 0; j < vectorReservation.size(); j++)
					if (vectorRoom[i].getNumero() == vectorReservation[j].getIdRoom())
					{

						find = 1;
					}
			}
	}


}
