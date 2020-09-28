#pragma once
#include <string>
#include "Object.h"
using namespace std;

class Node_huff : public Object
{
protected:
	char sym;
	int cont;
	Node_huff* izq;
	Node_huff* der;
public:
	Node_huff();
	Node_huff(char, int,Node_huff*,Node_huff*);
	void set_sym(char);
	char get_sym();
	void set_cont(int);
	int get_cont();
	void set_izq(Node_huff*);
	Node_huff* get_izq();
	void set_der(Node_huff*);
	Node_huff* get_der();
	bool equals(Object*);
	string toString();
	~Node_huff();
};
