
#ifndef QUEUE_H_
#define QUEUE_H_

#include "Collection.h"

namespace GTUCollection {
template<typename E, typename container = queue<E> >
class Queue: public Collection<E, container> {
public:
	Queue(){}
	virtual void offer(E e) = 0;
	virtual E element() = 0;
	virtual E poll() = 0;
};

} /* namespace GTUCollection */
#endif /* QUEUE_H_ */
