#include "method.h"
#include <QDebug>

#define EPS 1e-3
#define INF 10000000

method::method()
{

}

method::method(double a1, double b1,int n1)
{
   method:: a=a1;
   method::b=b1;
   method::n=n1;
   method:: h=(method::b-method::a)/(2*method::n);
}
double method::fi(double x, int k)
{

//    if(k==0)
//        return 1;
//    else return sin(k*x);


    return pow(x,k);

}

double method::f(double x,int a,int b,int c)
{
    double s=x*sin(x)+cos(x);
    return pow(s,c)*fi(x,a)*fi(x,b);
}

double method::countx(int i)
{
    return a+i*h;
}

double method::calc(int a1,int b1,int c1)
{

    double a=0;
    double b=0;
    for(int i=1;i<=n-1;i++)
    {
        a=a+f((countx(2*i-1)),a1,b1,c1);
        b+=f((countx(2*i)),a1,b1,c1);
    }

    a+=f((countx(2*method::n-1)),a1,b1,c1);
    return method::h/3*(4*a+2*b+f(countx(2*method::n),a1,b1,c1)+f(countx(0),a1,b1,c1));


}
//int gauss (vector < vector<double> > a, vector<double> & ans) {
//    int n = (int) a.size();
//    int m = (int) a[0].size() - 1;

//    vector<int> where (m, -1);
//    for (int col=0, row=0; col<m && row<n; ++col) {
//        int sel = row;
//        for (int i=row; i<n; ++i)
//            if (abs (a[i][col]) > abs (a[sel][col]))
//                sel = i;
//        if (abs (a[sel][col]) < EPS)
//            continue;
//        for (int i=col; i<=m; ++i)
//            swap (a[sel][i], a[row][i]);
//        where[col] = row;

//        for (int i=0; i<n; ++i)
//            if (i != row) {
//                double c = a[i][col] / a[row][col];
//                for (int j=col; j<=m; ++j)
//                    a[i][j] -= a[row][j] * c;
//            }
//        ++row;
//    }

//    ans.assign (m, 0);
//    for (int i=0; i<m; ++i)
//        if (where[i] != -1)
//            ans[i] = a[where[i]][m] / a[where[i]][i];
//    for (int i=0; i<n; ++i) {
//        double sum = 0;
//        for (int j=0; j<m; ++j)
//            sum += ans[j] * a[i][j];
//        if (abs (sum - a[i][m]) > EPS)
//            return 0;
//    }

//    for (int i=0; i<m; ++i)
//        if (where[i] == -1)
//            return INF;
//    return 1;
//}

