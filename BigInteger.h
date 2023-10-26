#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include<stdio.h>
#include<stdlib.h>


struct BigInteger
{
    struct node*l;
    int length;
    char sign;
};
struct node
{
    int data;
    struct node*next;
};
struct BigInteger initialize(char *s);

struct BigInteger add(struct BigInteger a,struct BigInteger b);
struct BigInteger sub(struct BigInteger a,struct BigInteger b);
struct BigInteger mul(struct BigInteger a,struct BigInteger b);
struct BigInteger div1(struct BigInteger a,struct BigInteger b);
struct BigInteger mod(struct BigInteger a,struct BigInteger b);
#endif
