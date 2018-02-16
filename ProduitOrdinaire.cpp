/********************************************
* Titre: Travail pratique #3 - ProduitOrdinaire.h
* Date: 16 f�vrier 2018
* Auteur: 1894061 & 1899088
*******************************************/


#include <string>
#include <iostream>
#include "ProduitOrdinaire.h"
#include "Fournisseur.h"
using namespace std;

/**
* Constructeur de ProduitAuxEncheres
* \param {Fournisseur& fournisseur} R�f�rence sur le fournisseur
* \param {const string& nom} Nom du produit
* \param {int reference} Num�ro de r�f�rence du produit
* \param {double prix} Prix du produit
*/
ProduitOrdinaire::ProduitOrdinaire(Fournisseur & fournisseur, const string & nom, int reference, double prix, bool estTaxable)
	: Produit(fournisseur, nom, reference, prix, TypeProduitOrdinaire), estTaxable_{ estTaxable }
{
}

/**
* M�thode d'acc�s � la valeur de v�rit� repr�sentant l'applicabilit� de taxes
* \return {bool} la valeur de v�rit� repr�sentant l'applicabilit� de taxes
*/
bool ProduitOrdinaire::obtenirEstTaxable() const
{
	return estTaxable_;
}

/**
* M�thode de modification de la valeur de v�rit� repr�sentant l'applicabilit� de taxes
* \param {bool} la nouvelle valeur de v�rit� repr�sentant l'applicabilit� de taxes
*/
void ProduitOrdinaire::modifierEstTaxable(bool estTaxable)
{
	estTaxable_ = estTaxable;
}


/**
* Surcharge de l'op�rateur << en utilisant celui de Produit par cast et 
* en ajoutant les attributs supppl�mentaires
* \param {ostream& os} flot de sortie
* \param {const ProduitOrdinaire& produit} produit qui sera �crit � la sortie du stream
* \return {ostream& os} flot de sortie
*/
ostream & operator<<(ostream & os, const ProduitOrdinaire & produit)
{
	os << static_cast<Produit>(produit)
		<< "\t Est taxable : " << boolalpha << produit.estTaxable_ << endl;
	return os;
}

/**
* Surcharge de l'op�rateur >> en utilisant celui de Produit par cast et
* en ajoutant les attributs supppl�mentaires
* \param {istream& is} flot d'entr�e
* \param {ProduitOrdinaire& produit} produit qui sera g�n�r� avec l'entr�e
* \return {istream& is} flot d'entr�e
*/
istream & operator>>(istream & is, ProduitOrdinaire & produit)
{
	return is >> static_cast<Produit>(produit) >> produit.estTaxable_;
}
