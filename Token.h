#ifndef TOKEN_H
#define TOKEN_H

void freeTokens(Token *tokens)
{
    while(tokens){
        Token *next = tokens->next;
        free(tokens);
        tokens = next;
    }
}

void printTokens(Token *tokens)
{
    Token *currentTkn = tokens;
    while(currentTkn){
        printf("type: %s\n", TokenTypeStr[currentTkn->type]);
        printf("value: ");
        switch (currentTkn->type) {
            case TKN_IDENT:
                printf("%s\n", currentTkn->ident);
                break;
            case TKN_PAREN:
                printf("%c\n", currentTkn->paren == PAREN_L ? '(':')');
                break;
            case TKN_NAT:
                printf("%u\n", currentTkn->nat);
                break;
            case TKN_STR:
                printf("\"%s\"\n", currentTkn->str);
                break;
            case TKN_END:
                printf("END\n");
                break;
            default:
                panic("Unknown TokenType: %i\n", currentTkn->type);
                break;
        }
        currentTkn = currentTkn->next;
        printf("\n");
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

uint lenTkn(char *text, const TokenType type)
{
    char *start = text;
    switch(type){
        case TKN_IDENT:
            while(*text && !isspace(*text) && *text != '"' && *text != '(' && *text++ != ')');
            return text-start;
            break;
        case TKN_PAREN:
            return 1;
            break;
        case TKN_NAT:
            while(*text && isdigit(*text))
                text++;
            return text-start;
            break;
        case TKN_STR:
            if(*text != '"')
                panic("First char of TKN_STR != '\"'");
            while(*++text != '"' && *text);
            if(!*text)
                panic("Unclosed '\"'");
            return text-start;
            break;
        case TKN_END:
            return 0;
            break;
        default:
            panic("Unknown TokenType: %i\n", type);
            break;
    }
    return 0;
}

char *skipSpace(char *text)
{
    while(*text && isspace(*text))
        text++;
    return text;
}

char *generateTkn(char *text, Token *token)
{
    const uint len = lenTkn(text, token->type);
    switch(token->type){
        case TKN_IDENT:
            token->ident = calloc(len+1, sizeof(char));
            memcpy(token->ident, text, len);
            return text+len;
            break;
        case TKN_PAREN:
            token->paren = *text == '(' ? PAREN_L:PAREN_R;
            return text+1;
        case TKN_NAT:
            for(uint i = 0; i < len; i++){
                token->nat *=  10;
                token->nat += *(text+(len-1)-i) - '0';
            }
            return text+len;
            break;
        case TKN_STR:
            text++;
            token->str = calloc(len, sizeof(char));
            memcpy(token->str, text, len-1);
            return text+len+1;
            break;
        case TKN_END:
            return text;
            break;
        default:
            panic("Unknown TokenType: %i\n", token->type);
            break;
    }
    return text;
}

Token* tokenize(char *text)
{
    Token *tokens = calloc(1, sizeof(Token));
    Token *currentTkn = tokens;
    while((currentTkn->type = tokenType(skipSpace(text))) != TKN_END){
        text = skipSpace(generateTkn(text, currentTkn));
        currentTkn->next = calloc(1, sizeof(Token));
        currentTkn = currentTkn->next;
    }
    return tokens;
}

#endif /* end of include guard: TOKEN_H */
