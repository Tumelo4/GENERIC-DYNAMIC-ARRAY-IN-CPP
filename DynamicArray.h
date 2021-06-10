//  Creating Generic Dynamic Array
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
#include <string>
using namespace std;

template<class T>
class DynamicArray;

template<class T>
ostream& operator<<(ostream &, DynamicArray<T>&);

template<class T>
class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();
	void insert(T data);
	void reverse();
	friend ostream& operator<< <T>(ostream &, DynamicArray<T>&);
	void resize();
private:
	T* array;
	bool flag;
	int size;
};
#endif