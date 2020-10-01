/*************************************************************************
                           ChainList  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ChainList> (fichier ChainList.h) ----------------
#if ! defined ( CHAINLIST_H )
#define CHAINLIST_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ChainList>
//
//
//------------------------------------------------------------------------

class ChainList 
{
//----------------------------------------------------------------- PUBLIC

public:
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

};

//-------------------------------- Autres définitions dépendantes de <ChainList>

#endif // CHAINLIST_H

