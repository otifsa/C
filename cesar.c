#include <stdio.h>
#include <string.h>

// la fonction decale pour decaler un caracetere par un nombre entier depuis le debut
char decale (char c ,char debut,int decalage ){
	char c1;
	while(decalage<0){decalage=+26;}
	c1=debut+((c-debut)+decalage)%26;
	return c1;
}
//*********************************************************************************************************

// la fonction code pour coder un caracetere par le codage de cesar
char code (char c,int decalage){ 
	 char c1;
	 if(c>='a' && c<='z')
	 	c1=decale(c,'a',decalage);
	 else if(c>='A' && c<='Z')
	 	c1=decale(c,'A',decalage);
	 else 
		c1=c;
	 return c1;
}
//*********************************************************************************************************

//la fonction decode pour decoder les caraceteres 

char decode(char c,int decalage)
{	return code(c,26-decalage);}
//*********************************************************************************************************

//la fonction codec pour coder une chaine par codage de cesar

char * codec(char *ch ,int decalage){
	int i;
    int a=strlen(ch);
	char ch1[a];
	for(i=0;i<=a;i++)
    ch1[i]=code(ch[i],decalage);
	return ch1;
}
//*********************************************************************************************************

//la fonction decodage pour decoder une chaine par codage de cesar
char * decodage(char *ch ,int decalage){
	return codec(ch,(26-decalage));
}

//*********************************************************************************************************
main()
{
	int choix,decalage;
	char caractere,resultat;
    char fsa;
    char chaine[100],*chaine1,*chaine2;
	do {
     
     printf("#*********************** le menu **************************************#\n");
	 printf("1-coder un caractere:\n");
	 printf("2-decoder un caractere:\n");
	 printf("3-coder une chaine:\n");
     printf("4-decoder une chaine:\n");
	 printf("5-quitter (press any key):\n");
     printf("taper ton choix:");
     scanf("%d",&choix);
     //#########################################
	 if(choix==1){ 
		printf("donner caractere: \n");
		scanf("%d",&caractere);
		printf("donner un decalage (nombre entier):\n");
		scanf("%d",&decalage);
		resultat=code(caractere,decalage);
		printf("le codage de %c par %d est: %c\n",caractere,decalage,resultat);
                 }
	//#########################################
	 else if(choix==2){
		printf("donner caractere: \n");
		scanf("%c",&caractere);
		printf("donner un decalage (nombre entier):\n");
		scanf("%c",&decalage);
		resultat=decode(caractere,decalage);
		printf("le decodage de %c par %d est: %c\n",caractere,decalage,resultat);
				}
    //#########################################
	 else if(choix==3){
		printf("donner une chaine pour le coder: \n");
		scanf("%s",chaine);
		printf("donner un decalage (nombre entier):\n");
		scanf("%d",&decalage);
		chaine2=codec(chaine,decalage);
		printf("le codage de (%s) par %d est: (%s)\n",chaine,decalage,chaine2);
				}
	//#########################################
	 else if(choix==4){
		printf("donner une chaine pour le decoder: \n");
		scanf("%s",chaine);
		printf("donner un decalage (nombre entier):\n");
		scanf("%d",&decalage);
		chaine1=decodage(chaine,decalage);
		printf("le decodage de (%s) par %d est: (%s)\n",chaine,decalage,chaine1);
				}
     else
 		break;
			}
	while(1);



getchar();
}







