#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a symbol in the symbol table
struct Symbol {
    char name[50];
    int type;  // You can use an enum or other type to represent data types
    int scope; // Scope level
};

// Maximum number of symbols in the symbol table
#define MAX_SYMBOLS 100

// Initialize the symbol table
struct Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;

// Function to add a symbol to the symbol table
void addSymbol(const char *name, int type, int scope) {
    if (symbolCount < MAX_SYMBOLS) {
        struct Symbol symbol;
        strcpy(symbol.name, name);
        symbol.type = type;
        symbol.scope = scope;
        symbolTable[symbolCount] = symbol;
        symbolCount++;
        printf("Added symbol: %s (Type: %d, Scope: %d)\n", name, type, scope);
    } else {
        printf("Symbol table is full. Cannot add more symbols.\n");
    }
}

// Function to search for a symbol in the symbol table
struct Symbol* findSymbol(const char *name, int scope) {
    for (int i = symbolCount - 1; i >= 0; i--) {
        if (strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].scope == scope) {
            return &symbolTable[i];
        }
    }
    return NULL;
}

int main() {
    // Example usage of symbol table operations
    addSymbol("x", 0, 0); // Add a symbol with name "x," type 0, and scope 0
    addSymbol("y", 1, 1); // Add a symbol with name "y," type 1, and scope 1

    struct Symbol* foundSymbol = findSymbol("x", 0);
    if (foundSymbol) {
        printf("Found symbol: %s (Type: %d, Scope: %d)\n", foundSymbol->name, foundSymbol->type, foundSymbol->scope);
    } else {
        printf("Symbol not found.\n");
    }

    return 0;
}
