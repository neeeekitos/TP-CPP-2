/*************************************************************************
                           Application  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <Application> (fichier Application.cpp) -------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Application.h"
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"

///////////////////////////////////////////////////////////////////  PRIVE
//---------------------------------------------------- Variables statiques

static Catalogue catalogue; 

//------------------------------------------------------ Fonctions privées

static void  BouclePrincipale() 
{
  bool doitContinuer = true;

  while(doitContinuer)
  {
    cout << endl; 
    cout << endl; 
    cout << endl; 
    AfficherMenu();
    doitContinuer = TraiterDemande(); 
  }
}

static void AfficherMenu() 
{
  cout << "-------------------------------------------------------------------------" << endl; 
  cout << "Menu : " << endl; 
  cout << "1 - Ajouter un trajet au catalogue." << endl;
  cout << "2 - Afficher le catalogue." << endl;
  cout << "3 - Rechercher un trajet." << endl;
  cout << "4 - Quitter." << endl; 
  cout << "Veuillez entrer le numéro de l'action que vous souhaitez réaliser :" << endl; 
  cout << "-------------------------------------------------------------------------" << endl; 

}

static char ScannerChar() 
{
  char test[150];
  cin.getline(test, 150);
  return test[0]; 
}

static int TraiterDemande() 
{
  char optionChoisie = ScannerChar(); 
  switch (optionChoisie)
  {
    case '1':
      AjouterTrajet(); 
      break;
    case '2':
      cout << "Trajets du catalogue : " << endl; 
      catalogue.Afficher();
      break;
    case '3':
      RechercherTrajet(); 
      break;
    case '4':
      cout << "Au revoir !" << endl; 
      return 0;
    default:
      cout << "Action impossible. Veuillez choisir un numéro entre 1 et 4." << endl;
  }

  return 1;
}

static void AjouterTrajet() 
{
  cout << "Voulez-vous ajouter un trajet simple ou un trajet composé ? Entrez S pour simple ou C pour composé." << endl;
  char typeTrajet = ScannerChar(); 
  switch (typeTrajet)
  {
    case 'S':
      AjouterTrajetSimple();
      break;

    case 'C':
      AjouterTrajetCompose();
      break;
    
    default:
      cout << "Les seuls options possibles sont S ou C. " << endl; 
      AjouterTrajet(); 
      break;
  }
}

static void AjouterTrajetSimple() 
{
  char * depart = new char[150];
  char * destination = new char[150]; 
  char * moyenTransport = new char[150]; 

  cout << "Départ du trajet : "; 
  cin.getline(depart,150);

  cout << "Destination du trajet : "; 
  cin.getline(destination,150);

  cout << "Moyen de transport du trajet du trajet : ";
  cin.getline(moyenTransport,150);

  catalogue.Ajouter(catalogue.CreerTrajetSimple(depart,destination,moyenTransport));
}

static void AjouterTrajetCompose() 
{
  char continuer = 'O';
  int nbEscales = 0;
  Trajet * pt_trajetCompose = catalogue.CreerTrajetCompose(); 

  while(continuer == 'O') {
    char * dep = new char[150];
    char * dest = new char[150]; 
    char * moyenTransport = new char[150];

    cout << "Départ de l'escale numéro " << nbEscales + 1 << " : ";
    cin.getline(dep,150);

    cout << "Destination de l'escale numéro : " << nbEscales + 1 << " : ";
    cin.getline(dest,150);

    cout << "Moyen de transport de l'escale numéro : " << nbEscales + 1 << " : ";
    cin.getline(moyenTransport,150);

    dynamic_cast<TrajetCompose*>(pt_trajetCompose)->AjouterEscale(catalogue.CreerTrajetSimple(dep,dest,moyenTransport));

    cout << "Voulez vous ajouter une autre escale ? O pour oui, N pour non." << endl;
    continuer = ScannerChar();
    while(continuer != 'O' && continuer != 'N'){
      cout << "Action impossible. Veuillez entrer O pour oui ou N pour non " << endl; 
      continuer = ScannerChar();
    }
    nbEscales++; 
  } 

  if(!dynamic_cast<TrajetCompose*>(pt_trajetCompose)->EstValide()) {
    cout << "Votre voyage n'est pas valide." << endl; 
  }else {
    catalogue.Ajouter(pt_trajetCompose);
  }
}

static void RechercherTrajet() 
{
  char * depart = new char[150];
  char * destination = new char[150]; 

  cout << "D'où voulez-vous partir ?" << endl; 
  cin.getline(depart,150);

  cout << "Où voulez-vous aller ?" << endl; 
  cin.getline(destination,150);

  cout << "Vous pouvez prendre le(s) trajet(s) suivants : " << endl; 
  catalogue.Rechercher(depart, destination);
}


//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main() 
{
  BouclePrincipale();
  return 0; 
}
