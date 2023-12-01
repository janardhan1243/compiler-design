%{
#include <stdio.h>
%}

DIGIT       [0-9]
INT_CONST   {DIGIT}+
FLOAT_CONST {DIGIT}+"."{DIGIT}+

%%
{INT_CONST}     printf("Integer Constant: %s\n", yytext);
{FLOAT_CONST}   printf("Float Constant: %s\n", yytext);
.               // Ignore other characters

%%

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        perror("Error opening file");
        return 1;
    }

    yyin = inputFile;

    yylex();

    fclose(inputFile);

    return 0;
}