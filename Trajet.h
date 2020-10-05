/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 01/10/2020
    copyright            : (C) 2020 par Terekhov Nikita et Lecuyer Alison
    e-mail               : nikita.terekhov@insa-lyon.fr 
                         : alison.lecuyer@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Trajet 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher( void ); 
    // Mode d'emploi :
    //

    virtual char * GetDepart();
    // Mode d'emploi :
    //
    
    virtual char * GetDestination();
    // Mode d'emploi :
    //

//-------------------------------------------- Constructeurs - destructeur
    Trajet ( );
    // Mode d'emploi :
    //

    virtual ~Trajet ( );
    // Mode d'emploi :
    //

//------------------------------------------------------------------ PRIVE

protected:

};

#endif // TRAJET_H

