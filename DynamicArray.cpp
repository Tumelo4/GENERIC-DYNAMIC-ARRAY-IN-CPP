#include "DynamicArray.h"


template<class T>
DynamicArray<T>::DynamicArray()
{
	flag = true;
	size = 0;
}

template<class T>
void DynamicArray<T>::insert(T data)
{
	this->resize();

	if(flag)
	{
		switch(size)
		{
			case 1:
				array[0] = data;
			break;

			default:
				int index = 0;
				for (; index < size - 1 && array[index] < data ; index++);

				if (array[index] != -1)
				{
					for ( int count = size - 1; count > index ; array[count] = array[count - 1], count--);
					array[index] = data;
				}
				else
				{
					array[index] = data;
				}
			break;
		}
	}
	else
	{
		switch(size)
		{
			case 1:
				array[0] = data;
			break;

			default:
				int index = 0;
				for (; index < size - 1 && array[index] > data ; index++);
					
				if (array[index] != -1)
				{
					for ( int count = size - 1; count > index ; array[count] = array[count - 1], count--);
					array[index] = data;
				}
				else
				{
					array[index] = data;
				}
			break;
		}
	}
}


template<class T>
ostream& operator<<(ostream &os, DynamicArray<T> &obj)
{
	for(int index = 0; index < obj.size; index++)
	{
		if(index + 1 == obj.size)
		{
			os << obj.array[index];
		}
		else os << obj.array[index]<<",";
	}
	return os;
}

template<class T>
void DynamicArray<T>::reverse()
{
	flag = !flag;

	for ( int i = 0, j = size-1 ; i < (size/2); i++,j--)
	{
		T tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}

template<class T>
void DynamicArray<T>::resize()
{
	size++;
	T* tmp = new T[size];

	for (int index = 0; index < size-1; index++)
	{
		tmp[index] = array[index];
	}

	array = new T[size];

	for (int index =0; index <size-1; index++)
	{
		array[index] = tmp[index];
	}
	array[size-1] = -1;
}