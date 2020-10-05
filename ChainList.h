/*************************************************************************
                           ChainList  -  description
                             -------------------
    début                : 01/10/2020
    copyright            : (C) 2020 par Terekhov Nikita et Lecuyer Alison
    e-mail               : nikita.terekhov@insa-lyon.fr 
                         : alison.lecuyer@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <ChainList> (fichier ChainList.h) ----------------
#if ! defined ( CHAINLIST_H )
#define CHAINLIST_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef struct Element
{
    Trajet * data;
    Element * suivant;
    Element * precedent;
} Element;

//------------------------------------------------------------------------
// Rôle de la classe <ChainList>
//
//
//------------------------------------------------------------------------

class ChainList 
{
//----------------------------------------------------------------- PUBLIC

public:
    void AjouterElement(Trajet * trajet);
    Element * RechercherElement(Trajet * tr);
    ChainList * RechercherParcours(char * depart, char * destination);
    Element * GetSuivantElement(Element * elem);
    Element * GetPremierElement();
    Element * GetDernierElement();
    bool RetirerElement(Trajet * tr);
    

//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    //ChainList & operator = ( const ChainList & unChainList );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    ChainList ( const ChainList & unChainList );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ChainList ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ChainList ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Element * tete, * queue;
};

//-------------------------------- Autres définitions dépendantes de <ChainList>

#endif // CHAINLIST_H

