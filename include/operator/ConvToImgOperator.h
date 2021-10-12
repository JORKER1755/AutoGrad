#ifndef CONVTOIMGOPERATOR_H
#define CONVTOIMGOPERATOR_H

#include "operator/Operator.h"

class ConvToImgOperator : public Operator {
public:
	ConvToImgOperator(const Tensor& tensor1, int num);
	Tensor operator()() override;
	void backward(Tensor& result) override;
private:
	int num;
};


#endif //CONVTOIMGOPERATOR_H
