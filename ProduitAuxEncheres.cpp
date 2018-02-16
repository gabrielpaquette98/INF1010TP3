/********************************************
* Titre: Travail pratique #3 - ProduitAuxEncheres.cpp
* Date: 16 f�vrier 2018
* Auteur: 1894061 & 1899088
*******************************************/

#include "ProduitAuxEncheres.h"

ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur & fournisseur, const string & nom, int reference, double prix, TypeProduit type)
	: Produit(fournisseur, nom, reference, prix, type), prixBase_{ 0 }, identifiantClient_{ 0 }
{
	/*Un constructeur par param�tres et par d�faut utilisant le constructeur 
	de la classe Produit et initialisant le prixBase_ (0 par d�faut) et 
	identifiantClient_ (d�faut � 0);*/
}

//M�thodes d'acc�s
int ProduitAuxEncheres::obtenirIdentifiantClient() const
{
	return identifiantClient_;
}

double ProduitAuxEncheres::obtenirPrixBase() const
{
	return prixBase_;
}

//M�thodes de modification
void ProduitAuxEncheres::modifierIdentifiantClient(int identifiantClient)
{
	identifiantClient_ = identifiantClient;
}

void ProduitAuxEncheres::modifierPrixBase(double prixBase)
{
	prixBase_ = prixBase;
}

//Surcharge des op�rateurs d'affichage 
istream & operator>>(istream & is, ProduitAuxEncheres & produit)
{
	// TODO: insert return statement here
	/*La surcharge de l�op�rateur >> qui fait seulement appel � la surcharge de l�op�rateur >> de la classe Produit.*/
	return is >> static_cast<Produit>(produit);
}

ostream & operator<<(ostream & os, const ProduitAuxEncheres & produit)
{
	// TODO: insert return statement here
	/*surcharge de l�op�rateur << pour afficher un produit aux ench�res. 
	Utilisez une forme d�affichage similaire � la classe Produit. Consid�rez 
	les attributs prixBase_et identifiantClient_ dans l�affichage.*/
	os << static_cast<Produit>(produit)
		<< "\t Prix de base : " << produit.prixBase_ << endl
		<< "\t Highest bidder ID : " << produit.identifiantClient_ << endl;

	return os;
}
