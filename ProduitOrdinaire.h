/********************************************
* Titre: Travail pratique #3 - ProduitOrdinaire.h
* Date: 16 février 2018
* Auteur: 1894061 & 1899088
*******************************************/

#ifndef PRODUITORDINAIRE_H
#define PRODUITORDINAIRE_H

#include <string>
#include <iostream>
#include "Produit.h"

class ProduitOrdinaire : public Produit
{

public:
	
	ProduitOrdinaire(Fournisseur& fournisseur, 
		             const string& nom = "outil", int reference = 0,
		             double prix = 0.0, bool estTaxable = true);

	bool obtenirEstTaxable() const;
	void modifierEstTaxable(bool estTaxable);
	friend ostream& operator<<(ostream& os, const ProduitOrdinaire& produit);
	friend istream& operator>>(istream& is, ProduitOrdinaire& produit);

private:

	bool estTaxable_;
	
};

#endif