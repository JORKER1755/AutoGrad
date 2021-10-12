#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include "Tensor.h"
#include "model/Model.h"
#include "model/LinearLayer.h"
#include "operator/ImgToConvOperator.h"
#include "operator/ConvToImgOperator.h"

class Convolution {
public:
	Convolution(Model& m, int inputChannel, int outputChannel, int dataRow, int dataCol, int kernelRow, int kernelCol, int stride=1, bool base=true);
	Tensor operator()(const Tensor& input);
private:
	int inputChannel;
	int dataRow;
	int dataCol;
	int kernelRow;
	int kernelCol;
	int stride;
	Linear linear;		// store kernel's weights
};


Tensor maxPool(const Tensor& t, int channel, int dataRow, int dataCol, int kernelRow, int kernelCol, int stride=1);


#endif //CONVOLUTION_H
