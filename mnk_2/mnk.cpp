#include "mnk.h"
#include "method.h"
#include "cMatrix.h"
#include "cgauss.h"
#include "math.h"
using namespace std;

mnk::mnk()
{

}
mnk::mnk(double a1, double b1, int n1)
{
   mnk::a=a1;
   mnk::b=b1;
   mnk::n=n1;
}
double mnk::integration(int a1, int b1, int c1)
{
    int k=100;
    method temp(mnk::a,mnk::b,k);
    return temp.calc(a1,b1,c1)/(b-a);

}
 vector<vector<double>> mnk::matrix()
 {
     vector<vector<double>> temp;
     temp.resize(mnk::n+1);
     for(int i=0;i<=mnk::n;i++)
         temp[i].resize(mnk::n+1);
     for(int i=0;i<=mnk::n;i++)
         for(int j=0;j<=mnk::n;j++)
             temp[i][j]=integration(i,j,0);
     return temp;
 }
 vector<double> mnk::righside()
 {
     vector<double>test;
     test.resize(n+1);
     for(int i=0;i<=n;i++)
         test[i]=integration(i,0,1);
     return test;
 }
 vector<double> mnk::ans()
 {
     cMatrix mat(matrix());
     cGauss gauss(mat,righside());
     return gauss.operator ()();
 }
 double mnk::func(double x)
 {
     vector<double>temp=mnk::ans();
     double sum=0;
     method test(a,b,100);
     for(int i=0;i<=n;i++)
         sum+=test.fi(x,i)*temp[i];
     return sum;
 }
