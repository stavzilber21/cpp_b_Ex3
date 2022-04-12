
#include <iostream>
#include <vector>
#include <string>
#include "Matrix.hpp"
//cd matrix-calculator-b
using namespace std;


namespace zich {
    Matrix::Matrix(const vector<double> &mat, int row, int col) {
        if (col <= 0 || row <= 0) {
            throw runtime_error("The col or row is not negative or zero");
        }
        if (mat.size() != row * col) {
            throw runtime_error("The size of vector must be row*col");
        }
        this->row = row;
        this->col = col;
        this->matrix = mat;
    }

    Matrix::Matrix(const Matrix &copy) {
        this->row = copy.row;
        this->col = copy.col;
        this->matrix = vector<double>(copy.matrix);
    }

//    Matrix::~Matrix() {
//        this->matrix.clear();
//    }

    void check_matrix(int row1, int col1, int row2, int col2) {
        if (row1 < 1 || row2 < 1 || col1 < 1 || col2 < 1) {
            throw runtime_error("The col or row is not negative or zero");
        }
        if (row1 != row2 || col1 != col2) {
            throw runtime_error("The col or row is not equal");
        }
    }

    double sum_matrix(Matrix mat1) {
        double sum = 0;
        for (size_t i = 0; i < mat1.getMat().size(); ++i) {
            sum += mat1.getMat().at(i);
        }
        return sum;
    }

    Matrix Matrix::operator+(const Matrix &mat1) {
        check_matrix(this->row, this->col, mat1.row, mat1.col);
        Matrix ans = {this->matrix, mat1.row, mat1.col};
        for (size_t i = 0; i < this->matrix.size(); i++) {
            ans.matrix.at(i)= this->matrix.at(i) + mat1.matrix.at(i);
        }
        return ans;
    }


    Matrix& Matrix::operator+=(const Matrix &mat1) {
        check_matrix(this->row, this->col, mat1.row, mat1.col);
        for (size_t i = 0; i < this->matrix.size(); i++) {
            this->matrix.at(i) += mat1.matrix.at(i);
        }
        return *this;
    }

    Matrix Matrix::operator+() {
        Matrix new_mat(*this);
        for (size_t i = 0; i < this->matrix.size(); i++) {
            new_mat.matrix.at(i) = (1) * this->matrix.at(i);
        }
        return new_mat;
    }

    Matrix Matrix::operator-(const Matrix &mat1) {
        check_matrix(this->row, this->col, mat1.row, mat1.col);
        Matrix ans = {this->matrix, mat1.row, mat1.col};
        for (size_t i = 0; i < this->matrix.size(); i++) {
            ans.matrix.at(i)=this->matrix.at(i)- mat1.matrix.at(i);
        }
        return ans;
    }

    Matrix& Matrix::operator-=(const Matrix &mat1) {
        check_matrix(this->row, this->col, mat1.row, mat1.col);
        for (size_t i = 0; i < this->matrix.size(); i++) {
            this->matrix.at(i)-= mat1.matrix.at(i);
        }
        return *this;
    }

    Matrix Matrix::operator-() {
        Matrix new_mat(*this);
        for (size_t i = 0; i < this->matrix.size(); i++) {
            new_mat.matrix.at(i) = (-1) * this->matrix.at(i);
        }
        return new_mat;
    }

    bool Matrix::operator<(const Matrix &mat1) const{
        Matrix mat(*this);
        check_matrix(mat.row, mat.col, mat1.row, mat1.col);
        return sum_matrix(mat) < sum_matrix(mat1);

    }

    bool Matrix::operator<=(const Matrix &mat1) const{
        Matrix mat(*this);
        check_matrix(mat.row, mat.col, mat1.row, mat1.col);
        return sum_matrix(mat) <= sum_matrix(mat1);
    }

    bool Matrix::operator>(const Matrix &mat1) const{
        Matrix mat(*this);
        check_matrix(mat.row, mat.col, mat1.row, mat1.col);
        return sum_matrix(mat) > sum_matrix(mat1);

    }

    bool Matrix::operator>=(const Matrix &mat1) const{
        Matrix mat(*this);
        check_matrix(mat.row, mat.col, mat1.row, mat1.col);
        return sum_matrix(mat) >= sum_matrix(mat1);

    }

    bool Matrix::operator!=(const Matrix &mat1) const{
        check_matrix(this->row, this->col, mat1.row, mat1.col);
//        return sum_matrix(*this) != sum_matrix(mat1);
//            return true;
//
        for (size_t i = 0; i < this->matrix.size(); ++i) {
            if(this->matrix.at(i)!=mat1.matrix.at(i)){
                return true;
            }
        }
        return false;
    }

    bool Matrix::operator==(const Matrix &mat1) const{
        check_matrix(this->row, this->col, mat1.row, mat1.col);
        if (sum_matrix(*this) != sum_matrix(mat1)){
            return false;
        }
        for (size_t i = 0; i < this->matrix.size(); ++i) {
            if(this->matrix.at(i)!=mat1.matrix.at(i)){
                    return false;
            }
        }
        return true;
    }

    Matrix& Matrix::operator++() {
        for (size_t i = 0; i < this->matrix.size(); ++i) {
            this->matrix.at(i) = this->matrix.at(i) + 1;
        }
        return *this;
    }

    Matrix& Matrix::operator--() {
        for (unsigned long i = 0; i < this->matrix.size(); ++i) {
            this->matrix.at(i) = this->matrix.at(i) - 1;
        }
        return *this;
    }
    Matrix Matrix::operator ++(int){
        Matrix mat_curr = (*this);
        for (size_t i = 0; i < this->matrix.size(); ++i) {
            this->matrix.at(i) = this->matrix.at(i) + 1;
        }
        return mat_curr;
    }
    Matrix Matrix::operator --(int){
        Matrix mat_curr = (*this);
        for (size_t i = 0; i < this->matrix.size(); ++i) {
            this->matrix.at(i) = this->matrix.at(i) - 1;
        }
        return mat_curr;
    }


    Matrix Matrix::operator*(const Matrix &mat1) {
        if (this->col != mat1.row) {
            throw runtime_error("col1 must be equal to row2");
        }
        vector<double> mat;
        for (unsigned long i = 0; i < this->row; i++) {
            for (unsigned long j = 0; j < mat1.col; j++) {
                double index = 0;
                for (unsigned long k = 0; k < this->col; k++) {
                    index += this->matrix.at((i * (unsigned long)this->col + k)) * mat1.matrix.at((k * (unsigned long)mat1.col + j));
                }
                mat.push_back(index);
            }
        }
        return {mat, this->row, mat1.col};
    }


    Matrix Matrix::operator*(const double n) {
        vector<double> mat;
        for (unsigned long i = 0; i < this->matrix.size(); ++i) {
                mat.push_back(this->matrix.at(i)*n);
        }
        Matrix ans = {mat, this->row, this->col};

        return ans;
    }

    Matrix operator*(const double n, const Matrix &mat1) {
        vector<double> mat;
        for (unsigned long i = 0; i < mat1.matrix.size(); ++i) {
            mat.push_back( n * mat1.matrix.at(i));
        }
        Matrix ans = {mat, mat1.row, mat1.col};
        return ans;
    }

    Matrix& Matrix::operator*=(const Matrix &mat1) {
        if (this->col != mat1.row) {
            throw runtime_error("col1 must be equal to row2");
        }
        *this = (*this) * mat1;
        return *this;

    }

    Matrix& Matrix::operator*=(const double n) {
        for (unsigned long i = 0; i < this->matrix.size(); ++i) {
            this->matrix.at(i) = this->matrix.at(i) * n;
        }
        return *this;
    }

    ostream &operator<<(ostream &out, const Matrix &mat) {
        for (unsigned long i = 0; i < mat.row; i++) {
            out << '[';
            for (unsigned long j = 0; j < mat.col; j++) {
                if(j==mat.col-1){
                    out << mat.matrix.at((i * (unsigned long)mat.col) + j) ;
                    out << ']';
                }
                else{
                    out <<mat.matrix.at((i * (unsigned long)mat.col) + j) << ' ';
                }

            }
            if(i!=mat.row-1){
                out << '\n';
            }

        }

        return out ;
    }

    istream &operator>>(istream &in, Matrix &mat1) {
        vector<double> mat;
        int idx_row=0;
        int idx_col=0;
        string str;
        char c=0;
        while(c!='\n'){
            c = in.get();
            str+=c;
        }
        for (unsigned long i = 0; i < str.length(); i++) {
            if(isdigit(str[i])!=0){
                mat.push_back(int(str[i]));
                idx_col++;
            }
            else if(str[i]==']'){
                idx_col=0;  //we finish column
            }
            else if(str[i]=='['){
                idx_row+=1;  //we add row and begin new row
            }
            else if(str[i]!=',' && str[i]!=' '){
                throw runtime_error("The character is invalid");
            }
            if(idx_col>mat1.col || idx_row>mat1.row){
                throw runtime_error("Exceeding the matrix limits");
            }

        }
        if(mat.size()!=mat1.matrix.size()){
            throw runtime_error("The quantities are not equal and this is an error");
        }

        mat1.matrix=mat;
        mat1.row =idx_row;
        mat1.col=idx_col;
        return in;
    }
}