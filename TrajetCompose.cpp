/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 01/10/2020
    copyright            : (C) 2020 par Terekhov Nikita et Lecuyer Alison
    e-mail               : nikita.terekhov@insa-lyon.fr 
                         : alison.lecuyer@insa-lyon.fr
*************************************************************************/

//- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) -

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
#include "TrajetSimple.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher() 
{
    cout << "    Départ du trajet composé : " << GetDepart() << endl; 
    cout << "    Destination du trajet composé : ";
    cout << GetDestination() << endl; 
    Element * trajet = trajets.GetPremierElement();
    int nbEscales = 1; 

    while (trajet != nullptr)
    {
        cout << endl; 
        cout << "Escale numéro " << nbEscales << " : " << endl;
        trajet->data->Afficher();
        trajet = trajet->suivant;
        nbEscales++; 
    }
}

char * TrajetCompose::GetDepart()
{
    return trajets.GetPremierElement()->data->GetDepart();
}

char * TrajetCompose::GetDestination()
{
    return trajets.GetDernierElement()->data->GetDestination();
}

ChainList * TrajetCompose::GetTrajets()
{
    return &trajets;
}

void TrajetCompose::AjouterEscale(Trajet * tr)
{
    trajets.AjouterElement(tr);
}

bool TrajetCompose::RetirerEscale(Trajet * tr)
{
    return trajets.RetirerElement(tr);
}

bool TrajetCompose::EstValide() 
{
    Element * trajet = trajets.GetPremierElement();

    while (trajet != nullptr)
    {
        if(trajet->suivant != nullptr && 
        strcmp(
            trajet->data->GetDestination(),
            trajet->suivant->data->GetDepart())) {
            return false; 
        }
        trajet = trajet->suivant;
    }
    return true; 
}

bool TrajetCompose::EstEgal(Trajet * t) 
{
    if (dynamic_cast<TrajetCompose*>(t) != nullptr) {
        if(dynamic_cast<TrajetCompose*>(t)->GetTrajets()->GetNbElements()!=trajets.GetNbElements()) {
            return false; 
        }


        Element * trajet = trajets.GetPremierElement();
        Element * trajetBis = dynamic_cast<TrajetCompose*>(t)->GetTrajets()->GetPremierElement(); 

        while(trajet != nullptr) {
            if(!trajet->data->EstEgal(trajetBis->data)) {
                return false; 
            }
            trajet = trajet->suivant;
            trajetBis = trajetBis->suivant;
        }

        return true; 
    } 

    return false; 
}


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de ~TrajetCompose
