#include "operator/ImgToConvOperator.h"

ImgToConvOperator::ImgToConvOperator(const Tensor &tensor1, int channel, int dataRow, int dataCol, int kernelRow, int kernelCol,
                     int stride) : Operator(tensor1, 0), channel(channel), dataRow(dataRow), dataCol(dataCol),
                                   kernelRow(kernelRow), kernelCol(kernelCol), stride(stride){

}

Tensor ImgToConvOperator::operator()() {
	auto value = std::make_shared<Matrix<double, Dynamic, Dynamic, RowMajor>>(tensor1.row()*((dataRow-kernelRow)/stride+1)*((dataCol-kernelCol)/stride+1), kernelRow*kernelCol*channel);
	value->setZero();
#pragma omp parallel for collapse(2)
	for (int i = 0; i < tensor1.row(); ++i) {
		for (int j = 0; j < dataRow*dataCol; ++j) {
			int x = j / dataCol;
			int y = j % dataCol;
			for (int k = 0; k < kernelRow*kernelCol; ++k) {
				int kx = k / kernelCol;
				int ky = k % kernelCol;
				int kx0 = x - kx;
				int ky0 = y - ky;
				if (kx0 >= 0 && ky0 >= 0 && kx0 <= dataRow-kernelRow && ky0 <= dataCol-kernelCol && kx0 % stride == 0 && ky0 % stride == 0) {
					int n = kx0 / stride * ((dataRow-kernelRow)/stride+1) + ky0 / stride;
					for (int c = 0; c < channel; ++c) {
						(*value)(i*((dataRow-kernelRow)/stride+1)*((dataCol-kernelCol)/stride+1)+n, k+c*kernelRow*kernelCol) = tensor1(i, j+c*dataRow*dataCol);
					}
				}
			}
		}
	}
	return Tensor(value, shared_from_this());
}

void ImgToConvOperator::backward(Tensor &result) {
#pragma omp parallel for collapse(2)
	for (int i = 0; i < tensor1.row(); ++i) {
		for (int j = 0; j < dataRow*dataCol; ++j) {
			int x = j / dataCol;
			int y = j % dataCol;
			for (int k = 0; k < kernelRow*kernelCol; ++k) {
				int kx = k / kernelCol;
				int ky = k % kernelCol;
				int kx0 = x - kx;
				int ky0 = y - ky;
				if (kx0 >= 0 && ky0 >= 0 && kx0 <= dataRow-kernelRow && ky0 <= dataCol-kernelCol && kx0 % stride == 0 && ky0 % stride == 0) {
					int n = kx0 / stride * ((dataRow-kernelRow)/stride+1) + ky0 / stride;
					for (int c = 0; c < channel; ++c) {
						tensor1.grad()(i, j+c*dataRow*dataCol) += result.grad()(i*((dataRow-kernelRow)/stride+1)*((dataCol-kernelCol)/stride+1)+n, k+c*kernelRow*kernelCol);
					}
				}
			}
		}
	}
}
