#include <iostream>
#include "Node_huff.h"
using namespace std;


	

Node_huff::Node_huff():Object(){
	sym=' ';
	cont=0;
	izq=NULL;
	der=NULL;
}

Node_huff::Node_huff(char sym, int cont, Node_huff* izq,Node_huff* der):Object(){
	this->sym=sym;
	this->cont=cont;
	this->izq=izq;
	this->der=der;
}

void Node_huff::set_sym(char x){
	sym=x;
}

char Node_huff::get_sym(){
	return sym;
}

void Node_huff::set_cont(int x){
	cont=x;
}

int Node_huff::get_cont(){
	return cont;
}

void Node_huff::set_izq(Node_huff* x){
	izq=x;
}

Node_huff* Node_huff::get_izq(){
	return izq;
}

void Node_huff::set_der(Node_huff* x){
	der=x;
}

Node_huff* Node_huff::get_der(){
	return der;
}


bool Node_huff::equals(Object* x){
	Node_huff* node = dynamic_cast<Node_huff*>(x);
	if (sym==node->get_sym())
	{
		return true;
	}
	else{
		return false;
	}
}

string Node_huff::toString(){
	string str=to_string(cont);
	string sim;
	sim+=sym;
	string text = "Simbolo: "+sim+"\nFrecuencia: "+str+"\n\n";
	///text+=izq->toString()+"\n"+der->toString()+"\n\n";
	return text;
	
}

Node_huff::~Node_huff(){
	cout<<"Nodo eliminado"<<endl;
}
