#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "datatype.h"
#include "tokenList.h"

#define MAX_WORD 50


struct list tokenList;

/*
*	TOKEN_EQUEL, //27
*   TOKEN_INF_EQ, //28
*   TOKEN_SUP_EQ //29
*/

//fomction operation si cest un operatuer
bool isOp(char c,int line,FILE *file){
	
	if(c == '='){
		if((c = fgetc(file)) == '=')
		{
			
		}else{
			ungetc(c,file);
		}
	}else if(c == '=')
	{
		if((c = fgetc(file)) == '=')
		{
			printf("Operateur de comparaison\n");
			//creation du token
        	token *_token = malloc(sizeof(token));
			_token->type = TOKEN_SUP_EQ;
        	strcpy(_token->value , "");
			add_to_liste(&tokenList,*_token,line);
			free(_token);
			return true;
		}else{
			ungetc(c,file);
		}
	}else if(c =='<')
	{
		if((c = fgetc(file)) == '=')
		{
			printf("Operateur de comparaison\n");
			//creation du token
        	token *_token = malloc(sizeof(token));
			_token->type = TOKEN_INF_EQ;
        	strcpy(_token->value , "");
			add_to_liste(&tokenList,*_token,line);
			free(_token);
			return true;
		}else{
			ungetc(c,file);
		}
	}
	return false;
}

// Fonction pour vérifier si un mot est un mot-cle
bool isKeyword(const char *word ,int line) {
    // Liste de mots-clés
    //keywords (la liste) est dans "datatype.h"
	const char *keywords[17] ={
	    "Snk_Begin",
	    "Snk_Int",	
	    "Snk_Real",
	    "Begin",
	    "Set",
	    "If",
	    "Else",
	    "Get",
	    "Snk_Print",
	    "Snk_End",
	    "While",
	    "End",
		"Add",
	    "Sub",
	    "Mul",
	    "Div",
	    "from"
	};

    // Verification si le mot est un mot clef
    int i;
	for (i = 0; i < sizeof(keywords) / sizeof(keywords[0]); ++i) {
        if (strcmp(word, keywords[i]) == 0) {
        	//pour un affichage plus en detaill
        	printf("mot cle trouver: %s ",keywords[i]);
        	switch(i)
        	{
        		case 0: {
					printf("pour debut du programme");
					break;	
				}
        		case 1: {
        			printf("pour declaration un entier ");
					break;
				}
        		case 2: {
        			printf("pour declaration un realle ");
					break;
				}
        		case 3: {
        			printf("pour debut un block d\'instruction ");
					break;
				}
        		case 4: {
        			printf("pour affectation d’une valeur ");
					break;
				}
        		case 5:{
        			printf("conditionnel");
					break;
				}
				case 6:{
					printf("conditionnel sinon");
					break;
				}
				case 7:{
					printf("pour affectation d’une valeur");
					break;
				}
				case 8:{
					printf("pour affichage d\'une chaine de charcter");
					break;
				}
				case 9:{
					printf("pour fin du programme");
					break;
				}
				case 10:{
					printf("pour une boucle while");
					break;
				}
				case 11:{
					printf("pour fin de block");
					break;
				}
				case 12:{
					printf("pour addition");
					break;
				}
				case 13:{
					printf("pour substraction");
					break;
				}
				case 14:{
					printf("pour multiplication");
					break;
				}
				case 15:{
					printf("pour division");
					break;
				}
				case 16:{
					printf("pour affectation");
					break;
				}
					
			}
        	
        	printf("\n");
        	
        	//creation du token
        	token *_token = malloc(sizeof(token));
        	// i est nbr toekn type
			_token->type = i;
        	strcpy(_token->value , "");
			add_to_liste(&tokenList,*_token,line);
			free(_token);
            return true;
        }
    }
    return false;
}
bool isSymboleCle(char symbole,bool affiche,int line,FILE *f) {
	const char KEYSYM[7] ={
	    '$',
	    '[',
	    ']',
	    ',',
	    '>',
	    '<',
	    '='
	};
    // verefication symbol cle
    int i;
	for (i = 0; i <= 6; i++) {
        if (symbole == KEYSYM[i]) {
        	//pour un affichage plus en detaill
        	
			if(affiche == false)
        		return true;
        	
        	printf("symbole trouver : %c",KEYSYM[i]);
        	switch(i)
        	{
        		case 0: {
					printf(" fin de ligne");
					break;
				}
        		case 1: {
        			printf(" Debut de condition");
					break;
				}
        		case 2: {
        			printf(" fin de condition");
					break;
				}
        		case 3: {
        			printf(" separateur");
					break;
				}
        		case 4: {
        			if( (symbole = fgetc(f)) == '='  )
        			{
        				printf("= Operateur de comparaison\n");
						//creation du token
			        	token *_token = malloc(sizeof(token));
						_token->type = TOKEN_SUP_EQ;
			        	strcpy(_token->value , "");
						add_to_liste(&tokenList,*_token,line);
						free(_token);
						return true;	
					}else ungetc(symbole,f);
					printf(" Operateur de comparaison");
					break;
				}
        		case 5:{
        			
        			if( (symbole = fgetc(f)) == '='  )
        			{
        				printf("= Operateur de comparaison\n");
						//creation du token
			        	token *_token = malloc(sizeof(token));
						_token->type = TOKEN_INF_EQ;
			        	strcpy(_token->value , "");
						add_to_liste(&tokenList,*_token,line);
						free(_token);
						return true;	
					}else ungetc(symbole,f);
					printf(" Operateur de comparaison");
					break;
				}
				case 6:{
					if( (symbole = fgetc(f)) == '='  )
        			{
        				printf("= Operateur de comparaison\n");
						//creation du token
			        	token *_token = malloc(sizeof(token));
						_token->type = TOKEN_EQUEL;
			        	strcpy(_token->value , "");
						add_to_liste(&tokenList,*_token,line);
						free(_token);
						return true;	
					}else ungetc(symbole,f);
					printf(" Operateur de comparaison");
					break;
				}
			}
        	
        	printf("\n");
        	
        	//ajouter le token a la liste
			token *_token = malloc(sizeof(token));
        	_token->type = i+17;
        	strcpy(_token->value , "");
			add_to_liste(&tokenList,*_token,line);
			free(_token);
            return true;
        }
    }
    return false;
}
//is an integer 
bool isInt(char *s,int line)
{
	int i;
	for(i=0;i<strlen(s);i++)
	{
		if(!isdigit(s[i]))
			return false;
	}
	token *_token = malloc(sizeof(token));
    _token->type = TOKEN_INT;

    strcpy(_token->value , s);
	add_to_liste(&tokenList,*_token,line);
	free(_token);
	return true;
}
//is real
bool isReal(char *s,int line)
{
	int i;
	bool vir = false;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i] == '.' && vir == true)
			return false;
		if(!isdigit(s[i]) && s[i] != '.')
			return false;
		if(s[i] == '.')
			vir = true;
	}
	token *_token = malloc(sizeof(token));
    _token->type = TOKEN_REAL;
    strcpy(_token->value , s);
	add_to_liste(&tokenList,*_token,line);
	free(_token);
	return true;
}

//work in progress
bool isValideId(char *s,int line)
{
	int i =1;
	if( !isalpha(s[0]) && s[0] != '_' )
		return false;
	
	for(;i<strlen(s);i++)
	{
		if(i>31)
		{
			printf("Erreur: (Taille de l'id ne peut pas depasser 31 char)\n");
			exit(1);
		}
		if(!isalnum(s[i]) && s[i] != '_')
			return false;
		
	}
	token *_token = malloc(sizeof(token));
    _token->type = TOKEN_IDENTIFIER;
    strcpy(_token->value , s);
	add_to_liste(&tokenList,*_token,line);
	free(_token);
	return true;
}

// un comentaire sur une seule ligne
bool isCommentaire(char c, FILE *f) {
    

    if (c == '$') {
    	if( (c = fgetc(f)) == '$')
    	{
    		return true;	
		}
        else{
        	ungetc(c,f);
        	return false;
		}
    }
    return false;
}



// Fonction principale pour l'analyse lexicale
void analyseur_lex(FILE *file) {
		
	// creation dune liste de token
	init_list(&tokenList);
    char mot[MAX_WORD];
    char c;
	bool endOfFile = false;
	
	int line = 1;
	int i = 0;
	printf("\n----------------line: %d-----------------------\n",line);
    while ( !endOfFile ) {
		c = fgetc(file);
		
		if (c == EOF)
        	endOfFile = true;
		
	
		//ingorie les comantaire
		//comentaire sur une ligne
		if(isCommentaire(c,file) )
			while( (c = fgetc(file)) != EOF && c != '\n'  );// do nothing
		
		//un comentaire sur +ieur ligne de code
		if(c == '#' )
		{
			
			while( (c = fgetc(file)) != EOF )
			{
				if (c == '#') 
			    	break;
			    if(c == '\n')
			    	line++;
			}
			if(c == EOF)
			{
				printf("Erreur: (Fermeture de commentaire manquante (#)).");
				exit(EXIT_FAILURE);
			}
			if(c == '#')
				c = fgetc(file);
		}
			
		
        if (isspace(c)  || isSymboleCle(c,false,line,file) || c == EOF) 
		{
		
            if (i > 0) // Vérifier si le mot n'est pas vide
			{ 
                mot[i] = '\0'; // Ajouter le caractère de fin de chaîne
                
                if (isKeyword(mot,line));
                
				else if (isInt(mot,line))
                	printf("cest un nombre entier:  %s\n",mot);
                else if (isReal(mot,line))
                	printf("cest un nombre real:  %s\n",mot);
                else if(isValideId(mot,line))
					printf("identificateur : %s\n",mot);
				else if(isOp(c,line,file));
				else
					printf("Erreur: ( %s dans la ligne: %d)\n",mot,line);
			}
			if (isSymboleCle(c,true,line,file));
            i = 0; // Réinitialiser l'indice du mot
        }
        
        //pour les Strings
        else if(c == '"'  )
		{
			char *s = (char*)malloc(sizeof(char)*201); //contien le string
			int j = 0;
			while( (c = fgetc(file)) != EOF && c != '"')
			{
				//automate String
				if (c == '\"' || j>200)
					break;
				while(c == '\n')
				{
					c = fgetc(file);
					line++;
					if( c == EOF || c == '"')
						break;
				}
				if(c == EOF || c == '\"' || j>100)
					break;
				s[j] = c;
				j++;
			}
			s[j] = '\0';
			if(c == '"')
			{
				token *_token = malloc(sizeof(token));
			    _token->type = TOKEN_STRING;
			    strcpy(_token->value , s);
				add_to_liste(&tokenList,*_token,line);
				free(_token);
				printf("string trouver : %s\n",s);
			}
			else
			{	
				printf("Erreur: (Guillemet (\") manquant ou taille Strin > 100 chars ligne: %d)\n",line);
				free(s);
				exit(EXIT_FAILURE);
			}
			free(s);
		}
		else 
           	mot[i++] = c; // Ajouter le caractère au mot 
           	
           	
           	
        if(c == '\n') //pour avoire le compt des ligne
        {
        	line++;
        	printf("\n----------------line: %d-----------------------\n",line);

		}
        
        
    }
    
    
    
    
    //cree le fichier token
    FILE *temp = fopen("token_table.temp", "wb");
	if (temp != NULL) {
	    // Write the entire array to the file
	    fwrite(&tokenList, sizeof(list), 1, temp);
	    fclose(temp);
	    printf("\n\n\nData written to file token_table.temp\n to use in syntaxe analyse\n");
	} else {
	    printf("Error opening file!\n");
	}
	

	
	
	free_memory(&tokenList);
}





/*void test()
{
	int i=0;
	for(;i<tokenList.nbrToken;i++)
		if(tokenList._token[i].type == tokenType.TOKEN_IDENTIFIER)
		printf("id: ",tokenList._token[i].value);
}*/
