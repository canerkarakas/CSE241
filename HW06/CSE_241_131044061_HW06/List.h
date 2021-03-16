

#ifndef LIST_H_
#define LIST_H_

#include "Collection.h"

namespace GTUCollection {
template<typename E, typename container = list<E> >
class List: public Collection<E, container> {
public:
	List(){}

};

} /* namespace GTUCollection */
#endif /* LIST_H_ */
