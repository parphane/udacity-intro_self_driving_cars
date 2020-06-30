#ifndef MATRIX_H

#define MATRIX_H

#include <iostream>
#include <vector>

class Matrix
{
    private:
        std::vector< std::vector <float> > grid;
        std::vector<float>::size_type rows;
        std::vector<float>::size_type cols;

    public:
        Matrix (std::vector<float>::size_type i_rows = 10, std::vector<float>::size_type i_cols = 5);
        Matrix (std::vector< std::vector <float> >);

        void setGrid(std::vector< std::vector <float> >);        

        std::vector< std::vector <float> > get_grid();
        std::vector<float>::size_type get_rows();
        std::vector<float>::size_type get_cols();

        Matrix matrix_addition(Matrix);
        Matrix matrix_transpose();

        void matrix_print();

};

#endif /* MATRIX_H */