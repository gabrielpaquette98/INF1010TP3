/********************************************
* Titre: Travail pratique #3 - Produit.cpp
* Date: 16 février 2018
* Auteur: 1894061 & 1899088
*******************************************/

#include "Produit.h"

/**
* Constructeur de Produit qui ajoute le produit au catalogue du fournisseur
* \param {Fournisseur& fournisseur} Référence sur le fournisseur
* \param {const string& nom} Nom du produit
* \param {int reference} Numéro de référence du produit
* \param {double prix} Prix du produit
* \param {TypeProduit type} Type du produit, doit ProduitAuxEncheres ou ProduitOrdinaire
*/
Produit::Produit(Fournisseur& fournisseur, const string& nom, int reference, double prix, TypeProduit type) :
	fournisseur_{ fournisseur },
	nom_{ nom },
	reference_{ reference },
	prix_{ prix },
	type_ { type }
{
	fournisseur_.ajouterProduit(this);
}

/**
* Destructeur de Produit qui le retire du catalogue du fournisseur
*/
Produit::~Produit() {
	fournisseur_.enleverProduit(this);
}

// Methodes d'acces
string Produit::obtenirNom() const
{
	return nom_;
}

int Produit::obtenirReference() const
{
	return reference_;
}

double Produit::obtenirPrix() const
{
	return prix_;
}

/**
* Méthode d'accès à la référence du fournisseur
* \return {Fournisseur&} Une référence sur le fournisseur du produit
*/
Fournisseur& Produit::obtenirFournisseur() const
{
	return fournisseur_;
}

/**
* Méthode d'accès au type du produit
* \return {TypeProduit} Le type du produit
*/
TypeProduit Produit::retournerType() 
{
	return type_;
}

// Methodes de modification
void Produit::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Produit::modifierReference(int reference)
{
	reference_ = reference;
}

void Produit::modifierPrix(double prix)
{
	prix_ = prix;
}


bool Produit::operator>(const Produit & produit) const
{
	return prix_ > produit.prix_;
}

bool Produit::operator<(const Produit & produit) const
{
	return prix_ < produit.prix_;
}

bool Produit::operator==(const Produit & produit) const
{
	return (nom_ == produit.nom_ &&
			prix_ == produit.prix_ &&
			reference_ == produit.reference_);
}

// pour lire un type enumeré
inline istream & operator >> (istream & is, TypeProduit & typeProduit) {
	unsigned int type = 0;
	if (is >> type)
		typeProduit = static_cast<TypeProduit>(type);
	return is;
}

istream & operator>>(istream & is, Produit & produit)
{
	return is >> produit.nom_ >> produit.reference_ >> produit.prix_ >> produit.type_;
}

 ostream & operator<<(ostream & os, const Produit & produit)
{
	 os << "Produit :"
		 << " nom: " << produit.obtenirNom() << endl
		 << " \t \t ref : " << produit.obtenirReference() << endl
		 << " \t \t prix actuel : " << produit.obtenirPrix() << endl
		 << "\t Fournisseur " << produit.obtenirFournisseur().obtenirNom() << endl;
	 return os;
}


