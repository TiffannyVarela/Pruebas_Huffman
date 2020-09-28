#include "Huffman.h"
#include "Object.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <unordered_map>
using namespace std;

Node_huff* Huffman::nuevo(char sym, int cont, Node_huff* izq, Node_huff* der){
	Object* newNode = new Node_huff;
	Node_huff* node;
	node=dynamic_cast<Node_huff*>(newNode);
	node = new Node_huff();
	node->set_sym(sym);
	node->set_cont(cont);
	node->set_izq(izq);
	node->set_der(der);
	return node;
}
struct comp
{
	bool operator()(Node_huff* a, Node_huff* b){
		return a->get_cont() > b->get_cont();
	}
};



void Huffman::codificar(Node_huff* node, string x, unordered_map<char,string> lista){//unordered sirve para crear una lista con un conjunto de elementos
	if (node == nullptr)
	{
		return;
	}
	if (!node->get_izq() && !node->get_der())
	{
		lista[node->get_sym()] = x;
	}
	codificar(node->get_izq(),x+"0",lista);
	codificar(node->get_der(),x+"1",lista);
}

void Huffman::decodificar(Node_huff* node, int& i, string x){
	if (node == nullptr)
	{
		return;
	}
	if (!node->get_izq() && !node->get_der())
	{
		cout<<node->get_sym();
		return;
	}
	i++;
	if (x[i]=='0')
	{
		decodificar(node->get_izq(),i,x);
	}
	else{
		decodificar(node->get_der(),i,x);
	}
}

void Huffman::construir(string x){

	int freq;
	Object* newNodei = new Node_huff;
	Node_huff* izquierdo;
	izquierdo=dynamic_cast<Node_huff*>(newNodei);

	Object* newNoded = new Node_huff;
	Node_huff* derecho;
	derecho=dynamic_cast<Node_huff*>(newNoded);

	Object* newNode = new Node_huff;
	Node_huff* newn;
	newn=dynamic_cast<Node_huff*>(newNode);


	unordered_map<char,int> lista;
	for (char y:x)
	{
		lista[y]++;
	}

	priority_queue<Node_huff*, vector<Node_huff*>, comp> que;
	for (auto pair:lista)
	{
		que.push(nuevo(pair.first, pair.second,nullptr,nullptr));
	}
	while(que.size()!=1){
		izquierdo = que.top();
		que.pop();
		derecho = que.top();
		que.pop();
		freq = izquierdo->get_cont()+derecho->get_cont();
		que.push(newn=new Node_huff('\0', freq, izquierdo, derecho));
	}
	Object* newNode2 = new Node_huff;
	Node_huff* newraiz;
	newraiz=dynamic_cast<Node_huff*>(newNode2);
	newraiz = que.top();

	unordered_map<char,string> code;
	codificar(newraiz,"",code);

	cout<<"CODIFICADO\n\n";
	for (auto pair:code)
	{
		cout<<pair.first<<" "<<pair.second<<endl;
	}

	cout<<"Original: "<<x<<endl;

	string str="";
	for (char ch:x)
	{
		str+=code[ch];
	}

	cout<<"Encoded: "<<str<<endl;
	int index = -1;
	cout<<"Decoded: "<<endl;
	while(index<(int)str.size()-2){
		decodificar(newraiz, index, str);
	}
}

Huffman::~Huffman(){

}