/*************************************************************************
                           ChainList  -  description
                             -------------------
    début                : 01/10/2020
    copyright            : (C) 2020 par Terekhov Nikita et Lecuyer Alison
    e-mail               : nikita.terekhov@insa-lyon.fr 
                         : alison.lecuyer@insa-lyon.fr
*************************************************************************/

//---- Réalisation de la classe <ChainList> (fichier ChainList.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "ChainList.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void ChainList::AjouterElement(Trajet * trajet)
{
    Element * temp = new Element();
    temp->data = trajet;
    temp->suivant = nullptr;
    temp->precedent = nullptr;
    if (tete == nullptr) {
        tete = temp;
        queue = temp;
        temp = nullptr;
    } else {
        queue->suivant = temp;
        queue->suivant->precedent = queue;
        queue = temp;
    }
}

Element * ChainList::GetSuivantElement(Element * elem)
{
    return elem->suivant;
}

Element * ChainList::GetPremierElement()
{
    return tete;
}

Element * ChainList::GetDernierElement()
{
    return queue;
}


Element * ChainList::RechercherElement(Trajet * tr)
{
    Element * trajet = GetPremierElement();

    /*
    strcmp(trajet->data->depart, depart) && !strcmp(trajet->data->destination, destination*/
    /*while (trajet != nullptr && *(trajet->data) != *tr)
    {
        trajet = GetSuivantElement(trajet);
    }*/

    return trajet;
}

ChainList * ChainList::RechercherParcours(char * depart, char * destination)
{
    int trajetCmt = 0;
    ChainList * resultat = new ChainList;

    Element * trajet = GetPremierElement();

    while (trajet != nullptr)
    {
        if (!strcmp(trajet->data->GetDepart(), depart) && !strcmp(trajet->data->GetDestination(), destination))
        {           
            resultat->AjouterElement(trajet->data);
        }
        trajet = GetSuivantElement(trajet);
    }    
    return resultat;
}

bool ChainList::RetirerElement(Trajet * tr)
{
    Element * trajet = RechercherElement(tr);

    if (trajet == nullptr) return false;

    if (trajet->suivant != nullptr && trajet->precedent != nullptr)
    {
        trajet->precedent->suivant = trajet->suivant;
        trajet->suivant->precedent = trajet->precedent;
    } else if (trajet->suivant == nullptr)
    {
        queue = trajet->precedent;
        queue->suivant = nullptr;
    } else {
        tete = trajet->suivant;
        tete->precedent = nullptr;
    }
    
    return true;
}

void ChainList::RetirerAll()
{
    Element * temp = queue;

    while (queue != nullptr)
    {
        temp = queue->precedent;
        delete queue;
        queue = temp;
    }
}


//-------------------------------------------- Constructeurs - destructeur
ChainList::ChainList ( const ChainList & unChainList )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ChainList>" << endl;
#endif
} //----- Fin de ChainList (constructeur de copie)


ChainList::ChainList ()
{
#ifdef MAP
    cout << "Appel au constructeur de <ChainList>" << endl;
#endif
    tete = nullptr;
    queue = nullptr;
} //----- Fin de ChainList


ChainList::~ChainList ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <ChainList>" << endl;
#endif

    Element * temp = queue;

    while (queue != nullptr)
    {
        temp = queue->precedent;
        delete queue->data;
        delete queue;
        queue = temp;
    }
} //----- Fin de ~ChainList