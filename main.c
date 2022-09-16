#include "Includes.h"

typedef enum{TKN_STR}TokenType;
typedef struct Token{
    TokenType type;
}Token;

typedef enum{N_FUNC}NodeType;
typedef struct Node{
    NodeType type;
}Node;

int main(int argc, char **argv)
{
    printf("Awooo\n");
    char *buf = fileReadText(argc > 1 ? argv[1] : "./in.bork");
    printf("Input file \"%s\":\n%s", argc > 1 ? argv[1] : "./in.bork", buf);
    return 0;
}
