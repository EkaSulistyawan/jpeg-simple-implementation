/*
 * Self Implementation of JPEG
 * */

#include <vector>
#include <iostream>
#include <math.h>

#include "jpeg.hpp"

#define PI 3.141592653589793238

/**
 * PRIVATE
 * */

double JPEG::ccons(int _a){
	if(_a == 0) return 1.0/sqrt(2.0);
	else return 1.0;
}


/**
 * PUBLIC
 * */
 JPEG::JPEG(){};


//	8 x 8 matrices input
std::vector<std::vector<double> > JPEG::dct(std::vector<std::vector<int> > small_f){
	//	fetch matrix dimention
	int N = small_f.size();
	int M = small_f[0].size(); 
	//	Row -> N
	//	col -> M
	std::vector<double> matxM(M, 0.0);
	std::vector<std::vector<double> > big_F (N, matxM);
	//
	//	calculate  DCT
	try{
		for(int u =0;u < N;u++){
			for(int v = 0;v < M;v++){
				double _temp = 0.0;
				double _c = 2 * ccons(u) * ccons(v) / sqrt(M*N);
				for(int i = 0; i < N; i++){
					for(int j = 0;j< M;j++){
						//std::cout << small_f[i][j] << " ";
						_temp += cos((PI*u/(2*N))*(2*i+1))*cos((PI*v/(2*M))*(2*j+1))*small_f[i][j];
					}
					//std::cout << "\n";
				}
				big_F[u][v] = _temp*_c;
			}
		}
		std::cout << "DCT Success \n";
		return big_F;
	}catch(...){
		std::cout << "Failed \n";
	}
}
