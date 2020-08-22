/*
 * Self Implementation of JPEG
 * */

#include <vector>
#include <iostream>
#include <math.h>

#define PI 3.141592653589793238

double ccons(int _a){
	if(_a == 0) return 1.0/sqrt(2.0);
	else return 1.0;
}


//	8 x 8 matrices input
std::vector<std::vector<double> > dct(std::vector<std::vector<int> > small_f, int N, int M){
	//	DCT process
	//	Row -> N
	//	col -> M
	std::vector<double> matxM(M, 0.0);
	std::vector<std::vector<double> > big_F (N, matxM);
	//
	//	calculate  DCT
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
			std::cout << big_F[u][v] << " ";
		}
		std::cout << "\n";
	}
	
	return big_F;
}


int main(){
	//	8 x 8 Grayscale format pixel matrix
	std::vector<std::vector<int> > data = 
	{
		{90,100},
		{100,105}
	};
	dct(data,2,2);
}
