#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct membre{
	int id_membre;
	string nom_membre;
	string prenom_membre;
	int sexe;
	int id_school;
	string filiere;
	int niveau;
	string poste;
	string appreciation;
};
struct activite{
	int id_activite;
	string nom_activite;
	string description_activite;
};

struct school{
	int id_school;
	string nom_school;
	school(int id, string nom) : id_school(id), nom_school(nom) {}
};

struct club{
	int id_club;
	string nom_club;
	vector<membre> bureau;
	vector<membre> membres;
	vector<activite> activites;
	int nombre_membres;
	int id_school;
};

vector<school> schools = {
	{1, "SET"},
	{2, "SOM"},
	{3, "SLC"},
	{4, "IST"},
};

void Saisie_Club(vector<club>& clubs1);
void afficher_schools();
void Afficher_Clubs(vector<club>& clubs1);
string afficher_nom_school(int id);
void ajouterMembre(vector<club>& clubs1, int clubChoisi);
void ajouterActivite(vector<club>& clubs1, int clubChoisi);
void afficher_activites(vector<club> clubs1, int clubChoisi);
void afficher_membres(vector<club> clubs1, int clubChoisi);
void donner_appreciation(vector<club>& clubs1, int clubChoisi);
void afficher_bureau(vector<club> clubs1, int clubChoisi);
void donner_repartition_schools(vector<club>& clubs1, int Clubchoisi);
void donner_repartition_genre(vector<club>& clubs1, int Clubchoisi);


int main(){
	
	vector<club> clubs;
	int choix;
	int choixClub;
	char continuer;
	
	cout << "Bienvenue dans ce programme de Gestion des clubs" << endl;
		
	do{
		cout << " Voici le menu :" << endl
		<< "1 - Ajouter un club" << endl
		<< "2 - Afficher la liste des clubs" << endl
		<< "3 - Ajouter des membres a club" << endl
		<< "4 - Ajouter des activites a un club" << endl
		<< "5 - Afficher le bureau d'un club " << endl
		<< "6 - Afficher les activites d'un club" << endl
		<< "7 - Donner une appreciation a un membre de club" << endl
		<< "8 - Donner la repartition d'une school dans un club" << endl
		<< "9 - Donner la repartition homme/femme d'un club" << endl
		<< "10 - Quitter" << endl;
		cout << "Que faire ?" << endl;
		cin >> choix;
		switch(choix) {
			case 1: 
				// code pour ajouter un club
				do{
					Saisie_Club(clubs);
					cout << "Ajouter un autre club ? Oui(o)/Non(n)" << endl;
					cin >> continuer;
				}while(continuer != 'n');
				break;
				
			case 2:
				// code pour afficher les clubs
				if(clubs.size() >= 1){
					cout << "Voici les clubs que vous avez ajoute" << endl;
					Afficher_Clubs(clubs);
				}
				else{
					cout << "Vous n'avez encore aucun club !" << endl;
				}
				break;
				
			case 3: 
				// code pour ajouter un membre a un club
				
				if(clubs.size() >= 1){
					Afficher_Clubs(clubs);
					cout << "A quel club voulez-vous ajouter un membre ?" << endl;
					cin >> choixClub;
					do{
						ajouterMembre(clubs, choixClub);
						cout << "Ajouter un autre membre ? Oui(o)/Non(n)" << endl;
						cin >> continuer;
					}while(continuer != 'n');
				}
				else{
					cout << "Vous n'avez encore aucun club !" << endl;
				}
				break;
			case 4: 
				// code pour ajouter une activite a un club
				
				if(clubs.size() >= 1){
					Afficher_Clubs(clubs);
					cout << "A quel club voulez-vous ajouter une activite ?" << endl;
					cin >> choixClub;
					do{
						ajouterActivite(clubs, choixClub);
						cout << "Ajouter une autre activite ? Oui(o)/Non(n)" << endl;
						cin >> continuer;
					}while(continuer != 'n');
				}
				else{
					cout << "Vous n'avez encore aucun club !" << endl;
				}
				break;
			
			case 5:
				//code pour afficher le bureau d'un club
				if(clubs.size() >= 1){
					Afficher_Clubs(clubs);
					cout << "De quel club voulez vous afficher le bureau ?" << endl;
					cin >> choixClub;
					afficher_bureau(clubs, choixClub);
				}
				else{
					cout << "Vous n'avez encore aucun club !" << endl;
				}
				break;
		
			case 6: 
				// code pour afficher les activites d'un club
				if(clubs.size() >= 1){
					Afficher_Clubs(clubs);
					cout << "De quel club voulez vous afficher les activites ?" << endl;
					cin >> choixClub;
					afficher_activites(clubs, choixClub);
				}
				else{
					cout << "Vous n'avez encore aucun club !" << endl;
				}
				
				break;
			
			case 7 :
				//code pour donner une appreciation à un membre d'un club
				if(clubs.size() >= 1){
						Afficher_Clubs(clubs);
						cout << "a quel club appartient le membre ?" << endl;
						cin >> choixClub;
						
						do{
							donner_appreciation(clubs,  choixClub);
							cout << "Donner une appreciation a un autre membre ? Oui(o)/Non(n)" << endl;
							cin >> continuer;
						}while(continuer != 'n');	
					}
				else{
					cout << "Vous n'avez encore aucun club !" << endl;
				}
				break;
				
			case 8:
				//Code pour donner la repartition des schools par club
				if(clubs.size() >= 1){
						do{
							Afficher_Clubs(clubs);
							cout << "Pour quel club voulez voir la repartition ?" << endl;
							cin >> choixClub;
							donner_repartition_schools(clubs, choixClub);
							cout << endl;
							cout << "Voir la repartition d'un autre club ? Oui(o)/Non(n)" << endl;
							cin >> continuer;
						}while(continuer != 'n');	
					}
				else{
					cout << "Vous n'avez encore aucun club !" << endl;
				}
				break;
				
			case 9:
				//code pour donner la repartition des clubs par genre
				if(clubs.size() >= 1){
						do{
							Afficher_Clubs(clubs);
							cout << "Pour quel club voulez voir la repartition ?" << endl;
							cin >> choixClub;
							donner_repartition_genre(clubs, choixClub);
							cout << endl;
							cout << "Voir la repartition d'un autre club ? Oui(o)/Non(n)" << endl;
							cin >> continuer;
						}while(continuer != 'n');	
					}
				else{
					cout << "Vous n'avez encore aucun club !" << endl;
				}
				break;
			
			case 10: 
				// Quitter le programme
				cout << "Aurevoir, bye" << endl;
				break;
				
			default :
				cout << "Choix invalide. Veuillez reessayer." << endl;
				break;
		}
	}
	while(choix != 10);
	
	
	return 0;
}

void Saisie_Club(vector<club>& clubs1){
	club current;
	
	cout << "Entrer l'id du club" << endl;
	cin >> current.id_club;
	cout << "Entrer le nom du club" << endl;
	cin >> current.nom_club;
	afficher_schools();
	cout << "Entrer l'id de la school" << endl;
	cin >> current.id_school;
	current.nombre_membres = 0;
	clubs1.push_back(current);
}

void afficher_schools(){
	for(size_t i(0); i < 4; ++i){
		cout << schools[i].id_school << " " << schools[i].nom_school << endl;
		cout << endl;
	}
}

void Afficher_Clubs(vector<club>& clubs1){
	club current;
	cout << "Liste des clubs" << endl << endl;
	for(size_t i(0); i < clubs1.size(); ++i){
		current = clubs1[i];
		cout << "ID du club : " << current.id_club << "	" << "Nom du club :" << current.nom_club
			<< "	"<< "school de rattachement: " << afficher_nom_school(current.id_school) 
			<< "	" << "Nombre de membres : " << current.nombre_membres << endl;
		cout  << endl;
	}
}

string afficher_nom_school(int id){
	size_t i;
	for(i = 0; i < 4; ++i){
		if(id == schools[i].id_school){
			break;
		}
	}
	return schools[i].nom_school;
}

void ajouterMembre(vector<club>& clubs1, int clubChoisi){
	membre current;
	int poste;
	cout << "Entrer l'id du membre" << endl;
	cin >> current.id_membre;
	cout << "Entrer le nom du membre" << endl;
	cin >> current.nom_membre;
	cout << "Entrer le prenom du membre" << endl;
	cin >> current.prenom_membre;
	cout << "Entrer le sexe du membre Homme(1) ou Femme(2)" << endl;
	cin >> current.sexe;
	afficher_schools();
	cout << "Choisir la school du membre" << endl;
	cin >> current.id_school;
	cout << "Entrer la filiere du membre" << endl;
	cin >> current.filiere;
	cout << "Entrer le niveau du membre : 1 = L1; 2 = L2; 3 = L3" << endl;
	cin >> current.niveau;
	cout << "Quel est le poste du membre ?" << endl
		<< "1 - President(e)" << endl
		<< "2 - Vice-president(e)"<< endl
		<< "3 - Secretaire generale" << endl
		<< "4 - Tresorier(e)" << endl
		<< "5 - Sympatisant" << endl;
	do{
		cin >> poste;
		switch(poste){
			case 1: 
				current.poste = "President(e)";
				break;
			case 2:
				current.poste = "Vice-president(e)";
				break;
			case 3:
				current.poste = "Secretaire";
				break;
			case 4:
				current.poste = "Tresorier(e)";
				break;
			case 5:
				current.poste = "Sympatisant";
				break;
		}
	}while(poste < 1 or poste > 5);
	
	for(size_t i(0); i < clubs1.size(); ++i){
		
		if(clubChoisi == clubs1[i].id_club){
			
			clubs1[i].membres.push_back(current);
			
			if(poste >= 1 and poste < 5){
				clubs1[i].bureau.push_back(current);	
			}
			
			clubs1[i].nombre_membres++;
			break;
		}
	}
}


void ajouterActivite(vector<club>& clubs1, int clubChoisi){
	activite current;
	cout << "Entrer l'id de l'activite" << endl;
	cin >> current.id_activite;
	cout << "Entrer le nom de l'activite" << endl;
	cin >> current.nom_activite;
	cout << "Entrer la description de l'activite (""utiliser des underscores comme espace)" << endl;
	cin >> current.description_activite;
	for(size_t i(0); i < clubs1.size(); ++i){
		if(clubChoisi == clubs1[i].id_club){
			clubs1[i].activites.push_back(current);
			break;
		}
	}
}

void afficher_activites(vector<club> clubs1, int clubChoisi){
	club current;
	for(size_t i(0); i < clubs1.size(); ++i){
		if(clubChoisi == clubs1[i].id_club){
			current = clubs1[i];
			break;
		}
	}
	if(current.activites.size() >= 1){
		for(size_t i(0); i < current.activites.size(); ++i){
			cout << "ID : " << current.activites[i].id_activite << "	"
				<< "Nom : " << current.activites[i].nom_activite << "	"
				<< "Description : " << current.activites[i].description_activite << endl;
		}
	}
	else{
		cout << "Ce club n'as pas encore d'activites' !" << endl;
	}
	
}

void afficher_membres(vector<club> clubs1, int clubChoisi){
	club current;
	for(size_t i(0); i < clubs1.size(); ++i){
		if(clubChoisi == clubs1[i].id_club){
			current = clubs1[i];
			break;
		}
	}
	if(current.membres.size() >= 1){
		for(size_t i(0); i < current.membres.size(); ++i){
			cout << "ID : " << current.membres[i].id_membre << "	"
				<< "Nom : " << current.membres[i].nom_membre << "	"
				<< "Prenom : " << current.membres[i].prenom_membre << "	";
			if(current.membres[i].sexe == 1){
				cout << "Sexe : Homme		";
			}
			else{
				cout << "Sexe : Femme		"; 
			}
			cout << "School : " << afficher_nom_school(current.membres[i].id_school) << "	"
				<< "Filiere : " << current.membres[i].filiere << "	"
				<< "Niveau : " << current.membres[i].niveau << "	"
				<< "Poste : " << current.membres[i].poste << "	"
				<< "Appreciation : " << current.membres[i].appreciation << endl << endl;
				
		}
	}
	else{
		cout << "Ce club n'as pas encore de membres !" << endl;
	}
	
}
void afficher_bureau(vector<club> clubs1, int clubChoisi){
	club current;
	for(size_t i(0); i < clubs1.size(); ++i){
		if(clubChoisi == clubs1[i].id_club){
			current = clubs1[i];
			break;
		}
	}
	if(current.bureau.size() >= 1){
		for(size_t i(0); i < current.bureau.size(); ++i){
		cout << "ID : " << current.bureau[i].id_membre << "	"
			<< "Nom : " << current.bureau[i].nom_membre << "	"
			<< "Prenom : " << current.bureau[i].prenom_membre << "	";
		if(current.membres[i].sexe == 1){
			cout << "Sexe : Homme	";
		}
		else{
			cout << "Sexe : Femme	"; 
		}
		cout << "School : " << afficher_nom_school(current.bureau[i].id_school) << "	"
			<< "Filiere : " << current.bureau[i].filiere << "	"
			<< "Niveau : " << current.bureau[i].niveau << "	"
			<< "Poste : " << current.bureau[i].poste << "	"
			<< "Appreciation : " << current.bureau[i].appreciation << endl;
	}
	}
	else{
		cout << "Ce club n'as pas encore de bureau !" << endl;
	}
	
}

void donner_appreciation(vector<club>& clubs1, int clubChoisi){
	size_t i, j;
	for(i = 0; i < clubs1.size(); ++i){
		if(clubChoisi == clubs1[i].id_club){
			break;
		}
	}
	
	if(clubs1[i].membres.size() >= 1){
		afficher_membres(clubs1, clubChoisi);
		int choixMembre;
		cout << "A quel membre voulez vous donner une appreciation ?" << endl;
		cin >> choixMembre;
		for(j = 0; j < clubs1[i].membres.size(); ++j){
			if(clubs1[i].membres[j].id_membre == choixMembre){
				break;
			}
		}
		cout << "Entrer l'appreciation de " << clubs1[i].membres[j].prenom_membre << " " << clubs1[i].membres[j].nom_membre << endl;
		cin >> clubs1[i].membres[j].appreciation;
	}
	else{
		cout << "Ce club n'a encore aucun membre !" << endl;
	}
}
void donner_repartition_schools(vector<club>& clubs1, int Clubchoisi){
	double nbre_membres, nbre_school;
	club current_club;
	membre current_membre;
	for(size_t i(0); i < clubs1.size(); ++i){
		
		if(clubs1[i].id_club == Clubchoisi){
			current_club = clubs1[i];
			nbre_membres = current_club.nombre_membres;
			
			if(current_club.membres.size() >= 1){
				
				cout << "Pour le " << current_club.nom_club << ":" << endl;
				
				for(int id_school(1); id_school <= 4; ++id_school){
					
					nbre_school = 0;
					for(size_t j(0); j < current_club.membres.size(); ++j){
						current_membre = current_club.membres[j];
						if(current_membre.id_school == id_school){
							nbre_school++;
						}
					}
					cout << afficher_nom_school(id_school) << ": " << (nbre_school/nbre_membres)*100 << "%		";
				}
			}
			else{
				cout << "Ce club n'a pas encore de membres !" << endl;
			}
			
			break;	
		}	
	}
}
void donner_repartition_genre(vector<club>& clubs1, int Clubchoisi){
	double homme(0), femme(0), nbre_membres; 
	
	for(size_t i(0); i < clubs1.size(); ++i){
		if(clubs1[i].id_club == Clubchoisi){
			
			if(clubs1[i].membres.size() >= 1){
				nbre_membres = clubs1[i].nombre_membres;
				
				cout << "Pour le " << clubs1[i].nom_club << endl;
				
				for(size_t j(0); j < clubs1[i].membres.size();++j){
					
					if(clubs1[i].membres[j].sexe == 1){
						homme++;
					}
					else{
						femme++;
					}
				}
				cout << "Homme: " << (homme/nbre_membres)*100 << "%		"
					<< "Femme : " << (femme/nbre_membres)*100 << "%" << endl;
			}
			else{
				cout << "Ce club n'a pas encore de membres !" << endl;
			}
			
			break;	
		}
	}
}