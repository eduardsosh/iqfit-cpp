#include<iostream>
#include<vector>
#include"algox.h"
using namespace std;

int main(){
	Dlink matrix;
	vector<vector<bool>> arrays = {
		{0,0,1,0,1},
		{1,0,1,0,0},
		{0,1,0,0,0},
		{1,0,0,1,0}
	};

	matrix.from_2d_vector(arrays);
	matrix.print_headers();
	cout<< endl;
	matrix.print_matrix();

	return 0;
}

