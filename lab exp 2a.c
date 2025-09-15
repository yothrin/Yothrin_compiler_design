#include <stdio.h>
#include <string.h>
#define SIZE 20

int main() {
    char non_terminal;
    char alpha, beta;
    int num;
    char production[10][SIZE];
    int index = 3; /* starting of RHS after "->" */

    printf("Enter Number of Productions: ");
    scanf("%d", &num);

    printf("Enter the grammar productions (example: E->E-A|B):\n");
    for (int i = 0; i < num; i++) {
        scanf("%s", production[i]);
    }

    for (int i = 0; i < num; i++) {
        printf("\nGRAMMAR : %s", production[i]);
        non_terminal = production[i][0];

        // Check if left recursive
        if (non_terminal == production[i][index]) {
            alpha = production[i][index + 1];
            printf(" is left recursive.\n");

            // Skip until '|'
            while (production[i][index] != '\0' && production[i][index] != '|')
                index++;

            if (production[i][index] != '\0') {
                beta = production[i][index + 1];

                printf("Grammar without left recursion:\n");
                printf("%c->%c%c'\n", non_terminal, beta, non_terminal);
                printf("%c'->%c%c'|E\n", non_terminal, alpha, non_terminal);
            } else {
                printf(" can't be reduced (no alternative found)\n");
            }
        } else {
            printf(" is not left recursive.\n");
        }
        index = 3; // reset for next production
    }

    return 0;
}