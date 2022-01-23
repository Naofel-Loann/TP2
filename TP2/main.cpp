#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "Customer.h"
#include "Room.h"
#include "Hotel.h"
#include "Reservation.h"

bool isCustomer(std::vector<Customer>& vectorCustomer);
void setReservation(std::vector<Reservation>& vectorReservation, std::vector<Room>& vectorRoom, Hotel hotel, Customer client);
bool freeDate(Date d, int nbNuit, Reservation reserv);
void displayAllReservations(std::vector<Reservation>& vectorReservation);
void displayReservation(int number, std::vector<Reservation>& vectorReservation);
void reservationCustomer(std::string id, std::vector<Reservation>& vectorReservation);
void updateReservation(int numberOfReservation, std::vector<Reservation>& vectorReservation, std::vector<Room>& vectorRoom);
Date askedDate();
void delReservation(int numberOfReservation, std::vector<Reservation>& vectorReservation);


int main() {
	//Création d'un hôtel et de 10 chambres
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

	std::cout << "Affichage des informations d'une chambre :	" << vectorRoom[2] << std::endl; //Affichage question 6b)

	std::vector <Customer> vectorCustomer;

	//Vecteur de clients question 6c)
	vectorCustomer.push_back(Customer("El Alouani", "Naofel"));
	vectorCustomer.push_back(Customer("Kamli", "Younes"));
	vectorCustomer.push_back(Customer("Nomine", "Lea"));

	std::cout << "Affichage des informations d'un client :	" << vectorCustomer[2] << std::endl; //Affichage question 6d)

	std::vector <Reservation> vectorReservation;

	//Création de réservations automatique
	Reservation res1(Date(2021, 12, 12), 5, hotel, vectorRoom[0], vectorCustomer[1]);
	Reservation res2(Date(2022, 12, 12), 4, hotel, vectorRoom[0], vectorCustomer[1]);

	//Vecteur des reservations
	vectorReservation.push_back(res1);
	vectorReservation.push_back(res2);

	isCustomer(vectorCustomer); //Informations d'un client question 7a)

	//Question 7b) et 7c): voir fonction setReservation
	std::cout << std::endl;
	std::cout << std::endl;
	setReservation(vectorReservation, vectorRoom, hotel, vectorCustomer[1]); //Création d'une reservation manuelle pour un client et un hôtel déjà renseignés
	std::cout << std::endl;
	std::cout << std::endl;
	displayAllReservations(vectorReservation); //Affichage de toutes les reservations
	std::cout << std::endl;
	std::cout << std::endl;
	displayReservation(1, vectorReservation); //Affichage d'une reservation par son numero
	std::cout << std::endl;
	std::cout << std::endl;
	updateReservation(1, vectorReservation, vectorRoom); //Modification d'une réservation
	delReservation(3, vectorReservation); //Suppression d'une reservation
	std::cout << std::endl;
	std::cout << std::endl;
	displayAllReservations(vectorReservation); //Affichage de toutes les reservations

	//Decommenter cette partie pour créer 5 reservations supplementaires
	/*for (int i = 0; i < 5; i++)
	{
		setReservation(vectorReservation, vectorRoom, hotel, vectorCustomer[1]);
	}*/

}


bool isCustomer(std::vector<Customer>& vectorCustomer)
{
	std::string nom, prenom;
	std::cout << "Recherche d'un client : ";
	std::cout << "Entrez un nom : ";
	std::getline(std::cin, nom);
	std::cout << "Entrez un prenom : ";
	std::getline(std::cin, prenom);
	for (int i = 0; i < vectorCustomer.size(); i++)
	{
		if (prenom == vectorCustomer[i].getPrenom() && nom == vectorCustomer[i].getNom())
		{
			std::cout << vectorCustomer[i];
			return true;
		}
	}
	std::cout << "Ce client n'existe pas, creation de ce dernier..." << std::endl;
	vectorCustomer.push_back(Customer(nom, prenom));
	std::cout << "Nouveau client cree : " << vectorCustomer.back();
	return false;
}

//Fonction permettant de reserver une chambre pour une date, un nombre de jour et un type entrés
void setReservation(std::vector<Reservation>& vectorReservation, std::vector<Room>& vectorRoom, Hotel hotel, Customer client) //MODIFIE
{
	//Entrée d'une date et d'un nombre de nuit
	int jour = 0, mois = 0, annee = 0, nombreNuit = 0;
	std::cout << "Creation d'une nouvelle reservation:" << std::endl;
	std::string type;
	std::cout << "Entrez un jour : ";
	std::cin >> jour;
	std::cout << "Entrez un mois : ";
	std::cin >> mois;
	std::cout << "Entrez une annee : ";
	std::cin >> annee;
	std::cout << "Entrez un nombre de nuit : ";
	std::cin >> nombreNuit;

	std::cout << "Entrez le type de chambre souhaite : ";
	std::cin >> type;

	if (vectorReservation.size() != 0)
	{
		for (int i = 0; i < vectorRoom.size(); i++) //Pour toutes les chambres de l'hotel
		{
			bool reserved = 0;
			if (type == vectorRoom[i].getType()) //Si le type est celui demandé
			{
				for (int j = 0; j < vectorReservation.size(); j++) // Pour toutes les reservation
				{
					if (vectorRoom[i].getNumero() == vectorReservation[j].getIdRoom()) // Si le n° de chambre trouvé est celui de la réservation
					{
						reserved = 1;
						if (freeDate(Date(annee, mois, jour), nombreNuit, vectorReservation[j]) == 1) // Si les dates demandées sont libres
						{
							std::cout << "Chambre libre trouvee: " << vectorRoom[i] << std::endl;
							std::cout << "Le montant total est: " << vectorRoom[i].getPrix() * nombreNuit << "euros" << std::endl; //MODIFIE
							vectorReservation.push_back(Reservation(Date(annee, mois, jour), nombreNuit, hotel, vectorRoom[i], client));
							std::cout << "Recapitulatif : " << vectorReservation.back();
							return;
						}
						else
						{
							std::cout << "Chambre " << vectorRoom[i].getNumero() << " non dispo pour ces dates" << std::endl;
							break;
						}
					}
				}
				if (reserved == 0)
				{
					std::cout << "Chambre libre trouvee: " << vectorRoom[i] << std::endl;
					std::cout << "Le montant total est: " << vectorRoom[i].getPrix() * nombreNuit << "euros" << std::endl; //MODIFIE
					vectorReservation.push_back(Reservation(Date(annee, mois, jour), nombreNuit, hotel, vectorRoom[i], client)); //MODIFIE
					std::cout << "Recapitulatif : " << vectorReservation.back();
					return;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < vectorRoom.size(); i++)
		{
			if (type == vectorRoom[i].getType()) //Si les types sont les memes
			{
				std::cout << "Chambre libre trouvee: " << vectorRoom[i] << std::endl;
				std::cout << "Le montant total est: " << vectorRoom[i].getPrix() * nombreNuit << "euros" << std::endl; //MODIFIE
				vectorReservation.push_back(Reservation(Date(annee, mois, jour), nombreNuit, hotel, vectorRoom[i], client)); //MODIFIE
				std::cout << "Recapitulatif : " << vectorReservation.back();
				return;
			}
		}
	}
	std::cout << "aucune chambre libre" << std::endl;
}

//Fonction permettant de savoit si une reservation peut se faire ou non en fonction des dates
bool freeDate(Date d, int nbNuit, Reservation reserv)
{
	std::vector<int> reservDate;
	std::vector<int> askedDate;
	Date start = reserv.getDateStart();

	for (int i = 0; i < nbNuit; i++)
		askedDate.push_back(convert(d + i));

	for (int i = 0; i < reserv.getNombreNuit(); i++)
		reservDate.push_back(convert(start + i));

	for (int i = 0; i < askedDate.size(); i++)
		for (int j = 0; j < reservDate.size(); j++)
			if (askedDate[i] == reservDate[j])
				return 0;

	return 1;
}

//Affichage de toutes les reservations
void displayAllReservations(std::vector<Reservation>& vectorReservation)
{
	std::cout << "Affichage de toutes les reservations : " << std::endl;
	for (int i = 0; i < vectorReservation.size(); i++)
	{
		std::cout << vectorReservation[i] << std::endl;
	}
}

//Affichage d'une reservation renseignée par son numero
void displayReservation(int number, std::vector<Reservation>& vectorReservation)
{
	for (int i = 0; i < vectorReservation.size(); i++)
	{
		if (number == vectorReservation[i].getId())
		{
			std::cout << "Affichage de la reservation " << number << std::endl;
			std::cout << vectorReservation[i];
		}
	}
}

void reservationCustomer(std::string id, std::vector<Reservation>& vectorReservation)
{
	int compte = 0;
	std::cout << "Reservation pour le client : " << id << std::endl;
	for (int i = 0; i < vectorReservation.size(); i++)
	{
		if (id == vectorReservation[i].getIdCustomer())
		{
			compte = 1;
			std::cout << "Reservation " << i + 1 << ": " << "\n" << vectorReservation[i] << std::endl;
		}
	}
	if (compte == 0)
		std::cout << "Ce client n'a pas encore de reservation";
}

void updateReservation(int numberOfReservation, std::vector<Reservation>& vectorReservation, std::vector<Room>& vectorRoom) //Pb si veut reserver le meme jour mais nb de nuits differents
{
	std::cout << "Mise a jour de la reservation " << numberOfReservation << std::endl;
	int jour = 0, mois = 0, annee = 0, nombreNuit = 0;
	std::string type;
	Date d = askedDate();
	std::cout << "Entrez un nombre de nuit : ";
	std::cin >> nombreNuit;

	std::cout << "Entrez le type de chambre souhaite : ";
	std::cin >> type;
	bool reserved;
	for (int j = 0; j < vectorRoom.size(); j++)
	{
		if (vectorRoom[j].getType() == type)
		{
			std::vector<bool> vectorBool;
			std::vector<bool> vect2;
			for (int i = 0; i < vectorReservation.size(); i++)
			{
				if (vectorReservation[i].getIdRoom() == vectorRoom[j].getNumero())
				{
					if (vectorReservation[i].getId() != numberOfReservation)
					{
						vectorBool.push_back(freeDate(d, nombreNuit, vectorReservation[i]));
					}
					vect2.push_back(1);
				}
				else
				{
					vect2.push_back(0);

				}
			}
			bool find = 0;
			bool find2 = 0;
			for (int i = 0; i < vect2.size(); i++)
			{
				if (vect2[i] == 1)
				{
					find2 = 1;
					break;
				}
			}
			if (find2 == 0)
			{
				vectorReservation[numberOfReservation - 1].setDateStart(d);
				vectorReservation[numberOfReservation - 1].setNombreNuit(nombreNuit);
				vectorReservation[numberOfReservation - 1].setRoomId(vectorRoom[j].getNumero());
				return;
			}

			for (int i = 0; i < vectorBool.size(); i++)
			{
				if (vectorBool[i] == 0)
				{
					find = 1;
					break;
				}
			}
			if (find == 0)
			{
				vectorReservation[numberOfReservation-1].setDateStart(d);
				vectorReservation[numberOfReservation-1].setNombreNuit(nombreNuit);
			}
		}
	}	
}

Date askedDate()
{
	int jour = 0, mois = 0, annee = 0, nombreNuit = 0;
	std::cout << "Entrez un jour : ";
	std::cin >> jour;
	std::cout << "Entrez un mois : ";
	std::cin >> mois;
	std::cout << "Entrez une annee : ";
	std::cin >> annee;
	return Date(annee, mois, jour);
}

void delReservation(int numberOfReservation, std::vector<Reservation>& vectorReservation)
{
	for (int i = 0; i < vectorReservation.size(); i++)
	{
		if (numberOfReservation == vectorReservation[i].getId())
		{
			std::cout << "Suppression de la reservation " << vectorReservation[i].getId() << std::endl;
			vectorReservation.erase(vectorReservation.begin()+i);
		}
	}
}

