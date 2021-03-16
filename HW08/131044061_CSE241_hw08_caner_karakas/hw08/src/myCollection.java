

public interface myCollection<E>{
	public abstract void add(E e)throws Exception;
	public abstract void addAll(myCollection<E> col) throws Exception;
	public abstract void clear();
	public abstract boolean contains(E e);
	public abstract boolean containsAll(myCollection<E> col);
	public abstract boolean isEmpty();
	public abstract void remove(E e) throws Exception;
	public abstract void removeAll(myCollection<E> c) throws Exception;
	public abstract void retainAll(myCollection<E> c) throws Exception;
	public abstract int size();
	public abstract E[] get_array();
	public abstract myIterator<E> iterator() throws Exception;
}
