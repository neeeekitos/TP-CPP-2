/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 01/10/2020
    copyright            : (C) 2020 par Terekhov Nikita et Lecuyer Alison
    e-mail               : nikita.terekhov@insa-lyon.fr 
                         : alison.lecuyer@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "ChainList.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"

//------------------------------------------------------------------ Types
typedef struct Bloc
{
    Trajet * blocData;
    int valeur;
} Bloc;

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
//
//------------------------------------------------------------------------

class Catalogue 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Rechercher(char * depart, char * destination);
    /**
     * Recherche parmi tous les trajets ceux qui ont le depart et
     * la destination passés en paramètres. Ensuite affiche tous 
     * les trajets trouvés.
     *  
     * @param depart depart du trajet.
     * @param destination l'arriveé du trajet.
     */


    void Afficher(ChainList * tr);
    /**
     * Affiche les trajets de la liste passée en paramètre.
     *  
     * @param tr de ChainList, liste des trajets à afficher.
     */

    void Afficher();
    /**
     * Affiche les trajets de l'attribut trajets de l'objet 
     * invoquant cette méthode.
     */

    void Ajouter(Trajet * tr);
    /**
     * Ajoute un trajet passé en paramètre dans la liste
     * de l'objet invoquant cette méthode.
     *  
     * @param tr de Trajet, le trajet à ajouter.
     */

    TrajetSimple * CreerTrajetSimple(char * depart, char * destination, char * moyenTransport);
    /**
     * Crée et retourne l'objet du type TrajetSimple avec des 
     * caractéristiaues passées en paramètres.
     *  
     * @param depart Depart du trajet à ajouter.
     * @param destination Destination du trajet à ajouter.
     * @param moyenTransport Moyen de transport du trajet à ajouter.
     * @return objet du type TrajetSimple
     */

    TrajetCompose * CreerTrajetCompose();
     /**
     * Crée et retourne l'objet du type TrajetCompose
     *  
     * @return objet du type TrajetCompose
     */

    bool RetirerTrajet(Trajet * tr);
    /**
     * Retire un trajet passée en paramètre.
     * Si celui est présent dans la liste,
     * retourne true, sinon false.
     *  
     * @param tr de Trajet, le trajet à ajouter.
     * @return bool pour indiquer si la suppresion a été réussite
     */

    void isPossible(Bloc ** caseTab, int ligne, const char * destination, ChainList * trajetsPrecedents, int nbDepEtDest);
    /**
     * Parcourt le tableau donné par une méthode RechercheAvance 
     * et s'appelle recursivement si la destination de la case trouvée
     * ne correspond pas à celle qu'on demande, sinon affiche l'itinéraire
     * complet.
     *  
     * @param caseTab une case du Tableau qui contient
     * une valeur (1 si le trajet de i dans j existe, sinon 0)
     * et un trajet de i dans j, s'il existe.
     * @param ligne Ligne sur laquelle le parcours du 
     * tableau caseTab va étre effectué.
     * @param destination Destination recherchée
     * @param trajetsPrecedents Liste des trajets précédents
     * qu'on utilise pour afficher l'itinéraire contenant 
     * plusieurs trajets
     * @param nbDepEtDest le nombre maximal de departs et 
     * destination possibles, ou 2 fois le nombre des trajets.
     * Cela est important pour connaitre la taille du tableau.
     */

    void RechercheAvance(char * depart, char * destination);

    /**
     * Recherche un itinéraire qui peut contenir plusieurs trajets
     * simples et complexes avec le depart et la destination correspondants à
     * ceux qui sont passés en paramètres.
     *  
     * @param depart depart du trajet.
     * @param destination l'arriveé du trajet.
     */


    bool ContientTrajet(Trajet * t);
    // Mode d'emploi : 
    // 

//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( const Catalogue & unCatalogue );
    // Constructeur de copie par défaut de TrajetCompose. 

    Catalogue ( );
    // Constructeur de TrajetCompose. 

    virtual ~Catalogue ( );
    // Destructeur de TrajetCompose. 

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    ChainList trajets;
};

#endif // CATALOGUE_H

