#ifndef ACTIVATEFUN_H
#define ACTIVATEFUN_H

#include "Tensor.h"

Tensor relu(const Tensor& t);
Tensor sigmoid(const Tensor& t);
Tensor softmax(const Tensor& t);
Tensor tanh(const Tensor& t);

#endif //ACTIVATEFUN_H
