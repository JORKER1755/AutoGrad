#ifndef MAXPOOLOPERATOR_H
#define MAXPOOLOPERATOR_H

#include "operator/Operator.h"

class MaxPoolOperator : public Operator {
public:
	MaxPoolOperator(const Tensor& tensor1, int channel, int dataRow, int dataCol, int kernelRow, int kernelCol, int stride);
	Tensor operator()() override;
	void backward(Tensor& result) override;
private:
	int channel;
	int dataRow;
	int dataCol;
	int kernelRow;
	int kernelCol;
	int stride;
};


#endif //MAXPOOLOPERATOR_H
