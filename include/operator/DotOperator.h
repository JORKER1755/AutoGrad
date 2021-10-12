#ifndef DOTOPERATOR_H
#define DOTOPERATOR_H

#include "operator/Operator.h"

class DotOperator : public Operator {
public:
	DotOperator(const Tensor& tensor1, const Tensor& tensor2);
	Tensor operator()() override;
	void backward(Tensor& result) override;
};


#endif //DOTOPERATOR_H
