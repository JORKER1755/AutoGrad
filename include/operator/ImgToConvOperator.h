#ifndef IMGTOCONVOPERATOR_H
#define IMGTOCONVOPERATOR_H

#include "operator/Operator.h"

class ImgToConvOperator : public Operator {
public:
	ImgToConvOperator(const Tensor& tensor1, int channel, int dataRow, int dataCol, int kernelRow, int kernelCol, int stride);
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


#endif //IMGTOCONVOPERATOR_H
