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
    if (trajet == nullptr) return;

    Element * temp = new Element;
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
    nbElements++;
}

int ChainList::GetNbElements()
{
    return nbElements;
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

ChainList * ChainList::CopyList()
{    
    ChainList * newList = new ChainList;
    Element * temp = this->GetPremierElement();
    if (temp == nullptr) return newList;

    newList->AjouterElement(temp->data);
    while ((temp = this->GetSuivantElement(temp)) != nullptr)
        newList->AjouterElement(temp->data);

    temp = nullptr;
    return newList;
}

Element * ChainList::RechercherElement(char * depart, char * destination)
{
    Element * trajet = GetPremierElement();

    while (trajet != nullptr)
    {
        if (!strcmp(trajet->data->GetDepart(), depart) && !strcmp(trajet->data->GetDestination(), destination))
        {           
            return trajet;
        }
        trajet = GetSuivantElement(trajet);
    }    

    return nullptr;
}

Element * ChainList::RechercherElement(Trajet * tr)
{
    return RechercherElement(tr->GetDepart(), tr->GetDestination());
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
        //delete queue;
        queue = temp;
    }
}

void ChainList::InsererListe(ChainList * listeAInserer)
{
    if (listeAInserer == nullptr) return;
    listeAInserer->GetPremierElement()->precedent = queue;

    if (queue != nullptr) queue->suivant = listeAInserer->GetPremierElement();
    else tete = listeAInserer->GetPremierElement();

    listeAInserer = nullptr;
}


//-------------------------------------------- Constructeurs - destructeur

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