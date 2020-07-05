#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define N 200000

 struct Tabel_castigatori{
  int castiguri_de_3;
  int castiguri_de_4;
  int castiguri_de_5;
  int castiguri_de_6;};

void genereaza_jocuri(char* nume_fisier){
    int i,j,k,v[6];
FILE* fisier;
fisier=fopen(nume_fisier,"w");

//scanf("%d",&N_rezerva);
if(fisier==NULL){
    printf("Nu am putut crea fisierul");
    return;
}
   srand(time(NULL));

   for(i=0;i<N;i++){
    for(j=0;j<6;j++){
            int r =rand()%49+1;
    v[j]=r;
    int c=0;
     for(k=j-1;k>=0;k--){
        while(r==v[k]){
            r=rand()%49+1;
            c=1;
            }
            if(c==1){
        k=j-1;
        c=0;
        }
     }

     fprintf(fisier,"%d ",r);

    }
    fprintf(fisier,"\n");
   }

    fclose(fisier);
    printf("Am terminat de generat\n");


}
int* extragere(){
    int i,k;
    int *v;
    v=(int*)malloc(6*sizeof(int));
    for(i=0;i<6;i++){
     v[i]=rand()%49+1;
    int c=0;
     for(k=i-1;k>=0;k--){
        while(v[i]==v[k]){
            v[i]=rand()%49+1;
            c=1;
            }
            if(c==1){
        k=i-1;
        c=0;
        }
    }
      }
      return v;}

//dubluri
//structura cu 4 membrii intregi castiguri de 3 4 5 6
//calc castigatori sa returneze structura
//completat case 4: case 5: case 6: (facut)
struct Tabel_castigatori calc_castigatori(char* nume_fisier,int*castig){
 int r,b=0;
 int i,j;
 struct Tabel_castigatori tabela;
tabela.castiguri_de_3=0;
tabela.castiguri_de_4=0;
tabela.castiguri_de_5=0;
tabela.castiguri_de_6=0;
 FILE* fisier;
 fisier=fopen(nume_fisier,"r");
     if(fisier==NULL){
        printf("Nu am putut deschide fisierul");
          return;   }
          while(!feof(fisier)){
                b=0;
                for(i=0;i<6;i++){
                    fscanf(fisier,"%d",&r);
                       for(j=0;j<6;j++){
                        if(r==castig[j])
                         b++;
                       }
                }
                switch(b){
                case 3:tabela.castiguri_de_3++;
                break;
                }
                switch(b){
                case 4:tabela.castiguri_de_4++;
                break;
                }
                switch(b){
                case 5:tabela.castiguri_de_5++;
                break;
                }
                switch(b){
                case 6:tabela.castiguri_de_6++;
                break;
                }
           }

   fclose(fisier);

   return tabela;
   }

#endif // HEADER_H_INCLUDED
