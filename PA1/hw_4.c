#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tub_str {
    int alt;
    int H;
    int W;
    int D;
    int V_tub;
    int relation;
}tub;
int compare (const void * x, const void * y){
    return ((tub*)x)->alt > ((tub*)y)->alt;
}
int main() {
    int N, err = 0, V;
    double  midH = 0, maxH, sumV = 0, sumVtmp = 0;
    printf("Zadejte pocet nadrzi:\n");
    if (scanf("%d", &N) != 1 || N <= 0 || N > 200000){
        printf("Nespravny vstup.\n");
        return 1;
    }
    tub * ptr = (tub*) malloc (N * sizeof(*ptr));
    printf("Zadejte parametry nadrzi:\n");
        for (int i = 0; i < N; ++i) {
            if (scanf("%d %d %d %d", &ptr[i].alt, &ptr[i].H, &ptr[i].W, &ptr[i].D) != 4
                                            || ptr[i].H <= 0 || ptr[i].W <= 0 || ptr[i].D <= 0) {
                printf("Nespravny vstup.\n");
                return 1;
            }
        }
        maxH = ptr[0].H + ptr[0].alt;
        for (int j = 1; j < N; ++j) {
            if (ptr[j].H + ptr[j].alt > maxH) maxH = ptr[j].H + ptr[j].alt;
        }
        for (int k = 0; k < N; ++k) {
            ptr[k].V_tub = ptr[k].H * ptr[k].D * ptr[k].W;
            ptr[k].relation = ptr[k].D * ptr[k].W;
            sumV += ptr[k].V_tub;
        }
        printf("Zadejte objem vody:\n");
        while ((err = scanf("%d", &V)) != EOF) {
        if (err != 1 || V < 0) {
            printf("Nespravny vstup.\n");
            return 1;
        }
        sumVtmp = sumV;
        if (V == 0)
            printf("Prazdne.\n");
        else {
            qsort(ptr, N, sizeof(ptr[0]), compare);
            if (V > sumV)
                printf("Pretece.\n");
            else if (V == sumV)
                printf("h = %lf\n", maxH);
            else {
                double top = maxH;
                double low = ptr[0].alt;

                while (fabs((double) (sumVtmp - V)) >= 0.0000001) {
                    midH = (double) (low + top) / 2;
                    sumVtmp = 0;
                    int flag = 0;
                    for (int j = 0; j < N; ++j) {
                        if (midH - ptr[j].alt > 0) {
                            if (midH >= ptr[j].alt + ptr[j].H) {
                                sumVtmp += ptr[j].V_tub;
                                if (fabs((double) (sumVtmp - V)) <= 0.0000001 && flag == 0)
                                    midH = ptr[j].H + ptr[j].alt;
                                continue;
                            }
                            sumVtmp += (midH - ptr[j].alt) * ptr[j].relation;
                            flag = 1;
                        }
                    }
                    if (sumVtmp > V) {
                        top = midH;
                    } else
                        low = midH;
                }
                printf("h = %.6lf\n", midH);
            }
        }
    }
    return 0;
}

