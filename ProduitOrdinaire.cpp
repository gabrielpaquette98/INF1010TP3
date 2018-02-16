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

/**
* Constructeur de ProduitAuxEncheres
* \param {Fournisseur& fournisseur} Référence sur le fournisseur
* \param {const string& nom} Nom du produit
* \param {int reference} Numéro de référence du produit
* \param {double prix} Prix du produit
*/
ProduitOrdinaire::ProduitOrdinaire(Fournisseur & fournisseur, const string & nom, int reference, double prix, bool estTaxable)
	: Produit(fournisseur, nom, reference, prix, TypeProduitOrdinaire), estTaxable_{ estTaxable }
{
}

/**
* Méthode d'accès à la valeur de vérité représentant l'applicabilité de taxes
* \return {bool} la valeur de vérité représentant l'applicabilité de taxes
*/
bool ProduitOrdinaire::obtenirEstTaxable() const
{
	return estTaxable_;
}

/**
* Méthode de modification de la valeur de vérité représentant l'applicabilité de taxes
* \param {bool} la nouvelle valeur de vérité représentant l'applicabilité de taxes
*/
void ProduitOrdinaire::modifierEstTaxable(bool estTaxable)
{
	estTaxable_ = estTaxable;
}


/**
* Surcharge de l'opérateur << en utilisant celui de Produit par cast et 
* en ajoutant les attributs suppplémentaires
* \param {ostream& os} flot de sortie
* \param {const ProduitOrdinaire& produit} produit qui sera écrit à la sortie du stream
* \return {ostream& os} flot de sortie
*/
ostream & operator<<(ostream & os, const ProduitOrdinaire & produit)
{
	os << static_cast<Produit>(produit)
		<< "\t Est taxable : " << boolalpha << produit.estTaxable_ << endl;
	return os;
}

/**
* Surcharge de l'opérateur >> en utilisant celui de Produit par cast et
* en ajoutant les attributs suppplémentaires
* \param {istream& is} flot d'entrée
* \param {ProduitOrdinaire& produit} produit qui sera généré avec l'entrée
* \return {istream& is} flot d'entrée
*/
istream & operator>>(istream & is, ProduitOrdinaire & produit)
{
	return is >> static_cast<Produit>(produit) >> produit.estTaxable_;
}
