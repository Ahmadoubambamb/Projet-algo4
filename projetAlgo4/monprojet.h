#ifndef MONPROJET_H_INCLUDED
#define MONPROJET_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char chaine[50];
typedef struct Aeroport{
   int codeAeroport;
   chaine nom;
   chaine ville;
   struct Aeroport* next;
}AEROPORT;
typedef AEROPORT* ListeAeroport;
typedef struct Avion{
  int idAvion;
  chaine modele;
  int capacite;
 struct Avion* next;
}AVION;
typedef AVION* ListeAvion;
typedef struct Pilote{
  int idPilote;
  chaine nom;
  chaine prenom;
struct Pilote* next;
}PILOTE;
typedef PILOTE* ListePilote;
typedef struct Vol{
  int idVol;
  int idAvion;
  int idPilote;
  chaine Heure_Depart;
  chaine Heure_Arrivee;
  int aero_Depart;
  int aero_Arrivee;
  struct Vol* next;
}VOL;
typedef VOL* ListeVol;
typedef struct Passager{
   int NumPassport;
   chaine nom;
   chaine prenom;
   int idVol;
   struct Passager* next;
}PASSAGER;
typedef PASSAGER* listePassager;
///////les declarations des structures tableaux/////////
typedef struct{
   int codeAeroport;
   chaine nom;
   chaine ville;
}tabAEROPORT;
typedef tabAEROPORT* tabAerport;
typedef struct {
  int idAvion;
  chaine modele;
  int capacite;
}tabAVION;
typedef tabAVION* tabAvion;
typedef struct{
  int idPilote;
  chaine nom;
  chaine prenom;
}tabPILOTE;
typedef tabPILOTE* tabPilote;
typedef struct{
  int idVol;
  int idAvion;
  int idPilote;
  chaine Heure_Depart;
  chaine Heure_Arrivee;
  int aero_Derpart;
  int aero_Arrivee;
}tabVOL;
typedef tabVOL* tabVol;
typedef struct{
   int NumPassport;
   chaine nom;
   chaine prenom;
   int idVol;
}tabPASSAGER;
typedef tabPASSAGER* tabPassager;
ListeAeroport creer_maillonAeroport(int codeA,chaine nomA,chaine villeA);
void charger_Table_Aeroport(ListeAeroport* A);
int existeAeroport(ListeAeroport A, int codeA);
void insererAeroport(ListeAeroport* A,int codeA, chaine nom, chaine ville);
void afficherTab_Aeroports(ListeAeroport ,tabAerport );
void afficherListe_Aeroports(ListeAeroport A);
void supprimerAeroport(ListeAeroport* ,ListeVol*,int);
tabAerport listeAero_vers_tab(ListeAeroport);
tabAerport tab_Aeroport_trie(ListeAeroport ,tabAerport );
void transfert_table_fichier(tabAerport,ListeAeroport );
////Avions///////////////////////////
ListeAvion creer_maillonAvion(int, chaine,int );
int existeAvion(ListeAvion Av,int idAvion);
void charger_Table_Avion(ListeAvion* );
void insererAvion(ListeAvion*,int, chaine,int);
ListeAvion supprimerAvion(int IdAvion,ListeVol lv,ListeAvion la);
void afficherListe_Avion(ListeAvion Av);
void afficherTab_Avion(tabAvion T,ListeAvion Av);
int longueurListeAvion(ListeAvion Av);
tabAvion TLT(ListeAvion);
tabAvion trie_Avion(tabAvion ,ListeAvion );
void transfert_tabAvion_fichier(tabAvion ,ListeAvion );
//////Pilotes///////////////////////////
int existePilote(ListePilote ,int);
ListePilote creer_maillonPilote(int ,chaine ,chaine);
void charger_Table_Pilote(ListePilote *);
void afficher_Pilote(ListePilote );
void afficherTab_Pilote(tabPilote,ListePilote);
void inserer_Pilote(ListePilote*,int,chaine,chaine);
int longueurListePilote(ListePilote );
void transfert_tabPilote_fichier(tabPilote,ListePilote );
void trie(tabPilote t ,int n);
tabPilote tlt_pilotes(ListePilote  );
tabPilote tab_Pilote_trie(ListePilote,tabPilote);
void suprimerPilote(ListePilote*,ListeVol,int );
int existePiloteVole(ListeVol V ,int idP);
/////Vols//////////////////////////////////
void charger_Table_Vol(ListeVol* V);
ListeVol creer_maillonVol(int idVol,int idAVion,int idPilote, chaine H_D,chaine H_A,int aero_D,int aero_A);
int existeVol(ListeVol V,int idVol);
void insererVol(ListeVol*,ListeAvion*,ListePilote*,int idVol,int idAVion,
int idPilote, chaine H_D,chaine H_A,int aero_D,int aero_A);
void afficherVol(ListeVol);
void afficherTab_VOL(tabVol ,ListeVol);
int longueurVol(ListeVol );
tabVol T_L_T(ListeVol );
tabVol trie_VOL(tabVol ,ListeVol);
void transfert_tabVol_fichier(tabVol ,ListeVol );
ListeVol suprimerVol(ListeVol *V,listePassager* P ,int idVol);
int existePassaVOL(listePassager ,int );
void requette_VOL4(ListeVol *,ListePilote *,listePassager *,int ,int );
////////Passagers///////////////////////////
listePassager  creer_maillonPassager(int NumP, chaine nomP, chaine prenomP,int idvol);
int existePassagers(listePassager P,int NumPassportP);
void charger_Table_Passagers(listePassager* P);
void insererPassager(listePassager *P,ListeVol* V,int NumPassportP,chaine nomP, chaine prenomP, int idvol);
void afficherListe_Passagers(listePassager P);
void afficherTab_Passagers(tabPassager,listePassager);
int longueurP(listePassager P);
tabPassager tfert_tableau(listePassager );
listePassager supprimerPassager(listePassager ,int);
tabPassager tab_Passagers_trie(listePassager ,tabPassager );
void transfert_tabPassager_fichier(tabPassager,listePassager );
////////////////////////requuetes//////////////
void requete_aeroport1(ListeVol, ListeAeroport);
void  requete_Avions_plus_vols(ListeVol );
void requette_VOL4(ListeVol *V ,ListePilote *P,listePassager *PA,int idP,int idPas);
void requete_pilote_sans_vol(ListePilote ,ListeVol );
void requette_avion_piloter(ListeVol ,ListeAvion);
#endif // MONPROJET_H_INCLUDED

