#ifndef __PROGTEST__
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#endif /* __PROGTEST__ */

void kod (double xMin, double xMax, double yMin, double yMax, double x, double y, int res[]){
    if(xMin - x <= DBL_EPSILON * 10)
        res[3] = 0 ;
    else res[3] =  1 ;
    if(x - xMax <= DBL_EPSILON * 10)
        res[2] = 0;
    else res[2] = 1;
    if(yMin - y <= DBL_EPSILON * 10)
        res[1] = 0;
    else res[1] = 1;
    if(y - yMax <= DBL_EPSILON * 10)
        res[0] = 0;
    else res[0] = 1;
}
void power (int res[], int *point){
    *point = 0;
    for (int i = 0, j = 8; i < 4; ++i, j /= 2) {
        if (res[i] == 1)
            *point += j;
    }
}
void cutLine (int point, double slope, double xMax, double xMin, double yMax, double yMin, double *x, double *y){

    if (point & 8){
        *x = *x + (yMax - *y) / slope;
        *y = yMax;
    }
    else if (point & 4){
        *x = *x + (yMin - *y) / slope;
        *y = yMin;
    }
    else if (point & 1){
        *y = *y + (xMin - *x) * slope;
        *x = xMin;
    }
    else if (point & 2){
        *y = *y + (xMax - *x) * slope;
        *x = xMax;
    }
}
int                clipLine                                ( double            rx1,
                                                             double            ry1,
                                                             double            rx2,
                                                             double            ry2,
                                                             double          * ax,
                                                             double          * ay,
                                                             double          * bx,
                                                             double          * by )
{
    double xMax, xMin, yMax, yMin, slope, x1 = *ax, y1 = *ay, x2 = *bx, y2 = *by;
    int res[4], res1[4], point1 = 0, point2 = 0;
    xMax = fmax(rx1, rx2);
    xMin = fmin(rx1, rx2);
    yMax = fmax(ry1, ry2);
    yMin = fmin(ry1, ry2);
    kod(xMin, xMax, yMin, yMax, x1, y1, res);
    kod(xMin, xMax, yMin, yMax, x2, y2, res1);
    power(res, &point1);
    power(res1, &point2);

    if ((point1 == point2) && point1 == 0)
        return 1;
    slope = (y2 - y1) / (x2 - x1);
    if ((point1 & point2) != 0)
        return 0;

    while (point1 != 0) {
        if ((point1 & point2) != 0) return 0;
        cutLine(point1, slope, xMax, xMin, yMax, yMin, &x1, &y1);
        kod(xMin, xMax, yMin, yMax, x1, y1, res);
        power(res, &point1);
    }
    if ((point1 & point2) != 0)
        return 0;
    *ax = x1;
    *ay = y1;
    while (point2 != 0) {
        if ((point1 & point2) != 0) return 0;
        cutLine(point2, slope, xMax, xMin, yMax, yMin, &x2, &y2);
        kod(xMin, xMax, yMin, yMax, x2, y2, res);
        power(res, &point2);
    }
    *bx = x2;
    *by = y2;
    return 1;
}

int                almostEqual                             ( double            x,
                                                             double            y )
{
    if (x - y <= DBL_EPSILON * 10)
        return 1;
    else
        return 0;
}

