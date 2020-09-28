#include "Object.h"
#include <iostream>
using std::cout;
using std::endl;

Object::Object(){
	
}

bool Object::equals(Object* x){
	return false;
}

string Object::toString(){
	return " ";
}



Object::~Object(){
	cout<<"Object Eliminado"<<endl;
}