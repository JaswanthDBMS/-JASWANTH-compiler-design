#include <stdio.h>
#include <string.h>
#define MAX_NON_TERMINALS 10
#define MAX_TERMINALS 10
struct FollowSet {
    char nonTerminal;
    char follow[MAX_TERMINALS];
    int size;
};
void initFollowSet(struct FollowSet *set, char nonTerminal) {
    set->nonTerminal = nonTerminal;
    set->size = 0;
}
void addToFollowSet(struct FollowSet *set, char terminal) {
    set->follow[set->size] = terminal;
    set->size++;
}

int main() {
    char grammar[MAX_NON_TERMINALS][10] = { "S->Aa", "A->b", "A->e" };
    struct FollowSet followSets[MAX_NON_TERMINALS];
    initFollowSet(&followSets[0], 'S');
    initFollowSet(&followSets[1], 'A');
    addToFollowSet(&followSets[0], 'a');
    addToFollowSet(&followSets[1], 'a');
    addToFollowSet(&followSets[1], '$'); 
    for (int i = 0; i < MAX_NON_TERMINALS; i++) {
        printf("FOLLOW(%c): { ", followSets[i].nonTerminal);
        for (int j = 0; j < followSets[i].size; j++) {
            printf("%c ", followSets[i].follow[j]);
        }
        printf("}\n");
    }

    return 0;
}
