#include "cGauss.h"

cGauss::cGauss()
{
    _matrix = nullptr;
}

cGauss::cGauss(const cMatrix& matrix, const cVector& vector)
{
    _matrix = new cMatrix(matrix);
    _vector = vector;
    _answer.resize(vector.size(), 0);
}

cGauss::~cGauss()
{
    delete _matrix;
    _matrix = nullptr;
}

cVector cGauss::operator()() {
    solve();
    return _answer;
}

void cGauss::solve()
{
    for (size_t k = 0; k < _matrix->lines() - 1; ++k) {
        for (size_t i = k + 1; i < _matrix->columns(); ++i) {
            double t = (*_matrix)[i][k] / (*_matrix)[k][k];
            _vector[i] -= t*_vector[k];
            for (size_t j = k ; j < _matrix->columns(); ++j) {
                (*_matrix)[i][j] -= t*(*_matrix)[k][j];
            }
        }
    }
    _answer.back() = _vector.back() / _matrix->back().back();
    for (int k = _matrix->lines() - 2; k >= 0; --k) {
        _answer[k] = 1 / (*_matrix)[k][k]*(_vector[k] - sum(k + 1, _vector.size() - 1, k));
    }
}

double cGauss::sum(size_t from, size_t to, size_t k) {
    double _sum = 0;
    for (size_t i = from; i <= to; ++i) {
        _sum += (*_matrix)[k][i] * _answer[i];
    }
    return _sum;
}
