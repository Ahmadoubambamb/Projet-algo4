#include "monprojet.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void effacerEcran() {
    system("cls");
}
int main()
{
    ListeAeroport A=NULL;
    tabAerport tAe;
    ListeAvion Av=NULL;
    tabAvion tAv;
    ListeVol V=NULL;
    tabVol tVo;
    ListePilote P=NULL;
    tabPilote tpi;
    listePassager PA=NULL;
    tabPassager tpa;
    int choixMenuPrincipal,choixSousMenu_1,choixSousMenu_2,choixSousMenu_3,choixSousMenu_4,choixSousMenu_5,choixSousMenu_6,choixSousMenu_7;
    int choixSousMenu_8,choixSousMenu_9,choixSousMenu_10;
    do{effacerEcran();
        printf("1:CHARGER LA BASE DE DONNEES\n");
        printf("2:INSERTION DES NOUVEAUX ELEMENTS\n");
        printf("3:TRANSFERT LISTES VERS TABLEAUX \n");
        printf("4:AFFICHAGE DES LISTES \n");
        printf("5:AFFICHAGE DES TABLEAUX \n");
        printf("6:TRI DES TABLEAUX \n");
        printf("7:SUPPRESSION D'UN ELEMENT DANS LA TABLE \n");
        printf("8:RECHERCHE D'UN ELEMENT DANS LA TABLE \n");
        printf("9:ENREGISTREMENT DE LA BD DANS LES FICHIERS\n");
        printf("10:SIMULATION DES REQUETES\n");
        printf("0: FIN DE TRAITEMENT \n");
        printf("tapper votre choix:");
        scanf("%d",&choixMenuPrincipal);
        switch(choixMenuPrincipal){
            case 1:
                do{
                    printf("****chargement de la BD****\n");
                    printf("1:la table Aeroports\n");
                    printf("2:la table Avions\n");
                    printf("3:la table Pilotes\n");
                    printf("4:la table Vols\n");
                    printf("5:la table Passager :\n");
                    printf("tapper 6 pour sortir:\n");
                    scanf("%d",&choixSousMenu_1);
                   switch(choixSousMenu_1){
                          case 1:{ charger_Table_Aeroport(&A) ;break;}
                          case 2:{ charger_Table_Avion(&Av)   ;break;}
                          case 3:{ charger_Table_Pilote(&P)   ;break;}
                          case 4:{ charger_Table_Vol(&V)      ;break;}
                          case 5:{ charger_Table_Passagers(&PA);break;}
                          case 6:
                            break;
                          default :printf("choix invalide.\n");
                   }
                }while(choixSousMenu_1!=6);
                break ;
            case 2:
                do{
                    printf("****Insertion des nouveaux elements****\n");
                    printf("1:la table Aeroports\n");
                    printf("2:la table Avions\n");
                    printf("3:la table Pilotes\n");
                    printf("4:la table Vols\n");
                    printf("5:la table Passager :\n");
                    printf("tapper 6 pour sortir:\n");
                    scanf("%d",&choixSousMenu_2);
                   switch(choixSousMenu_2){
                          case 1:{ insererAeroport(&A,5,"DAS","Abuja");
                                   insererAeroport(&A,6,"MMP","Nantes");
                                   insererAeroport(&A,7,"TTR","Lagos");
                                   insererAeroport(&A,8,"DKM","Ankara");
                                   printf("l'insertion a ete effectuee avec succes.\n");
                                   printf("Allez au menu 4,Ss-menu 1 pour afficher la liste des Aeroports\n");
                                   break;}
                                   printf("\n");
                          case 2:{ insererAvion(&Av,15,"Boei47",400);
                                   insererAvion(&Av,16,"Bog62",350);
                                   insererAvion(&Av,17,"A388",250);
                                   insererAvion(&Av,18,"SKY",150);
                                   printf("l'insertion a ete effectuee avec succes.\n");
                                   printf("Allez au menu 4,Sous-menu 2 pour afficher la liste des Avions\n");
                                   break;}
                                   printf("\n");
                          case 3:{  inserer_Pilote(&P,115,"Claud","Demba");
                                    inserer_Pilote(&P,116,"Moussa","Lo");
                                    inserer_Pilote(&P,117,"DEME","Leo");
                                    inserer_Pilote(&P,118,"DOUD","SY");
                                    printf("l'insertion a ete effectuee avec succes.\n");
                                    printf("Allez au menu 4,Sous-menu 3 pour afficher la liste des Pilotes\n");
                                  break;}
                                  printf("\n");
                          case 4:{ insererVol(&V,&Av,&P,1005,15,115,"10:25","14:45",5,8);
                                   insererVol(&V,&Av,&P,1006,18,117,"9:20","19:35",7,5);
                                   insererVol(&V,&Av,&P,1007,15,116,"9:20","19:35",6,8);
                                   insererVol(&V,&Av,&P,1008,11,116,"22:50","17:35",7,2);
                                   printf("l'insertion a ete effectuee avec succes.\n");
                                   printf("Allez au menu 4,Sous-menu 4 pour afficher la liste des Vols\n");
                                   break;}
                                   printf("\n");
                          case 5:{  insererPassager(&PA,&V,133,"SOW","Ahmat",1005);
                                    insererPassager(&PA,&V,147,"FARIS","Kadou",1006);
                                    insererPassager(&PA,&V,474,"LO","BAKARY",1007);
                                    insererPassager(&PA,&V,717,"FALL","Dakou",1005);
                                    printf("l'insertion a ete effectuee avec succes.\n");
                                    printf("Allez au menu 4,Sous-menu 5 pour afficher la liste des Passagers\n");
                                    break;}
                          case 6:
                               break;

                          default :printf("choix invalide.\n");
                   }
                  }while(choixSousMenu_2!=6);
                   break;
            case 3:
                do{
                    printf("****transfert listes vers tableaux****\n");
                    printf("1:la table Aeroports\n");
                    printf("2:la table Avions\n");
                    printf("3:la table Pilotes\n");
                    printf("4:la table Vols\n");
                    printf("5:la table Passager :\n");
                    printf("tapper 6 pour sortir:\n");
                    scanf("%d",&choixSousMenu_3);
                   switch(choixSousMenu_3){
                          case 1:{ tAe=listeAero_vers_tab(A) ;break;}
                          case 2:{  tAv=TLT(Av) ;break;}
                          case 3:{  tpi=tlt_pilotes(P);break;}
                          case 4:{  tVo=T_L_T(V)        ;break;}
                          case 5:{ tpa=tfert_tableau(PA);break;}
                          case 6:
                               break;
                               break;
                          default :printf("choix invalide.\n");
                   }
                }while(choixSousMenu_3!=6);
                 break;
            case 4:
                do{
                    printf("****Affichage des tables****\n");
                    printf("1:la table Aeroports\n");
                    printf("2:la table Avions\n");
                    printf("3:la table Pilotes\n");
                    printf("4:la table Vols\n");
                    printf("5:la table Passager :\n");
                    printf("tapper 6 pour sortir:\n");
                    scanf("%d",&choixSousMenu_4);
                   switch(choixSousMenu_4){
                          case 1:{ afficherListe_Aeroports(A);break;}
                          printf("\n");
                          case 2:{ afficherListe_Avion(Av);break;}
                          printf("\n");
                          case 3:{ afficher_Pilote(P);break;}
                          printf("\n");printf("\n");
                          case 4:{ afficherVol(V);break;}
                          printf("\n");
                          case 5:{ afficherListe_Passagers(PA);break;}
                          printf("\n");
                          case 6:
                               break;
                               break;
                          default :printf("choix invalide.\n");
                   }
                }while(choixSousMenu_4!=6);
                 break;
            case 5:
                do{
                    printf("****Affichage des Tableaux****\n");
                    printf("1:Aeroports\n");
                    printf("2:Avions\n");
                    printf("3:Pilotes\n");
                    printf("4:Vols\n");
                    printf("5:Passager :\n");
                    printf("tapper 6 pour sortir:\n");
                    scanf("%d",&choixSousMenu_5);
                   switch(choixSousMenu_5){
                          case 1:{ afficherTab_Aeroports(A,tAe);break;}
                          printf("\n");
                          case 2:{ afficherTab_Avion(tAv,Av);break;}
                          printf("\n");
                          case 3:{ afficherTab_Pilote(tpi,P);break;}
                          printf("\n");printf("\n");
                          case 4:{ afficherTab_VOL(tVo,V);break;}
                          printf("\n");
                          case 5:{ afficherTab_Passagers(tpa,PA);break;}
                          printf("\n");
                          case 6:
                               break;
                               break;
                          default :printf("choix invalide.\n");
                   }
                }while(choixSousMenu_5!=6);
                 break;
            case 6:
                do{
                    printf("****tri des tables****\n");
                    printf("1:la table Aeroports\n");
                    printf("2:la table Avions\n");
                    printf("3:la table Pilotes\n");
                    printf("4:la table Vols\n");
                    printf("5:la table Passager :\n");
                    printf("tapper 6 pour sortir:\n");
                    scanf("%d",&choixSousMenu_6);
                   switch(choixSousMenu_6){
                          case 1:{ tAe=tab_Aeroport_trie(A,tAe);
                                   printf("le tableau des aeroports a ete trie avec succes suivant le nom\n");
                                    break;
                                }
                          case 2:{  tAv=trie_Avion(tAv,Av);
                                    printf("le tableau des Avions a ete trie avec succes suivant la capacite\n");
                                    break;
                                }
                          case 3:{ //tpi=tab_Pilote_trie(P,tpi);
                                      trie(tpi,longueurListePilote(P));
                                   printf("le tableau des pilotes a ete trie avec succes suivant le nom\n");
                                    break;
                                 }
                          case 4:{  tVo=trie_VOL(tVo,V);
                                    printf("le tableau des Vols a ete trie avec succes suivant l'idVOL \n");
                                    break;}
                          case 5:{  tpa=tab_Passagers_trie(PA,tpa);
                                    printf("le tableau des passagers a ete trie avec succes suivant le nom\n");
                                    break;}
                          case 6:
                               break;
                               break;
                          default :printf("choix invalide.\n");
                   }
                }while(choixSousMenu_6!=6);
                 break;
            case 7:
                do{
                    printf("****suppression d'un element de la liste****\n");
                    printf("1:la table Aeroports\n");
                    printf("2:la table Avions\n");
                    printf("3:la table Pilotes\n");
                    printf("4:la table Vols\n");
                    printf("5:la table Passager :\n");
                    printf("tapper 6 pour sortir:\n");
                    scanf("%d",&choixSousMenu_7);
                   switch(choixSousMenu_7){
                          case 1:{ supprimerAeroport(&A,&V,8);break;}
                          case 2:{ Av=supprimerAvion(17,V,Av);break;}
                          case 3:{ suprimerPilote(&P,V,118);break;}
                          case 4:{ V=suprimerVol(&V,&P,1003);break;}
                          case 5:{ PA=supprimerPassager(PA,179) ;break;}
                          case 6:
                            break;
                            break;
                          default :printf("choix invalide.\n");
                   }
                }while(choixSousMenu_7!=6);
                 break;
          case 8:{              ; break;}
          case 9:
              do{
                    printf("****Enregistrement****\n");
                    printf("1:Aeroports\n");
                    printf("2:Avions\n");
                    printf("3:Pilotes\n");
                    printf("4:Vols\n");
                    printf("5:Passager :\n");
                    printf("tapper 6 pour sortir:\n");
                    scanf("%d",&choixSousMenu_9);
                   switch(choixSousMenu_9){
                          case 1:{ transfert_tableau_fichier(tAe,A);  break;}
                          case 2:{ transfert_tabAvion_fichier(tAv,Av) ;break;}
                          case 3:{ transfert_tabPilote_fichier(tpi,P);break;}
                          case 4:{ transfert_tabVol_fichier(tVo,V);break;}
                          case 5:{ transfert_tabPassager_fichier(tpa,PA);break;}
                          case 6:
                               break;
                               break;
                          default :printf("choix invalide.\n");
                   }
                }while(choixSousMenu_9!=6);
                 break;
          case 10:
              do{
                    printf("****soient les requetes suivantes****\n");
                    printf("1:AFFICHER NOM ET VILLE DE L'AEROPORTS OU L'AVION AVEC ID 11 A DECOLLE AVANT 20H00 ?\n");
                    printf("2:AVIONS AYANT EFFECTUES PLUS DE VOLS:\n");
                    printf("3:LES PILOTES QUI N'ONT EFFECTUE AUCUN VOL:\n");
                    printf("4:QUEL EST LE VOL QUI A ETE RESERVE PAR LE PASSAGER 991 DONT LE PILOTE EST 111 ?\n");
                   // printf("5:QUELS SONT LES PASSAGERS AYANT PRIS AU MOINS  DEUX VOLS DIFFERENTS ?\n");
                   printf("5:LISTE DES AVIONS QUI ONT UNE FOIS ETE PILOTER PAR LE PILOTE AVEC ID 111?\n");
                    printf("tapper 6 pour sortir:\n");
                    scanf("%d",&choixSousMenu_10);
                   switch(choixSousMenu_10){
                          case 1:{ requete_aeroport1(V,A);break;}
                          case 2:{ requete_Avions_plus_vols(V);break;}
                          case 3:{ requete_pilote_sans_vol(P,V);break;}
                          case 4:{ requette_VOL4(&V,&P,&PA,111,991);break;}
                          case 5:{ requette_avion_piloter(V,Av);break;}

                          default :printf("choix invalide.\n");
                   }
                }while(choixSousMenu_10!=6);
        }
    }while(choixMenuPrincipal!=0);
    printf("FIN DE TRAITEMENT.");
  return 0;
}
