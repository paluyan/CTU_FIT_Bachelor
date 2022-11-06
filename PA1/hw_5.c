#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <float.h>
typedef struct point_s {
    double x;
    double y;
    int id;
    char * line;
}point;
void freeMem (point * ptr, int i){
    for (int m = 0; m < i; m++)
        free(ptr[m].line);
    free(ptr);
}

int main() {
    int N = 1, err, i = 0, size = 10, j = 0, cnt = 0;
    char c1, c2, s;
    double dist;
    point * ptr = (point*) malloc (N * sizeof(*ptr));
    printf("Zadejte lety:\n");
    while (1){
           if((err = scanf(" %c %lf , %lf %c ", &c1, &ptr[i].x, &ptr[i].y, &c2)) != 4 || c2 != ']' || c1 != '['){
               if (err == EOF) break;
               printf("Nespravny vstup.\n");
               freeMem(ptr,i);
               return 1;
           }
           ptr[i].id = cnt;
           cnt++;
           ptr[i].line = (char*)malloc(size * sizeof(ptr[i].line));
           int flag = 0;
            while (1){
                s = getchar();
                //if ( s == EOF) break;

                if(j + 1 >= size){
                    size *= 2;
                    ptr[i].line = (char*) realloc (ptr[i].line, size * sizeof(ptr[i].line));
                }
                if (s == '\n') {
                    ptr[i].line[j++] = '\0';
                    i++;
                    j = 0;
                    break;
                }
                if (isspace(s) && flag == 0) continue;
                ptr[i].line[j++] = s;
                flag = 1;
            }
        if (i >= N) {
            N *= 2;
            ptr = (point *) realloc(ptr, N * sizeof(*ptr));
        }
    }
    if (cnt <= 1){
        printf("Nespravny vstup.\n");
        freeMem(ptr,i);
        return 1;
    }
    double minD = -1;
    cnt = 0;
    for (int k = 0; k < i - 1; ++k) {
        cnt++;
        for (int l = cnt; l < i; ++l) {
            dist = sqrt(pow(ptr[l].x - ptr[k].x,2) + pow(ptr[l].y - ptr[k].y, 2));
            if (minD == -1) minD = dist;
            else if (dist < minD) {
                minD = dist;
            }
        }
    }
    printf("Nejmensi vzdalenost: %lf\n", minD);
    cnt = 0;
    for (int k = 0; k < i - 1; ++k) {
        cnt++;
        for (int l = cnt; l < i; ++l) {
            dist = sqrt(pow(ptr[l].x - ptr[k].x,2) + pow(ptr[l].y - ptr[k].y, 2));
            if (fabs(dist - minD) <= DBL_EPSILON * 10000000 * fmax(dist, minD))
                printf("%s - %s\n", ptr[k].line, ptr[l].line);
            }
        }
    freeMem(ptr, i);
    return 0;
}