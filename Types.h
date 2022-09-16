#ifndef TYPES_H
#define TYPES_H

typedef unsigned int uint;
typedef FILE File;

void clearTerminal(void)
{
    printf(__extension__"\e[1;1H\e[2J");
}

#endif /* end of include guard: TYPES_H */
