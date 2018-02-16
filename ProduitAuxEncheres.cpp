/********************************************
* Titre: Travail pratique #3 - ProduitAuxEncheres.cpp
* Date: 16 février 2018
* Auteur: 1894061 & 1899088
*******************************************/

#include "ProduitAuxEncheres.h"

ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur & fournisseur, const string & nom, int reference, double prix, TypeProduit type)
	: Produit(fournisseur, nom, reference, prix, type), prixBase_{ 0 }, identifiantClient_{ 0 }
{
	/*Un constructeur par paramètres et par défaut utilisant le constructeur 
	de la classe Produit et initialisant le prixBase_ (0 par défaut) et 
	identifiantClient_ (défaut à 0);*/
}

//Méthodes d'accès
int ProduitAuxEncheres::obtenirIdentifiantClient() const
{
	return identifiantClient_;
}

double ProduitAuxEncheres::obtenirPrixBase() const
{
	return prixBase_;
}

//Méthodes de modification
void ProduitAuxEncheres::modifierIdentifiantClient(int identifiantClient)
{
	identifiantClient_ = identifiantClient;
}

void ProduitAuxEncheres::modifierPrixBase(double prixBase)
{
	prixBase_ = prixBase;
}

//Surcharge des opérateurs d'affichage 
istream & operator>>(istream & is, ProduitAuxEncheres & produit)
{
	// TODO: insert return statement here
	/*La surcharge de l’opérateur >> qui fait seulement appel à la surcharge de l’opérateur >> de la classe Produit.*/
	return is >> static_cast<Produit>(produit);
}

ostream & operator<<(ostream & os, const ProduitAuxEncheres & produit)
{
	// TODO: insert return statement here
	/*surcharge de l’opérateur << pour afficher un produit aux enchères. 
	Utilisez une forme d’affichage similaire à la classe Produit. Considérez 
	les attributs prixBase_et identifiantClient_ dans l’affichage.*/
	os << static_cast<Produit>(produit)
		<< "\t Prix de base : " << produit.prixBase_ << endl
		<< "\t Highest bidder ID : " << produit.identifiantClient_ << endl;

	return os;
}
