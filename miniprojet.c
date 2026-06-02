
#include <stdio.h>
#include <conio.h>//pour utiliser la fonction getch()
#include <stdlib.h>//pour rand(), system(), exit()
#include <string.h>//pour strcpy(), strcat(), strlen()
#include <time.h>//pour time() utilisé dans srand()
#include <windows.h>//pour manipuler la console (changer taille police)
#define taille 100//longueur maximale des chaînes (questions, noms, réponses)
//structure pour une question
typedef struct
{
   char Q[taille];       //la question
   char RA[taille];      //choix A
   char RB[taille];      //choix B
   char RC[taille];      //choix C
   char RD[taille];      //choix D
   char BR;              //la bonne répense
}qst;
//tableaux pour stocker les questions
qst pre_question[taille];// questions des "tryouts"
qst question[taille];//questions du "main quiz"
//structure pour stocker :
typedef struct
{
    char full_name[taille];//le nom complet du joueur
    int score;//le score du joueur
}h_s;
h_s high_score[taille];//tableau pour enregistrer le nom du joueur et son score
char rep;//variable utilisée pour la bonne répense
char nom[taille];//le nom du joueur
char prenom[taille];//le prenom du joueur
int nbr_joueur =0,indice_jou=0;//nombre de joueurs et indice du joueur actuel
//Les modules utilisées
void background();
void help();
void pre_questions();
void questions();
void quit();
int tryouts();
int game();
void nom_player();
void nom_complet(int i);
int start();
void reset_record();
void show_record();
//affichage du l’interface principale
void background()
{
    system("cls");//efface l’écran
    system("color E0");//couleur de la console
    printf("\t\t\t\t\t QUIZ CRAFTED IN C\n");
    printf("\t\t\t**************************************************\n"
           "\t\t\t\t\tWELCOME TO THE GAME \n"
           "\t\t\t**************************************************\n ");
    printf("\t\t\t\t\t C THE KNOWLEDGE \n"
           "\t\t\t**************************************************\n");
    printf("\t\t\t >PRESS S TO START THE GAME \n"
           "\t\t\t >PRESS V TO VIEW THE HIGHEST SCORE \n"
           "\t\t\t >PRESS R TO RESET SCORE \n"
           "\t\t\t >PRESS H FOR HELP \n"
           "\t\t\t >PRESS Q TO QUIT \n"
           "\t\t\t**************************************************\n"
           "your choice : ");
}
//page d’aide
void help()
{
    system("cls");
    printf("\t     C THE KNOWLEDGE !!\n");
    printf(" It's a quiz game where you test your knowledge and your IQ in multiple questions while \n"
           " WINNING MONEY!! \n"
           " So this game is a two part game :\n"
           "   --- THE TRYOUTS --- \n"
           " In this part you will be asked two questions like a test and you need to \n"
           " answer both of them correctly to advance to the next part of the game \n"
           " otherwise you can't progress and the game ends .\n "
           "   --- THE MAIN QUIZ ---\n"
           " In this part you will be given multiple choice questions and for every right answer \n"
           " you will receive $100k you have 15 questions to the reach your goal \n"
           "  THE MILLION DOLLARS PRIZE\n"
           " so what are you waiting for press s to start \n"
           "\n\n PS : you have to answer within the limited choices(which are A B C and D) of each \n"
           "      question or the answer will be considered wrong \n\n "
           " press any key to return to the main page");
    getch();
}
//**la base des donées questions**
//questions des tryouts
void pre_questions()
{
   strcpy(pre_question[0].Q,"What is the smallest country in the world ?");
   strcpy(pre_question[0].RA,"Vatican city");
   strcpy(pre_question[0].RB,"San Marino");
   strcpy(pre_question[0].RC,"Tunisia");
   strcpy(pre_question[0].RD,"Taiwan");
   pre_question[0].BR='A';

   strcpy(pre_question[1].Q,"what animal is known as 'the king of the jungle' ?");
   strcpy(pre_question[1].RA,"Tiger");
   strcpy(pre_question[1].RB,"Elefant");
   strcpy(pre_question[1].RC,"Lion");
   strcpy(pre_question[1].RD,"Eagle");
   pre_question[1].BR='C';

   strcpy(pre_question[2].Q,"What is the fastest land animal?");
   strcpy(pre_question[2].RA,"Cheetah");
   strcpy(pre_question[2].RB,"Lion");
   strcpy(pre_question[2].RC,"Horse");
   strcpy(pre_question[2].RD,"Leopard");
   pre_question[2].BR='A';

   strcpy(pre_question[3].Q,"What do bees produce?");
   strcpy(pre_question[3].RA,"Milk");
   strcpy(pre_question[3].RB,"Honey");
   strcpy(pre_question[3].RC,"Oil");
   strcpy(pre_question[3].RD,"Sugar");
   pre_question[3].BR='B';

   strcpy(pre_question[4].Q,"Which country invented pizza?");
   strcpy(pre_question[4].RA,"France");
   strcpy(pre_question[4].RB,"USA");
   strcpy(pre_question[4].RC,"Italy");
   strcpy(pre_question[4].RD,"Spain");
   pre_question[4].BR='C';

   strcpy(pre_question[5].Q,"Which ocean is the smallest?");
   strcpy(pre_question[5].RA,"Indian Ocean");
   strcpy(pre_question[5].RB,"Pacific Ocean");
   strcpy(pre_question[5].RC,"Arctic Ocean");
   strcpy(pre_question[5].RD,"Atlantic Ocean");
   pre_question[5].BR='C';

   strcpy(pre_question[6].Q,"What is the tallest mountain in the world?");
   strcpy(pre_question[6].RA,"K2");
   strcpy(pre_question[6].RB,"Mount Everest");
   strcpy(pre_question[6].RC,"Kilimanjaro");
   strcpy(pre_question[6].RD,"Mont Blanc");
   pre_question[6].BR='B';
   strcpy(pre_question[7].Q,"Which continent is Egypt located in?");
   strcpy(pre_question[7].RA,"Asia");
   strcpy(pre_question[7].RB,"Africa");
   strcpy(pre_question[7].RC,"Europe");
   strcpy(pre_question[7].RD,"South America");
   pre_question[7].BR='B';

   strcpy(pre_question[8].Q,"What is the hardest natural substance on Earth?");
   strcpy(pre_question[8].RA,"Gold");
   strcpy(pre_question[8].RB,"Iron");
   strcpy(pre_question[8].RC,"Diamond");
   strcpy(pre_question[8].RD,"Silver");
   pre_question[8].BR='C';

   strcpy(pre_question[9].Q,"Which scientist proposed the three laws of motion?");
   strcpy(pre_question[9].RA,"Albert Einstein");
   strcpy(pre_question[9].RB,"Isaac Newton");
   strcpy(pre_question[9].RC,"Nikola Tesla");
   strcpy(pre_question[9].RD,"Galileo Galilei");
   pre_question[9].BR='B';
}
//questions principales
void questions()
{
   strcpy(question[0].Q,"What does CPU stands for ?");
   strcpy(question[0].RA,"Central process unit");
   strcpy(question[0].RB,"Computer personal unit");
   strcpy(question[0].RC,"Central program unit");
   strcpy(question[0].RD,"Central processing unit");
   question[0].BR='D';

   strcpy(question[1].Q,"In which sport do we use a racket ?");
   strcpy(question[1].RA,"Football");
   strcpy(question[1].RB ,"Swimming");
   strcpy(question[1].RC,"Tennis");
   strcpy(question[1].RD,"Boxing");
   question[1].BR='C';


   strcpy(question[2].Q,"Which country is famous for the Eiffel Tower ?");
   strcpy(question[2].RA,"Italy");
   strcpy(question[2].RB,"France");
   strcpy(question[2].RC,"Spain");
   strcpy(question[2].RD,"Germany");
   question[2].BR='B';

   strcpy(question[3].Q,"What is the freezing point of water in °C ?");
   strcpy(question[3].RA,"0°C");
   strcpy(question[3].RB,"-10°C");
   strcpy(question[3].RC,"100°C");
   strcpy(question[3].RD,"37°C");
   question[3].BR='A';

   strcpy(question[4].Q,"When did the WW1 end ?");
   strcpy(question[4].RA,"1939");
   strcpy(question[4].RB,"1945");
   strcpy(question[4].RC,"1918");
   strcpy(question[4].RD,"1916");
   question[4].BR='C';

   strcpy(question[5].Q,"Who is known as 'the father of computers' ?");
   strcpy(question[5].RA,"Alan Turing");
   strcpy(question[5].RB,"Bill Gates");
   strcpy(question[5].RC,"Steve Jobs");
   strcpy(question[5].RD,"Charles Babbage");
   question[5].BR='D';

   strcpy(question[6].Q,"Which club won the UEFA Champions League in 2022 ?");
   strcpy(question[6].RA,"Manchester City");
   strcpy(question[6].RB,"Real Madrid");
   strcpy(question[6].RC,"Liverpool");
   strcpy(question[6].RD,"Chelsea");
   question[6].BR='B';

   strcpy(question[7].Q,"What is the largest island in the world (not a continent) ?");
   strcpy(question[7].RA,"Greenland");
   strcpy(question[7].RB,"Madagascar");
   strcpy(question[7].RC,"Borneo");
   strcpy(question[7].RD,"Iceland");
   question[7].BR='A';

   strcpy(question[8].Q,"What gas do the planets absorb during photosynthesis ?");
   strcpy(question[8].RA,"Carbon Dioxide");
   strcpy(question[8].RB,"Oxygen");
   strcpy(question[8].RC,"Nitrogen");
   strcpy(question[8].RD,"Methane");
   question[8].BR='A';

   strcpy(question[9].Q,"Who was the first women to win the Nobel prize ?");
   strcpy(question[9].RA,"Marie Cury");
   strcpy(question[9].RB,"Ada Lovelace");
   strcpy(question[9].RC,"Shakira");
   strcpy(question[9].RD,"Jane Goodall");
   question[9].BR='A';

   strcpy(question[10].Q,"Who invented C language ?");
   strcpy(question[10].RA,"James Gosling");
   strcpy(question[10].RB,"Dennis Ritchie");
   strcpy(question[10].RC,"Bill Gates");
   strcpy(question[10].RD,"Ken Thompson");
   question[10].BR='B';

   strcpy(question[11].Q,"Which athlete still holds (in 2025) the men’s 100 meters world record ?");
   strcpy(question[11].RA,"Carl Lewis");
   strcpy(question[11].RB,"Usain Bolt");
   strcpy(question[11].RC,"Justin Gatlin");
   strcpy(question[11].RD,"Yohan Blake");
   question[11].BR='B';

   strcpy(question[12].Q,"Which city is located on two continents — Europe and Asia ?");
   strcpy(question[12].RA,"Moscow");
   strcpy(question[12].RB,"Istanbul");
   strcpy(question[12].RC,"Cairo");
   strcpy(question[12].RD,"Athens");
   question[12].BR='B';

   strcpy(question[13].Q,"How many planets are in our solar system ?");
   strcpy(question[13].RA,"7");
   strcpy(question[13].RB,"8");
   strcpy(question[13].RC,"15");
   strcpy(question[13].RD,"4");
   question[13].BR='B';

   strcpy(question[14].Q,"In which periode did the dinosaures extinct ?");
   strcpy(question[14].RA,"Ice Age");
   strcpy(question[14].RB,"Trianic");
   strcpy(question[14].RC,"Cretaceous");
   strcpy(question[14].RD,"Stone Age");
   question[14].BR='C';

   strcpy(question[15].Q,"Which planet is known as the Red Planet?");
   strcpy(question[15].RA,"Earth");
   strcpy(question[15].RB,"Mars");
   strcpy(question[15].RC,"Jupiter");
   strcpy(question[15].RD,"Venus");
   question[15].BR='B';

   strcpy(question[16].Q,"How many continents are there?");
   strcpy(question[16].RA,"5");
   strcpy(question[16].RB,"6");
   strcpy(question[16].RC,"7");
   strcpy(question[16].RD,"8");
   question[16].BR='C';

   strcpy(question[17].Q,"Who wrote 'Romeo and Juliet'?");
   strcpy(question[17].RA,"Mark Twain");
   strcpy(question[17].RB,"William Shakespeare");
   strcpy(question[17].RC,"Charles Dickens");
   strcpy(question[17].RD,"Homer");
   question[17].BR='B';

   strcpy(question[18].Q,"What is the chemical symbol for water?");
   strcpy(question[18].RA,"CO2");
   strcpy(question[18].RB,"O2");
   strcpy(question[18].RC,"H2O");
   strcpy(question[18].RD,"HO2");
   question[18].BR='C';

   strcpy(question[19].Q,"Which country has the Eiffel Tower?");
   strcpy(question[19].RA,"Italy");
   strcpy(question[19].RB,"France");
   strcpy(question[19].RC,"Germany");
   strcpy(question[19].RD,"Spain");
   question[19].BR='B';

   strcpy(question[20].Q,"How many degrees are in a right angle?");
   strcpy(question[20].RA,"45");
   strcpy(question[20].RB,"60");
   strcpy(question[20].RC,"90");
   strcpy(question[20].RD,"180");
   question[20].BR='C';

   strcpy(question[21].Q,"Which gas do plants absorb?");
   strcpy(question[21].RA,"Oxygen");
   strcpy(question[21].RB,"Carbon dioxide");
   strcpy(question[21].RC,"Nitrogen");
   strcpy(question[21].RD,"Helium");
   question[21].BR='B';

   strcpy(question[22].Q,"What is the largest ocean on Earth?");
   strcpy(question[22].RA,"Atlantic Ocean");
   strcpy(question[22].RB,"Pacific Ocean");
   strcpy(question[22].RC,"Indian Ocean");
   strcpy(question[22].RD,"Arctic Ocean");
   question[22].BR='B';

   strcpy(question[23].Q,"Which instrument has 6 strings?");
   strcpy(question[23].RA,"Piano");
   strcpy(question[23].RB,"Guitar");
   strcpy(question[23].RC,"Violin");
   strcpy(question[23].RD,"Flute");
   question[23].BR='B';

   strcpy(question[24].Q,"How many days are there in a leap year?");
   strcpy(question[24].RA,"364");
   strcpy(question[24].RB,"365");
   strcpy(question[24].RC,"366");
   strcpy(question[24].RD,"367");
   question[24].BR='C';

   strcpy(question[25].Q,"What is the capital of Japan?");
   strcpy(question[25].RA,"Kyoto");
   strcpy(question[25].RB,"Osaka");
   strcpy(question[25].RC,"Tokyo");
   strcpy(question[25].RD,"Nagasaki");
   question[25].BR='C';

   strcpy(question[26].Q,"What is the largest animal on Earth?");
   strcpy(question[26].RA,"Elephant");
   strcpy(question[26].RB,"Blue whale");
   strcpy(question[26].RC,"Giraffe");
   strcpy(question[26].RD,"Shark");
   question[26].BR='B';

   strcpy(question[27].Q,"Which element has the symbol 'Fe'?");
   strcpy(question[27].RA,"Fluorine");
   strcpy(question[27].RB,"Iron");
   strcpy(question[27].RC,"Zinc");
   strcpy(question[27].RD,"Silver");
   question[27].BR='B';

   strcpy(question[28].Q,"Who painted the Mona Lisa?");
   strcpy(question[28].RA,"Pablo Picasso");
   strcpy(question[28].RB,"Leonardo da Vinci");
   strcpy(question[28].RC,"Vincent van Gogh");
   strcpy(question[28].RD,"Michelangelo");
   question[28].BR='B';

   strcpy(question[29].Q,"What is the boiling point of water?");
   strcpy(question[29].RA,"50°C");
   strcpy(question[29].RB,"90°C");
   strcpy(question[29].RC,"100°C");
   strcpy(question[29].RD,"120°C");
   question[29].BR='C';

   strcpy(question[30].Q,"What is the longest river in the world?");
   strcpy(question[30].RA,"Amazon River");
   strcpy(question[30].RB,"Nile River");
   strcpy(question[30].RC,"Yangtze River");
   strcpy(question[30].RD,"Mississippi River");
   question[30].BR='A';

   strcpy(question[31].Q,"Which metal is liquid at room temperature?");
   strcpy(question[31].RA,"Mercury");
   strcpy(question[31].RB,"Iron");
   strcpy(question[31].RC,"Gold");
   strcpy(question[31].RD,"Aluminum");
   question[31].BR='A';

   strcpy(question[32].Q,"Which organ pumps blood in the human body?");
   strcpy(question[32].RA,"Liver");
   strcpy(question[32].RB,"Heart");
   strcpy(question[32].RC,"Kidneys");
   strcpy(question[32].RD,"Lungs");
   question[32].BR='B';

   strcpy(question[33].Q,"What is H in the periodic table?");
   strcpy(question[33].RA,"Helium");
   strcpy(question[33].RB,"Hydrogen");
   strcpy(question[33].RC,"Hassium");
   strcpy(question[33].RD,"Holmium");
   question[33].BR='B';

   strcpy(question[34].Q,"Which continent is the largest?");
   strcpy(question[34].RA,"Africa");
   strcpy(question[34].RB,"Asia");
   strcpy(question[34].RC,"Europe");
   strcpy(question[34].RD,"North America");
   question[34].BR='B';

   strcpy(question[35].Q,"Which language has the most native speakers?");
   strcpy(question[35].RA,"English");
   strcpy(question[35].RB,"Spanish");
   strcpy(question[35].RC,"Mandarin Chinese");
   strcpy(question[35].RD,"Hindi");
   question[35].BR='C';

   strcpy(question[36].Q,"What is the chemical formula of table salt?");
   strcpy(question[36].RA,"NaCl");
   strcpy(question[36].RB,"KCl");
   strcpy(question[36].RC,"Na2SO4");
   strcpy(question[36].RD,"CaCl2");
   question[36].BR='A';

   strcpy(question[37].Q,"Who developed the theory of relativity?");
   strcpy(question[37].RA,"Isaac Newton");
   strcpy(question[37].RB,"Albert Einstein");
   strcpy(question[37].RC,"Stephen Hawking");
   strcpy(question[37].RD,"Niels Bohr");
   question[37].BR='B';

   strcpy(question[38].Q,"Which gas is most abundant in the Earth's atmosphere?");
   strcpy(question[38].RA,"Oxygen");
   strcpy(question[38].RB,"Nitrogen");
   strcpy(question[38].RC,"Carbon dioxide");
   strcpy(question[38].RD,"Hydrogen");
   question[38].BR='B';

   strcpy(question[39].Q,"Which organ in the human body produces insulin?");
   strcpy(question[39].RA,"Liver");
   strcpy(question[39].RB,"Pancreas");
   strcpy(question[39].RC,"Kidney");
   strcpy(question[39].RD,"Heart");
   question[39].BR='B';
}
//quitter le jeu
void quit ()
{
  system("cls");
    printf("the game has been ended by you :) \n");
    system("exit");//ferme la console
}
//partie "tryouts" : le joueur doit répondre correctement à 2 questions pour passer
int tryouts ()
{
    system("cls");
    time_t t;
    srand((unsigned) time(&t));//initialisation de rand()
    int indice_Q,indice_T=0,temp,k,question_pose=0,bonne_repense=0;
    int tab_num_quest[10];//les indices des questions de sens croissant (1,2,3,....)
    for (int i=0; i<10;i++){//remplir le tableau
      tab_num_quest[i]=i;}
    //mélanger les indices pour choisir des questions aléatoires (5,7,29,...)
    for (int i=9;i>0;i--){
      k= rand() % (i + 1);
      temp = tab_num_quest[i];
      tab_num_quest[i] = tab_num_quest[k];
      tab_num_quest[k] = temp;}
    printf("\t\t\tWELCOME TO THE TRYOUTS\n");
    do
    {
        indice_Q=tab_num_quest[indice_T];//indice_T est l'indice du tableau et indice_Q est l'indice de la question
        printf("Question %d : %s \n",question_pose+1,pre_question[indice_Q].Q);
        printf("A) %s   \tB) %s   \nC) %s   \tD) %s\n",pre_question[indice_Q].RA,pre_question[indice_Q].RB,pre_question[indice_Q].RC,pre_question[indice_Q].RD);
        printf("YOUR ANSWER : ");
        scanf("%s",&rep);//lire un caractère
        rep=toupper(rep);
        if (rep == pre_question[indice_Q].BR)
          {
              printf("CORRECT :)\n ");
              bonne_repense++;//compteur des bonnes réponses
              }
        else
           printf("WRONG :( \n");
     question_pose++; //question_pose est un conteur des question posées
     indice_T++;
    }while (question_pose<2);
    return bonne_repense;
}
//partie principale du quiz
int game()
{
      system("cls");
      time_t t;
      srand((unsigned) time(&t));
      int indice_T=0,indice_Q,temp,k,question_pose=0,gain=0;//s=score
                            //les autres variables ont la méme utilisation que le module pre_start
      int tab_num_quest[40];
      for (int i=0; i<40;i++){
        tab_num_quest[i]=i;}
      for (int i=39;i>0;i--){
        k= rand() % (i + 1);
        temp = tab_num_quest[i];
        tab_num_quest[i] = tab_num_quest[k];
        tab_num_quest[k] = temp;}
      printf("\t\tGONGRATS ON PASSING THE TRYOUTS NOW TO THE REAL CHALLENGE\n");
      do
    {
        indice_Q=tab_num_quest[indice_T];

        printf("Question %d : %s \n",question_pose+1,question[indice_Q].Q);
        printf("A) %s   \tB) %s   \nC) %s   \tD) %s\n",question[indice_Q].RA,question[indice_Q].RB,question[indice_Q].RC,question[indice_Q].RD);
        printf("YOUR ANSWER : ");
        scanf("%s",&rep);
        rep=toupper(rep);
        if (rep == question[indice_Q].BR)
          {
              printf("CORRECT :)\n ");
              gain=gain+100;//chaque bonne réponse = 100k
          }
        else
           printf("WRONG :( \n");
       printf("your current score is %dk $\n",gain);
       indice_T++;
       question_pose++;
    }while (gain<1000 && question_pose<15);//max 15 questions ou score est 1000k
    //messages selon le score
    if (gain==1000)
    {
        system("cls");
        printf("\t\t\t**************************************************\n"
           "\t\t\t\tCONGRATS YOU ARE NOW A MILLIONNER\n"
           "\t\t\t**************************************************\n\n\n "
           " press any key to return to the main page");}
    else if (gain==0)
           {system("cls");
          printf("\t\t\t**************************************************\n"
           "\t\t\t   WELL MAYBE NAXT TIME YOU WILL WIN SOME MONEY\n"
           "\t\t\t**************************************************\n\n\n "
           " press any key to return to the main page");}
    else
        {system("cls");
         printf("\t\t\t**************************************************\n"
           "\t\t\t\tCONGRATS YOU WON %dK DOLLARS\n"
           "\t\t\t**************************************************\n\n\n ",gain);
           printf(" press any key to return to the main page");}
    return gain;//retourne le score final
}
//saisie du nom et prénom
void nom_player()
{
    do{
    printf("Enter your first name please :) \n(Your first name must consist only of the alphabet, without spaces) :\t");
    scanf("%s",nom);
    }while (strlen(nom)>taille);
    do{
    printf("Enter your last name please :) \n(Your last name must consist only of the alphabet, without spaces) :\t");
    scanf("%s",prenom);
    }while (strlen(prenom)>taille);
}
//concatène nom et prénom pour nom compléte du joueur
void nom_complet(int i)
{
    strcpy(high_score[i].full_name, nom);
    strcat(high_score[i].full_name, " ");
    strcat(high_score[i].full_name, prenom);
}
//lancer le jeu
int start()
{
    nom_player();
    int rec=tryouts();
    if (rec==2)//si réussi
        {
        printf("\n\nYOU PASSED THE TRYOUTS :)\n"
               "press any key to continue");
        getch();
        high_score[indice_jou].score=game();//enregistrement du score du joueur actuel
        nom_complet(indice_jou);//enregistrement du nom du joueur actuel
        indice_jou++;// pour préparé une caisse du joueur suivant
        nbr_joueur++;
        getch();
        return high_score[indice_jou].score;}//retourner le score du joueur actuel
    else
       {printf(" YOU FAILED THE TRYOUTS :( \n"
               " THANKS FOR PLAYING MAYBE NEXT TIME  \n\n"
               "press any key to return to the main page");
               getch();
               return 0;}//joueur échoué
}
//réinitialiser les scores
void reset_record()
{
    system("cls");
    for (int i=0;i<nbr_joueur;i++)
    {
        high_score[i].score=0;//tous les scores à 0
    }
    printf("\t\t\t*******************************************\n"
           "\t\t\t       The record has been reseted\n"
           "\t\t\t*******************************************\n\n\n "
           "press any key to return to the main page");
    getch();
}
//afficher le joueur avec le score le plus élevé
void show_record()
{
    system("cls");
    int h_sc=0;//variable pour le plus grand score marqué
    char f_nm[taille];//variable pour le nom du joueur qui à marqué le plus grand score
    for (int i=0 ; i<nbr_joueur;i++)
    {
        if (high_score[i].score>=h_sc){
            h_sc=high_score[i].score;
            strcpy(f_nm,high_score[i].full_name);}
    }
    if (h_sc==1000)
        {printf("\t\t\t****************************************************\n");
        printf("\t\t\t   %s has won the MILLION DOLLARS\n",f_nm);
        printf("\t\t\t****************************************************\n ");}
    else if (h_sc>0)
        {printf("\t\t\t******************************************************\n");
        printf("\t\t\t   %s has won the Highest score %dk\n",f_nm,h_sc);
        printf("\t\t\t******************************************************\n ");}
    else
        {printf("\t\t\t*******************************************\n"
        "\t\t\t\t     The record is empty\n"
        "\t\t\t*******************************************\n\n\n ");}
    printf(" press any key to return to the main page");
    getch();
}
void main()
{
     questions();//initialise les questions du jeu principale
     pre_questions();//initialise les questions du tryouts
     char ch;//choix du joueur
     do{
     background();//affiche menu
     scanf("%s",&ch);
     ch=toupper(ch);//cette fonction permet d’accepter la saisie de l’utilisateur en majuscules ou en minuscules
     switch(ch)
     {
     case 'H' : help(); break;//page d’aide
     case 'S' : start(); break;//lancer le jeu
     case 'Q' : quit(); break;//quitter le jeu
     case 'V' : show_record(); break;//afficher le joueur avec le score le plus élevé
     case 'R' : reset_record();break;//réinitialiser les scores
     }
     }while (ch!='Q'); //répéter tant que le joueur ne quitte pas et son choix est invalable
}
