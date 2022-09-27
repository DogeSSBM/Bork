#ifndef TYPES_H
#define TYPES_H

typedef unsigned int uint;
typedef FILE File;

typedef enum{PAREN_L, PAREN_R}Paren;

typedef enum{TKN_IDENT, TKN_PAREN, TKN_NAT, TKN_STR, TKN_END, TKN_N}TokenType;
char *TokenTypeStr[TKN_N] = {"TKN_IDENT", "TKN_PAREN", "TKN_NAT", "TKN_STR", "TKN_END"};

typedef struct Token{
    TokenType type;
    union{
        Paren paren;
        uint nat;
        char *ident;
        char *str;
    };
    struct Token *next;
}Token;

void clearTerminal(void)
{
    printf(__extension__"\e[1;1H\e[2J");
}

#endif /* end of include guard: TYPES_H */
