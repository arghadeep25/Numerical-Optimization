#ifndef OPTIMIZER_GRADIENT_DESCENT
#define OPTIMIZER_GRADIENT_DESCENT

#include "types.hpp"

namespace optimizer{
    Status gradientDescent(const Function &func, Matrix &mat, Scalar step){
        mat = mat- step * func(mat);
        return SUCCESS;
    }
}

#endif