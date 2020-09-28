#ifndef OBJECT_H
#define OBJECT_H
#include <string>

using namespace std;

class Object{

    public:
    	Object();
        virtual ~Object();
        
        virtual bool equals(Object*);

        virtual string toString();
};
#endif