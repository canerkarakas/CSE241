#ifndef ITERATOR_H_
#define ITERATOR_H_
#include<iostream>
#include<iterator>
using namespace std;
namespace GTUCollection {

template<typename T>
class Iterator {
public:
	Iterator(){}
	Iterator(T *t){container = t; iter = container->begin(); begin = t->begin();}

	bool hasNext() const{
		typename T::iterator temp;
		temp = iter;
		if(++temp != container->end())
			return true;
		return false;
	}

	void set_iter(typename T::iterator i){
		iter = i;
	}

	typename T::iterator next(){
		iter++;
		return iter;
	}

	typename T::iterator back(){
		iter--;
		return iter;
	}

	typename T::iterator get_begin(){
		iter == begin;
		return iter;
	}

	typename T::iterator end(){
			return container->end();
	}

	typename T::iterator remove(){
		typename T::iterator temp;
		temp = iter;
		container->erase(temp);
		iter++;
		return iter;
	}

	typename T::iterator get_iter(){
		return iter;
	}

	/*void remove(){
			T* temp = new T[size-1];
			for(int i=0;i<size-1;i++)
				temp[i] = *(ptr + i);
			for(int i = 0;i<size-1;i++)
				temp[i] = *(ptr + i + 1);
			ptr = new T[size-1];
			ptr = temp;
			size = down_size();
		}*/

private:
	T *container;
	typename T::iterator iter;
	typename T::iterator begin;

	/*bool hasNext() const {
		T *temp;
		T *temp2 = ptr + size - 1;
		for(temp=ptr;temp<=temp2;temp++){
			if(ptr+1 == temp)
				return true;
		}
		return false;
	}

	T next(){
		ptr++;
		size = down_size();
		return *ptr;
	}

	T back(){
		ptr--;
		size = up_size();
		return *ptr;
	}

	T* get_ptr() const {return ptr;}

	int down_size(){
		--size;
		return size;
	}

	int up_size(){
		++size;
		return size;
	}

	void remove(){
		T* temp = new T[size-1];
		for(int i=0;i<size-1;i++)
			temp[i] = *(ptr + i);
		for(int i = 0;i<size-1;i++)
			temp[i] = *(ptr + i + 1);
		ptr = new T[size-1];
		ptr = temp;
		size = down_size();
	}

	Iterator& operator ++(int ignore){
		Iterator temp;
		temp = *this;
		ptr++;
		return temp;
	}

	Iterator& operator ++(){
		ptr++;
		return *this;
	}

	Iterator& operator --(int ignore){
		Iterator temp;
		temp = *this;
		ptr--;
		return temp;
	}

	Iterator& operator --(){
		ptr--;
		return *this;
	}

	T* operator -> () const{return get_ptr;}

	T& operator * () const{return get_ptr();}

private:
	T *ptr;
	int size;*/
};

} /* namespace GTUCollection */
#endif /* ITERATOR_H_ */
