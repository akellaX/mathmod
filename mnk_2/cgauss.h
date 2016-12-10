#define cVector std::vector<double>

#include "cMatrix.h"

#ifndef C_GAUSS_H
#define C_GAUSS_H

class cGauss
{
public:
    cGauss();
    cGauss(const cMatrix& matrix, const cVector& vector);
    ~cGauss();
    cVector operator()();
private:
    cMatrix* _matrix;
    cVector _vector;
    cVector _answer;

    void solve();
    double sum(size_t from, size_t to, size_t k);
};

#endif
