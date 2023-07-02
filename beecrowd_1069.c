#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
    int i, j, rept = 0, dima;
    char ground[1010];
    scanf("%d", &rept);
    while (rept--){
        scanf("%s", ground);
        dima = 0;
        for (i = 0; i < strlen(ground); i++){
            if (ground[i] == '\0')
                break;
            if (ground[i] == '<'){
                for (j = i; j< strlen(ground); j++){
                    if (ground[j] == '>'){
                        dima++;
                        ground[j] = '0';
                        break;
                    }
                }
            }
        }
        printf("%d\n", dima);
    }
    return 0;
}