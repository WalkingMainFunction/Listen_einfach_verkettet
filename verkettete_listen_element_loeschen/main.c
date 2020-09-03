#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include <windows.h>

typedef struct Person
{
    char vorname[30];
    char nachname[30];
    int alter;

    struct Person *next;

}Person;

void anlegen(int groesse, Person **start);
void loeschen(int groesse, Person **start, int eliminate);

void anlegen(int groesse, Person **start)
{
    int anz = 0;
    Person *p, *h;
    //Person *start = NULL;
    do
    {
        p = (Person *) malloc(sizeof(Person));

        if(p == NULL)
        {
            puts("Kein Speicher vorhanden");
        }
        else
        {

                fflush(stdin);
                puts("Vorname: ");
                gets(p->vorname);
                puts("Nachname: ");
                gets(p->nachname);
                puts("Alter: ");
                scanf("%d", &(p->alter));

                p->next = NULL;

                if(*start == NULL)
                {
                    *start = p;
                }
                else
                {
                    h = *start;

                    while(h->next != NULL)
                    {
                        h = h->next;
                    }
                    h->next = p;


                }
        }
        anz++;

    }while(anz != groesse);

    p = *start;

    puts(" ");
    puts(" ");

    do
    {
        textcolor(YELLOW);
        puts("Vorname: ");
        textcolor(LIGHTCYAN);
        puts(p->vorname);

        textcolor(YELLOW);
        puts("Nachname: ");
        textcolor(LIGHTCYAN);
        puts(p->nachname);

        textcolor(YELLOW);
        puts("Alter: ");
        textcolor(LIGHTCYAN);
        printf("%d", p->alter);

        puts(" ");
        puts(" ");


        p = p->next;
    }while(p != NULL);
}

void loeschen(int groesse, Person **start, int eliminate)
{
    Person *p, *h;



     if(eliminate > 2)  //wenn das zu löschende Element einer der ersten 2 ist, funktionieren die Schleifen nicht mehr
     {
        p = *start;
        h = *start;
        for(int i = 0; i < eliminate-1; i++)
        {
            p = p->next;
        }

        for(int i = 0; i < eliminate-2; i++)
        {
            h = h->next;
        }

        h->next = p->next;
        free(p);
        p = NULL;

     }
     else if (eliminate == 2)
     {
        h = *start;
        p = h->next;

        h->next = p->next;
        free(p);
        p = NULL;
     }
     else if (eliminate == 1)
     {
         p = *start;

         *start = p->next;
         free(p);
         p = NULL;
     }








    puts(" ");
    puts(" ");
    p = *start;

    do
    {
        if(p != NULL)
        {
        textcolor(YELLOW);
        puts("Vorname: ");
        textcolor(LIGHTCYAN);
        puts(p->vorname);

        textcolor(YELLOW);
        puts("Nachname: ");
        textcolor(LIGHTCYAN);
        puts(p->nachname);

        textcolor(YELLOW);
        puts("Alter: ");
        textcolor(LIGHTCYAN);
        printf("%d", p->alter);

        puts(" ");
        puts(" ");


        p = p->next;
        }
        else
        {
            textcolor(LIGHTGREEN);
            puts("Liste ist leer!");
        }
    }while(p != NULL);
}


int main()
{

    console_init();

    int auswahl = 0;
    int anz = 0;
    bool list_exist = false;


    Person *start = NULL;

    do
    {
        clrscr();

        textcolor(LIGHTGRAY);
        puts("--------------------------");
        textcolor(LIGHTMAGENTA);
        printf("   1");
        textcolor(LIGHTGRAY);
        printf(" - ");
        textcolor(YELLOW);
        puts("Liste erstellen");
        textcolor(LIGHTMAGENTA);
        printf("\n   2");
        textcolor(LIGHTGRAY);
        printf(" - ");
        textcolor(YELLOW);
        puts("Element löschen");
        textcolor(LIGHTGRAY);
        puts("--------------------------");
        puts(" ");
        puts("Auswahl: ");
        textcolor(LIGHTCYAN);
        scanf("%d", &auswahl);

    }while(!(auswahl > 0 && auswahl < 3));

    if(auswahl == 1)
    {
        textcolor(YELLOW);
        puts("Größe der Liste: ");
        textcolor(LIGHTCYAN);
        scanf("%d", &anz);
        textcolor(WHITE);

        anlegen(anz, &start);
        list_exist = true;
        goto loeschen;
    }
    else
    {
        loeschen:

        if(list_exist)
        {
                do
                {

                    textcolor(YELLOW);
                    printf("welches Element soll gelöscht werden?");
                    textcolor(DARKGRAY);
                    printf(" [");
                    textcolor(LIGHTGRAY);
                    printf("1");
                    textcolor(DARKGRAY);
                    printf(" - ");
                    textcolor(LIGHTGRAY);
                    printf("%d", anz);
                    textcolor(DARKGRAY);
                    printf("] \n");
                    textcolor(LIGHTCYAN);
                    scanf("%d", &auswahl);



                }while(!(auswahl > 0 && auswahl < anz+1));
                loeschen(anz, &start, auswahl);

                textcolor(LIGHTGREEN);
                printf("Element <");
                textcolor(LIGHTMAGENTA);
                printf("%d", auswahl);
                textcolor(LIGHTGREEN);
                printf("> wurde gelöscht!");
        }
        else
        {
            textcolor(LIGHTRED);
            puts("Es existiert noch keine Liste!");
        }
    }



    return 0;
}
