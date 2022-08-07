#ifndef __LINKED_LIST__H
#define __LINKED_LIST__H

#include <iostream>

template <class Type , class ID>
class Node 
{
private:

	ID id;
	Type t;
	Node* node;
	bool isHead;


public:
	Node();
	Node(Type t,ID id, bool isHead);
	Node(const Node<Type, ID>& other);

	Node<Type, ID>& operator=(const Node<Type, ID> other);

	bool push(const Type& t ,const ID& id ,const bool& isHead);
	bool remove(const ID& id);

	const ID getId() const { return this->id; }
	Node* getNode() const { return this->node; }
	const Type getType() const { return t; }

	Type* getTypeById(const ID& id) const ;
	Type getTypeByNum(const int num) const ;

	void print() const;
};


template<class Type, class ID>
inline Node<Type, ID>::Node()
{
}

template<class Type, class ID>
Node<Type, ID>::Node(Type t, ID id, bool isHead)
	: t(t), id(id) , isHead(isHead), node(NULL)
{
}

template<class Type, class ID>
Node<Type, ID>::Node(const Node<Type,ID>& other)
{
	*this = other;
}

template<class Type, class ID>
Node<Type, ID>& Node<Type, ID>::operator=(const Node<Type, ID> other)
{
	Node <Type, ID>* tmp = node;
	while (tmp != NULL)
	{
	tmp->id = other.getId();
	tmp->t = other.getType();
	tmp->isHead = other.isHead;
	tmp->node = new Node<Type, ID>(other.getType(), other.getId(), other.isHead);
	tmp = tmp->getNode();
	}

	return *this;
}



template<class Type, class ID>
bool Node<Type, ID>::push(const Type& t,const ID& id,const bool& isHead)
{
	if (node == NULL)
	{
		if (isHead) {
			this->id = id;
			this->t = t;
		}
		else
		{
			node = new Node<Type, ID>(t, id, isHead);
			return true;
		}
		
	}
	else
	{
		return node->push(t , id , isHead);
	}
	return false;
}

template<class Type, class ID>
bool Node<Type, ID>::remove(const ID& id)
{
	if (isHead && this->id == id)
	{
		*this = *node;
		return true;
	}
	else
	{
		if (this->node->getId() == id)
		{
			if (this->node->getNode() == NULL)
			{
				this->node = NULL;
				return true;
			} 
			else
			{
				this->node = this->node->getNode();
				return true;
			}
		}
	}
	return this->node->remove(id);
}

template<class Type, class ID>
Type* Node<Type, ID>::getTypeById(const ID& id) const 
{
	if (this->id == id)
	{
		return &this->t;
	}
	else
	{
		if (node == NULL) {
			return NULL;
		}
		else
		{
		return this->node->getTypeById(id);
		}
	}
}

template<class Type, class ID>
inline Type Node<Type, ID>::getTypeByNum(const int num) const 
{
	Node<Type, ID>* tmp = node;
	for (int i = 0; i < num; i++)
	{
		tmp = tmp->node;
	}
	return tmp->getType();
}


template<class Type, class ID>
void Node<Type, ID>::print() const
{
	std::cout << this->t << std::endl;
	if (node != NULL)
	{
		this->node->print();
	}
}

#endif


