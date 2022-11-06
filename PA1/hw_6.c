#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct str_s {
    char * line;
    double num;
    int flag;
}str;
int cmp (const void * a, const void * b){
    return ((str*)a)->num > ((str*)b)->num;
}
char * lower (char * line, char * newline, int len){
    newline = (char*) malloc ((len+2)  * sizeof(char));
    for (int j = 0; j < len; ++j) {
        if (islower((int)line[j]))
            newline[j] = line[j];
        else newline[j] = tolower((int)line[j]);
    }
    newline[len] = '\0';
    return newline;
}
int main() {
    int size_s = 10, cnt_find = 0, i = 0, len = 0, k = 0, input, cnt = 0;
    unsigned long size_l = 10, size_find = 10;
    char c;
    char *res = NULL, *line = (char*)malloc(size_l * sizeof(char));
    str *arr = (str *) malloc(size_l * sizeof(*arr));
    printf("Casto hledane fraze:\n");
    while (1) {
            input = getline(&line, &size_l, stdin);
            line[input - 1] = '\0';
        if (input == 1) break;

        arr[i].flag = 0;
        arr[i].line = (char*) malloc (input * sizeof(arr[i].line));
        if(sscanf(line, "%lf %c %[^\n]s ", &arr[i].num, &c, arr[i].line) != 3 || c != ':'){
            for (int j = 0; j <= i; ++j)
                free(arr[j].line);
            free(arr);
            free(line);
            printf("Nespravny vstup.\n");
            return 1;
        }
        i++;
        if (i >= size_s) {
            size_s *= 2;
            arr = (str *) realloc(arr, size_s * sizeof(*arr));
        }
    }
    if (i < 1) {
        for (int j = 0; j <= i; ++j)
            free(arr[j].line);
        free(arr);
        free(line);
        printf("Nespravny vstup.\n");
            return 1;
    }
       qsort(arr, i, sizeof(arr[0]), cmp);
    printf("Hledani:\n");

    while (1) {
        char * find = (char *) malloc(size_find * sizeof(char));
        len = getline(&find, &size_find, stdin);
        if (len == EOF) {
            free(find);
            break;
        }
        find[len - 1] = '\0';
        k = 0;
        cnt_find = 0;
        while (k < i) {
            char * b = NULL;
            char * a = NULL;
            b = lower(find, b, strlen(find));
            a = lower(arr[k].line, a, strlen(arr[k].line));
            res = strstr(a, b);
            if (res != NULL) {
                cnt_find++;
                arr[k].flag = 1;
            }
            free(a);
            free(b);
            k++;
        }
        free(find);
        printf("Nalezeno: %d\n", cnt_find);
        cnt = 0;
        for (int j = i; j >= 0; --j) {
            if (arr[j].flag == 1){
                printf("> %s\n", arr[j].line);
                cnt++;
                arr[j].flag = 0;
                if (cnt == 50) break;
            }
        }

    }
    for (int j = 0; j < i; ++j) {
        free(arr[j].line);
    }
    free(arr);
    free(line);
    res = NULL;
    return 0;
}
