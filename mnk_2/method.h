#ifndef METHOD_H
#define METHOD_H
#include <vector>
using namespace std;

class method
{
public:
    double fi(double x,int k);
    method();
    double h,a,b;
    int n;
    double countx(int i);
    double f(double x, int a, int b, int c);
    method(double a1,double b1,int n1);
    double calc(int a1, int b1, int c1);
//    int gauss (vector<vector<double>> a, vector<double> & ans);
};

#endif // METHOD_H
