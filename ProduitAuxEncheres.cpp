/********************************************
* Titre: Travail pratique #3 - ProduitAuxEncheres.cpp
* Date: 16 février 2018
* Auteur: 1894061 & 1899088
*******************************************/

#include "ProduitAuxEncheres.h"

/**
* Constructeur de ProduitAuxEncheres
* \param {Fournisseur& fournisseur} Référence sur le fournisseur
* \param {const string& nom} Nom du produit
* \param {int reference} Numéro de référence du produit
* \param {double prix} Prix du produit
*/
ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur & fournisseur, const string & nom, int reference, double prix)
	: Produit(fournisseur, nom, reference, prix, TypeProduitAuxEncheres), prixBase_{ 0 }, identifiantClient_{ 0 }
{
}

/**
* Méthode d'accès à l'identifiant du client avec la plus grosse mise
* \return {int} le numéro d'identification du client avec la plus grosse mise
*/
int ProduitAuxEncheres::obtenirIdentifiantClient() const
{
	return identifiantClient_;
}

/**
* Méthode d'accès au prix de base du produit
* \return {double} le prix de base du produit
*/
double ProduitAuxEncheres::obtenirPrixBase() const
{
	return prixBase_;
}

/**
* Méthode de modification de l'identifiant du client avec la plus grosse mise
* \param {int identifiantClient} nouvel identifiant du client avec la plus grosse mise
*/
void ProduitAuxEncheres::modifierIdentifiantClient(int identifiantClient)
{
	identifiantClient_ = identifiantClient;
}

/**
* Méthode de modification du prix de base du produit
* \param {double prixBase} nouveau prix de base du produit
*/
void ProduitAuxEncheres::modifierPrixBase(double prixBase)
{
	prixBase_ = prixBase;
}

/**
* Surcharge de l'opérateur >> en utilisant celui de Produit par cast
* \param {istream& is} flot d'entrée
* \param {ProduitAuxEncheres& produit} produit qui sera généré avec l'entrée
* \return {istream& is} flot d'entrée
*/
istream & operator>>(istream & is, ProduitAuxEncheres & produit)
{
	return is >> static_cast<Produit>(produit);
}

/**
* Surcharge de l'opérateur << en utilisant celui de Produit par cast
* \param {ostream& os} flot de sortie
* \param {const ProduitAuxEncheres& produit} produit qui sera écrit à la sortie du stream
* \return {ostream& os} flot de sortie
*/
ostream & operator<<(ostream & os, const ProduitAuxEncheres & produit)
{
	os << static_cast<Produit>(produit)
		<< "\t Prix de base : " << produit.prixBase_ << endl
		<< "\t Highest bidder ID : " << produit.identifiantClient_ << endl;

	return os;
}
