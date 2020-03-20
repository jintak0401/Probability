#include "Least_Square.h"
#include <stdlib.h>
#include <math.h>                           /* math functions */

inline static double sqr(double x) {
    return x * x;
}

int leastSquare(int n, int x[], int y[], double* m, double* b, double* r){
    double  sumx = 0.0;                      /* sum of x     */
    double  sumx2 = 0.0;                     /* sum of x**2  */
    double  sumxy = 0.0;                     /* sum of x * y */
    double  sumy = 0.0;                      /* sum of y     */
    double  sumy2 = 0.0;                     /* sum of y**2  */

    for (int i = 0; i < n; i++){ 
        sumx  += x[i];       
        sumx2 += sqr(x[i]);  
        sumxy += x[i] * y[i];
        sumy  += y[i];      
        sumy2 += sqr(y[i]); 
    } 

    double denom = (n * sumx2 - sqr(sumx));
    if (denom == 0) {
        *m = 0;
        *b = 0;
        if (r) *r = 0;
            return 0;
    }

    *m = (n * sumxy  -  sumx * sumy) / denom;
    *b = (sumy * sumx2  -  sumx * sumxy) / denom;
    if (r!=NULL) {
        *r = (sumxy - sumx * sumy / n) /    /* compute correlation coeff */
              sqrt((sumx2 - sqr(sumx)/n) *
              (sumy2 - sqr(sumy)/n));
    }

    return 1; 
}

