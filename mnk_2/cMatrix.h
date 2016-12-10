#include <vector>

#define size_t unsigned int

#ifndef C_MATRIX_H
#define C_MATRIX_H

class cMatrix
{
public:
    cMatrix();
    cMatrix(size_t lines, size_t columns);
    cMatrix(std::vector<std::vector<double> > matrix);
    cMatrix(const cMatrix& rhs);
    ~cMatrix();

    std::vector<double>& operator[] (int index);

    size_t columns() const;
    size_t lines() const;

    std::vector<double>& back();
private:
    std::vector<std::vector<double> > _matrix;

    size_t _columns;
    size_t _lines;
};

#endif
