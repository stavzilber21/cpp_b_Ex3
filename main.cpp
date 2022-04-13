
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

    std::vector<double> vec7 = {1,2,3,4};
    std::vector<double> vec8 = {1,2,3,4,5,6};
    Matrix a{vec7, 2, 2};
    Matrix b{vec8, 2, 3};

    cout << (a*b) << endl;




    return 0;
}