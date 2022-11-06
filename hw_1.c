#include <stdio.h>
#include <math.h>
#include <float.h>


int netvori (double a, double b, double c){
    if (((a + b - c <  DBL_EPSILON * 100 * c)
         || (b + c - a < DBL_EPSILON * 100 * a)
         || (a + c - b < DBL_EPSILON * 100 * b))
         || (a <=0 || b <= 0 || c <= 0))
        return 1;
    return 0;
}
int shodnost (double a, double b, double c, double a1, double b1, double c1){
    if ( (fabs(a - a1) < (DBL_EPSILON * a * 100) && (fabs(b - b1) < (DBL_EPSILON * b * 100)) && (fabs(c - c1) < (DBL_EPSILON * a  * 100)))
         || (fabs(a - a1) < (DBL_EPSILON * a * 100) && (fabs(b - c1) < (DBL_EPSILON * b * 100)) && (fabs(c - b1) < (DBL_EPSILON * c * 100)))

         || (fabs(a - b1) < (DBL_EPSILON * a * 100) && (fabs(b - a1) < (DBL_EPSILON * b * 100)) && (fabs(c - c1) < (DBL_EPSILON * c * 100)))
         || (fabs(a - b1) < (DBL_EPSILON * a * 100) && (fabs(b - c1) < (DBL_EPSILON * b * 100)) && (fabs(c - a1) < (DBL_EPSILON * c * 100)))

         || (fabs(a - c1) < (DBL_EPSILON * a * 100) && (fabs(b - a1) < (DBL_EPSILON * b * 100)) && (fabs(c - b1) < (DBL_EPSILON * c * 100)))
         || (fabs(a - c1) < (DBL_EPSILON * a * 100) && (fabs(b - b1) < (DBL_EPSILON * b * 100))  && (fabs(c - a1) < (DBL_EPSILON * c * 100))) )
        return 1;
    return 0;
}
void swap (double a, double b, double c, double *min, double *mid, double *max){

    if (a > b && a > c) *max = a;
    else if (b > a && b > c) *max = b;
    else *max = c;

    if (a < b && a < c) *min = a;
    else if (b < a && b < c) *min = b;
    else *min = c;

    if (a > *min && a < *max) *mid = a;
    else if (b > *min && b < *max) *mid = b;
    else *mid = c;
}
int porovnej (double side1, double side2){
    if (fabs(side1 - side2) <= (DBL_EPSILON * 100 * fmax(side1, side2))) return 1;
    return 0;
}
int podobnost (double a, double b, double c, double a1, double b1, double c1){

   double x, y ,z, min, mid, max;
   swap(a , b, c, &min, &mid, &max);
    a = min;
    b = mid;
    c = max;
   swap(a1 , b1, c1, &min, &mid, &max);
    a1 = min;
    b1 = mid;
    c1 = max;
   x = a/a1;
   y = b/b1;
   z = c/c1;
   if(porovnej(x,y) && porovnej(x, z) && porovnej(y, z))
            return 1;
    return 0;
}
int main() {
    double a, b ,c, a1, b1, c1;
    char s1, s2, s3;

    printf("Trojuhelnik #1:\n");

    if (scanf(" %c%c%c %lf %lf %lf", &s1, &s2, &s3, &a, &b, &c) != 6
                        || a <= 0 || b <= 0 || c <= 0) {
        printf("Nespravny vstup.\n");
        return 1;
    }
    if (s1 == 'S' && s2 == 'S' && s3 == 'S');
    else if (s1 == 'S' && s2 == 'U' && s3 == 'S'){
        if (b >= 180){
            printf("Nespravny vstup.\n");
            return 1;
        }
        b = sqrt(a*a + c*c - 2*a*c*cos(b*M_PI/180));
    }
    else if (s1 == 'U' && s2 == 'S' && s3 == 'U'){
        if (a >= 180 || c >= 180){
            printf("Nespravny vstup.\n");
            return 1;
        }
        if (a + c >= 180){
            printf("Vstup netvori trojuhelnik.\n");
            return 1;
        }
        double anew = a;
        a = b*(sin(a*M_PI/180))/sin((180 - c - a)*M_PI/180);
        c = b*(sin(c*M_PI/180))/sin((180 - c - anew)*M_PI/180);
    }
    else {
        printf("Nespravny vstup.\n");
        return 1;
    }
    if (netvori(a, b, c)){
        printf("Vstup netvori trojuhelnik.\n");
        return 1;
    }
    printf("Trojuhelnik #2:\n");
    if (scanf(" %c%c%c %lf %lf %lf", &s1, &s2, &s3, &a1, &b1, &c1) != 6
                        || a1 <= 0 || b1 <= 0 || c1 <= 0) {
        printf("Nespravny vstup.\n");
        return 1;
    }
    if (s1 == 'S' && s2 == 'S' && s3 == 'S');
    else if (s1 == 'S' && s2 == 'U' && s3 == 'S'){
        if (b1 >= 180){
            printf("Nespravny vstup.\n");
            return 1;
        }
        b1 = sqrt(a1*a1 + c1*c1 - 2*a1*c1*cos(b1*M_PI/180));
    }
    else if (s1 == 'U' && s2 == 'S' && s3 == 'U'){
        if (a1 >= 180 || c1 >= 180){
            printf("Nespravny vstup.\n");
            return 1;
        }
        if (a1 + c1 >= 180){
            printf("Vstup netvori trojuhelnik.\n");
            return 1;
        }
        double anew = a1;
        a1 = b1*(sin(a1*M_PI/180))/sin((180 - c1 - a1)*M_PI/180);
        c1 = b1*(sin(c1*M_PI/180))/sin((180 - c1 - anew)*M_PI/180);
    }
    else {
        printf("Nespravny vstup.\n");
        return 1;
    }
    if (netvori(a1, b1, c1)){
        printf("Vstup netvori trojuhelnik.\n");
        return 1;
    }
    if (shodnost(a, b, c, a1, b1, c1))
        printf("Trojuhelniky jsou shodne.\n");
    else if (podobnost(a, b, c, a1, b1, c1))
        printf("Trojuhelniky nejsou shodne, ale jsou podobne.\n");
    else
        printf("Trojuhelniky nejsou shodne ani podobne.\n");
    return 0;
}
/*SUS 384 11.828209939359610 179
 * USU 11.828209939359546 874.487321915959 158.205366635469773*/