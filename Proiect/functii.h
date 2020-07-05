#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

///scrie in fisier datele unui bilet
int scriere_bilet(FILE* fisier,struct Bilet_lotto bilet){
    if(fprintf(fisier,"%ld: ",bilet.ID)<=0)///verific daca s-a reusit scrierea
        return 0;///nu s-a putut scrie ID-ul pe bilet
    int i;
    for(i=0;i<SASE;i++){///scrierea a exact 6 numere in fisier
        if(fprintf(fisier,"%d ",bilet.numere[i].v)<=0)///scrie cele 6 numere in fisier,iar numerele sunt luate din structura Bilet_lotto
            return 0;///nu s-a putut scrie un numar
        }
        fprintf(fisier,"\n");///rand nou dupa fiecare set de 6 numere
  return 1;///terminarea cu succesc a functiei
}


///verificare daca exista dubluri printre numere
int verificare_dubluri(int v[],int j){
 int k;
 int r =rand()%PATRU_NOUA+1;///r=numar random intre 1 si 49,restul maxim poate fi 48 asadar avem +1
 v[j]=r;///v=vectorul cu numerele generate in acelasi bilet,j reprezinta pozitiile numerelor,punem in v fiecare numar r random
    int c=0;
     for(k=j-1;k>=0;k--){///parcurge toate numerele generate inainte in acest bilet
        while(r==v[k]){///se tot regenereaza alt numar pana cand nu mai exista dubluri
            r=rand()%PATRU_NOUA+1;///regenerarea din nou a numarului random r
            c=1;///marcam ca s-a gasit o dublura
            }
            if(c==1){///daca s-a gasit o dublura
        k=j-1;///luam verificarea de la capat (capatul acestui bilet in care suntem)
        c=0;///indica faptul ca s-a identificat o dublura si trebuie sa reluam cautarea de la inceput
        }
    } return r;

     }



///genereaza cele 200000 de bilete
void genereaza_jocuri(char* nume_fisier){///primeste ca parametru numele fisierului
    int i,j;
    int*v;
    v=(int*)malloc(SASE*sizeof(int));///alocarea dinamica a memoriei pentru 6 numere intregi
FILE* fisier;///declararea unui pointer la o structura de tip fisier
fisier=fopen(nume_fisier,"w");///deschidere fisier pentru scriere

///verificare daca s-a putut deschide fisierul
if(fisier==NULL){
    printf("Nu am putut crea fisierul");
    return;
}

   srand(time(NULL));///initializare functie pentru generare numere random
struct Bilet_lotto* bilet;///biletul de lotto jucat
  bilet=(struct Bilet_lotto*)malloc(sizeof(struct Bilet_lotto));///alocare dinamica a memoriei
   for(i=0;i<N;i++){///parcurge toate cele 200000 de bilete si le creeaza
        bilet->ID=i+1;/// ID=al catelea bilet este(porneste de la 0, ar ajunge pana la 199999 asadar vom avea +1)
    for(j=0;j<SASE;j++){///generez fiecare numar din cele 6 ale unui bilet

      bilet->numere[j].v=verificare_dubluri(v,j);///salavarea numarului ok fara dubluri
       *(v+j)=bilet->numere[j].v;
    }
    if(scriere_bilet(fisier,*bilet)==0)///scriere in fisier a biletului
        break;///daca un bilet nu a putut fi scris, nu mai continuam si cu urmatoarele
   }

    fclose(fisier);///inchidem fisierul
    free(bilet);///eliberam memoria
    free(v);

    printf("Popa Catalin Andrei                                                                                  11.01.2018\n");
    printf("C.T.I. , GRUPA 154 \n\n");
    printf("                                     PROIECT 6/49                                   \n\n");
    printf("Am terminat de generat:\n");
}

void Alocare_structuri{
int i,n;
int v[i]=(struct Bilet_lotto*)malloc(sizeof(struct Bilet_lotto)*n);}



///extrage numerele castigatoare
struct Bilet_lotto* extragere(){
    int i;
    int *v=(int*)malloc(sizeof(int)*SASE);///alocarea dinamica a memoriei pentru 6 numere intregi
    struct Bilet_lotto* b;///b=biletul cu numerele castigatoare
    b=(struct Bilet_lotto*)malloc(sizeof(struct Bilet_lotto));///alocarea memoriei pentru bilet
    b->ID=0;///initializarea ID-ului cu 0
    for(i=0;i<SASE;i++){///parcurge fiecare numar pentru biletul castigator
        b->numere[i].v=verificare_dubluri(v,i);///genereaza un nou numar fara dublura si il pune in numarul de pe pozitia i
        *(v+i)=b->numere[i].v;///memorarea numarului random de pe pozitia i,vectorul tine minte ca la pasul urmator sa genereze un numar diferit de cele de pana acum
      }
      return b;
}



///deschide fisierul si numara cate castiguri de fiecare fel sunt
struct Tabel_castigatori calc_castigatori(char* nume_fisier,struct Bilet_lotto*castig){///castig=biletul cu numerele castigatoare
 int r,b=0;
 int i,j;
 long int id;
 struct Tabel_castigatori tabela;
tabela.castiguri_de_3=0;
tabela.castiguri_de_4=0;
tabela.castiguri_de_5=0;
tabela.castiguri_de_6=0;
 FILE* fisier;///acceseaza fisierul
 fisier=fopen(nume_fisier,"r");
     if(fisier==NULL){
        printf("Nu am putut deschide fisierul");
          return;   }
          while(!feof(fisier)){///citesc toate biletele din fisier pana la sfarsit
                b=0;
                fscanf(fisier,"%ld",&id);///citesc ID-ul biletului
                fseek(fisier,1,SEEK_CUR);///sar peste caracterul ":"
                for(i=0;i<SASE;i++){///citesc fiecare numar din fisier si verific cate dintre ele sunt printre cele castigatoare
                    fscanf(fisier,"%d",&r);
                       for(j=0;j<SASE;j++){///parcurgem fiecare numar de pe biletul cu numerele castigatoare
                        if(r==castig->numere[j].v)///daca numarul citit din fisier este egal cu unul de pe biletul cu numere castigatoare
                         b++;///contorul pentru a indica cate dintre numerele unui bilet sunt printre cele castigatoare
                       }

                }
                switch(b){///pentru fiecare castig se incrementeaza contorul corespunzator
                case 3:tabela.castiguri_de_3++;
                break;

                case 4:tabela.castiguri_de_4++;
                break;

                case 5:tabela.castiguri_de_5++;
                break;

                case 6:tabela.castiguri_de_6++;
                break;
                }
           }
tabela.valori[0]=(5*N)/100;
tabela.valori[1]=(15*N)/100;
tabela.valori[2]=(20*N)/100;
tabela.valori[3]=(60*N)/100;
   fclose(fisier);

   return tabela;
   }

void afisare_castigatoare(struct Bilet_lotto bilet){///afiseaza cele 6 numerele castigatoare
   int i;
   for(i=0;i<SASE;i++)
   {
       printf("%d ",bilet.numere[i].v);
   }
}

void afisare_castiguri(struct Tabel_castigatori tabela){
    printf(" \nCastiguri de 3 nr: %d  Valoare:%d lei\n",tabela.castiguri_de_3, tabela.valori[0]);
    printf("Castiguri de 4 nr: %d   Valoare:%d lei\n",tabela.castiguri_de_4,tabela.valori[1]);
    printf("Castiguri de 5 nr: %d     Valoare:%d lei\n",tabela.castiguri_de_5,tabela.valori[2]);
    printf("Castiguri de 6 nr: %d     Valoare:%d lei\n",tabela.castiguri_de_6,tabela.valori[3]);
    }


#endif // FUNCTII_H_INCLUDED
