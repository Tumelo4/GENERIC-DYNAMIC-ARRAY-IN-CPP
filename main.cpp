#include "DynamicArray.h"
#include "DynamicArray.cpp"

int main()
{
	DynamicArray<int>* array = new DynamicArray<int>();
	for (int i=0; i<10; i++)array->insert(i);
	cout<<*array<<"\n";
	array->reverse();
	cout<<*array<<"\n";
	array->insert(10);
	cout<<*array<<"\n";
	return 0;
}