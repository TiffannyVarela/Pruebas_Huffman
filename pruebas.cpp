#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include "Node_huff.h"
#include "Huffman.h"
#include "Object.h"
using namespace std;

struct codigo
{
	char sym;
	string cod= "";
};

/*void codificacion(char x,queue <Node_huff*> que){
	if (!queueNode.empty())
	{
		codificacion(que.)
	}
}*/


void print(vector<char>x){
	for (int i = 0; i < x.size(); i++)
	{
		cout<<x[i]<<endl;
	}
}

int main(int argc, char const *argv[])
{
	string nombre;
	string rutaC = "Codificar/";
	string rutaD = "Decodificar/";
	string line =" ";
	vector <char> carac;
	vector <char> aux;
	vector <int> cant;
	int frecuencia=0;
	Object* nuevoNode = new Node_huff;
	vector <Node_huff*> nodos;
	Node_huff* temp;
	
	Node_huff* nuevo;
	nuevo=dynamic_cast<Node_huff*>(nuevoNode);

	queue <Node_huff*> queueNode;
	Object* nuevoNodeq = new Node_huff;
	Node_huff* nuevoq;
	nuevoq=dynamic_cast<Node_huff*>(nuevoNodeq);


	cout<<"Ingrese el nombre del archivo"<<endl;
	cin>>nombre;
	ifstream archivo(rutaC+nombre+".txt");
	if (archivo.is_open())
	{
		while(!archivo.eof())
		{
			getline(archivo,line,'\0');
			
			for (int i = 0; i < line.size(); i++)//ingresar texto al vector
			{
				carac.push_back(line[i]);
			}//fin ingresar texto al vector
			//print(carac);
			aux=carac;//asignar vector al aux
			for (int i = 0; i <carac.size(); i++)//primer for borrar repetidos
			{
				for (int j = i+1; j <carac.size(); j++)//segundo for borrar repetidos
				{
					if (carac[i]==aux[j])//comparar caracteres iguales
					{
						aux.erase(aux.begin()+j);
					}//fin comparar caracteres iguales
				}//fin segundo for borrar repetidos
			}//fin primer for borrar repetidos
			//cout<<"Segundo"<<endl;
			//print(aux);
			int cont=0;
			for (int i = 0; i <aux.size(); i++)//primer for contar repeticiones
			{
				cont=0;
				for (int j = 0; j <carac.size(); j++)//segundo for contar repeticiones
				{
					if (aux[i]==carac[j])//comparar caracteres iguales
					{
						cont++;
					}//fin comparar caracteres iguales
				}//fin segundo for contar repeticiones
				cant.push_back(cont);
			}//fin primer for contar repeticiones
			for (int i = 0; i < cant.size(); i++)
			{
				cout<<cant[i]<<endl;
			}
			//cout<<"\n\n dynamic \n\n";
			for (int i = 0; i < aux.size(); i++)
			{
				nuevo=new Node_huff();
				nuevo->set_sym(aux[i]);
				nuevo->set_cont(cant[i]);
				nodos.push_back(nuevo);
			}
			for (int i = 0; i < nodos.size(); i++)
			{
				for (int j = 1; j < nodos.size()-i; j++)
				{
					if (nodos[j-1]->get_cont()>nodos[j]->get_cont())
					{
						temp=nodos[j-1];
						nodos[j-1]=nodos[j];
						nodos[j]=temp;
					}
				}
			}
			//ordenado
			cout<<"ORDENADO\n\n"<<endl;
			for (int i = 0; i < nodos.size(); i++)
			{
				cout<<nodos[i]->toString();
			}
			for (int i = 0; i < cant.size(); i++)
			{
				frecuencia+=cant[i];
			}
			//cout<<"frecuencia: "<<frecuencia<<"\n\n"<<endl;
			//llenado del queue
			for (int i = 0; i < nodos.size(); i++)
			{
				queueNode.push(nodos[i]);
			}
			//impresion del queue
			/*cout<<"QUEUE\n\n";
			while(!queueNode.empty()){
				cout<<queueNode.front()->toString();
				queueNode.pop();
			}*/
			
			//cout<<"0"<<endl;
			cout<<"\n\n\n";
			int contx=0;
			while(queueNode.size()!=1){
				//cout<<"1"<<endl;
				nuevoq = new Node_huff();
				//cout<<"2"<<endl;
				temp=queueNode.front();
				//cout<<"3"<<endl;
				nuevoq->set_izq(temp);
				//cout<<"4"<<endl;
				queueNode.pop();
				//cout<<"5"<<endl;
				temp=queueNode.front();
				//cout<<"6"<<endl;
				nuevoq->set_der(temp);
				//cout<<"7"<<endl;
				queueNode.pop();
				//cout<<"8"<<endl;
				nuevoq->set_cont(nuevoq->get_izq()->get_cont()+nuevoq->get_der()->get_cont());
				cout<<contx<<endl;
				cout<<nuevoq->toString()<<endl;
				contx++;
				//cout<<"9"<<endl;
				queueNode.push(nuevoq);
				//cout<<"0"<<endl;
			}
			//cout<<"10"<<endl;
			/*ofstream fileNew;
			fileNew.open(rutaD+"nuevo.txt");
			while(!queueNode.empty()){
				fileNew<<queueNode.front();
				queueNode.pop();
			}
			fileNew.close();*/
			cout<<"QUEUE\n\n";
			while(!queueNode.empty()){
				cout<<queueNode.front()->toString();
				queueNode.pop();
			}
		}
		archivo.close();
	}
	else{
		cout<<"Error al abrir el archivo"<<endl;
	}
	/*for (int i = 0; i < nodos.size()-1; i++)
    {
        delete nodos[i];
        nodos[i] = NULL;
    }*/
    carac.clear();
    aux.clear();
    cant.clear();
    nodos.clear();
    delete nuevoNode;
    delete nuevo;
    delete nuevoNodeq;
    //delete nuevoq;
    delete temp;
	
	return 0;
}







