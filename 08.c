#include <stdio.h>

enum shape { ROCK, PAPER, SCISSORS };
enum result { LOSS, DRAW, WIN };

void print_shape(enum shape s)
{
    switch(s)
    {
        case ROCK: printf("Rock\n"); break;
        case PAPER: printf("Paper\n"); break;
        case SCISSORS: printf("Scissors\n"); break;
    }
}

void print_result(enum result r)
{
    switch(r)
    {
        case LOSS: printf("Loss\n"); break;
        case DRAW: printf("Draw\n"); break;
        case WIN: printf("Win\n"); break;
    }
}

enum result get_result(enum shape a, enum shape b)
{
    if (a == b) return DRAW;
    if ((a == ROCK && b == SCISSORS) ||
        (a == PAPER && b == ROCK) ||
        (a == SCISSORS && b == PAPER))
        return WIN;
    return LOSS;
}

enum shape get_strength(enum shape s)
{
    if (s == ROCK) return SCISSORS;
    if (s == PAPER) return ROCK;
    return PAPER;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    
    enum shape s1 = a;
    enum shape s2 = b;
    
    print_shape(s1);
    print_shape(s2);
    print_result(get_result(s1, s2));
    print_shape(get_strength(s1));
    
    return 0;
}