#include "matrix.h"

using namespace std;

Matrix::Matrix(vector<float>::size_type i_rows, vector<float>::size_type i_cols) {
    rows = i_rows;
    cols = i_cols;
    grid = vector< vector <float> >(rows, vector <float>(cols, 0.5));
}

Matrix::Matrix(vector< vector <float> > a_matrix) {
    grid = a_matrix;
    rows = a_matrix.size();
    cols = a_matrix[0].size();
}

void Matrix::setGrid(vector< vector <float> > a_matrix) {
    grid = a_matrix;
    rows = a_matrix.size();
    cols = a_matrix[0].size();
}

vector<float>::size_type Matrix::get_rows() {
    return rows;
}
vector<float>::size_type Matrix::get_cols() {
    return cols;
}

vector< vector <float> > Matrix::get_grid() {
    return grid;    
}

Matrix Matrix::matrix_addition(Matrix other) {
    vector< vector <float> > result;
    vector <float> result_rows;
    if(rows != other.get_rows() || cols != other.get_cols()){
        throw std::invalid_argument("matrices are not the same size");
    }

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            result_rows.push_back(grid[i][j] + other.get_grid()[i][j]);
        }
        result.push_back(result_rows);
        result_rows.clear();
    }
    return Matrix(result);
}

Matrix Matrix::matrix_transpose() {
    std::vector< std::vector<float> > new_grid;
    std::vector<float> row;

    for (int i = 0; i < cols; i++) {
        row.clear();

        for (int j = 0; j < rows; j++) {
            row.push_back(grid[j][i]); 
        }
        new_grid.push_back(row);
    }

    return Matrix(new_grid);
}

void Matrix::matrix_print() {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}