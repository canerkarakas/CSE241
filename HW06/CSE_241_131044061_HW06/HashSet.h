#ifndef HASHSET_H_
#define HASHSET_H_

#include "Set.h"
#include"Iterator.h"
#include<set>

namespace GTUCollection {

template<typename E, typename container = set<E> >
class HashSet: public Set<E, container> {
public:
	HashSet(){}

	Iterator<container> iterator(){
		Iterator<container > iter(&cont);
		iter.next();
		return iter;
	}

	set<E> get_c(){return cont;}

	E* get_Cont(){
		E *temp;
		int i = cont.size();
		temp = new E[i];
		Iterator<set<E> > iter(&cont);
		for(i=0;i<cont.size();i++){
			temp[i] = *(iter.get_iter());
			iter.next();
		}
		return temp;
	}


	void add(E e){
		cont.insert(e);
	}

	void addAll(Collection<E,container> *c){
		E *temp;
		temp = new E[c->size()];
		temp = c->get_Cont();

		int i;
		for(i=0;i<c->size();i++){
			cont.insert(temp[i]);
		}
	}

	void clear(){
		cont.clear();
	}

	bool contains(E e){
		Iterator<container> iter(&cont);
		Iterator<container> temp(&cont);
		for(;iter.get_iter()!=temp.end();){
			if(*(iter.get_iter()) == e){
				return true;
			}
			iter.next();
		}
		return false;
	}

	bool containsAll(Collection<E,container> *c){
		if(c->size() == cont.size()){
			Iterator<container> iter(&cont);
			E *temp;
			temp = new E[c->size()];
			temp = c->get_Cont();
			int i = 0;
			if(*(iter.end()) != temp[i]){
				return false;
			}
			else{
				for(;iter.get_iter()!=iter.end();){
					if(*(iter.get_iter()) != temp[i])
						return false;
					else{
						iter.next();
						i++;
					}
				}
				return true;
			}
		}
		else
			return false;
	}

	bool isEmpty(){
		return cont.empty();
	}

	void remove(E e){
		Iterator<container> iter(&cont);
		if(*(iter.end()) == e){
			for(;iter.get_iter() != iter.end();){
				iter.next();
			}
			iter.remove();
		}
		else{
			for(;iter.get_iter() != iter.end();){
				if(*(iter.get_iter()) == e){
					iter.remove();
				}
				else
					iter.next();
			}
		}
	}

	void removeAll(Collection<E,container> *c){
		int i = 0;
		Iterator<container> temp(&cont);
		E *temp1;
		temp1 = new E[c->size()];
		temp1 = c->get_Cont();
		int j = 0;
		for(;temp.get_iter() != temp.end();){
			i = 0;
			for(j=0;j<c->size();j++){
				if(temp1[j] == *(temp.get_iter())){
					this->remove(*(temp.get_iter()));
				}
				j++;
				i++;
			}
			temp.next();
		}
	}

	void retainAll(Collection<E,container> *c){
		int i = 0;
		int control = 0;
		Iterator<container> temp(&cont);
		E *temp1;
		temp1 = new E[c->size()];
		temp1 = c->get_Cont();
		int j = 0;
		for(;temp.get_iter() != temp.end();){
			i = 0;
			for(j=0;j<c->size();j++){
				if(temp1[j] == *(temp.get_iter())){
					control = 1;
				}
				j++;
				i++;
			}
			if(control!=1){
				this->remove(*(temp.get_iter()));
			}
			temp.next();
			control = 0;
		}
	}

	int size(){return cont.size();}

	void test(){
		Iterator<set<E> > iter(&cont);
		typename set<E>::iterator begin;
		typename set<E>::iterator end;
		end = cont.end();
		for(begin=cont.begin();begin!=end;begin++)
			cout<<*(begin)<<endl;
	}

private:
	set<E> cont;
};

} /* namespace GTUCollection */
#endif /* HASHSET_H_ */
