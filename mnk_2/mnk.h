#ifndef MNK_H
#define MNK_H
using namespace std;
#include "method.h"



class mnk
{
public:
    mnk();
    mnk(double a1,double b1,int n1);
    double a,b;
    int n;
    double integtare();
    vector<vector<double>> matrix();
    vector<double> righside();
    vector<double> ans();
    double integration(int a1, int b1, int c1);
    double func(double x);



};

#endif // MNK_H
