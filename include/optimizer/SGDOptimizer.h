#ifndef SGDOPTIMIZER_H
#define SGDOPTIMIZER_H

#include "optimizer/Optimizer.h"

class SGDOptimizer : public Optimizer {
public:
	SGDOptimizer(const vector<Tensor>& parameters, double lr, double rho);
	void step() override;
private:
	vector<Tensor> v;
	double lr;
	double rho;
};


#endif //SGDOPTIMIZER_H
