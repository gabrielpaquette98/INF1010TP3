/********************************************
* Titre: Travail pratique #3 - Fournisseur.cpp
* Date: 16 février 2018
* Auteur: 1894061 & 1899088
*******************************************/
#include "Fournisseur.h"

Fournisseur::Fournisseur(const string&  nom, const string& prenom, int identifiant, const string& codePostal)
    : Usager::Usager(nom, prenom, identifiant, codePostal)
    , contenuCatalogue_ { }
{
    for (int i = 0; i < NIVEAUX_SATISFACTION; i++) 
        satisfaction_.niveaux_[i] = 0;
}

vector<Produit*> Fournisseur::obtenirCatalogue() const
{
    return contenuCatalogue_;
}

Satisfaction Fournisseur::obtenirSatisfaction() const 
{
    return satisfaction_;
}

void Fournisseur::modifierSatisfaction(Satisfaction satisfaction)
{
    for (int i = 0; i < NIVEAUX_SATISFACTION; i++)
        satisfaction_.niveaux_[i] = satisfaction.niveaux_[i];
}

void Fournisseur::noter(int appreciation)
{
    satisfaction_.niveaux_[appreciation]++;
}

void Fournisseur::ajouterProduit(Produit* produit)
{
    contenuCatalogue_.push_back(produit);
}

void Fournisseur::enleverProduit(Produit* produit)
{
    int positionProduit = -1;
    for (int i = 0; i < contenuCatalogue_.size() ; i++)
    {
        if (contenuCatalogue_[i] == produit)
            positionProduit = i;
    }
    if (positionProduit != -1)
    {
        int positionARetirer = positionProduit-1;
        if (positionProduit == 1)
            positionARetirer = 1;
        if (positionARetirer == -1)
            positionARetirer = 0;
        contenuCatalogue_.erase(contenuCatalogue_.begin()+(positionARetirer));
    }
}

Fournisseur & Fournisseur::operator=(const Fournisseur & fournisseur)
{
	if (this != &fournisseur) {
		Usager temp(*this);
		temp = static_cast<Usager> (fournisseur);
        // Copier les attributs spécifiques à un Fournisseur (contenuCatalogue_)
        contenuCatalogue_.clear();
        for (int i = 0; i < fournisseur.obtenirCatalogue().size(); i++)
            contenuCatalogue_.push_back(fournisseur.obtenirCatalogue()[i]);
	}
	return *this;
}

ostream& operator<<(ostream & os, Fournisseur& fournisseur)
{
    os << static_cast<Usager>(fournisseur)
        << "\t satisfaction: " << endl;
    for (int i = 0; i < NIVEAUX_SATISFACTION; i++)
    {
        os << "\t \t" << "Niveau: " << (i + 1) << ": "
            << fournisseur.obtenirSatisfaction().niveaux_[i] << endl;
    }

    return os;
}