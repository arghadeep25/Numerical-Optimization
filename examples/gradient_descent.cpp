/*
 * The objective of this example to demonstrate the computation
 * of local extremum of a second order multivariate polynomial
 * using gradient descent.
 *
 * f(x,y) = x^2 + y^2 + 2x +  8y
 *
 * The first order derivative is given by
 * df/dx = 2x + 2
 * df/dy = 2y + 8
 *
 * The global minimum of the function is at (-1, -4)
 *
 * */
#include <iomanip>
#include "gradient_decent.hpp"

int main(){
    /// First order derivative
    optimizer::Function df = [](const optimizer::Matrix &mat) -> optimizer::Matrix {
        optimizer::Matrix m(2,1);
        m(0) = 2.f * mat(0) + 2.f; // df/dx
        m(1) = 2.f * mat(1) + 8.f; // df/dy

        return m;
    };
    /// Random Guess to initiate gradient descent
    optimizer::Matrix x(2, 1);
    x(0) =30.f;
    x(1) = -2.f;

    optimizer::Status status = optimizer::SUCCESS;
    while (status == optimizer::SUCCESS && df(x).norm() > 0.001f){
        status = optimizer::gradientDescent(df, x, 0.01f);
        std::cout
        << std::fixed << std::setw(3) <<"Parameters: "
        << x.transpose() << " Error: " << df(x).norm() << std::endl;
    }
    return 0;
}