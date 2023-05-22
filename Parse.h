#ifndef PARSE_H
#define PARSE_H

// NaturalNum, Set, Range, Tuple, String, Expression
typedef enum{E_NAT, E_SET, E_RNG, E_TUP, E_STR, E_EXP, E_NUM}ExprType;
const char *ExprTypeStr[E_NUM] = {"E_NAT", "E_SET", "E_RNG", "E_TUP", "E_STR", "E_EXP"};

typedef struct Expr{
    ExprType type;
    union{
        uint nat;
        struct Expr *expr;
    };
    struct Expr *next;
}Expr;

#endif /* end of include guard: PARSE_H */
