#include <stdio.h>
#include <string.h>

int main() {
    char gram[50], part1[25], part2[25];
    char modifiedGram[30], newGram[30];
    int i, j = 0, k = 0, pos = 0;

    printf("Enter Production : A->");
    scanf("%s", gram);   // safer than gets()

    // Split into part1 and part2
    for (i = 0; gram[i] != '|'; i++, j++)
        part1[j] = gram[i];
    part1[j] = '\0';

    for (j = ++i, i = 0; gram[j] != '\0'; j++, i++)
        part2[i] = gram[j];
    part2[i] = '\0';

    // Find common prefix
    for (i = 0; i < strlen(part1) && i < strlen(part2); i++) {
        if (part1[i] == part2[i]) {
            modifiedGram[k++] = part1[i];
            pos = i + 1;
        } else {
            break;
        }
    }

    // Add X to represent suffixes
    modifiedGram[k++] = 'X';
    modifiedGram[k] = '\0';

    // Build new production for X
    for (i = pos, j = 0; part1[i] != '\0'; i++, j++)
        newGram[j] = part1[i];

    newGram[j++] = '|';

    for (i = pos; part2[i] != '\0'; i++, j++)
        newGram[j] = part2[i];

    newGram[j] = '\0';

    // Print results
    printf("\nA->%s", modifiedGram);
    printf("\nX->%s\n", newGram);

    return 0;
}