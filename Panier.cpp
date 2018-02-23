/********************************************
* Titre: Travail pratique #3 - Panier.cpp
* Date: 
* Auteur: 
*******************************************/

#include "Panier.h"
using namespace std;

Panier::Panier(int idClient) {
	idClient_ = idClient;
}


Panier::~Panier()
{
	contenuPanier_.clear();
}

// methodes d'accès
vector<Produit*>  Panier::obtenirContenuPanier()const
{
	return contenuPanier_;
}

int Panier::obtenirNombreContenu() const
{
	return (int)contenuPanier_.size();
}


int Panier::obtenirIdClient() const {
	return idClient_;
}

double Panier::obtenirTotalApayer() const {
	return totalAPayer_;
}


double Panier::calculerTotalApayer()  const
{
	 // TODO rechercher les objets ProduitAuxEncheres
	double total = 0.0;
	for (int i = 0; i < contenuPanier_.size(); i++)
	{
		if (contenuPanier_[i]->retournerType() == TypeProduitAuxEncheres)
		{
			// TODO verifier si id du client ayant fait la > mise est id du client possedant ce panier
			ProduitAuxEncheres* prodObserve = static_cast<ProduitAuxEncheres*>(contenuPanier_[i]);
			if (prodObserve->obtenirIdentifiantClient() == idClient_)
			{
				// TODO Ajouter le montant de ce produit dans totalAPayer_
				total = totalAPayer_ + prodObserve->obtenirPrix();
			}
		}
	}
	return total;
}



void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}


void Panier::modifierIdClient(int idClient) {
	idClient_ = idClient;
}

void Panier::appliquerTaxe(Produit * prod)
{
	prod->modifierPrix(prod->obtenirPrix*(1 + TAUX_TAXE)); // Ajout des taxes
}

void Panier::ajouter(Produit * prod)
{
	if (prod->retournerType() == TypeProduitOrdinaire)
	{
		if (static_cast<ProduitOrdinaire*>(prod)->obtenirEstTaxable())
		{
			appliquerTaxe(prod);
		}
	}

	contenuPanier_.push_back(prod);
}

void Panier::livrer()
{
	totalAPayer_ = 0;
	contenuPanier_.clear();
}

Produit* Panier::trouverProduitPlusCher()
{
	if (contenuPanier_.empty())
		return nullptr;

	Produit* prodPlusChere = contenuPanier_[0];
	for (unsigned int i = 1; i < contenuPanier_.size(); i++)
		if (*contenuPanier_[i] > *prodPlusChere)
			prodPlusChere = contenuPanier_[i];

	return prodPlusChere;
}

ostream & operator<<(ostream & os,  const Panier & panier)
{
	os << "Votre Panier: " << endl;
	for (int i = 0; i < panier.obtenirNombreContenu(); i++)
	{
		if (panier.obtenirContenuPanier()[i]->retournerType() == TypeProduitOrdinaire)
		{
			ProduitOrdinaire* prodOrdinaireAAfficher = static_cast<ProduitOrdinaire*>(panier.obtenirContenuPanier()[i]);
			os << '\t' << *prodOrdinaireAAfficher << endl;
		}
		else if (panier.obtenirContenuPanier()[i]->retournerType() == TypeProduitAuxEncheres)
		{
			ProduitAuxEncheres* prodEncheresAAfficher = static_cast<ProduitAuxEncheres*>(panier.obtenirContenuPanier()[i]);
			os << '\t' << *prodEncheresAAfficher << endl;
		}
		else {
			os << '\t' << "Produit invalide" << endl;
		}
	}
	return os;
}
