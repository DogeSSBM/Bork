#include "Includes.h"

int main(int argc, char **argv)
{
    printf("Awooo\n");

    char *inputFile = argc > 1 ? argv[1] : "./in.bork";
    char *buf = fileReadText(inputFile);
    printf("Input file \"%s\":\n%s", inputFile, buf);

    Token *tokens = tokenize(buf);
    printf("\nTokens -\n");
    printTokens(tokens);

    free(buf);
    freeTokens(tokens);
    return 0;
}
