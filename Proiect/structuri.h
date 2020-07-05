#ifndef STRUCTURI_H_INCLUDED
#define STRUCTURI_H_INCLUDED

#define N 200000
#define SASE 6
#define PATRU_NOUA 49

///tabela pentru a memora castigurile pentru fiecare categorie
 struct Tabel_castigatori{
  int castiguri_de_3:20;
  int castiguri_de_4:20;
  int castiguri_de_5:20;
  int castiguri_de_6:20;
  int valori[4]};

  ///un numar random extras intre 1 si 49
  union Numar{
  int v:7;
  };

  ///bilet lotto cu identificator si 6 numere random
 struct Bilet_lotto{
  long int ID;
  union Numar numere[SASE]} ;


#endif // STRUCTURI_H_INCLUDED
