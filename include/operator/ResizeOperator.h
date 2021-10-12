#ifndef RESIZEOPERATOR_H
#define RESIZEOPERATOR_H

#include "operator/Operator.h"

class ResizeOperator : public Operator {
public:
	ResizeOperator(const Tensor& tensor1, int rowNum, int colNum, bool isNew);
	Tensor operator()() override;
	void backward(Tensor& result) override;
private:
	bool isNew;
	int rowNum;
	int colNum;
};


#endif //RESIZEOPERATOR_H
