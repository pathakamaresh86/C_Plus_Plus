#include <iostream>

#include "base.h"
#include "derived1.h"
#include "derived2.h"

int main()
{
	Base* obj;
	Derived1 d1;
	Derived2 d2;
	obj = &d1;
	obj->getWadapav();
	obj = &d2;
	obj->getWadapav();
	//obj->getSandwich();
	dynamic_cast<Derived2*>(obj)->getSandwich();
	std::cout<<"Size of Base:-"<<sizeof(Base)<<std::endl;
	std::cout<<"Size of Derived1:-"<<sizeof(Derived1)<<std::endl;
	std::cout<<"Size of Derived2:-"<<sizeof(Derived2)<<std::endl;		
}

