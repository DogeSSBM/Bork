#include "Includes.h"
typedef enum{PAREN_L, PAREN_R}Paren;

typedef enum{TKN_IDENT, TKN_PAREN, TKN_NAT, TKN_STR, TKN_END, TKN_N}TokenType;
char *TokenTypeStr[T_N] = {"TKN_IDENT", "TKN_PAREN", "TKN_NAT", "TKN_STR", "TKN_END"};

typedef struct Token{
    TokenType type;
    union{
        Paren paren;
        uint nat;
        char *type;
        char *ident;
        char *str;
    };
    struct Token *next;
}Token;

void printTokens(Token *tokens)
{
    Token *currentTkn = tokens;
    while(currentTkn){
        printf("type: %s\n", TokenTypeStr[currentTkn->type]);
        switch (token->type) {
            case TKN_NAT:
                printf()
        }
    }
}

TokenType tokenType(char *text)
{
    if(!text)
        panic("Cant get tokenType for NULL text");
    if(isspace(*text))
        panic("Whitespace does not have a TokenType");

    if(isdigit(*text))
        return TKN_NAT;

    if(*text == '"')
        return TKN_STR;

    if(*text == '(' || *text == ')')
        return TKN_PAREN;

    if(*text == '\0')
        return TKN_END;

    return TKN_IDENT;
}

Token* tokenize(char *text)
{
    Token *tokens = calloc(1, sizeof(Token));
    Token *currentTkn = tokens;
    while((currentTkn->type = tokenType(text)) != TKN_END){

        currentTkn->next = calloc(1, sizeof(Token));
        currentTkn = currentTkn->next;
    }
}


int main(int argc, char **argv)
{
    printf("Awooo\n");

    char *inputFile = argc > 1 ? argv[1] : "./in.bork";
    char *buf = fileReadText(inputFile);
    printf("Input file \"%s\":\n%s", inputFile, buf);


    free(buf);
    return 0;
}
