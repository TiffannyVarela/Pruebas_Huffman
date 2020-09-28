#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <unordered_map>
#include "Node_huff.h"
#pragma once

class Huffman
{
protected:
	Node_huff* padre;
	Node_huff* hijo;
	Node_huff* raiz;
	char id;
public:
	Node_huff* nuevo(char, int, Node_huff*, Node_huff*);
	bool comparar(Node_huff*, Node_huff*);
	void codificar(Node_huff*, string, unordered_map<char,string>);
	void decodificar(Node_huff*, int&, string);
	void construir(string);
	~Huffman();
	
};
