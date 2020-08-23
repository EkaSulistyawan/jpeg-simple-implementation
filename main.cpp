/*
 * Self Implementation of JPEG
 * */

#include <vector>
#include <iostream>
#include <math.h>

#include "jpeg.hpp"

int main(){
	//	8 x 8 Grayscale format pixel matrix
	std::vector<std::vector<int> > data = 
	{
		{90,100},
		{100,105}
	};
	JPEG instance;
	std::vector<std::vector<double> > res = instance.dct(data);
	for(int i = 0;i < res.size();i++){
		for(int j =0;j<res[0].size();j++){
			std::cout << res[i][j] << " ";
		}
		std::cout << "\n";
	}
}
