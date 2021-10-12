#include "model/Model.h"

Tensor Model::operator()(const Tensor &input) {
	return forward(input);
}
