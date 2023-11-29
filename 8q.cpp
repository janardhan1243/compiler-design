#include <stdio.h>
#include <string.h>
#define MAX_SYMBOLS 100
typedef struct {
    char name[50];
    int value;
} Symbol;
Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;
void insertSymbol(const char* name, int value) {
    if (symbolCount < MAX_SYMBOLS) {
        strcpy(symbolTable[symbolCount].name, name);
        symbolTable[symbolCount].value = value;
        symbolCount++;
        printf("Inserted: %s = %d\n", name, value);
    } else {
        printf("Symbol table is full. Cannot insert %s.\n", name);
    }
}
Symbol* searchSymbol(const char* name) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return &symbolTable[i];
        }
    }
    return NULL;
}
void deleteSymbol(const char* name) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            printf("Deleted: %s = %d\n", symbolTable[i].name, symbolTable[i].value);
            symbolTable[i] = symbolTable[symbolCount - 1];
            symbolCount--;
            return;
        }
    }
    printf("%s not found. Cannot delete.\n", name);
}
	void displaySymbolTable() {
    printf("Symbol Table:\n");
    for (int i = 0; i < symbolCount; i++) {
        printf("%s: %d\n", symbolTable[i].name, symbolTable[i].value);
    }
}
int main() {
    insertSymbol("variable1", 10);
    insertSymbol("variable2", 20);
    insertSymbol("variable3", 30);

    displaySymbolTable();

    Symbol* result = searchSymbol("variable2");
    if (result != NULL) {
        printf("Found: %s = %d\n", result->name, result->value);
    } else {
        printf("Not Found\n");
    }

    deleteSymbol("variable2");

    displaySymbolTable();

    return 0;
}

