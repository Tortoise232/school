#pragma once
template<typename Type>
/*Generic dynamic vector structure*/
class Vector
{
private:
	Type* elements;
	int size;
	int capacity;

public:
	/*Returns a pointer to an array of elements of type "Type" representing the elements in the vector*/
	Type* getElements()
	{
		return this->elements;
	}

	/*Constructor for the vector structure with one parameter (capacity) representing the initial capacity of the vector*/
	Vector(int capacity = 5)
	{
		this->size = 0;
		this->capacity = capacity;
		this->elements = new Type[capacity];
	}

	/*Destructor for the vector structure*/
	~Vector()
	{
		delete[] this->elements;
	}

	/*Constructor for the vector structure with one parameter representing another vector of type "Type" to be copied into the initialised one*/
	Vector(const Vector<Type>& originalVector)
	{
		this->size = originalVector.size;
		this->capacity = originalVector.capacity;
		this->elements = new Type[this->capacity];
		for (int counter = 0; counter < this->size; counter++)
			this->elements[counter] = originalVector.elements[counter];
	}

	/*Overload for the "=" operator, effectively copying the vector structure from the parameter*/
	Vector<Type>& operator=(const Vector<Type>& sourceVector)
	{
		if (this == &sourceVector)
			return *this;
		this->size = sourceVector.size;
		this->capacity = sourceVector.capacity;
		delete[] this->elements;
		this->elements = new Type[this->capacity];
		for (int counter = 0; counter < this->size; counter++)
			this->elements[counter] = sourceVector.elements[counter];
	}

	/*Function searches through the vector structure and returns an integer value if the element with the given name is found (parameter "name" is the given name)*/
	bool isIn(char name[30])
	{//1 for found element, 0 for no element found
		for (int counter = 0; counter < this->size; counter++)
			if (strcmp(this->elements[counter].getTitle(), name) == 0)
				return 1;
		return 0;
	}

	/*Adds the element of type "Type" to the vector structure*/
	bool add(Type element)
	{
		if (this->size == this->capacity)
			this->resize(2);
		this->elements[this->size] = element;
		this->size++;
		return 0;
	}

	/*Returns the size of the vector structure (attribute)*/
	int getSize() const
	{
		return this->size;
	}

	/*Allocates factor times the previous space allocated for the vector structure*/
	void resize(double factor)
	{
		this->capacity *= factor;
		Type* newElements = new Type[this->capacity];
		for (int counter = 0; counter < this->size; counter++)
			newElements[counter] = this->elements[counter];
		delete[] this->elements;
		elements = newElements;
	}

	/*Removes an element with the name attribute identical to the given array of characters (name); returns 0 for successfull removal and 1 if the removal does not succeed*/
	bool remove(char name[30])
	{// 1 for error 0 for good removal
		for (int counter = 0; counter < this->size; counter++)
			if (strcmp(this->elements[counter].getTitle(), name) == 0)
			{
				for (int counter2 = counter; counter2 < this->size; counter2++)
					this->elements[counter2] = this->elements[counter2 + 1];
				this->size--;
				return 0;
			}
		return 1;
	}

	/*Prints all the elements of the vector on the screen*/
	void printAll()
	{
		for (int counter = 0; counter < this->size; counter++)
		{
			std::cout << "\n" << this->elements[counter].getTitle() << " of genre " << this->elements[counter].getGenre() << " released in " << this->elements[counter].getYear() << " with " << this->elements[counter].getLikes() << " likes;";
		}
	}
	/*Overloads the + operator to add an element to the vector by way of the + operator*/
	bool operator+(Type element)
	{
		return this->add(element);
	}
	/*Overloads the + operator to add an element to the vector by way of the + operator (the other way around)*/
	friend bool operator+(Type element, Vector& v) {
		return v.add(element);
	}

	/*Overloads the - operator to remove an element from the vector by way of the - operator*/
	bool operator-(char name[30])
	{
		return this->remove(name);
	}

	/*Returns a vector structure containing all the elements found in the initial structure as having the attribute genre identical to the given parameter (genre)*/
	Vector<Type> getGenre(char genre[30])
	{
		Vector<Type> vectorGenre;
		for (int counter = 0; counter < this->size; counter++)
		{
			if (strcmp(this->elements[counter].getGenre(), genre) == 0)
				vectorGenre.add(this->elements[counter]);
		}
		return vectorGenre;
	}
};


