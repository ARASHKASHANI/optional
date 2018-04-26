#include <iostream>

#include "optional.h"




experimental::optional<double> sqr_root(double x){

	experimental::optional<double> o;

	if (x > 0) {
		o = pow(x, 0.5);
	}

	return o;
}


int main(){

	experimental::optional<int> o(100);

	std::cout << o << std::endl;


	std::cout << sqr_root(4.0) << std::endl;
	std::cout << sqr_root(-4.0) << std::endl;


	try {

		auto a = sqr_root(4.0).getValue();
		auto b = sqr_root(-4.0).getValue();
	}

	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	











	return 0;
}