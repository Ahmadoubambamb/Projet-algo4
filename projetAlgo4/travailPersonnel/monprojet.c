#include "monprojet.h"
ListePilote creer_maillonPilote(int id ,chaine nom,chaine prenom)
{ ListePilote nouv=(ListePilote)malloc(sizeof(struct Pilote));
  nouv->idPilote=id; strcpy(nouv->nom,nom); strcpy(nouv->prenom,prenom);
  nouv->next=NULL;
  return nouv;
}
void afficher_Pilote(ListePilote P)
{ListePilote q=P;
    while(q)
    { printf("%d  %s  %s \n",q->idPilote,q->nom,q->prenom);
        q=q->next;
    }
     printf("\n=========================\n");
}
void charger_Table_Pilote(ListePilote *P)
{ FILE *fic=fopen("fichierpilote.txt","r");
    if(!fic)
   {printf("impossible d'ouvrir ce fichier !!!");
       exit(1);
   }
   ListePilote q=*P=NULL;
   int a; chaine b , c;
   while(fscanf(fic,"%d%s%s",&a,b,c)==3)
   { if(!(*P))
     q=*P=creer_maillonPilote(a,b,c);
     else
     {q->next=creer_maillonPilote(a,b,c);
       q=q->next;
     }
   }
   fclose(fic);
}

void inserer_Pilote(ListePilote *P,int id , chaine nom,chaine prénom)
{ if(!existePilote(*P,id))
     { ListePilote m=creer_maillonPilote(id,nom,prénom);
     m->next=*P;
      *P=m;
      }
      else
      printf("Attention !! ##Incoherence !!!!! \n");
}
int existePilote(ListePilote L ,int id)
{ListePilote p=L; int i=1;
  while(p!=NULL)
  { if(p->idPilote==id)
    return i;
    p=p->next;
    i++;
  }
  return 0;
}
int longList(ListePilote P)
{ListePilote q=P;
  int j=0;
  while(q)
  {j=j+1 ;
    q=q->next;
  }
  return j;
}
tabPilote tlt(ListePilote P ,int *n)
{ tabPilote T=(tabPilote)malloc(longList(P)*sizeof(tPILOTE));
  ListePilote m=P;
  for(int i=0;i<longList(P);i++)
  {T[i].idPilote=m->idPilote;
   strcpy(T[i].nom,m->nom); strcpy(T[i].prenom,m->prenom);
   m=m->next;
  }
  (*n)=longList(P);
  return T;
}
void afficher_tabpilote(tabPilote t ,int n)
{ for(int i=0;i<n;i++)
  printf("%d  %s   %s \n\n",t[i].idPilote,t[i].nom,t[i].prenom);
  printf("============================\n");
}
ListePilote ttl(tabPilote t ,int n)
{ListePilote P=NULL,m=NULL;
  for(int i=0;i<n;i++)
  {if(P==NULL)
    P=m=creer_maillonPilote(t[i].idPilote,t[i].nom,t[i].prenom);
    else
    {m->next=creer_maillonPilote(t[i].idPilote,t[i].nom,t[i].prenom);
     m=m->next;
    }
  }
 return P;
}
void trie(tabPilote t ,int n)
{ int d=n , esttrie , i;
  chaine tmpN , tmpP ; int tmp1;
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
   }
   if(esttrie)
     break;
    d--;
 }
}
/*void decharger_Table_Pilote(ListePilote P)
{ FILE *fic=fopen("fichierpiloteD.txt","a");
    if(!fic)
   {printf("impossible d'ouvrir ce fichier !!!");
       exit(1);
   }
   ListePilote q=P;
   while(q)
   { fprintf(fic,"%d %s %s\n",q->idPilote,q->nom,q->prenom);
     q=q->next;
   }
   fclose(fic);
}*/
int existePiloteVole(ListeVol V ,int idP)
{ListeVol p=V;
  while(p!=NULL)
  {if(p->idPilote==idP)
    return 1;
    p=p->next;
  }
  return 0;
}
void supprimerPilote(ListePilote *P,ListeVol V,int id)
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
    printf("Le pilote n'est pas dans vole donc il est supprimer \n");
  }
  else
   printf("impossible le Pilote est dans Vole!!\nVeuillez attendre qu'il atterisse Merci !!\n");
}
//+++++++++++++++++++++++++++++++++++++++++++++++


ListeVol creer_maillonVol(int idVol,int idAvion,int idPilote ,chaine H_D,chaine H_A,int aero_D,int aero_A)
 {
    ListeVol m=(ListeVol)malloc(sizeof(VOL));
    if (m == NULL) {
        printf("Erreur d'allocation mémoire");
        exit(-1);
    }
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
    FILE* fp4 = fopen("fichiervol.txt","r");
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
int existeVol(ListeVol *V,int idVol) {
    ListeVol courant = *V;
    while (courant != NULL) {
        if (courant->idVol == idVol){
            return 1;
            }
        courant = courant->next;
    }
    return 0;
}
/*void insererVol(ListeVol* V,ListeAvion Av,ListePilote PL,int idVol,
                int idAvion,int idPilote,chaine H_D,chaine H_A,int aero_D,int aero_A) {
    if (!existeAvion(Av,idAvion)) {
        printf("Erreur : Avion avec Id %d introuvable.\n",idAvion);
        return;
    }
    if (!existePilote(PL, idPilote)){
        printf("Erreur : Pilote avec Id %d introuvable.\n",idPilote);
        return;
    }
    if(existeVol(*V,idVol)){
        printf("le vol avec id %d existe  deja.\n",idVol);
        return;
    }
    ListeVol nVol=creer_maillonVol(idVol,idAvion,idPilote,H_D,H_A,aero_D,aero_A);
    nVol->next=*V;
    *V= nVol;
}*/
void afficherVol(ListeVol V){
  ListeVol temp=V;
   printf("l'affichage de la liste des Vols:\n");
   printf("***********************************\n");
  while(temp!=NULL){
    printf("%d %d %d %s %s %d %d\n",temp->idVol,temp->idAvion,temp->idPilote,temp->Heure_Depart,temp->Heure_Arrivee,temp->aero_Depart,temp->aero_Arrivee);
    temp=temp->next;
  }
  printf("\n");
  printf("***********************************\n");
}
/*void supprimerVol(ListeVol V ,int idvol)
{
 ListeVol cour=V,prec=NULL,nex;
 if(cour==NULL)
  {
   printf("LA TABLE EST VIDE \n");
   return;
  }
  if(V->idVol==idvol)
  {
   prec=V;
   V=cour->next;
  }
    while(cour!=NULL)
     {
       nex=prec;
       prec=cour;
       cour=cour->next;
       if(prec->idVol==idvol)
           nex->next=cour;
     }
prec->next=NULL;
free(prec);
}
*/

