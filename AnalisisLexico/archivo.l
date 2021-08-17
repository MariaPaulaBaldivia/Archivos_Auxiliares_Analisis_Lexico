%option noyywrap
%option yylineno 

%{

#include <stdio.h>

%}

TABULACION (\t)+
ESPACIO_EN_BLANCO (" ")+
SALTO_DE_LINEA (\n)+
LETRA [a-zA-Z]

/*Constantes enteras*/
DIGITO_DECIMAL [0-9]
DECIMAL_NO_NULO [1-9]
DIGITO_HEXADECIMAL [0-9A-Fa-f]
DIGITO_OCTAL [0-7]
SUFIJO_UNSIGNED [uU]
SUFIJO_LONG [lL]
SUFIJO_ENTERO (({SUFIJO_LONG}{SUFIJO_UNSIGNED}?)|({SUFIJO_UNSIGNED}{SUFIJO_LONG}?))

/*Constantes reales*/
SIGNO [+-]
PARTE_EXPONENTE [eE]{SIGNO}?{DIGITO_DECIMAL}+
CONSTANTE_FRACCION ({DIGITO_DECIMAL}*\.{DIGITO_DECIMAL}+)|({DIGITO_DECIMAL}+\.)
SUFIJO_REAL [fFlL]

/*Palabras reservadas*/
PALABRA_RESERVADA auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|union|unsigned|void|volatile|while

/*Operadores y caracteres de puntuación*/
OPERADOR_O_CARACTER_DE_PUNTUACION "["|"]"|"("|")"|"{"|"}"|"."|"->"|"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"|"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"|"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^="|"|="|"?"|":"|";"|"..."|","|"#"|"##"

/*Constante caracter*/
CUALQUIER_CARACTER_EXCEPTO_BARRA_INVERTIDA_O_COMILLA_SIMPLE [^'\\]
SECUENCIA_DE_ESCAPE_SIMPLE (\'|\"|\?|\\|\a|\b|\f|\n|\r|\t|\v)
SECUENCIA_DE_ESCAPE_OCTAL \\(DIGITO_OCTAL){1,3}
SECUENCIA_DE_ESCAPE_HEXADECIMAL \\x(DIGITO_HEXADECIMAL){1,2}
SECUENCIA_DE_ESCAPE {SECUENCIA_DE_ESCAPE_SIMPLE}|{SECUENCIA_DE_ESCAPE_OCTAL}|{SECUENCIA_DE_ESCAPE_HEXADECIMAL}
CONSTANTE_CARACTER {CUALQUIER_CARACTER_EXCEPTO_BARRA_INVERTIDA_O_COMILLA_SIMPLE}|{SECUENCIA_DE_ESCAPE}

/*Constante cadena*/
CUALQUIER_CARACTER_EXCEPTO_BARRA_INVERTIDA_O_COMILLA_DOBLE [^"\\]
CONSTANTE_CADENA_CARACTER {CUALQUIER_CARACTER_EXCEPTO_BARRA_INVERTIDA_O_COMILLA_DOBLE}|{SECUENCIA_DE_ESCAPE}

PREPROCESADOR #include|#define

/*Los printf son para probar*/
%%
{TABULACION}|{ESPACIO_EN_BLANCO}|{SALTO_DE_LINEA} {;}                                                                   // Ignora tabulaciones, espacios en blanco y saltos de linea
{PALABRA_RESERVADA} {printf("%s : PalabraReservada -> Numero de linea: %i \n", yytext, yylineno);}                                    // Palabra reservada
{DECIMAL_NO_NULO}{DIGITO_DECIMAL}*{SUFIJO_ENTERO}? {printf("%s : ConstanteDecimal -> Numero de linea: %i \n", yytext, yylineno);}     // Constante decimal
0{DIGITO_OCTAL}*{SUFIJO_ENTERO}? {printf("%s : ConstanteOctal -> Numero de linea: %i \n", yytext, yylineno);}                         // Constante octal
0[xX]{DIGITO_HEXADECIMAL}+{SUFIJO_ENTERO}? {printf("%s : ConstanteHexadecimal -> Numero de linea: %i \n", yytext, yylineno);}         // Constante hexadecimal
({LETRA}|"_")({LETRA}|{DIGITO_DECIMAL}|"_")* {printf("%s : Identificador -> Numero de linea:  %i \n", yytext, yylineno);}               // Identificador
{CONSTANTE_FRACCION}{PARTE_EXPONENTE}?{SUFIJO_REAL}? {printf("%s : ConstanteReal -> Numero de linea: %i \n", yytext, yylineno);}      // Constante real
{DIGITO_DECIMAL}+{PARTE_EXPONENTE}{SUFIJO_REAL}? {printf("%s : ConstanteReal -> Numero de linea: %i \n", yytext, yylineno);}          // Constante real
{OPERADOR_O_CARACTER_DE_PUNTUACION} {printf("%s : OperadorYCaracterDePuntuacion -> Numero de linea: %i \n", yytext, yylineno);}    // Operador o caracter de puntuación
\'{CONSTANTE_CARACTER}\' {printf("%s : Caracter -> Numero de linea: %i \n", yytext, yylineno);}                                        // Constante caracter
\"{CONSTANTE_CADENA_CARACTER}+\" {printf("%s : LiteralCadena -> Numero de linea: %i \n", yytext, yylineno);}                          // Literal cadena
[\/][\/][^\/\/\n]+[\n] {printf("%s : Comentario -> Numero de linea: %i \n", yytext, yylineno);}                                                        // Comentario, aclaracion es posible escribir comentarios vacios
(\/)(\*)[^\*\/]+[\*][\/] {printf("%s : ComentarioMultilinea -> Numero de linea: %i \n", yytext, yylineno);}                                         // Comentario multilinea
. {printf("%s : NoReconocido -> Numero de linea: %i \n", yytext, yylineno);}                                                          // Cadena no reconocida
%%

int main() {     
        yyin = fopen("entrada.c", "r+");
        yylex();                                 

   return 0;
}