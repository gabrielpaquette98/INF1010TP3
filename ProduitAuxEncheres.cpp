/********************************************
* Titre: Travail pratique #3 - ProduitAuxEncheres.cpp
* Date: 16 f�vrier 2018
* Auteur: 1894061 & 1899088
*******************************************/

#include "ProduitAuxEncheres.h"

/**
* Constructeur de ProduitAuxEncheres
* \param {Fournisseur& fournisseur} R�f�rence sur le fournisseur
* \param {const string& nom} Nom du produit
* \param {int reference} Num�ro de r�f�rence du produit
* \param {double prix} Prix du produit
*/
ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur & fournisseur, const string & nom, int reference, double prix)
	: Produit(fournisseur, nom, reference, prix, TypeProduitAuxEncheres), prixBase_{ 0 }, identifiantClient_{ 0 }
{
}

/**
* M�thode d'acc�s � l'identifiant du client avec la plus grosse mise
* \return {int} le num�ro d'identification du client avec la plus grosse mise
*/
int ProduitAuxEncheres::obtenirIdentifiantClient() const
{
	return identifiantClient_;
}

/**
* M�thode d'acc�s au prix de base du produit
* \return {double} le prix de base du produit
*/
double ProduitAuxEncheres::obtenirPrixBase() const
{
	return prixBase_;
}

/**
* M�thode de modification de l'identifiant du client avec la plus grosse mise
* \param {int identifiantClient} nouvel identifiant du client avec la plus grosse mise
*/
void ProduitAuxEncheres::modifierIdentifiantClient(int identifiantClient)
{
	identifiantClient_ = identifiantClient;
}

/**
* M�thode de modification du prix de base du produit
* \param {double prixBase} nouveau prix de base du produit
*/
void ProduitAuxEncheres::modifierPrixBase(double prixBase)
{
	prixBase_ = prixBase;
}

/**
* Surcharge de l'op�rateur >> en utilisant celui de Produit par cast
* \param {istream& is} flot d'entr�e
* \param {ProduitAuxEncheres& produit} produit qui sera g�n�r� avec l'entr�e
* \return {istream& is} flot d'entr�e
*/
istream & operator>>(istream & is, ProduitAuxEncheres & produit)
{
	return is >> static_cast<Produit>(produit);
}

/**
* Surcharge de l'op�rateur << en utilisant celui de Produit par cast
* \param {ostream& os} flot de sortie
* \param {const ProduitAuxEncheres& produit} produit qui sera �crit � la sortie du stream
* \return {ostream& os} flot de sortie
*/
ostream & operator<<(ostream & os, const ProduitAuxEncheres & produit)
{
	os << static_cast<Produit>(produit)
		<< "\t Prix de base : " << produit.prixBase_ << endl
		<< "\t Highest bidder ID : " << produit.identifiantClient_ << endl;

	return os;
}
