#include "monprojet.h"
ListeAeroport creer_maillonAeroport(int codeA, chaine nomA, chaine villeA) {
    ListeAeroport m = (ListeAeroport)malloc(sizeof(AEROPORT));
    if (m == NULL) {
        printf("Erreur d'allocation mémoire");
        return NULL;
    }
    m->codeAeroport = codeA;
    strcpy(m->nom, nomA);
    strcpy(m->ville, villeA);
    m->next = NULL;
    return m;
}
int existeAeroport(ListeAeroport A, int codeA) {
    ListeAeroport courant = A;
    while (courant != NULL) {
        if (courant->codeAeroport == codeA) {
            return 1;
        }
        courant = courant->next;
    }
    return 0;
}
void charger_Table_Aeroport(ListeAeroport* A) {
    FILE* fp1 = fopen("fichierAeroport.txt", "r");
    if (fp1 == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(-1);
    }
    int codeAeroport;
    chaine nomA;
    chaine villeA;
    ListeAeroport tmp = NULL;
    while (fscanf(fp1, "%d %s %s", &codeAeroport, nomA, villeA) == 3) {
        if (*A == NULL) {
            tmp = *A = creer_maillonAeroport(codeAeroport, nomA, villeA);
        } else {
            tmp->next = creer_maillonAeroport(codeAeroport, nomA, villeA);
            tmp = tmp->next;
        }
    }
    fclose(fp1);
    printf("La table Aeroport a été chargée avec succès.\n");
}
void insererAeroport(ListeAeroport* A, int codeA, chaine nom, chaine ville) {
    if (existeAeroport(*A, codeA)) {
        printf("Impossible, le code existe déjà !\n");
        return;
    }
    ListeAeroport nAe = creer_maillonAeroport(codeA, nom, ville);
    nAe->next = *A;
    *A = nAe;
}
int longueurlisteAeroprt(ListeAeroport A){
    int cmpt=0;
    while(A!=NULL){
        cmpt=cmpt+1;
        A=A->next;
    }
    return cmpt;
}
tabAerport listeAero_vers_tab(ListeAeroport A){
    int i=0;
    int n=longueurlisteAeroprt(A);
    tabAerport t=(tabAerport)malloc(n*sizeof(tabAEROPORT));
    if(t!=NULL){
        i=0;
        ListeAeroport tmp=A;
        while(tmp!=NULL){
            t[i].codeAeroport=tmp->codeAeroport;
            strcpy(t[i].nom,tmp->nom);
            strcpy(t[i].ville,tmp->ville);
            i++;
            tmp=tmp->next;
        }
        return t;
        printf("le transfert de la liste Aeroports vers tableau est succes\n");
    }
}
tabAerport tab_Aeroport_trie(ListeAeroport A,tabAerport tA){
    int i,j;
    tabAEROPORT tmp;
    for(i= 0 ; i < longueurlisteAeroprt(A)-1;i++){
        for(j=i+1;j< longueurlisteAeroprt(A);j++){
            if(strcmp(tA[i].nom,tA[j].nom)>0){
                tmp=tA[i];
                tA[i]=tA[j];
                tA[j]=tmp;
            }
        }
    }
    return tA;
    printf("le  tableau d'aeroports a ete trie avec succes\n");
}
void afficherListe_Aeroports(ListeAeroport A) {
    ListeAeroport temp = A;
    printf("L'affichage de la liste des aeroports:\n");
    printf("***********************************\n");
    printf("code\tnom\tville\n");
    while (temp!=NULL) {
        printf("\033[1;31m%d \t%s \t%s\033[0m\n",temp->codeAeroport,temp->nom,temp->ville);
        temp = temp->next;
    }
    printf("\n");
    printf("***********************************\n");
}
void afficherTab_Aeroports(ListeAeroport A,tabAerport t) {
    int i=0;
    int n=longueurlisteAeroprt(A);
    printf("L'affichage du tableau des aeroports:\n");
    printf("***********************************\n");
    printf("code\tnom\tville\n");
    while (i< n) {
        printf("\033[1;31m%d \t%s \t%s\033[0m\n",t[i].codeAeroport, t[i].nom, t[i].ville);
        i++;
    }
    printf("\n");
    printf("***********************************\n");
}
void supprimerAeroport(ListeAeroport* A,ListeVol *V,int codeAeroport) {
    ListeVol tempVol = *V;
    while (tempVol != NULL) {
        if (tempVol->aero_Depart == codeAeroport || tempVol->aero_Arrivee == codeAeroport) {
            printf("Impossible de supprimer l'aéroport. Il est associé à au moins un vol.\n");
            return;
        }
        tempVol = tempVol->next;
    }
    ListeAeroport courant =*A;
    ListeAeroport precedent = NULL;
    while (courant != NULL) {
        if (courant->codeAeroport == codeAeroport) {
            if (precedent == NULL) {
                *A= courant->next;
            } else {
                precedent->next = courant->next;
            }
            free(courant);
            printf("L'aéroport avec le code %d a été supprimé avec succès.\n",codeAeroport);
            return;
        }
        precedent = courant;
        courant = courant->next;
    }
    printf("L'aeroport avec le code %d n'a pas été trouvé dans la liste.\n", codeAeroport);
}
void transfert_tableau_fichier(tabAerport tAe,ListeAeroport A){
    if(tAe!=NULL){
        FILE* fic1=fopen("tableAeroport.txt","a");
      if (fic1 == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        return ;
        }
              int n=longueurlisteAeroprt(A);
              int i=0;
                 while(i<n){
                fprintf(fic1,"%d %s %s\n",tAe[i].codeAeroport, tAe[i].nom, tAe[i].ville);
                i++;
            }
            fclose(fic1);
            printf("Enregistrement de la table Aeroport est effectif\n");
      }
}
///////////////////Avions///////////////////////////////////////////////
ListeAvion creer_maillonAvion(int idAvion, chaine modele,int capacite) {
    ListeAvion m= (ListeAvion)malloc(sizeof(AVION));
    if (m == NULL) {
        printf("Erreur d'allocation mémoire");
        return NULL;
    }
    m->idAvion= idAvion;
    strcpy(m->modele, modele);
    m->capacite=capacite;
    m->next = NULL;
    return m;
}
int existeAvion(ListeAvion Av,int idAvion) {
    ListeAvion tmp;
    for(tmp=Av;tmp!=NULL;tmp=tmp->next){
        if (tmp->idAvion==idAvion)
            return 1;
    }
    return 0;
}
int existVol(ListeVol V,int idAvion) {
    ListeVol courant = V;
    while (courant != NULL) {
if (courant->idAvion == idAvion){
            return 1;
    }
        courant = courant->next;
    }
    return 0;
}
void charger_Table_Avion(ListeAvion* Av) {
    FILE* fp2=fopen("fichierAvion.txt","r");
    if (fp2 == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(-1);
    }
    int idAvion;
    chaine modele;
    int capacite;
    ListeAvion tmp;
    while (fscanf(fp2,"%d %s %d",&idAvion,modele,&capacite) == 3){
         if(*Av==NULL)
                tmp=*Av=creer_maillonAvion(idAvion,modele,capacite);
           else{
            tmp->next=creer_maillonAvion(idAvion,modele,capacite);
            tmp=tmp->next;
        }
   }
    fclose(fp2);
    printf("la table Avion a ete chargee avec succes.\n");
}
tabAvion TLT(ListeAvion Av){
    int i=0;
    tabAvion T=(tabAvion)malloc(sizeof(tabAVION)*longueurListeAvion(Av));
    if(T==NULL){
        printf("Erreur lors de lallocation");
        return ;
    }
    else{
        while(Av!=NULL){
            T[i].idAvion=Av->idAvion;
            strcpy(T[i].modele,Av->modele);
            T[i].capacite=Av->capacite;
            i++;
            Av=Av->next;
        }
    }
    return T;
}
tabAvion trie_Avion(tabAvion T,ListeAvion Av){
    int n=longueurListeAvion(Av),i,j;
     tabAVION tmp;
     for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(T[i].capacite>T[j].capacite){
                tmp=T[i];
                T[i]=T[j];
                T[j]=tmp;
            }
        }
    }
    return T;
    printf("le  tableau d'avions a ete trie avec succes\n");
}
int longueurListeAvion(ListeAvion Av){
    int l=0;
    ListeAvion p=Av;
    while(p!=NULL){
    l=l+1;
    p=p->next;
    }
    return l;

}
void insererAvion(ListeAvion* Av,int idAvion,chaine modele,int  capacite) {
        if (existeAvion(*Av, idAvion)) {
            printf("Impossible, l'ID existe déjà!\n");
            return;
        }
        ListeAvion nAv = creer_maillonAvion(idAvion, modele, capacite);
            nAv->next = *Av;
            *Av = nAv;
}
void afficherListe_Avion(ListeAvion Av){
  ListeAvion temp=Av;
   printf("l'affichage de la liste des avions:\n");
   printf("***********************************\n");
   printf("idAv\tmodele\tcapacite\n");
  while(temp!=NULL){
    printf("\033[1;31m%d\t%s\t%d\033[0m\n",temp->idAvion,temp->modele,temp->capacite);
    temp=temp->next;
  }
  printf("\n");
  printf("***********************************\n");
}
void afficherTab_Avion(tabAvion T,ListeAvion Av){
  int i=0;
  int n=longueurListeAvion(Av);
  printf("l'affichage du tableau des avions:\n");
   printf("***********************************\n");
   printf("idAv\tmodele\tcapacite\n");
  while(i<n){
    printf("\033[1;31m%d\t%s\t%d\033[0m\n",T[i].idAvion,T[i].modele,T[i].capacite);
    i++;
  }
  printf("\n");
  printf("***********************************\n");
}
ListeAvion supprimermilieu(ListeAvion debut,int v){
    ListeAvion tmp,p;  tmp=debut;
    if(debut->idAvion==v){
        p=tmp;
        debut=debut->next;
        free(p);
      }
    else{
        while(tmp->next->idAvion!=v && tmp->next!=NULL)
           tmp=tmp->next;
          if( tmp->next != NULL ){
            p=tmp->next;
            tmp->next=tmp->next->next;
            free(p);
            }
          else
          printf("Pas assez despace\n");
    }
    return debut;
}
ListeAvion supprimerAvion(int IdAvion,ListeVol lv,ListeAvion la){
    if(existVol(lv,IdAvion)){
        printf("Vous ne pouvez pas supprimer l'avion car l'avion existe dans la table Vol\n");
        return la;
    }
    else{
            la=supprimermilieu(la,IdAvion);
            printf("Vous avez supprimer l'avion avec id %d \n",IdAvion);
            return la;
    }
}
void transfert_tabAvion_fichier(tabAvion T,ListeAvion Av){
    if(T!=NULL){
        FILE* fic3=fopen("tableAvion.txt","a+");
      if (fic3 == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        return ;
        }
              int n=longueurListeAvion(Av);
              int i=0;
               while(i<n){
                fprintf(fic3,"%d %s %d\n",T[i].idAvion,T[i].modele,T[i].capacite);
                i++;
               }
            fclose(fic3);
            printf("Enregistrement de la table Avion est effectif\n");
      }
}
////////////Pilotes//////////////////////***********************
int existePilote(ListePilote P,int idPilote){
    ListePilote courant =P;
    while (courant != NULL) {
        if (courant->idPilote == idPilote){
            return 1;
            }
        courant = courant->next;
    }
    return 0;
}
ListePilote creer_maillonPilote(int idPilote ,chaine nom,chaine prenom ){
  ListePilote nP=(ListePilote)malloc(sizeof(PILOTE));
  nP->idPilote=idPilote;
  strcpy(nP->nom,nom);
  strcpy(nP->prenom,prenom);
  nP->next=NULL;
  return nP;
}
void charger_Table_Pilote(ListePilote *P){
    FILE *fp3=fopen("fichierPilote.txt","r");
    if(fp3==NULL)
     {
       printf("impossible d'ouvrir ce fichier!");
       exit(-1);
    }
   int idPilote;
   chaine nom,prenom;
   ListePilote q=NULL;
   while(fscanf(fp3,"%d %s %s\n",&idPilote,nom,prenom)==3){
      if(*P==NULL)
          q=*P=creer_maillonPilote(idPilote,nom,prenom);
        else{
            q->next=creer_maillonPilote(idPilote,nom,prenom);
        q=q->next;
     }
   }
  fclose(fp3);
  printf("La table Pilote a été chargée avec succès.\n");
}
void inserer_Pilote(ListePilote *P,int idPilote,chaine nom,chaine prenom){
    if(existePilote(P,idPilote)){
      printf("le pilote avec ce code  existe déjà !");
      free(P);
      return;
    }
    ListePilote m=creer_maillonPilote(idPilote,nom,prenom);
     m->next=*P;
      *P=m;
}
void afficher_Pilote(ListePilote P){
 ListePilote q=P;
 printf("l'affichage de la liste des Pilotes:\n");
 printf("***********************************\n");
 printf("idP\tnom\tprenom\n");
    while(q!=NULL){
    printf("\033[1;31m%d \t%s \t%s\033[0m\n",q->idPilote,q->nom,q->prenom);
    q=q->next;
    }
      printf("\n");
      printf("***********************************\n");
}
void afficherTab_Pilote(tabPilote tp,ListePilote P){
 int n=longueurListePilote(P);
 int i=0;
 printf("l'affichage du tableau des Pilotes:\n");
 printf("***********************************\n");
 printf("idP\tnom\tprenom\n");
    while(i<n){
    printf("\033[1;31m%d \t%s \t%s\033[0m\n",tp[i].idPilote,tp[i].nom,tp[i].prenom);
    i++;
    }
      printf("\n");
      printf("***********************************\n");
}
int longueurListePilote(ListePilote P){
 ListePilote q=P;
  int j=0;
  while(q)
  {j=j+1;
    q=q->next;
  }
  return j;
}
tabPilote tlt_pilotes(ListePilote P ){
  int n=longueurListePilote(P);
  tabPilote T=(tabPilote)malloc(n*sizeof(tabPILOTE));
  ListePilote m=P;
  for(int i=0;i<n;i++)
  {T[i].idPilote=m->idPilote;
   strcpy(T[i].nom,m->nom);
   strcpy(T[i].prenom,m->prenom);
   m=m->next;
  }
  return T;
}
/*tabPilote tab_Pilote_trie(ListePilote P,tabPilote tp){
    int i,j;
    tabPILOTE tmp;
    for(i= 0 ; i < longueurListePilote(P)-1;i++){
        for(j=i+1;j< longueurListePilote(P);j++){
            if(strcmp(tp[i].nom,tp[j].nom)>0){
                tmp=tp[i];
                tp[i]=tp[j];
                tp[j]=tmp;
            }
        }
    }
    return tp;
    printf("le  tableau des pilotes a ete trie avec succes\n");
}*/
void trie(tabPilote t ,int n)
{ int d=n , esttrie , i , tmp1;
  char tmpN[255] , tmpP[255] ;
  while(d >0)
  { esttrie=1;
   for(i=0;i<d-1;i++)
   {  if(strcmp(t[i].nom,t[i+1].nom)>0)
     {
      strcpy(tmpN,t[i].nom);
      strcpy(tmpP,t[i].prenom);
      tmp1=t[i].idPilote;

      strcpy(t[i].nom,t[i+1].nom);
      strcpy(t[i].prenom,t[i+1].prenom);
      t[i].idPilote=t[i+1].idPilote;

      strcpy(t[i+1].nom,tmpN);
      strcpy(t[i+1].prenom,tmpP);
      t[i+1].idPilote=tmp1;
      esttrie=0;
     }
    if(strcmp(t[i].nom,t[i+1].nom)==0)
    {  if(strcmp(t[i].prenom,t[i+1].prenom)>0)
     {
      strcpy(tmpN,t[i].nom);
      strcpy(tmpP,t[i].prenom);
      tmp1=t[i].idPilote;

      strcpy(t[i].nom,t[i+1].nom);
      strcpy(t[i].prenom,t[i+1].prenom);
      t[i].idPilote=t[i+1].idPilote;

      strcpy(t[i+1].nom,tmpN);
      strcpy(t[i+1].prenom,tmpP);
      t[i+1].idPilote=tmp1;
      esttrie=0;
     }
    }
   }
   if(esttrie==1)
     break;
    d--;
 }
}
void transfert_tabPilote_fichier(tabPilote tp,ListePilote P){
    if(tp!=NULL){
        FILE* fic5=fopen("tablePilote.txt","a+");
      if (fic5 == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        return ;
        }
              int n=longueurListePilote(P);
              int i=0;
               while(i<n){
                fprintf(fic5,"%d %s %s\n",tp[i].idPilote,tp[i].nom,tp[i].prenom);
                i++;
               }
            fclose(fic5);
            printf("Enregistrement de la table Avion est effectif\n");
      }
}
int existePiloteVole(ListeVol V ,int idP)
{ListeVol p=V;
  while(p!=NULL)
  {if(p->idPilote==idP)
    return 1;
    p=p->next;
  }
  return 0;
}
void suprimerPilote(ListePilote *P,ListeVol V,int id)
{ if(!existePiloteVole(V,id))
     { int pos=existePilote(*P,id);
       if(pos)
       {ListePilote cour=*P,prec=*P; int i=1;
        if(pos>1){
         while(i++<pos)
         {prec=cour;
          cour=cour->next;
         }
          prec->next=cour->next;
           free(cour);
           cour=NULL;
          }
      if(pos==1)
       {ListePilote tmp=*P;
        (*P)=(*P)->next;
         free(tmp);
          tmp=NULL;
       }
    }
    printf("\nLe pilote n'est pas dans vole donc il est supprimer\n\n");
  }
  else
   printf("\nimpossible le Pilote est dans Vole!!\nVeuillez attendre qu'il atterisse Merci !!\n");
}
////////////Vols//////////////////////////*************************
ListeVol creer_maillonVol(int idVol,int idAvion,int idPilote ,chaine H_D,chaine H_A,int aero_D,int aero_A){
    ListeVol m=(ListeVol)malloc(sizeof(VOL));
    m->idVol = idVol;
    m->idAvion=idAvion ;
    m->idPilote=idPilote;
    strcpy(m->Heure_Depart, H_D);
    strcpy(m->Heure_Arrivee, H_A);
    m->aero_Depart=aero_D;
    m->aero_Arrivee=aero_A;
    m->next = NULL;
    return m;
}
void charger_Table_Vol(ListeVol* V) {
    FILE* fp4 = fopen("fichierVol.txt","r");
    if (fp4 == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(-1);
    }
    int idVol,idAVion,idPilote ;
    chaine Heure_Depart, Heure_Arrivee;
    int aero_Depart,aero_Arrivee;
    ListeVol tmp=NULL;
    while (fscanf(fp4,"%d %d %d %s %s %d %d",&idVol,&idAVion,&idPilote,Heure_Depart,Heure_Arrivee,&aero_Depart,&aero_Arrivee) == 7)
        {
           if(*V==NULL)
                tmp=*V=creer_maillonVol(idVol,idAVion,idPilote,Heure_Depart,Heure_Arrivee,aero_Depart,aero_Arrivee);
           else{
            tmp->next=creer_maillonVol(idVol,idAVion,idPilote,Heure_Depart,Heure_Arrivee,aero_Depart,aero_Arrivee);
            tmp=tmp->next;
    }
  }
  fclose(fp4);
  printf("La table Vol a été chargée avec succès.\n");
}
int existeVol(ListeVol V,int idVol) {
    ListeVol courant = V;
    while (courant != NULL) {
        if (courant->idVol == idVol){
            return 1;
            }
        courant = courant->next;
    }
    return 0;
}
void insererVol(ListeVol* V,ListeAvion* Av,ListePilote* PL,int idVol,int idAvion,int idPilote,chaine H_D,chaine H_A,int aero_D,int aero_A){
    if (existeAvion(*Av,idAvion)==0) {
        printf("Erreur : Avion avec Id %d introuvable dans la table AVION \n",idAvion);
        return;
    }
    if (existePilote(*PL,idPilote)==0) {
        printf("Erreur : pilote avec Id %d introuvable dans la table PILOTE\n",idPilote);
        return;
    }
    if(existeVol(*V,idVol)==1){
        printf("le vol avec id %d existe  deja.\n",idVol);
        return;
    }
    ListeVol nVol=creer_maillonVol(idVol,idAvion,idPilote,H_D,H_A,aero_D,aero_A);
    nVol->next=*V;
    *V= nVol;
}
void afficherVol(ListeVol V){
  ListeVol temp=V;
   printf("l'affichage de la liste des Vols:\n");
   printf("***********************************\n");
   printf("idVol\tidAv\tidP\tH_D\tH_A\taeroD\taeroA\n");
  while(temp!=NULL){
    printf("\033[1;31m%d \t%d \t%d \t%s \t%s \t%d \t%d\033[0m\n",temp->idVol,temp->idAvion,temp->idPilote,temp->Heure_Depart,temp->Heure_Arrivee,temp->aero_Depart,temp->aero_Arrivee);
    temp=temp->next;
  }
  printf("\n");
  printf("***********************************\n");
}
int longueurVol(ListeVol V){
ListeVol cour=V;int k=0;
  while(cour!=NULL)
  {
   k++;
   cour=cour->next;
  }
return k;
}
tabVol T_L_T(ListeVol V)
{
 int n=longueurVol(V),i=0;
 tabVol TV=(tabVol)malloc(n*sizeof(tabVOL));
  if(TV)
  {
   ListeVol Vol=V;
   while(Vol!=NULL)
   {
    TV[i].idVol=Vol->idVol;
    TV[i].idAvion=Vol->idAvion;
    TV[i].idPilote=Vol->idPilote;
    strcpy(TV[i].Heure_Depart,Vol->Heure_Depart);
    strcpy(TV[i].Heure_Arrivee,Vol->Heure_Arrivee);
    TV[i].aero_Derpart=Vol->aero_Depart;
    TV[i].aero_Arrivee=Vol->aero_Arrivee;
    i++;
    Vol=Vol->next;
   }
  }
  return TV;

}
tabVol trie_VOL(tabVol TV ,ListeVol V)
{
  int n=longueurVol(V),i,j;
     tabVOL tmp;
     for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(TV[i].idVol > TV[j].idVol){
                tmp=TV[i];
                TV[i]=TV[j];
                TV[j]=tmp;
            }
        }
    }
    return TV;
    printf("le  tableau de VOL a ete bien  trie avec succes\n");
}
void afficherTab_VOL(tabVol TV,ListeVol V)
{
  int n=longueurVol(V);
  printf("idVol\tidAv\tidP\tH_D\tH_A\taeroD\taeroA\n");
  for(int i=0;i<n;i++)
  {
    printf("\033[1;31m%d \t%d \t%d \t%s \t%s \t%d \t%d\033[0m\n",TV[i].idVol,TV[i].idAvion,TV[i].idPilote,TV[i].Heure_Depart,TV[i].Heure_Arrivee,TV[i].aero_Derpart,TV[i].aero_Arrivee);
  }
}
void transfert_tabVol_fichier(tabVol TV,ListeVol V){
    if(TV!=NULL){
        FILE* fic4=fopen("tableVol.txt","a+");
      if (fic4 == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        return ;
        }
              int n=longueurVol(V);
              int i=0;
               while(i<n){
                fprintf(fic4,"%d %d %d %s %s %d %d\n",TV[i].idVol,TV[i].idAvion,TV[i].idPilote,TV[i].Heure_Depart,TV[i].Heure_Arrivee,TV[i].aero_Derpart,TV[i].aero_Arrivee);
                i++;
               }
            fclose(fic4);
            printf("Enregistrement de la table Vol est effectif\n");
      }
}
ListeVol suprimerVol(ListeVol *V,listePassager* P ,int idVol)
{
 ListeVol cour=*V,prec;
 if(existePassaVOL(P,idVol)==0)
  {
    if(cour->idVol==idVol)
     {
        prec=cour;
        cour=cour->next;
        *V=cour;
        free(prec);
     }
     else
     {cour=*V;
      while(cour!=NULL)
      {
       if(cour->idVol!=idVol)
        {
          prec=cour;
          cour=cour->next;
        }
       else break;
      }
      prec->next=cour->next;
      free(cour);
     }
  }
 else
    printf("***ATTENTION***CE VOL NUMERO %d A ETE RESERVER***A LA PROCHAINE***\n",idVol);
return *V;
}
int existePassaVOL(listePassager P,int idVol){
   listePassager courant = P;
    while (courant != NULL) {
        if (courant->idVol == idVol){
            return 1;
            }
        courant = courant->next;
    }
    return 0;
}
////////////Passagers//////////////////////////////////////////////////
listePassager  creer_maillonPassager(int NumP, chaine nomP, chaine prenomP,int idvol) {
    listePassager m=(listePassager)malloc(sizeof(PASSAGER));
    if (m == NULL) {
        printf("Erreur d'allocation mémoire");
        exit(-1);
    }
    m->NumPassport=NumP;
     strcpy(m->nom, nomP);
     strcpy(m->prenom,prenomP);
     m->idVol=idvol;
    m->next = NULL;
     return m;
}
int existePassagers(listePassager P,int NumPassportP) {
    listePassager courant = P;
    while (courant != NULL) {
        if (courant->NumPassport == NumPassportP){
            return 1;
            }
        courant = courant->next;
    }
    return 0;
}
void charger_Table_Passagers(listePassager* P){
    FILE *fp5=fopen("fichierPassager.txt","r");
    if (fp5 == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        return;
    }
    int NumPassportP;
    chaine nomP;
    chaine prenomP;
    int  idvol;
    listePassager tmp=NULL;
    while (fscanf(fp5,"%d %s %s %d",&NumPassportP,nomP,prenomP,&idvol)== 4) {
           if(*P==NULL)
                tmp=*P= creer_maillonPassager(NumPassportP,nomP,prenomP,idvol);
           else
            {
             tmp->next= creer_maillonPassager(NumPassportP,nomP,prenomP,idvol );
             tmp=tmp->next;
           }
  }
  fclose(fp5);
  printf("la liste des Passagers a ete chargee avec succes.\n");
}
int longueurP(listePassager P){
        int cp=0;
        while(P!=NULL){
            cp++;
            P=P->next;
    }
    return cp;
}
void insererPassager(listePassager *P,ListeVol* V,int NumPassportP,chaine nomP, chaine prenomP, int idvol){
        if(existePassagers(*P,NumPassportP)){
            printf("impossible le NumPassport existe !\n");
            return ;
        }

        if(existeVol(*V,idvol)==0){
           printf("impossible le Vol avec id %d n'existe pas dans la table Vol !\n",idvol);
           return ;
        }
        listePassager newP = creer_maillonPassager(NumPassportP,nomP, prenomP, idvol);
             newP->next=*P;
              *P=newP;
}
tabPassager tfert_tableau(listePassager Pa){
    int n=longueurP(Pa);
    tabPassager T=(tabPassager)malloc(n*sizeof(tabPASSAGER));
    if(T!=NULL){
        int i=0;
        listePassager P=Pa;
      while(P!=NULL){
             T[i].NumPassport=P->NumPassport;
             strcpy(T[i].nom,P->nom);
             strcpy( T[i].prenom,P->prenom);
             T[i].idVol=P->idVol;
             i++;
             P=P->next;

         }
         return T;
         printf("le transfert de la liste Passager vers tableau est succes\n");
      }
}
listePassager supprimerPassager(listePassager P,int NumPassportP){
        listePassager  m=NULL,  courant ,tmp=NULL;
            if(P==NULL){
              printf("liste vide");
               return NULL;
            }
            courant=P;
             while(courant!=NULL && courant->NumPassport!=NumPassportP ){
               tmp=courant;
            courant=courant->next;  }
                if(courant!=NULL) {
                m=courant->next;
                tmp->next=m;
                free(courant);
                }
            return P;
}
tabPassager tab_Passagers_trie(listePassager PA,tabPassager tp){
    int i,j;
    tabPASSAGER tmp;
    for(i= 0 ; i < longueurP(PA)-1;i++){
        for(j=i+1;j< longueurP(PA);j++){
            if(strcmp(tp[i].nom,tp[j].nom)>0){
                tmp=tp[i];
                tp[i]=tp[j];
                tp[j]=tmp;
            }
        }
    }
    return tp;
    printf("le  tableau d'aeroports a ete trie avec succes\n");
}
void afficherListe_Passagers(listePassager P){
    listePassager temp=P;
    printf("l'affichage de la liste des Passagers:\n");
   printf("***********************************\n");
   printf("NumP\tNom\tPrenom\tidVol\n");
  while(temp!=NULL){
    printf("\033[1;31m%d \t%s \t%s \t%d\033[0m\n",temp->NumPassport,temp->nom,temp->prenom,temp->idVol);
    temp=temp->next;
  }
  printf("\n");
  printf("***********************************\n");
}
void afficherTab_Passagers(tabPassager tp,listePassager P){
    int n=longueurP(P);
    int i=0;
    printf("l'affichage du Tableau des  Passagers:\n");
   printf("***********************************\n");
   printf("NumP\tNom\tPrenom\tidVol\n");
  while(i<n){
    printf("\033[1;31m%d \t%s \t%s \t%d\033[0m\n",tp[i].NumPassport,tp[i].nom,tp[i].prenom,tp[i].idVol);
    i++;
  }
  printf("\n");
  printf("***********************************\n");
}
void transfert_tabPassager_fichier(tabPassager tpa,listePassager P){
    if(tpa!=NULL){
        FILE* fic2=fopen("tablePassager.txt","a+");
      if (fic2 == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        return ;
        }
              int n=longueurP(P);
              int i=0;
               while(i<n){
                fprintf(fic2,"%d %s %s %d\n",tpa[i].NumPassport,tpa[i].nom,tpa[i].prenom,tpa[i].idVol);
                i++;
               }
            fclose(fic2);
            printf("Enregistrement de la table Passager est effectif\n");
      }
}
/////////////////REQUETES///////////////////////////////
void requete_aeroport1(ListeVol V, ListeAeroport A) {
     printf("************************************\n");
    ListeVol temp = V;
     printf("nom\tville\n");
    while (temp != NULL) {
        if (temp->idAvion == 11 && strcmp(temp->Heure_Depart, "20:00") < 0) {
            ListeAeroport p= A;
            while (p != NULL) {
                if (p->codeAeroport == temp->aero_Depart) {
                    printf("\033[1;31m%s\t%s\033[0m\n",p->nom,p->ville);
                    break;                 }
                p = p->next;
            }
        }
        temp = temp->next;
    }
     printf("************************************\n");
}
void  requete_Avions_plus_vols(ListeVol V)
{
    int nbvols[100]={0};
    int maxnbvols=0;
    ListeVol temVol=V;
    while(temVol!=NULL){
        nbvols[temVol->idAvion]++;
        temVol=temVol->next;
    }
    for(int i=0;i<100;i++){
        if(nbvols[i]>maxnbvols){
            maxnbvols=nbvols[i];
        }
    }
     printf("************************************\n");
    for(int i=0;i<100;i++){
        if(nbvols[i]==maxnbvols){
            printf("\033[1;31mID Avion : %d ,Nombre de vols : %d\033[0m\n",i,nbvols[i]);
            }
        }
    printf("************************************\n");
}
void requette_VOL4(ListeVol *V ,ListePilote *P,listePassager *PA,int idP,int idPas)
{
 printf("************************************\n");
 printf("idVol\tidAv\tidP\tH_D\tH_A\taeroD\taeroA\n");
  ListeVol courv=*V;ListePilote courpi=*P;listePassager courpa=*PA;
  while(courv!=NULL)
  {
    while(courpa!=NULL)
    {
      if(courpa->NumPassport==idPas && courv->idPilote==idP && courpa->idVol==courv->idVol)
      {
         printf("\033[1;31m%d \t%d \t%d \t%s \t%s \t%d \t%d\033[0m\n",courv->idVol,courv->idAvion,courv->idPilote,courv->Heure_Depart,courv->Heure_Arrivee,courv->aero_Depart,courv->aero_Arrivee);
         courpa=courpa->next;
      }
       else{
        courpa=courpa->next;}
    }
    courv=courv->next;
  }
   printf("************************************\n");
}
void requete_pilote_sans_vol(ListePilote p,ListeVol v){
    printf("*******************************************\n");
     printf("idP\tnom\tprenom\n");
    ListePilote tmpPilote=p;
    int aucunvol=1;

    while(tmpPilote!=NULL){
     if(!existePiloteVole(v,tmpPilote->idPilote)){
      printf("\033[1;31m%d \t%s \t%s\033[0m\n",tmpPilote->idPilote,tmpPilote->nom,tmpPilote->prenom);
        aucunvol=0;
        }
        tmpPilote=tmpPilote->next;
      }
       if(aucunvol){
        printf("tous les pilotes ont effectue des vols\n");
        }
    printf("*******************************************\n");

}
void requette_avion_piloter(ListeVol V,ListeAvion A)
{ ListeVol p=V;
while(p!=NULL)
{ if(p->idPilote==111)
    { ListeAvion q=A;
     while(q!=NULL)
      {if(p->idAvion==q->idAvion)
       {printf("\n%d  %s  %d\n",q->idAvion,q->modele,q->capacite);
           break;}
        q=q->next;
      }
    }
    p=p->next;
}
}
