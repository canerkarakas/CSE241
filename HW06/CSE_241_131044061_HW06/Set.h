#ifndef SET_H_
#define SET_H_

#include "Collection.h"

namespace GTUCollection {

template<typename E, typename container = set<E> >
class Set: public Collection<E, container> {
public:
	Set(){}
};

} /* namespace GTUCollection */
#endif /* SET_H_ */
