#pragma once

#include <algorithm>
#include <iterator>

using namespace std;


template <typename TElem>
class DynamicArray
{
private:
	int capacity, size;
	TElem* elements;
public: 
	/*
	Creates a generic type array with capacity 1 and no elements
	*/
	DynamicArray(int capacity = 1);
	
	/*
	Dynamic array destroyer
	*/	
	~DynamicArray();

	/*
	Getter for the dynamic array size
	*/
	int getSize() const { return this->size; }

	/*
	Adds an object of generic type to the dynamic array
	*/
	void add(TElem element);

	/*
	Deletes the object from a given position
	*/
	void deleteFromPosition(int position);

	/*
	Square brackets operator override
	*/
	TElem& operator[](int position);

	/*
	Copy constructor for the dynamic array
	*/
	DynamicArray(const DynamicArray& dynamicArray);

	/*
	Assign operator override
	*/
	DynamicArray& operator=(const DynamicArray& arr);
	

private:
	/*
	Resizes the array
	*/
	void resize();
};


template<typename TElem>
inline DynamicArray<TElem>::DynamicArray(int capacity)
{
	this->elements = new TElem[capacity];
	this->capacity = capacity;
	this->size = 0;
}

template<typename TElem>
inline DynamicArray<TElem>::~DynamicArray()
{
	delete[] this->elements;
}

template<typename TElem>
inline void DynamicArray<TElem>::add(TElem element)
{
	if (this->size == this->capacity)
		this->resize();
	this->elements[this->size] = element;
	this->size++;
}

template<typename TElem>
inline void DynamicArray<TElem>::deleteFromPosition(int position)
{
	if (position < 0 || position >= size)
		throw exception();
	size--;
	for (int i = position; i < size; i++)
		elements[i] = elements[i + 1];
	
}


template<typename TElem>
inline TElem& DynamicArray<TElem>::operator[](int position)
{
	// TODO: insert return statement here
	return this->elements[position];
}

template<typename TElem>
inline DynamicArray<TElem>::DynamicArray(const DynamicArray& dynamicArray)
{
	this->capacity = dynamicArray.capacity;
	this->size = dynamicArray.size;
	this->elements = new TElem[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elements[i] = dynamicArray.elements[i];
}

template<typename TElem>
inline DynamicArray<TElem>& DynamicArray<TElem>::operator=(const DynamicArray& arr)
{
	DynamicArray<TElem> temporaryArray{ arr };
	swap(temporaryArray.elements, this->elements);
	swap(temporaryArray.capacity, this->capacity);
	swap(temporaryArray.size, this->size);
	
	return *this;
}

template<typename TElem>
inline void DynamicArray<TElem>::resize()
{
	this->capacity *= 2;
	TElem* auxiliary = new TElem[this->capacity];
	for (int i = 0; i < this->size; i++)
		auxiliary[i] = this->elements[i];
	delete[] this->elements;
	this->elements = auxiliary;
}
