#include <stdio.h>
#include <string.h>

#define MAX_SYMBOLS 100

// Define a symbol structure
typedef struct {
    char name[50];
    int value;
} Symbol;

// Define the symbol table
Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;

// Function to insert a symbol into the symbol table
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

// Function to search for a symbol in the symbol table
Symbol* searchSymbol(const char* name) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return &symbolTable[i];
        }
    }
    return NULL;
}

// Function to delete a symbol from the symbol table
void deleteSymbol(const char* name) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            printf("Deleted: %s = %d\n", symbolTable[i].name, symbolTable[i].value);
            // Replace the current symbol with the last symbol and decrement count
            symbolTable[i] = symbolTable[symbolCount - 1];
            symbolCount--;
            return;
        }
    }
    printf("%s not found. Cannot delete.\n", name);
}

// Function to display the symbol table
void displaySymbolTable() {
    printf("Symbol Table:\n");
    for (int i = 0; i < symbolCount; i++) {
        printf("%s: %d\n", symbolTable[i].name, symbolTable[i].value);
    }
}

// Main function for testing the symbol table
int main() {
    insertSymbol("variable1");
    insertSymbol("variable2");
    insertSymbol("variable3");

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

