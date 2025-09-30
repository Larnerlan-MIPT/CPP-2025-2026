#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct game {
    char title[50];
    double average;
};

int main() {
    int n;
    scanf("%d", &n);
    
    struct game* games = malloc(n * sizeof(struct game));
    
    for (int i = 0; i < n; i++) {
        char temp;
        scanf(" %[^:]:", games[i].title);
        
        int k;
        scanf("%d", &k);
        
        double sum = 0;
        for (int j = 0; j < k; j++) {
            int score;
            scanf("%d", &score);
            sum += score;
        }
        games[i].average = sum / k;
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (games[j].average < games[j + 1].average) {
                struct game temp = games[j];
                games[j] = games[j + 1];
                games[j + 1] = temp;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        printf("%s, %.3f\n", games[i].title, games[i].average);
    }
    
    free(games);
    return 0;
}