/**
 * JPEG hpp
 * */
#pragma once

#include <iostream>
#include <vector>

class JPEG final{
	private:
		double ccons(int _a);
	public:
		JPEG();
		std::vector<std::vector<double> > dct(std::vector<std::vector<int> > small_f);
};
