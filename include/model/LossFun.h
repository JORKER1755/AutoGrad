#ifndef LOSSFUN_H
#define LOSSFUN_H

#include "Tensor.h"

Tensor MSELoss(Tensor& pred, Tensor& label);
Tensor crossEntropyLoss(Tensor& pred, Tensor& label);

#endif //LOSSFUN_H
