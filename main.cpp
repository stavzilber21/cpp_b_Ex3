
/**
 * Demo file for the exercise on numbers with units
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 *
 * Edited by Tal Zichlinsky
 * @since 2022-02
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Matrix.hpp"
using namespace zich;

int main() {

//    std::vector<double> vec7 = {1,2,3,4};
//    std::vector<double> vec8 = {1,2,3,4,5,6};
//    Matrix a{vec7, 2, 2};
//    Matrix b{vec8, 2, 3};
//
//    cout << (a*b) << endl;
//    std::vector<double> vec7 = {1,2,3,1,2,3};
//    std::vector<double> vec8 = {2,3};
//    Matrix a{vec7, 3, 2};
//    Matrix b{vec8, 2, 1};
//
//    cout << (a++) << endl;
//    cout << (a) << endl;

//    CHECK(mat5*9 == mat7*4 );

//     vector<double> vec = {0,0};
//     Matrix mat1 = Matrix(vec,1,2);

       std::vector<double> unit_matrix = {1, 0, 0, 0, 1, 0, 0, 0, 1};
       Matrix mat1{unit_matrix,3,3};
       istringstream is7{"[1 1 1 1], [1 1 1 1], [1 1 1 1]\n"};
       is7 >> mat1;
       std::cout << mat1 << endl;

    return 0;
}