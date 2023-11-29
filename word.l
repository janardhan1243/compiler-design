%{
#include <stdio.h>
#include <string.h>
%}

%%
"to"    { fprintf(output, "notepad"); }
.       { fprintf(output, "%s", yytext); }

%%

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");

    if (input == NULL || output == NULL) {
        perror("Error opening file");
        return 1;
    }

    yyin = input;
    yyout = output;

    yylex();

    fclose(input);
    fclose(output);

    return 0;
}
