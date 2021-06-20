#ifndef OPTIMIZER_TYPES
#define OPTIMIZER_TYPES

#include <iostream>
#include <functional>
#include <Eigen/Dense>

namespace optimizer{
    /// Default Scalar type
    typedef float Scalar;

    /// Defalt Matrix type
    typedef Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> Matrix;

    /// Default Vector type
    typedef Eigen::Matrix<Scalar, Eigen::Dynamic, 1> Vector;

    /// Default Function prototype
    typedef std::function<Matrix (const Matrix &x) > Function;

    /// Result info
    enum Status{
        SUCCESS,
        ERROR
    };

    /// Dimension of function inputs and outputs
    struct Dims
    {
        int x_rows;
        int x_cols;
        int y_rows;
        int y_cols;

        inline Dims(int _x_rows, int _x_cols, int _y_rows, int _y_cols)
        :x_rows(_x_rows),x_cols(_x_cols),y_rows(_y_rows),y_cols(_y_cols){}
    };
    
}
#endif