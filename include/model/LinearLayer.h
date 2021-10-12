#ifndef LINEARLAYER_H
#define LINEARLAYER_H

#include "Tensor.h"
#include "model/Model.h"

class Linear {
public:
	Linear(Model& m, int inputNum, int outputNum, bool base=true);
	Tensor operator()(const Tensor& input);
private:
	bool isBase;
	Tensor weight;
	Tensor base;
};


#endif //LINEARLAYER_H
