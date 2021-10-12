#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include <vector>
#include "Tensor.h"

using std::vector;

class Optimizer {
public:
	explicit Optimizer(const vector<Tensor>& parameters);
	void clearGradient();
	virtual void step() = 0;
	virtual ~Optimizer() = default;
protected:
	vector<Tensor> parameters;
};


#endif //OPTIMIZER_H
