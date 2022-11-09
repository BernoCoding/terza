/*
    Questo programma chiede in input una data ben formattata e calcola quanti giorni è
    distante dall'anno 0.
*/

#include <stdio.h>

void main()
{
    int g, m, a;
    int gTotali, gAnniCompleti, gAnnoCorrente;

    printf("Inserisci giorno mese e anno (gg/mm/aaaa): ");
    scanf("%d/%d/%d", &g, &m, &a);

    gAnniCompleti = 365*(a-1);
    gAnniCompleti += (a-1)/4 - (a-1)/100 + (a-1)/400; // aggiusto considerando anni bisestili

    gAnnoCorrente = 0;
    for (int i = 1; i < m; i++) // escludo il mese corrente!
    {
        switch (i)
        {
        case 10:
        case 4:
        case 6:
        case 9:
            gAnnoCorrente += 30;
            break;
        case 2:
            gAnnoCorrente += 28;
            break;
        default:
            gAnnoCorrente += 31;
            break;
        }
    }
    // se è passato febbraio e l'anno è bisestile aggiungo 1
    if ((m > 2) && (a % 400 == 0 || (a % 4 == 0 && a % 100 != 0)))
    {
        gAnnoCorrente += 1;
    }
    // aggiungo i giorni della data, oggi escluso
    gAnnoCorrente += g - 1;

    gTotali = gAnnoCorrente + gAnniCompleti;

    printf("Dall'inizio dei tempi sono passati %d giorni", gTotali);
}
