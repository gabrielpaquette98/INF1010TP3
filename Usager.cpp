/********************************************
* Titre: Travail pratique #3 - Client.h
* Date: 2018-02-23
* Auteur: 1894061 et 1899088
*******************************************/

#include "Usager.h"
using namespace std;

/**
* Constructeur d'objets Usager
* \param {string&} nom nom de l'Usager
* \param {string&} prenom prenom de l'Usager
* \param {int} identifiant identifiant de l'Usager
* \param {string&} codePostal code postal de l'Usager
*/
Usager::Usager(const string&  nom, const string& prenom, int identifiant, const string& codePostal):
	nom_{ nom },
	prenom_{ prenom },
	identifiant_{ identifiant },
	codePostal_{ codePostal }	
{
}


string Usager::obtenirNom() const
{
	return nom_;
}


string Usager::obtenirPrenom() const
{
	return prenom_;
}


int Usager::obtenirIdentifiant() const
{
	return identifiant_;
}


string Usager::obtenirCodePostal() const
{
	return codePostal_;
}


void  Usager::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Usager::modifierPrenom(const string& prenom)
{
	prenom_ = prenom;
}

void Usager::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}

void Usager::modifierCodePostal(const string& codePostal)
{
	codePostal_ = codePostal;
}

/**
* Surcharge de l'opérateur = pour un Usager
* \param {Usager&} usager usager que l'on assigne à l'Usager courant
* \return {Usager} Usager qui a reçu l'affectation
*/
Usager &Usager::operator=(const Usager & usager)
{
	if (this != &usager) {
		nom_ = usager.nom_;
		prenom_ = usager.prenom_;
		identifiant_ = usager.identifiant_;
		codePostal_ = usager.codePostal_;		
	}
	return *this;
}

/**
* Surcharge de l'opérateur == pour un Usager. Compare l'identifiant
* \param {identifiant} identifiant à comparer
* \return {bool} true si identiques, false sinon
*/
bool Usager::operator==(int indentifiant) const {
	return identifiant_ == indentifiant;
};

bool Usager::operator == (const Usager & usager)
{
	return  *this == usager.obtenirIdentifiant();
}
bool operator==(int indentifiant, const Usager& usager) {
	return usager == indentifiant;
}

/**
* Surcharge de l'opérateur de flot de sortie pour afficher un Usager
* \param {ostream&} os flot de sortie
* \param {Usager&} usager Usager devant être affiché
* \return {ostream&} flot de sortie pour permettre les appels en cascades.
*/
ostream & operator<<(ostream & os, const Usager & usager)
{
	os << " Usager :";
	os << "\t nom : " << usager.obtenirNom() << endl
	   << "\t prenom : " << usager.obtenirPrenom() << endl
	   << "\t codePostal: " << usager.obtenirCodePostal() << endl;
	return os;
}

