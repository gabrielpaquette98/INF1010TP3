/********************************************
* Titre: Travail pratique #3 - ProduitAuxEncheres.h
* Date: 16 f�vrier 2018
* Auteur: 1894061 & 1899088
*******************************************/
#ifndef PRODUITAUXENCHERES_H
#define PRODUITAUXENCHERES_H

#include <string>
#include <iostream>
#include "Produit.h"
using namespace std;

class ProduitAuxEncheres : public Produit 
{

public:
	ProduitAuxEncheres(Fournisseur& fournisseur, const string& nom = "outil", int reference = 0,
		double prix = 0.0);
			
	int obtenirIdentifiantClient() const;
	double obtenirPrixBase() const;

	void modifierIdentifiantClient(int identifiantClient) ;
	void modifierPrixBase(double prixBase) ;

	friend istream& operator>>(istream& is, ProduitAuxEncheres& produit);
	friend ostream& operator<<(ostream& os, const ProduitAuxEncheres& produit);
	
private:		
	double prixBase_;	
	int identifiantClient_;
};
#endif