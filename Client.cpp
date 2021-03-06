/********************************************
* Titre: Travail pratique #3 - Client.cpp
* Date: 16 février 2018 
* Auteur: 1894061 & 1899088
*******************************************/

#include "Client.h"
#include "Fournisseur.h"

/**
* Destructeur d'objet Client
*/
Client::~Client()
{
	if (monPanier_ != nullptr)
		delete monPanier_;
}

/**
* Constructeur d'objet Client avec paramètres
* \param {string&} nom nom du Client
* \param {string&} prenom prenom du Client
* \param {int} identifiant identifiant du Client
* \param {string&} codePostal code postal du Client
* \param {long} date date de naissance du Client
*/
Client::Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date)
	: Usager(nom, prenom, identifiant, codePostal)
	, dateNaissance_ {date}
	, monPanier_ {nullptr}
{

}

/**
* Constructeur d'objet Client par copie
* \param {Client&} client Client copié
*/
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

/**
* Méthode permettant d'acheter un Produit
* \param {ProduitOrdinaire*} prod produit acheté
*/
void Client::acheter(ProduitOrdinaire * prod)
{
	if (monPanier_ == nullptr)
		monPanier_ = new Panier(this->obtenirIdentifiant());
	monPanier_->ajouter(prod);
	int noteRnd = rand() % NIVEAUX_SATISFACTION;
	Fournisseur& fournisseur = prod->obtenirFournisseur();

	fournisseur.noter(noteRnd);
}

void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
}

/**
* Méthode permettant de miser sur un Produit aux enchères: ProduitAuxEncheres
* \param {ProduitAuxEncheres*} produitAuxEncheres produit sur lequel la mise est effectuée
* \param {double} montantMise montant de la mise
*/
void Client::miserProduit(ProduitAuxEncheres* produitAuxEncheres, double montantMise) {
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

/**
* Surcharge de l'opérateur =
* \param {Client&} client Client affecté
* \return {Client&} Client ayant reçu l'affectation
*/
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

/**
* Surcharge de l'opérateur de flot de sortie pour afficher un Client
* \param {ostream&} os flot de sortie
* \param {Client&} client Client devant être affiché
* \return {ostream&} flot de sortie pour permettre les appels en cascades.
*/
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
