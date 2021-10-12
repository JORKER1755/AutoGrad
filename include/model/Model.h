#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "Tensor.h"

using std::vector;

class Model {
public:
	Tensor operator()(const Tensor& input);
	virtual Tensor forward(const Tensor& input) = 0;
	virtual ~Model() = default;
public:
	vector<Tensor> parameters;
};


#endif //MODEL_H
