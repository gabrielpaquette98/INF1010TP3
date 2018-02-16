/********************************************
* Titre: Travail pratique #3 - ProduitOrdinaire.h
* Date: 16 février 2018
* Auteur: 1894061 & 1899088
*******************************************/


#include <string>
#include <iostream>
#include "ProduitOrdinaire.h"
#include "Fournisseur.h"
using namespace std;


ProduitOrdinaire::ProduitOrdinaire(Fournisseur & fournisseur, const string & nom, int reference, double prix, TypeProduit type, bool estTaxable)
	: Produit(fournisseur, nom, reference, prix, type), estTaxable_{ estTaxable }
{
}

//Méthode d'accès 
bool ProduitOrdinaire::obtenirEstTaxable() const
{
	return estTaxable_;
}

//Méthode de modification
void ProduitOrdinaire::modifierEstTaxable(bool estTaxable)
{
	estTaxable_ = estTaxable;
}


//Surcharge des opérateurs de stream
// penser à utiliser static_cast<T>(Objet).
ostream & operator<<(ostream & os, const ProduitOrdinaire & produit)
{
	// La surcharge de l’opérateur << pour afficher un produit ordinaire. 
	// Utilisez une forme d’affichage similaire à la classe Produit. Considérez 
	// l’attribut estTaxable_ dans l’affichage.

	os << static_cast<Produit>(produit)
		<< "\t Est taxable : " << boolalpha << produit.estTaxable_ << endl;
	return os;
}

istream & operator>>(istream & is, ProduitOrdinaire & produit)
{
	// La surcharge de l’opérateur >> qui fait appel à la surcharge de 
	// l’opérateur >> de la classe Produit et ajoute la lecture de l’attribut estTaxable_
	return is >> static_cast<Produit>(produit) >> produit.estTaxable_;
}
