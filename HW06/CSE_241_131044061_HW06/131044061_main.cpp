#include"Collection.h"
#include"HashSet.h"
#include"ArrayList.h"
#include"LinkedList.h"
#include"Queue.h"
#include"Iterator.h"
using namespace GTUCollection;


void test_arrListToLinkList();
void test_setToHashSet();
void test_add();
void test_addAll();
void test_clear();
void test_contains();
void test_containsAll();
void test_isEmpty();
void test_remove();
void test_removeAll();
void test_retainAll();
void test_size();
void test_element();
void test_offer();
void test_poll();


int main(){

	test_arrListToLinkList();
	test_setToHashSet();
	test_add();
	test_addAll();
	test_clear();
	test_contains();
	test_containsAll();
	test_isEmpty();
	test_remove();
	test_removeAll();
	test_retainAll();
	test_size();
	test_element();
	test_offer();
	test_poll();

	set<int> l;
	l.insert(3);
	l.insert(2);
	l.insert(4);
	l.insert(5);

	Iterator<set<int> > iter(&l);
	cout<<"iter = "<<*iter.get_iter()<<endl;
	cout<<"iter hasNext = "<<iter.hasNext()<<endl;
	cout<<"iter next = "<<*iter.next()<<endl;
	cout<<"iter next = "<<*iter.next()<<endl;
	cout<<"iter next = "<<*iter.next()<<endl;
	cout<<"iter hasNext = "<<iter.hasNext()<<endl;
	cout<<endl;

	return 0;
}

void test_arrListToLinkList(){

	cout<<"linkedlist to arraylist"<<endl;

	ArrayList<int> a;
	LinkedList<int> l;
	List<int> *l1;

	l.add(55);
	l.add(56);
	l.add(213);

	l1=&l;
	a.addAll(l1);
	a.test();

	l1=&a;
	cout<<endl;
	l.addAll(l1);
	l.test();

	cout<<endl;
}

void test_setToHashSet(){
	cout<<"set to hashset"<<endl;
	HashSet<char> s1;
	Set<char> *a;
	a=&s1;
	a->add('t');
	a->add('a');
	a->add('s');
	a->add('w');
	a->add('1');

	a->test();

	cout<<endl;

}

void test_add(){
	cout<<"test_add"<<endl;
	HashSet<int> s1;
	ArrayList<int> a;
	LinkedList<int> l;
	s1.add(5);
	s1.add(3);
	s1.add(6);
	a.add(2);
	a.add(1);
	a.add(5);
	l.add(3);
	l.add(3);
	l.add(3);

	s1.test();
	cout<<endl;
	a.test();
	cout<<endl;
	l.test();
	cout<<endl;
}

void test_addAll(){
	cout<<"test_add_all"<<endl;
	ArrayList<int> a;
	LinkedList<int> l;
	List<int, list<int> > *s;
	a.add(2);
	a.add(1);
	a.add(5);
	l.add(3);
	l.add(3);
	l.add(3);
	s = &l;
	a.addAll(s);
	a.test();
	cout<<endl;

}
void test_clear(){
	cout<<"test_clear"<<endl;
	ArrayList<int> a;
	a.add(2);
	a.add(1);
	a.add(5);
	a.test();
	cout<<"after test- for list!!!"<<endl;
	a.clear();
	a.test();
	cout<<"clear all!!"<<endl<<endl;
	HashSet<int> s1;
	s1.add(5);
	s1.add(3);
	s1.add(6);
	s1.test();
	cout<<"after test- for set!!!"<<endl;
	s1.clear();
	s1.test();
	cout<<"clear all!!"<<endl;
	cout<<endl;

}
void test_contains(){
	cout<<"test_contains"<<endl;
	ArrayList<int> a;
	LinkedList<int> l;
	a.add(2);
	a.add(1);
	a.add(5);
	a.test();
	cout<<endl<<"1 is here => "<<a.contains(1)<<endl<<"0 is here => "<<a.contains(0)<<endl;
	l.add(2);
	l.add(1);
	l.add(5);
	l.test();
	cout<<endl<<"1 is here => "<<l.contains(1)<<endl<<"0 is here => "<<l.contains(0)<<endl;
	HashSet<int> s1;
	s1.add(5);
	s1.add(3);
	s1.add(6);
	s1.test();
	cout<<endl<<"3 is here => "<<s1.contains(3)<<endl<<"0 is here => "<<s1.contains(0)<<endl;
	cout<<endl;

}
void test_containsAll(){
	cout<<"test_containsAll"<<endl;
	ArrayList<int> a;
	LinkedList<int> l;
	List<int, list<int> > *s;
	a.add(2);
	a.add(1);
	a.add(5);
	cout<<" a list "<<endl;
	a.test();
	l.add(3);
	l.add(2);
	l.add(7);
	cout<<" l list "<<endl;
	l.test();
	s = &l;
	cout<<"l in a => "<<a.containsAll(s)<<endl;
	cout<<endl;
}
void test_isEmpty(){
	cout<<"test_isEmpty"<<endl;
	ArrayList<int> a;
	LinkedList<int> l;
	a.add(2);
	a.add(1);
	a.add(5);

	cout<<"a is empty => "<<a.isEmpty()<<endl;
	cout<<"l is empty => "<<l.isEmpty()<<endl;
	cout<<endl;
}
void test_remove(){
	cout<<"test_remove"<<endl;
	ArrayList<int> a;
	LinkedList<int> l;
	a.add(2);
	a.add(1);
	a.add(5);
	cout<<" a list "<<endl;
	a.test();
	cout<<"clear element => 2"<<endl;
	a.remove(2);
	cout<<" new array "<<endl;
	a.test();
	l.add(3);
	l.add(2);
	l.add(7);
	cout<<" l list "<<endl;
	l.test();
	cout<<"clear element => 2"<<endl;
	l.remove(2);
	cout<<" new array "<<endl;
	l.test();
	cout<<endl;
}
void test_removeAll(){
	cout<<"test_removeAll"<<endl;
	ArrayList<int> a;
	LinkedList<int> l;
	List<int, list<int> > *s;
	a.add(2);
	a.add(1);
	a.add(5);
	cout<<" a list "<<endl;
	a.test();
	l.add(3);
	l.add(2);
	l.add(7);
	cout<<" l list "<<endl;
	l.test();
	s = &l;
	cout<<"a - l => "<<endl;
	a.removeAll(s);
	a.test();
	cout<<endl;
}
void test_retainAll(){
	cout<<"test_retainAll"<<endl;
	ArrayList<int> a;
	LinkedList<int> l;
	List<int, list<int> > *s;
	a.add(2);
	a.add(1);
	a.add(5);
	cout<<" a list "<<endl;
	a.test();
	l.add(3);
	l.add(2);
	l.add(7);
	cout<<" l list "<<endl;
	l.test();
	s = &l;
	cout<<"after retain => "<<endl;
	a.retainAll(s);
	a.test();
	cout<<endl;
}
void test_size(){
	cout<<"test_size"<<endl;
	ArrayList<int> a;
	LinkedList<int> l;
	a.add(2);
	a.add(1);
	a.add(5);
	a.test();
	cout<<" a size => "<<a.size()<<endl;
	l.add(2);
	l.test();
	cout<<" l size => "<<l.size()<<endl;
	HashSet<int> s1;
	s1.add(5);
	s1.add(3);
	s1.add(6);
	s1.add(623);
	s1.add(61);
	s1.test();
	cout<<" s1 size => "<<s1.size()<<endl;
	cout<<endl;
}
void test_element(){
	cout<<"test_element"<<endl;
	LinkedList<int> l;
	l.add(2);
	l.add(22);
	l.add(233);
	l.add(21);
	l.test();
	cout<<" after test element =>"<<l.element()<<endl;
	cout<<endl;
}
void test_offer(){
	cout<<"test_offer"<<endl;
	LinkedList<int> l;
	l.add(25);
	l.add(20);
	l.add(23);
	l.add(21);
	l.test();
	cout<<" after test offer(5) =>"<<endl;
	l.offer(5);
	l.test();
	cout<<endl;
}
void test_poll(){
	cout<<"test_poll"<<endl;
	LinkedList<int> l;
	l.add(2);
	l.add(22);
	l.add(233);
	l.add(21);
	l.test();
	cout<<" after test poll => "<<endl;
	cout<<"clean element = "<<l.poll()<<endl<<endl;
	l.test();
	cout<<endl;
	cout<<"second test_poll"<<endl;
	LinkedList<int> l1;
	cout<<" after test poll => "<<endl;
	l1.poll();
	cout<<endl;
}
//void test_Iterator(){}



