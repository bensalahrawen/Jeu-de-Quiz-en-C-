#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
#include <ctype.h>


// Déclaration des variables globales

char choix;
char reponse;
int nrep=0;
int pass;
int mscore = 0;
int i = 0;
int q, t;
int rep;
char qt[100];
int num_theme, num_question;
int alea_questions_toutes[25] = {0};
int questions_restantes = 25;
int alea_theme [5];
int alea_q[5];
// Structure pour les questions
typedef struct {
    char qt[300];
    char bonne_rep;
} questions;

// Déclaration des thèmes
questions themesante[5];
questions themetechnologie[5];
questions themehistoire[5];
questions themesport[5];
questions themelecture[5];

// Prototypes des fonctions
char welcome();
int echauffement();
void verreponse();
void initialise_themesante();
void initialise_themetechnologie();
void initialise_themehistoire();
void initialise_themesport();
void initialise_themelecture();
int random_theme();
int random_question();
int question(char qt[], char bonne_rep);
void level();
int quiz();
void help();
void quit();
int random_unique_index();

// la fonction du menu principale : le bienvenue et demande à l'utilisateur de choisir une option
char welcome ()
{
    printf("--- Modification apportee par le binome ---\n");
    printf("                                     THIS IS YOUR CHANCE TO BECOME A MILLIONAIRE !!\n");
    printf("                                           *****************************\n");
    printf("                                                      WELCOME           \n");
    printf("                                                   to the game !       \n");
    printf("                                                ****************      \n");
    printf("                                           *****************************\n");
    printf("                                                      PRESS :            \n");
    printf("                                             |* S to start the game|  \n");
    printf("                                        |* U to view the highest score|\n");
    printf("                                                 |* H for help|         \n");
    printf("                                                 |* Q to quit |        \n");
    printf("\n");
    scanf("%c",&choix);
    choix=toupper(choix);
    while (choix!='S'&& choix!='U'&& choix!='H'&& choix!='Q' )
    {
    printf("choix invalide voulez vous choisir de nouveau?\n");
    scanf("%c",&choix);
    }
system("cls");
return toupper(choix);
}

int echauffement()
{
    printf("                                       ***TOUR D'ECHAUFFEMENT***                                                       \n");
    printf("ATTENTION: VOUS DEVEZ REPONDRE CORRECTEMENT A AU MOINS DEUX PARMI CES TROIS QUESTIONS POUR ACCEDER AU TOUR SUIVANT !\n");
    printf("..................................................................................................................");
    printf("                                  \\\\\\\\la premiere question////////                                               \n");
    printf("                                                                                                                   \n");
    //question1
    printf("->              Quel est l'organe principal responsable de la respiration chez l'etre humain ?\n");
    printf("                       A) Le coeur B) Le fois C) Les poumons D) Le cerveau\n");
    printf("votre reponse:\n");
    scanf(" %c",&reponse);
    verreponse();
    if (toupper(reponse)=='C')
        nrep++;
    //question2
    printf("..................................................................................................................");
    printf("                                   \\\\\\\\la deuxième question////////                                               \n");
    printf("                                                                                                                    \n");
    printf("->                          Quelle planète est la plus proche du Soleil ?\n");
    printf("                              A) Vénus B) Terre C) Mercure D) Mars\n");
    printf("votre reponse:\n");
    scanf(" %c",&reponse);
    verreponse();
    if (toupper(reponse)=='C')
        nrep++;
    //question3
    printf("..................................................................................................................");
    printf("                                  \\\\\\\\la troisième question////////                                               \n");
    printf("                                                                                                                   \n");
    printf("                              -> Quelle est la capitale du Canada ?\n");
    printf("                          A) Toronto B) Ottawa C) Vancouver D) Montréal\n");
    printf("votre reponse:\n");
    scanf(" %c",&reponse);
    verreponse();
    if (toupper(reponse)=='B')
        nrep++;
        if (nrep>=2)
            pass=1;
        else
        pass=0;
system("cls");
return pass;
}

// VERIFIER DE CHOIX DE REPONSE
void verreponse()
{
    while (toupper(reponse)!='A' && toupper(reponse)!='B' && toupper(reponse)!='C' && toupper(reponse)!='D' )
    {
    printf("                reponse invalide pouvez vous choisir une parmi celles qui sont indiquees sous la question\n");
    scanf(" %c",&reponse);
    }
}


//LES THEMES

//THEME SANTE
void initialise_themesante()
{
    //Q1
    strcpy(themesante[0].qt,"Quel nutriment fournit principalement de l’énergie au corps ?\n A. Les protéines  B. Les glucides  C. Les vitamines  D. Les fibres \n");
    themesante[0].bonne_rep='B';
    //Q2
    strcpy(themesante[1].qt,"Quel minéral est essentiel pour la solidité des os ?\n A. Le sodium  B. Le calcium  C. Le fer  D. Le potassium \n");
    themesante[1].bonne_rep='B';
    //Q3
    strcpy(themesante[2].qt,"Quel organe produit l’insuline ?\n A. Le rein  B. Le pancréas  C. Le foie   D. La rate \n");
    themesante[2].bonne_rep='B';
    //Q4
    strcpy(themesante[3].qt,"Quel est le groupe sanguin donneur universel ?\n A. AB+  B. A−  C. O−  D. B+ \n");
    themesante[3].bonne_rep='C';
    //Q5
    strcpy(themesante[4].qt,"Quel type d’exercice améliore le plus le cœur ?\n A. Yoga  B.Course à pied  C. Haltérophilie  D. Étirements \n");
    themesante[4].bonne_rep='B';
}
//technologie
void initialise_themetechnologie ()
{
    //Q1 c
    strcpy(themetechnologie[0].qt,"Que signifie “hardware” ?\n  A. Les programmes d’un ordinateur  B. Les informations d’un réseau  C. Les composants physiques d’un ordinateur  D. Le stockage dans le cloud");
    themetechnologie[0].bonne_rep='C';
    //Q2 b
    strcpy(themetechnologie[1].qt,"Quel est l’objectif principal de la cybersécurité ?\n  A. Augmenter la vitesse des ordinateurs  B. Protéger les systèmes et données contre les attaques\n  C. Installer des jeux  D. Gérer des impressions");
    themetechnologie[1].bonne_rep='B';
    //Q3 b
    strcpy(themetechnologie[2].qt,"Qu’est-ce qu’un réseau informatique ?\n A. Une machine industrielle  B. Une connexion entre plusieurs appareils pour échanger des données\n    C. Un câble d’alimentation   D. Une application mobile \n");
    themetechnologie[2].bonne_rep='B';
    //Q4 b
    strcpy(themetechnologie[3].qt,"Quel est le rôle d’un système d’exploitation ?\n A. Exécuter uniquement les jeux vidéo  B. Gérer les ressources matérielles et les logiciels\n  C. Accélérer Internet  D. Contrôler les virus \n");
   themetechnologie[3].bonne_rep='B';
    //Q5 b
    strcpy(themetechnologie[4].qt,"Qu’est-ce qu’un pare-feu (firewall) ?\n A. Un logiciel pour nettoyer l’écran  B. Un outil de protection qui bloque les connexions non autorisées\n  C. Un câble réseau  D. Une application de montage vidéo \n");
    themetechnologie[4].bonne_rep='B';
}

//histoire
void initialise_themehistoire ()
{
    //Q1 a
    strcpy(themehistoire[0].qt,"Quel événement a déclenché la Première Guerre mondiale ?\n   A. L’assassinat de l’archiduc François-Ferdinand  B. La révolution russe\n  C. Le traité de Versailles  D. L’invasion de la Pologne\n");
    themehistoire[0].bonne_rep='A';
    //Q2 b
    strcpy(themehistoire[1].qt," En quelle année est tombé le mur de Berlin ?\n  A. 1987  B. 1989  C. 1991  D. 1993\n");
    themehistoire[1].bonne_rep='B';
    //Q3 b
    strcpy(themehistoire[2].qt,"Quelle est la première grande civilisation à avoir inventé l’écriture ?\n  A. Les Égyptiens  B. Les Sumériens  C. Les Chinois  D. Les Mayas\n");
     themehistoire[2].bonne_rep='B';
    //Q4 a
    strcpy(themehistoire[3].qt,"Qui a fondé Carthage ?\n A. Les Phéniciens  B. Les Romains  C. Les Vandales  D. Les Arabes\n");
     themehistoire[3].bonne_rep='A';
    //Q5 b
    strcpy(themehistoire[4].qt,"5. La Tunisie est devenue un protectorat français en quelle année ?\n A. 1871   B. 1881 C. 1891  D. 1901 \n");
     themehistoire[4].bonne_rep='B';
}


//SPORT
void initialise_themesport ()
{
    //Q1 c
    strcpy(themesport[0].qt,"Combien de joueurs y a-t-il dans une équipe de football sur le terrain ?\n A. 9  B. 10  C. 11  D. 12 \n");
   themesport[0].bonne_rep='C';
    //Q2 b
    strcpy(themesport[1].qt,"Combien de points vaut un essai au rugby ?\n A. 3  B. 5  C. 7  D. 1 \n");
    themesport[1].bonne_rep='B';
    //Q3 c
    strcpy(themesport[2].qt,"5. Quel athlète est connu comme le “roi du basketball” ?\n A. LeBron James  B. Kobe Bryant  C. Michael Jordan  D. Magic Johnson \n");
    themesport[2].bonne_rep='C';
    //Q4 c
    strcpy(themesport[3].qt,"Quel sport combine ski et tir à la carabine ?\n A. Pentathlon  B. Ski alpin  C. Biathlon  D. Ski nordique \n");
    themesport[3].bonne_rep='C';
    //Q5 a
    strcpy(themesport[4].qt,"Qui détient le record du monde du 100 mètres en athlétisme ?\n A. Usain Bolt  B. Carl Lewis  C. Justin Gatlin  D. Tyson Gay \n");
    themesport[4].bonne_rep='A';
}
//lecture
void initialise_themelecture ()
{
    //Q1 b
    strcpy(themelecture[0].qt,"Qui a écrit Les Misérables ?\n A. Émile Zola  B. Victor Hugo  C. Gustave Flaubert  D. Albert Camus \n");
    themelecture[0].bonne_rep='B';
    //Q2 c
    strcpy(themelecture[1].qt,"Quel genre littéraire raconte des aventures imaginaires ou impossibles ?\n A. Biographie  B. Roman historique  C. Fantastique / Science-fiction  D. Essai \n");
    themelecture[1].bonne_rep='C';
    //Q3 d
    strcpy(themelecture[2].qt,"Quel livre est considéré comme un classique de la littérature française du XVIIe siècle ?\n A. Madame Bovary  B. Les Fleurs du Mal C. Germinal  D. Le Cid \n");
    themelecture[2].bonne_rep='D';
    //Q4 c
    strcpy(themelecture[3].qt,"Que signifie “bibliophile” ?\n A. Auteur de livres  B. Libraire  C. Amateur et collectionneur de livres  D. Traducteur \n");
    themelecture[3].bonne_rep='C';
    //Q5 a
    strcpy(themelecture[4].qt,"Qui a réalisé le film Titanic ?\n A. James Cameron  B. Steven Spielberg  C. Martin Scorsese  D. Christopher Nolan \n");
    themelecture[4].bonne_rep='A';
}



int random_unique_index()
{
    int index_unique;

    if (questions_restantes == 0) {
        return -1;}
    while (1) {
        index_unique = rand() % 25;
    if (alea_questions_toutes[index_unique] == 0) {
          alea_questions_toutes[index_unique] = 1;
            questions_restantes--;
            return index_unique;}
    }
}
// Affiche une question et vérifie la réponse de l'utilisateur
int question(char qt[], char bonne_rep)
{
    puts(qt);


    scanf(" %c", &choix);
    while ((toupper(choix) != 'A') && (toupper(choix) != 'B') && (toupper(choix) != 'C') && (toupper(choix) != 'D')) {
        printf("La reponse est invalide . Essayez a nouveau !");
        scanf(" %c", &choix);
    }

// Vérifier si l'utilisateur a donné la bonne réponse
    if (toupper(choix) == bonne_rep) {
        rep = 1;

        printf("                    BRAVO! BONNE REPONSE \n");
        if (i == 4) {
        printf("\n                  BRAVO!! VOUS AVEZ GAGNE 200.000£ \n\n");
        system("pause");
        }
        if (i == 9) {
        printf("\n                  BRAVO!! VOUS AVEZ GAGNE 400.000£ \n\n");
        system("pause");
        }
        if (i == 14) {
        printf("\n                  BRAVO!! VOUS AVEZ GAGNE 600.000£ \n\n");
        system("pause");
        }
        if (i == 19) {
        printf("\n                  BRAVO!! VOUS AVEZ GAGNE 800.000£ \n\n");
        system("pause");
        }
        if (i == 24) {
        printf("\n                 Felicitations ! Vous etes desormais un veritable millionnaire \n\n");
        system("pause");
        }

    } else { // Réponse incorrecte
        printf("Le jeu touche à sa fin… Merci d’avoir joue . Que la chance soit avec vous la prochaine fois, champion !\n");
        quit();
        rep = 00;
    }
    return rep ;
}

// Fonction pour afficher les niveaux du quiz
void level()
{
    system("cls");
    if(i==0)
{

printf("                   ===================================================\n");
printf("                              BIENVENUE AU NIVEAU 1                  \n"); }

    if(i==5)
{


printf("                   ===================================================\n");
printf("                              BIENVENUE AU NIVEAU 2                  \n");   }

    if(i==10)
    {

printf("                   ===================================================\n");
printf("                              BIENVENUE AU NIVEAU 3                  \n");}

    if(i==15)
    {

printf("                   ===================================================\n");
printf("                              BIENVENUE AU NIVEAU 4                  \n");}

    if(i==20)
    {
printf("                   ===================================================\n");
printf("                              BIENVENUE AU NIVEAU 5                  \n");}

}



int quiz ()
{

    for(i=0; i<25; i++)
        {
        if(i % 5 == 0)
        {
            level();

        }


        int index_global = random_unique_index();

        if (index_global == -1)
        {
            break;
        }


        num_theme = index_global / 5;
        num_question = index_global % 5;



        if (num_theme == 0)
        {
            question(themesante[num_question].qt, themesante[num_question].bonne_rep);
        }
        else if (num_theme == 1)
        {
            question(themetechnologie[num_question].qt, themetechnologie[num_question].bonne_rep);
        }
        else if (num_theme == 2)
        {
            question(themehistoire[num_question].qt, themehistoire[num_question].bonne_rep);
        }
        else if (num_theme == 3)
        {
            question(themesport[num_question].qt, themesport[num_question].bonne_rep);
        }
        else if (num_theme == 4)
        {
            question(themelecture[num_question].qt, themelecture[num_question].bonne_rep);
        }


        if(rep == 00)
        {
            break;
        }
        }

    if(i == 25)
      printf("Felicitations ! Vous etes desormais un veritable millionnaire !");

    return i;
}




//HELP
void help()
{
printf("                                      *****************************\n");
printf("                                              ***REGLES***\n");
printf("                                      *****************************\n");
printf("                                       ***Il existe deux tours***\n");
printf("                       +++Vous devez passer le premier tour pour atteindre le second+++\n");
printf("                                                                                           \n");
printf("         //le premier tour formé de trois questions et vous devez repondre correctement à au moins 2\\\n");
printf("                                                                                           \n");
printf("                       +++ pour le 2 ème tour pour chaque réponse correcte vous gagnerez 100 000$+++\n");
printf("                                                                                           \n");
printf("              ***Le jeu se termine lorsque le prix en argent de joueur s'élève à 1 million de dollars***");
printf("                   ===================================================\n");

printf("                       > Appuyez sur S pour commencer le jeu            \n");
printf("                       > Appuyez sur Q pour quitter le jeu              \n");


printf("\n");
scanf(" %c",&choix);
while (!((toupper(choix)=='S')|| (toupper(choix)=='Q') ))
   {
    printf("la reponse est invalide ");
    scanf(" %c",&choix);
   }

        if (toupper(choix)=='Q')
            quit();
        else
        {
         if (echauffement())
            quiz();
         return;
        }
}

// Fonction pour quitter le jeu
void quit() {

   printf("Au revoir et merci....");
   exit(0);
}

int main() {
    // Initialisation
    srand(time(0));
    initialise_themesante();
    initialise_themetechnologie();
    initialise_themehistoire();
    initialise_themesport();
    initialise_themelecture();
    system("color ec");
        do {
        choix = toupper(welcome());
        switch (choix)
        { case 'S':
                if ( echauffement() !=0 )
                   { int x = quiz();
                    if (mscore < x) {
                        mscore = x;
                    }
                    printf("Votre meilleur score : %d\n", mscore);
                }
                else {
                    printf("Bonne chance la prochaine fois !\n");
                    exit(0);
                }
                break;
        case 'H':
                help();
                break;
        case 'Q':
                quit();
                break;
         case 'R':
                mscore = 0;
                printf("Le score est reinitialise\n");
                break;
        case 'U':
                printf("Le meilleur score est %d\n", mscore);
                break;

        default:
                printf("Choix invalide. Veuillez reessayer.\n");
                break;
        }
    } while (rep == 1);

    return 0;
}


