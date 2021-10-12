#ifndef TRANSPOSEOPERATOR_H
#define TRANSPOSEOPERATOR_H

#include "operator/Operator.h"

class TransposeOperator : public Operator {
public:
	TransposeOperator(const Tensor& tensor1, bool isNew);
	Tensor operator()() override;
	void backward(Tensor& result) override;
private:
	bool isNew;
};


#endif //TRANSPOSEOPERATOR_H
