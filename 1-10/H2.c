#include <stdio.h>

int main() {
    int number;
    
    if (scanf("%d", &number) == 1) {
        if ((number % 2 == 0) && ((number >= 0 && number <= 20) || (number > 100 && number < 200))) {
            printf("Yes");
        } else {
            printf("No");
        }
    } else {
        printf("No");
    }
    
    return 0;
}