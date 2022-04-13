#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;
namespace zich{
    class Matrix {
    private:
        int row;
        int col;
        vector<double> matrix;
    public:
        Matrix(const vector<double> &mat, int row, int col);
        Matrix(Matrix const & copy);



        Matrix operator+(Matrix const &mat1);
        Matrix& operator+=(Matrix const &mat1);
        Matrix operator+();

        Matrix operator- (Matrix const &mat1);
        Matrix& operator-= (Matrix const &mat1);
        Matrix operator-();

        bool operator< (Matrix const &mat1)const;
        bool operator<= (Matrix const &mat1)const;
        bool operator> (Matrix const &mat1)const;
        bool operator>= (Matrix const &mat1)const;
        bool operator!=(Matrix const &mat1)const;
        bool operator== (Matrix const &mat1)const;

        Matrix& operator++ ();
        Matrix& operator-- ();

        Matrix operator ++(int);
        Matrix operator --(int);

        Matrix operator* (Matrix const &mat1);
        Matrix operator* (const double n);
        friend Matrix operator* (const double n,Matrix const &mat1);

        Matrix& operator*= (Matrix const &mat1);
        Matrix& operator*= (const double n);

        friend ostream &operator<<(ostream &out, Matrix const &mat1);
        friend istream &operator>>(istream &in, Matrix &mat);

    int getRow(){
        return row;
    }

    int getCol(){
        return col;
    }

    vector<double> getMat(){
        return matrix;
    }

    };
}