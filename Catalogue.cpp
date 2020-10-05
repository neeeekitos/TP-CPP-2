/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 01/10/2020
    copyright            : (C) 2020 par Terekhov Nikita et Lecuyer Alison
    e-mail               : nikita.terekhov@insa-lyon.fr 
                         : alison.lecuyer@insa-lyon.fr
*************************************************************************/

//---- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::Afficher(ChainList * tr)
{
    Element * trajet = tr->GetPremierElement();

    if (trajet == nullptr) cout << "Aucun trajet" << endl;
    else {
        while (trajet != nullptr)
        {
            cout << "    --------------------------------" << endl; 
            trajet->data->Afficher();
            cout << "    --------------------------------" << endl; 
            trajet = trajet->suivant;
        }
    }
}

void Catalogue::Afficher()
{
    this->Afficher(&trajets);
}

void Catalogue::Rechercher(char * depart, char * destination)
{
    ChainList * resultatTrajets = trajets.RechercherParcours(depart, destination);
    Afficher(resultatTrajets);
    resultatTrajets->RetirerAll();
    delete resultatTrajets;
    delete[] depart;
    delete[] destination;
}

void Catalogue::Ajouter(Trajet * tr)
{
    trajets.AjouterElement(tr);
}

TrajetSimple * Catalogue::CreerTrajetSimple(char * depart, char * destination, char * moyenTransport)
{
    return new TrajetSimple(depart, destination, moyenTransport);
}

TrajetCompose * Catalogue::CreerTrajetCompose()
{
    return new TrajetCompose();
}

bool Catalogue::RetirerTrajet(Trajet * tr)
{
    return trajets.RetirerElement(tr);
}

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( const Catalogue & unCatalogue )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue (constructeur de copie)


Catalogue::Catalogue ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue