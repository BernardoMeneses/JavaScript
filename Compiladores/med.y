%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylex();
extern int yylineno;
extern void yyerror(char *); 


int nClasses = 0;



int n_Fabricantes = 0;
int ano;

typedef struct med{
	char nome[25], classe[25], comp[20], fabricantes[50], equivalentes[50];
	int codigo, nfabricantes;
	float preco;
} medic;

medic med;
medic **Fabricantes = NULL;




%}
%union 
{
    char *string;
}

%start Document

// tokens here
%token COLON DOT OPEN_SQUARE_BRACKET CLOSE_SQUARE_BRACKET OPEN_CURLY_BRACKET CLOSE_CURLY_BRACKET OPEN_PARENTHESIS CLOSE_PARENTHESIS COMMA BRANCOS
%token <string> SYMP ID 
%token <num> INT
%token <rnum> REAL

%type <string> IdList Name Code Category ChemComp Med MedList Price Repetable Repetables Equal Equals EqualList
%type Classes

%%
Document: Header Body
        ;


Classes: ID 					{nClasses++;};
	   | Classes COMMA ID		{nClasses++;};
     ;

Header: SYMP COLON INT { ano = $3; }
      ;

Body:ClassHeader ClassBody
    ;




IdList: ID
              | IdList COMMA ID
                {
                    char * newIdent = $3; 
                    char * others = $1; 
                    strcat(others, ", ");
                    strcat(others, newIdent);
                    $$ = others;
                }
              ;

ClassHeader: OPEN_SQUARE_BRACKET IdList CLOSE_SQUARE_BRACKET 
           ;

MedList: Med
            | MedList Med 
            ;

ClassBody: OPEN_SQUARE_BRACKET MedList CLOSE_SQUARE_BRACKET // Corresponde a zona onde tem a lista de medicamentos
         ;



Med: OPEN_PARENTHESIS Name COMMA Code COMMA Category COMMA ChemComp COMMA Price COMMA Repetables COMMA Equals CLOSE_PARENTHESIS 
        {
            int i=0, j=0, existeFabricante = 0;
            auxFarmaco = (Farmaco)malloc(sizeof(struct farmaco));
            med.nome = strdup($2);
            med.codigo = strdup($4);
            med.classe = strdup($6);
            med.comp = strdup($8);
            med.preco = strdup($10);
            med.fabricantes = str_split_comma(strdup($12), &(med.nFabricantes));
                        

            // Adicionar à lista apenas os fabricantes que ainda não tenham aparecido
            for(i=0; i<med.nFabricantes; i++){
                int compare = 0;
                for(j=0; j < n_Fabricantes; j++){
                    if(strcmp(med.fabricantes[i], todosFabricantes[j])==0){
                        compare = 1;
                        break;
                    }
                }
                if(!compare){
                    addString(&Fabricantes, &n_Fabricantes, (med.fabricantes)[i]);
                }
            }
          med.equivalentes = strdup($14);
        }
        ;

Name: ID
    ;

Category: ID
    ;

Repetable: ID
            ;

Code: INT
    ;

ChemComp: ID
        ;

Price: REAL
     ;




Repetables: OPEN_CURLY_BRACKET IdList CLOSE_CURLY_BRACKET {$$ = $2;}
             ;

EqualList: Equal                                       //Adiciona medicamento a lista de repetidos
               | EqualList COMMA Equal
               {
                    char * newEq = strdup($3); 
                    char * others = strdup($1); 
                    strcat(others, ", ");
                    strcat(others, newEq);
                    $$ = others;
               }
               ;

Equals: OPEN_CURLY_BRACKET EqualList CLOSE_CURLY_BRACKET { $$ = $2; }
           ;

Equal: Name BRANCOS Repetables       //Diz o numero de medicamentos repetidos
            {
                char * eq = strdup($1);
                strcat(eq, "-");
                strcat(eq, $3);
                $$ = eq;
            }
          ;

%%


void yyerror(char* erro){
   printf("erro: %d: %s: %s\n",yylineno,erro,yytext);
}


void printMedicamentos(){	//Dar Print aos Medicamentos
	int i,j;
	for( i = 0; i < nClasses; i++){
		for( j=0; j < n_fabricantes[i]; j++){
			printf("Nome: %s\nCod: %d\nCat: %s\nComposicao: %s\nPreco: %.2f\nFabricante: %s\nEquivalentes: %s\n-----------------------\n", Fabricantes[i][j].nome, Fabricantes[i][j].codigo, Fabricantes[i][j].classe, Fabricantes[i][j].comp, array[i][j].preco, array[i][j].fabricante, array[i][j].equivalentes);  
		} 
	}

	
} 


int main (void) {
	int errado;

	if(errado = yyparse( )){	//ERROR
		return 0;
	}else {					//Success
		printMedicamentos();
		return 0;
	}
}
