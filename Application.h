/*************************************************************************
                           Application  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <Application> (fichier Application.h) -------------------
#if ! defined ( APPLICATION_H )
#define APPLICATION_H

//------------------------------------------------------------------------
// Rôle du module <Application>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
static void  BouclePrincipale();
static void AfficherMenu();
static char ScannerChar();
static int TraiterDemande(); 
static void AjouterTrajet(); 
static void AjouterTrajetSimple(); 
static void AjouterTrajetCompose(); 
static void RechercherTrajet();

#endif // Application_H
