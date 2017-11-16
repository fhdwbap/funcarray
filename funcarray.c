/* funcarray.c
   Kurzdemonstration einer parametrisierbaren Menu-Fuehrung.
   Verwendet: Array von Funktionen.

   http://www.github.com/fhdwbap/funcarray 
   BAP 2017-11-16  
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define PROGTITLE "FuncArray"
#define VERSION   "0.0.2"
#define PROGDATE  "2017"
#define AUTHOR    "FHDW Developer's Group"

//-----------------------------------------------------------------
struct proginfo // Alle relevanten Programminformationen fuer die 
                // aufzurufenden Funktionen etc.
{
   int status;  // hier nur exemplarisch
   // ...
};


//-----------------------------------------------------------------
// All die schoenen Prototypen...
void doIt();     // Action...
void function1(struct proginfo *);  // die inhaltlichen Funktionen
void function2(struct proginfo *);
void showSelection();   // Auswahl-Menu anzeigen


//-----------------------------------------------------------------
int main()
{
   /* Feierliche Begruessung des Anwenders */
   printf("%s %s (c) %s %s\n\n",PROGTITLE,VERSION,PROGDATE,AUTHOR);
   
   /* Hier geschieht es... */
   doIt();

   /* Abschied nehmen */ 
   return EXIT_SUCCESS;
}
//-----------------------------------------------------------------
// Hier wird das exemplarische Auswahlmenu implementiert
void doIt()
{
   int ende = -99;
   int auswahl = -1;

   struct proginfo proginfo;
   proginfo.status = 0;    

   // Array von hier exemplarisch zwei Funktionen
   // Alle Funktionen muessen uniformen Aufbau haben, also gleiche
   // Parameterlisten und Rueckgabetypen
   // (Ueber sog. variable Parameterlisten koennte dies ebenfalls
   // noch verallgemeinert werden. Hier wurde stattdessen mit einer
   // Struktur proginfo gearbeitet, die die jeweils relevanten 
   // Informationen beeinhalten koennte.)
   void (*funcs[2])(struct proginfo *) = { function1, function2 };

   do
   {
      showSelection();
      scanf("%d",&auswahl);
      ende = auswahl==0;
      switch(auswahl)
      {
         case 1:
         case 2:
            funcs[auswahl-1](&proginfo);
            break;
         case 0:
            return;  
         default: 
            // Exemplarisch wird der proginfo.status auf die auswahl gesetzt
            proginfo.status = auswahl; // quasi zur Dokumentation...
            printf("Die Auswahl \"%d\" liegt bedauerlicherweise heute"
                   " noch nicht fuer Sie implementiert vor.\n",auswahl);
      }
   } while (!ende);
}
//-----------------------------------------------------------------
void function1(struct proginfo * pproginfo)
{
   printf("Hier meldet sich function1()!\n");
   printf("   Bisheriger Status: %d\n",pproginfo->status);
   pproginfo->status = 1;
}
//-----------------------------------------------------------------
void function2(struct proginfo * pproginfo)
{
   printf("Hier meldet sich function2()!\n");
   printf("   Bisheriger Status: %d\n",pproginfo->status);
   pproginfo->status = 2;
}
//-----------------------------------------------------------------
void showSelection()
{
   printf(
      "Bitte Ihre Auswahl treffen: \n"
      "    1 = funktion1() \n"
      "    2 = funktion2() \n"
      "    0 = Programm beenden \n"    
         );

}
//-----------------------------------------------------------------
