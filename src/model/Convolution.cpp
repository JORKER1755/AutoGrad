#include "model/Convolution.h"
#include "operator/MaxPoolOperator.h"


Convolution::Convolution(Model &m, int inputChannel, int outputChannel, int dataRow, int dataCol, int kernelRow, int kernelCol,
                         int stride, bool base) : linear(m, inputChannel*kernelRow*kernelCol, outputChannel, base), inputChannel(inputChannel),
                         dataRow(dataRow), dataCol(dataCol), kernelRow(kernelRow), kernelCol(kernelCol), stride(stride){

}

// Convert convolution to matrix multiplication
Tensor Convolution::operator()(const Tensor &input) {
	Tensor output = (*shared_ptr<Operator>(new ImgToConvOperator(input, inputChannel, dataRow, dataCol, kernelRow, kernelCol, stride)))();		
	output = linear(output);		
	output = (*shared_ptr<Operator>(new ConvToImgOperator(output, ((dataRow-kernelRow)/stride+1)*((dataCol-kernelCol)/stride+1))))();			
	return output;
}

Tensor maxPool(const Tensor& t, int channel, int dataRow, int dataCol, int kernelRow, int kernelCol, int stride) {
	return (*shared_ptr<Operator>(new MaxPoolOperator(t, channel, dataRow, dataCol, kernelRow, kernelCol, stride)))();
}
