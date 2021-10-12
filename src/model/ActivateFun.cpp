#include "model/ActivateFun.h"


Tensor relu(const Tensor& t) {
	Tensor tmp(t.row(), t.col());
#pragma omp parallel
	for (int i = 0; i < tmp.row(); ++i) {
		for (int j = 0; j < tmp.col(); ++j) {
			if (t(i, j) > 0) {
				(*tmp)(i, j) = 1;
			}
		}
	}
	return t.dot(tmp);
}

Tensor sigmoid(const Tensor& t) {
	return (t.exp().pow(-1)+1).pow(-1);
}

Tensor softmax(const Tensor& t) {
	auto out = t - (*t).maxCoeff();
	Tensor tmp(t.col(), t.col());
	tmp.setOnes();
	return out.exp().dot((out.exp() * tmp).pow(-1));
}

Tensor tanh(const Tensor& t) {
	return sigmoid(t*2)*2-1;
}
