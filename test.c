#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct agenda
{
    char nume[51], numar[11], adresa[51];
};

void sortareAgendaNume(struct agenda contact[], int nr_contact)
{
    int i, j;
    struct agenda copie;

    for (i = 0; i < nr_contact - 1; i++)
    {
        for (j = i + 1; j < nr_contact; j++)
        {
            if (strcmp(contact[i].nume, contact[j].nume) > 1)
            {
                copie = contact[i];
                contact[i] = contact[j];
                contact[j] = copie;
            }
        }
    }
}

void cautaContactDupaNumar(struct agenda contact[], int nr_contact, char numarcautat[])
{
    int i, gasit = 0;
    for (i = 1; i < nr_contact; i++)
    {
        if (strcmp(contact[i].numar, numarcautat) == 0)
        {
            printf("Contact gasit:\n");
            printf("Nume: %s\n", contact[i].nume);
            printf("Numar telefon: %s\n", contact[i].numar);
            printf("Adresa email: %s\n", contact[i].adresa);
            gasit = 1;
            break;
        }
    }

    if (gasit == 0)
        printf("Nu s-a gasit niciun contact cu acest numar de telefon\n");
}

void cautaContactDupaNume(struct agenda contact[], int nr_contact, char numecautat[])
{
    int i, gasit = 0;
    for (i = 1; i < nr_contact; i++)
    {
        if (strcmp(contact[i].nume, numecautat) == 0)
        {
            printf("Contact gasit:\n");
            printf("Nume: %s\n", contact[i].nume);
            printf("Numar telefon: %s\n", contact[i].numar);
            printf("Adresa email: %s\n", contact[i].adresa);
            printf("\n");
            gasit = 1;
            break;
        }
    }

    if (gasit == 0)
        printf("Nu s-a gasit niciun contact cu acest nume\n");
}

void main(void)
{
    struct agenda contact[20];
    int optiune, pas = 1, nr_contact = 1, ok, i, j, iesire = 1;
    char repetare, numarcautat[11], numecautat[51];

    do
    {

        printf("------------------------------- MENIU -------------------------------\n");
        printf("Pentru a adauga o persoana in contact apasati tasta 1\n");
        printf("Pentru a lista contactele apasati tasta 2\n");
        printf("Pentru a cauta un contact dupa numarul de telefon apasati tasta 3\n");
        printf("Pentru a cauta un contact dupa neme apasati tasta 4\n");
        printf("---------------------------------------------------------------------\n");
        scanf("%d", &optiune);
        printf("\nAti ales optiunea ");

        if (optiune == 1)
        {
            printf("adaugare persoana in contact\n");
            printf("\n");

            printf("Introduceti numele contactactului: ");
            scanf(" %50s", &contact[nr_contact].nume);
            printf("\nIntroduceti numarul de telefon: ");
            scanf(" %10s", &contact[nr_contact].numar);
            printf("\nIntroduceti adresa de email: ");
            scanf(" %50s", &contact[nr_contact].adresa);

            printf("\nAti introdus contactul cu urmatoarele specificatii in agenda:\n");
            printf("Nume: %s\n", contact[nr_contact].nume);
            printf("Numar telefon: %s\n", contact[nr_contact].numar);
            printf("Adresa email: %s\n", contact[nr_contact].adresa);
            nr_contact++;
            ok = 1;
        }
        else if (optiune == 2)
        {
            printf("listare contacte\n");
            ok = 1;
            sortareAgendaNume(contact, nr_contact);

            for (i = 1; i < nr_contact; i++)
            {
                printf("%d) Nume: %s   |   Telefon: %s   |   Email: %s\n", i, contact[i].nume, contact[i].numar, contact[i].adresa);
            }
        }
        else if (optiune == 3)
        {
            printf("cautare dupa numarul de telefon\n");
            ok = 1;

            printf("Introduceti numarul de telefon pe care doriti sa-l cautati: ");
            scanf(" %10s", numarcautat);
            printf("\n");
            cautaContactDupaNumar(contact, nr_contact, numarcautat);
        }
        else if (optiune == 4)
        {
            printf("cautare dupa nume\n");
            ok = 1;

            printf("Introduceti numele pe care doriti sa-l cautati: ");
            scanf(" %50s", numecautat);
            printf("\n");
            cautaContactDupaNume(contact, nr_contact, numecautat);
        }
        else
            printf("ati apasat o tasta gresita, va rugam sa apasati alta tasta \n");

        if (ok == 1)
        {
            do
            {
                printf("\nDoriti sa mai utilizati vreo optiune? Y = \"Da\" | N = \"Nu\"\n");
                scanf(" %c", &repetare);
                getchar();
                if (toupper(repetare) == 'N')
                {
                    pas = 0;
                    iesire = 0;
                }
                else if (toupper(repetare) == 'Y')
                {
                    ok = 0;
                    iesire = 0;
                }
                else
                    printf("Ati introdus o valoare incorecta. Va rugam reincercati!\n");
            } while (iesire != 0);
        }
    } while (pas != 0);
}