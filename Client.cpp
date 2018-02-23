/********************************************
* Titre: Travail pratique #3 - Client.cpp
* Date: 16 février 2018 
* Auteur: 1894061 & 1899088
*******************************************/

#include "Client.h"
#include "Fournisseur.h"



Client::~Client()
{
	if (monPanier_ != nullptr)
		delete monPanier_;
}

Client::Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date)
	: Usager(nom, prenom, identifiant, codePostal)
	, dateNaissance_ {date}
	, monPanier_ {nullptr}
{

}

Client::Client(const Client & client) :
	Usager(client.obtenirNom(), client.obtenirPrenom(), client.obtenirIdentifiant(), client.obtenirCodePostal()),	
	dateNaissance_{ client.dateNaissance_ }
{
	if (client.monPanier_ == nullptr)
		monPanier_ = nullptr;
	else {
		monPanier_ = new Panier(client.obtenirIdentifiant());
		for (int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++) {
			monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);
		}
		int idClient = this->obtenirIdentifiant();
		monPanier_->modifierTotalAPayer(client.monPanier_->obtenirTotalApayer());
	}
}


// Methodes d'acces
long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}

Panier * Client::obtenirPanier() const
{
	return monPanier_;
}


// Methodes de modification
void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

// Autres méthodes
void Client::acheter(ProduitOrdinaire * prod)
{
	if (monPanier_ == nullptr)
		monPanier_ = new Panier(this->obtenirIdentifiant());
	monPanier_->ajouter(prod);
	// obtenir une note aléatoire
	int noteRnd = rand() % NIVEAUX_SATISFACTION;
	// faire la mise à jour de la satisfaction au fournisseur
	
	//cette ligne fait un reset des valeurs de satisfaction. 
	//Est-ce un fournisseur different a chaque fois?


	//CECI FAIT UNE COPIE! (il faut prendre sa ref)
	/*
	Fournisseur fournisseur = prod->obtenirFournisseur();
	*/
	Fournisseur& fournisseur = prod->obtenirFournisseur();

	fournisseur.noter(noteRnd);
}

void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
}


void Client::miserProduit(ProduitAuxEncheres* produitAuxEncheres, double montantMise) {
	// à faire
	// modification du prix de base
	// Vérifie si le montant de la mise est supérieur au prix actuel de l'enchère
	if (montantMise > produitAuxEncheres->obtenirPrixBase())
	{
		produitAuxEncheres->modifierPrixBase(montantMise);
		produitAuxEncheres->modifierIdentifiantClient(this->obtenirIdentifiant());
	}
	else
	{
		cout << "La mise n'est pas assez haute" << endl;
	}
}

Client & Client::operator=(const Client & client)
{
	if (this != &client) {
		this->modifierNom(client.obtenirNom());
		this->modifierPrenom(client.obtenirPrenom());
		this->modifierIdentifiant(client.obtenirIdentifiant());
		this->modifierCodePostal(client.obtenirCodePostal());
		dateNaissance_ = client.obtenirDateNaissance();
		if (client.monPanier_ != nullptr) {
			delete monPanier_;
			monPanier_ = new Panier(obtenirIdentifiant());
			for (int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++) {
				monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);
			}
		}
		else
			monPanier_ = nullptr;
	}
	return *this;
}


ostream & operator<<(ostream & os, const Client & client)
{
	os << static_cast<Usager>(client)
        << "\t Contenu du panier: " << endl;
	if (client.obtenirPanier() != nullptr) 
	{
		Panier panierDuClient = *client.obtenirPanier();
		for (int i = 0; i < panierDuClient.obtenirNombreContenu(); i++)
		{
			os << "\t \t" << *panierDuClient.obtenirContenuPanier()[i];
		}
	}
	else
		os << "Le panier est vide" << endl;


    return os;
}
