// LIBRAIRIES
#include "lora.h"

// MAIN
int main()
{
    // Initialisation des variables
    // variable i ??
    double tempsEmission[NB_MAX_ESSAIS];        // ej
    double tempsAttente[NB_MAX_ESSAIS - 1];     // wj

    for(int i = 0; i < NB_MAX_ESSAIS; i++)
    {
        tempsEmission[i] = 10;

        if(i < (NB_MAX_ESSAIS - 1))
        {
            tempsAttente[i] = 0.25;
        }
    }

    // Calculs
    Simulateur(tempsEmission, tempsAttente);

    // Fin
    exit(0);
}