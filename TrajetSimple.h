/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:

    
//----------------------------------------------------- Méthodes publiques
    void Afficher();
    char * GetDepart();
    char * GetDestination();

//------------------------------------------------- Surcharge d'opérateurs
    //TrajetSimple & operator = ( const TrajetSimple & unTrajetSimple );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple ( char * dep, char * dest, char * moyenT );
    // Mode d'emploi :
    //

    virtual ~TrajetSimple ( );
    // Mode d'emploi :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    char * moyenTransport; 
    char * destination;
    char * depart; 
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H

