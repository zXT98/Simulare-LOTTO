#include <stdio.h>
#include <stdlib.h>
#include "structuri.h"
#include "functii.h"


int main()
{
    ///generarea celor 20000 de bilete si scrierea in fisier
    genereaza_jocuri("Jocuri.txt");
    ///extragerea celor 6 numere castigatoare
    struct Bilet_lotto*rezultate=extragere();
    ///afisarea celor 6 numere castigatoare
    afisare_castigatoare(*rezultate);
    ///afisarea castigurilor pe categorii
    afisare_castiguri(calc_castigatori("Jocuri.txt",rezultate));
    free(rezultate);
    return 0;

}
