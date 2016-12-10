#include "cMatrix.h"



cMatrix::cMatrix()
{
}

cMatrix::cMatrix(size_t lines, size_t columns):
    _lines{lines},
    _columns{columns}
{
    _matrix.resize(lines);
    for (size_t i = 0; i < lines; ++i) {
        _matrix[i].resize(columns, 0);
    }
}

cMatrix::cMatrix(std::vector<std::vector<double> > matrix) :
    _matrix{ matrix },
    _lines{matrix.size()},
    _columns{matrix[0].size()}
{}

cMatrix::cMatrix(const cMatrix& rhs) {
    _matrix = rhs._matrix;
    _columns = rhs._columns;
    _lines = rhs._lines;
}

cMatrix::~cMatrix()
{
    //pass
}

std::vector<double>& cMatrix::operator[](int index)
{
    if (index < 0) {
        index += _columns;
    }

    if (index < 0) {
        throw std::exception();
    }

    if (index >= _columns) {
        throw std::exception();
    }

    return (_matrix[index]);
}

size_t cMatrix::columns() const
{
    return _columns;
}

size_t cMatrix::lines() const
{
    return _lines;
}

std::vector <double>& cMatrix::back()
{
    return _matrix.back();
}
