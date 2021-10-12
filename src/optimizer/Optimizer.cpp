#include "optimizer/Optimizer.h"

Optimizer::Optimizer(const vector<Tensor>& parameters) : parameters(parameters) {

}

void Optimizer::clearGradient() {
	for (auto& p : parameters) {
		p.clearGradient();
	}
}
