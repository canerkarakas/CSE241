#ifndef COLLECTION_H_
#define COLLECTION_H_
#include<vector>
#include<iostream>
#include"Iterator.h"
#include<set>
#include<list>
#include<queue>
using namespace std;

namespace GTUCollection {
template<typename E, typename container = vector<E> >
class Collection {
public:
	Collection(){}

	virtual Iterator<container> iterator() = 0;
	virtual void add(E e) = 0;
	virtual void addAll(Collection<E,container> *c) = 0;
	virtual void clear() = 0;
	virtual bool contains(E e) = 0;
	virtual bool containsAll(Collection<E,container> *c) = 0;
	virtual bool isEmpty() = 0;
	virtual void remove(E e) = 0;
	virtual void removeAll(Collection<E,container> *c) = 0;
	virtual void retainAll(Collection<E,container> *c) = 0;
	virtual void test() = 0;
	virtual int size() = 0;

	virtual E* get_Cont() = 0;

};

}
#endif
