%{
#include "y.tab.h"
#include <stdlib.h>
#include <stdio.h>
%}
%option yylineno
%%
[ |\t|\n]+ 								{yylval.string = strdup(yytext); return BRANCOS;}
[1-9]+[0-9]*								{yylval.num = atoi(yytext); return INT; }
[0-9]+[.][0-9]*								{yylval.rnum = atof(yytext); return REAL; }
[A-Za-z]+								{yylval.string = strdup(yytext); return ID; }
"["									{yylval.string = strdup(yytext); return OPEN_SQUARE_BRACKET;}
"]"									{yylval.string = strdup(yytext); return CLOSE_SQUARE_BRACKET;}
"("									{yylval.string = strdup(yytext); return OPEN_PARENTHESIS;}
")"									{yylval.string = strdup(yytext); return CLOSE_PARENTHESIS;}
"{"									{yylval.string = strdup(yytext); return OPEN_SQUARE_BRACKET;}
"}"									{yylval.string = strdup(yytext); return CLOSE_SQUARE_BRACKET;}
","									{yylval.string = strdup(yytext); return COMMA;}
"."									{yylval.string = strdup(yytext); return DOT;}
":"									{yylval.string = strdup(yytext); return COLON;}
.									fprintf(stderr, "%d:Unexpected char: '%s'\n", yylineno, yytext);
%%
int yywrap(void)        
{
    return -1;           
}
