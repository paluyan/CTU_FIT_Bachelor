#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long long int divUp (long long int x, long long int y){
    return x/y + (x % y != 0);
}
void toBase (long long int a, long long int base, long long int * cnt, char ** aBased){
    long long int base_pw = base;
    *cnt = 1;
    while ( base_pw <= a) {
        (*cnt)++;
        base_pw *= base;
    }

    *aBased = (char *) malloc(*cnt);
    base_pw /= base;
    for (long long int i = 0; i < *cnt ; i++) {
        (*aBased)[i] = (char) (a/base_pw);
        a %= base_pw;
        base_pw /= base;
    }
}
long long int rev (long long int N, int base){
    long long int res = 0;
    for ( ; N > 0; N /= base) {
        res = res * base + N % base;
    }
    return res;
}

char palPossible(const char * based, long long int n) {
    for (long long int i = 0; i < n/2; i++) {
        if (based[n/2-i-1] < based[divUp(n,2)+i])
            return 0;
        if (based[n/2-i-1] > based[divUp(n,2)+i])
            return 1;
    }
    return 1;
}

int main() {
    int base, err, tmp;
    long long int hi, lo, cnt = 0, res = 0;
    char c;
    printf("Vstupni intervaly:\n");
    while ((err = scanf(" %c %d %lld %lld", &c, &base, &lo, &hi)) != EOF){
        if (err != 4 || (c != 'l' && c != 'c')
                     || base > 36 || base < 2 || lo > hi || lo < 0){
            printf("Nespravny vstup.\n");
            return 1;
        }
        else if (c == 'c') {
            char *loBased = NULL;
            char *hiBased = NULL;
            long long nLo = 0;
            long long nHi = 0;
            toBase(lo,base, &nLo, &loBased);
            toBase(hi,base, &nHi, &hiBased);

            cnt = 0;
            for (long long int ni=nLo+1; ni < nHi +1; ni++) {
                cnt += (base-1)*(long long int) pow(base,(double) (divUp(ni,2)-1));
            }

            for (long long i=0; i < divUp(nLo,2); i++) {
                cnt += (base-loBased[i]-1)*(long long int) pow(base,(double) (divUp(nLo,2)-i -1));
            }
            for (long long i=0; i < divUp(nHi,2); i++) {
                cnt -= (base-hiBased[i]-1)*(long long int) pow(base,(double) (divUp(nHi,2)-i -1));
            }

            cnt += palPossible(loBased,nLo);
            cnt -= palPossible(hiBased,nHi);
            cnt += hi == rev(hi,base);

            free(loBased);
            free(hiBased);
            printf("Celkem: %lld\n", cnt);
            continue;
        }
        else if (base <= 10){
            while (lo <= hi) {
                res = rev(lo, base);
                if (res == lo) {
                    if (c == 'l') {
                        if (lo == 0)
                            printf("%lld = %lld", lo, lo);
                        else
                            printf("%lld = ", lo);
                        while (res > 0) {
                            printf("%lld", res % base);
                            res /= base;
                        }
                        printf(" (%d)\n", base);
                    }
                }
                lo++;
             }
        } else if (base > 10) {
            while (lo <= hi) {
                res = rev(lo, base);
                if (res == lo){
                  if (c == 'l'){
                      if (lo == 0)
                          printf("%lld = %lld", lo, lo);
                      else
                          printf("%lld = ", lo);
                      while (res > 0) {
                          tmp = res % base;
                          if (tmp < 10)
                              tmp += 48;
                          else
                              tmp += 87;
                          printf("%c", (char)tmp);
                          res /= base;
                      }
                      printf(" (%d)\n", base);
                  }
                }
                lo++;
            }
        }
    }
    return 0;
}