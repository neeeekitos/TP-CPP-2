/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 01/10/2020
    copyright            : (C) 2020 par Terekhov Nikita et Lecuyer Alison
    e-mail               : nikita.terekhov@insa-lyon.fr 
                         : alison.lecuyer@insa-lyon.fr
*************************************************************************/

//-- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// La classe TrajetSimple hérite de la classe Trajet. 
// Elle possède trois attributs : 
// depart, destination et moyenTransport qui sont tous des char*
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:

    
//----------------------------------------------------- Méthodes publiques
    void Afficher();
    // Mode d'emploi :
    // Affiche un TrajetSimple : 
    // départ, destination et moyen de transport
    // Redéfinie la méthode Afficher() de Trajet.

    char * GetDepart();
    // Mode d'emploi :
    // Renvoie le départ du TrajetSimple.
    // Redéfinie la méthode GetDepart() de Trajet.

    char * GetDestination();
    // Mode d'emploi :
    // Renvoie la destination du TrajetSimple.
    // Redéfinie la méthode GetDestination() de Trajet.


//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple ( char * dep, char * dest, char * moyenT );
    // Mode d'emploi :
    // Constructeur d'un trajet simple. 
    // Prends en paramètres dep, dest et moyenT, des char * qui 
    // correspondent respectivement aux attributs protégés 
    // depart, destination et moyenTransport 

    virtual ~TrajetSimple ( );
    // Mode d'emploi :
    // Destructeur d'unn trajet simple.

//------------------------------------------------------------------ PRIVE

protected:

//----------------------------------------------------- Attributs protégés
    char * depart; 
    char * destination;
    char * moyenTransport; 
};


#endif // TRAJETSIMPLE_H