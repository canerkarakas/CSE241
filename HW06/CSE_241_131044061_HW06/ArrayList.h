
#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include "List.h"

namespace GTUCollection {
template<typename E, typename container = list<E> >
class ArrayList: public List<E, container> {
public:
	ArrayList(){}


	Iterator<container> iterator(){
		Iterator<container > iter(&cont);
		iter.next();
		return iter;
	}

	list<E> get_c(){return cont;}

	E* get_Cont(){
		E *temp;
		cont.sort();
		int i = cont.size();
		temp = new E[i];
		Iterator<list<E> > iter(&cont);
		for(i=0;i<cont.size();i++){
			temp[i] = *(iter.get_iter());
			iter.next();
		}
		return temp;
	}

	void add(E e){
		Iterator<container> iter(&cont);
		cont.insert(iter.get_begin(), e);
		cont.sort();
	}

	void addAll(Collection<E,container> *c){
		E *temp;
		temp = new E[c->size()];
		temp = c->get_Cont();

		int i;
		for(i=0;i<c->size();i++){
			cont.insert(cont.begin(), temp[i]);
		}
		cont.sort();
	}

	void clear(){
		cont.clear();
	}

	bool contains(E e){
		Iterator<container> iter(&cont);
		Iterator<container> temp(&cont);
		for(;iter.get_iter()!=temp.end();){
			if(*(iter.get_iter()) == e){
				cont.sort();
				return true;
			}
			iter.next();
		}
		cont.sort();
		return false;
	}

	bool containsAll(Collection<E,container> *c){
		if(c->size() == cont.size()){
			Iterator<container> iter(&cont);
			E *temp;
			temp = new E[c->size()];
			temp = c->get_Cont();
			if(*(iter.end()) != temp[c->size()-1]){
				cont.sort();
				return false;
			}
			else{
				int i = 0;
				for(;iter.get_iter()!=iter.end();){
					if(*(iter.get_iter()) != temp[i]){
						cont.sort();
						return false;
					}
					else{
						iter.next();
						i++;
					}
				}
				cont.sort();
				return true;
			}
		}
		else{
			cont.sort();
			return false;
		}
	}

	bool isEmpty(){
		return cont.empty();
	}

	void remove(E e){
		Iterator<container> iter(&cont);
		for(;iter.get_iter() != iter.end();){
			if(*(iter.get_iter()) == e){
				iter.set_iter(cont.erase(iter.get_iter()));
			}
			else{
				iter.next();
			}
		}
		cont.sort();
	}

	void removeAll(Collection<E,container> *c){
		int i;
		Iterator<container> temp1(&cont);
		E *temp;
		temp = new E[c->size()];
		temp = c->get_Cont();
		for(;temp1.get_iter() != temp1.end();){
			for(i=0;i<c->size();i++){
				if(temp[i] == *(temp1.get_iter())){
					temp1.set_iter(cont.erase(temp1.get_iter()));
				}
			}
			temp1.next();
		}
		cont.sort();
	}

	void retainAll(Collection<E,container> *c){
		int i;
		int control = 0;
		int control2 = 0;
		int j;
		Iterator<container> temp(&cont);
		for(;temp.get_iter() != temp.end();){
			E *temp1;
			temp1 = new E[c->size()];
			temp1 = c->get_Cont();
			i = c->size();
			j = 0;
			while(control == 0){
				if(i==0){
					control = 1;
				}
				else{
					if(temp1[j] == *(temp.get_iter())){
						control = 1;
						control2 = 1;
					}
					else{
						j++;
					}
					i--;
				}
			}
			if(control2==0){
				temp.set_iter(cont.erase(temp.get_iter()));
				control = 0;
				control2 = 0;
			}
			else{
				temp.next();
				control = 0;
				control2 = 0;
			}
		}
		cont.sort();
	}

	void test(){
		Iterator<list<E> > iter(&cont);
		typename list<E>::iterator begin;
		typename list<E>::iterator end;
		end = cont.end();
		for(begin=cont.begin();begin!=end;begin++)
			cout<<*(begin)<<endl;
		cont.sort();
	}

	int size(){return cont.size();}

private:
	list<E> cont;
};

} /* namespace GTUCollection */
#endif /* ARRAYLIST_H_ */
