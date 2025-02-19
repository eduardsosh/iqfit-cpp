#include<iostream>
#include"algox.h"
using namespace std;

int main(){
	Dlink matrix;

	matrix.add_column("Column1");
	matrix.print_headers();
	matrix.add_column("Column2");
	matrix.print_headers();

	return 0;
}

