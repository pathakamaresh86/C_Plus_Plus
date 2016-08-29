#include <iostream>

int& FunctionReturningReference(int &param)
{
    int i = param;
	param = 40;
	return param;
    //return i;
}

int main()
{
	int var = 10;
	FunctionReturningReference(var) = 200;
	std::cout<<var<<std::endl;
	return 0;
}
