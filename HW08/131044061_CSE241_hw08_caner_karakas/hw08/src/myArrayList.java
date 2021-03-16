import java.util.Arrays;

public class myArrayList<E> implements myList<E> {

	private E [] array;
	private int size;
	private int capacity=0;
	private int index = 0;
	
	public myArrayList() throws Exception {
		size = 0;
		capacity = 0;
		index = 0;
		array = null;
	}
	
	public myArrayList(int a) throws Exception {
		size = 1;
		capacity = 1;
		index = 0;
		array = (E[]) new Integer[1];
		array[0] = (E) new Integer(-999999);
	}
	
	public myArrayList(String a) throws Exception {
		size = 1;
		capacity = 1;
		index = 0;
		array = (E[]) new String[1];
		array[0] = (E) new String("");
	}
	
	public myArrayList(E arr[]) throws Exception {
		//this(1);
		int count = 0;
		if(arr.getClass().getName() == "[Ljava.lang.Integer;") {
			set_size(arr.length);
			index = 0;
			array = (E[]) new Integer[arr.length];
			for(int i=0;i<arr.length;i++) 
				array[i] = (E) new Integer((Integer)arr[i]);
			while(array[count].getClass().getName() == Integer.class.getName()) {
				count++;
				if(count==size())
					break;
			}
			Arrays.sort(array);
		}
		if(arr.getClass().getName() == "[Ljava.lang.String;"){
			set_size(arr.length);
			array = (E[]) new String[arr.length];
			for(int i=0;i<size();i++)
				array[i] =  (E) new String((String)arr[i]);
			while(get_array()[count].getClass().getName() == String.class.getName()) {
				count++;
				if(count==size())
					break;
			}
			Arrays.sort(array);
		}
		set_capacity(size()-count);
	}
	
	
	public int get_capacity() {
		return capacity;
	}

	public void set_capacity(int c) throws Exception{
		if(c<=size && c>=0) {
			this.capacity = c;
		}
		else
			new Exception();
	}
	
	public int get_index() {
		return index;
	}

	public void set_index(int index) throws Exception{
		if(index<this.size() && index>=0)
			this.index = index;
		else
			new Exception();
	}

	public void set_size(int s) throws Exception{
		if(s>0)
			this.size = s;
		else
			new Exception();
	}
	
	public void print() {
		for(int i=0;i<size();i++)
			System.out.println(array[i]);
	}

	@Override
	public void add(E e) throws Exception {
		if(capacity!=0) {
			if(array.getClass().getName() == "[Ljava.lang.Integer;") {
				array[size-capacity] = (E) new Integer((Integer)e);
				capacity = capacity - 1;
			}
			else if(array.getClass().getName() == "[Ljava.lang.String;") {
				array[size-capacity] = (E) new String((String)e);
				capacity = capacity - 1;
			}
			else {
				new Exception();
			}
		}
		else {
			if(get_array().getClass().getName() == "[Ljava.lang.Integer;") {
				E [] tempArr = (E[]) new Integer[size()+1];
				for(int i=0;i<size();i++) 
					tempArr[i] = (E) new Integer((Integer)get_array()[i]);
				tempArr[size()] = (E) new Integer((Integer)e);
				array = (E[]) new Integer[size()+1];
				for(int i=0;i<size()+1;i++)
					array[i] = (E) new Integer((Integer)tempArr[i]);
				index = index + 1;
				size = size + 1;
			}
			else if(array.getClass().getName() == "[Ljava.lang.String;"){
				E [] tempArr = (E[]) new String[size()+1];
				for(int i=0;i<size();i++) 
					tempArr[i] =  (E) new String((String)get_array()[i]);
				tempArr[size()] = (E) new String((String)e);
				array = (E[]) new String[size()+1];
				for(int i=0;i<size()+1;i++)
					array[i] = (E) new String((String)tempArr[i]);
				index = index + 1;
				size = size + 1;
			}
			else {
				new Exception();
			}
		}
		Arrays.sort(array);
	}

	@Override
	public void addAll(myCollection<E> col) throws Exception {
		for(int i=0;i<col.size();i++)
			add((E)col.get_array()[i]);
		Arrays.sort(array);
	}

	@Override
	public void clear() {
		array = null;
		size = 0;
		capacity = 0;
		index = 0;
		
	}

	@Override
	public boolean contains(E e) {
		boolean control = false;
		for(int i=0;i<size;i++) {
			if(array[i].equals(e)) {
				control = true;
			}
		}
		return control;
	}

	@Override
	public boolean containsAll(myCollection<E> col) {
		if(col.size() == this.size()) {
			for(int i=0;i<col.size();i++) {
				if(contains(col.get_array()[i])==false)
					return false;
			}
			return true;
		}
		else
			return false;
	}

	@Override
	public boolean isEmpty() {
		if(size==0)
			return true;
		return false;
	}

	@Override
	public void remove(E e) throws Exception {
		myIterator<E> myIter = new myIterator<E>(this.get_array());
		int index = 0;
		for(int i=0;i<size();i++) {
			if(get_array()[i].equals(e)) {
				index = i;
				myIter.set_index(index);
				myIter.remove();
				if(array.getClass().getName() == "[Ljava.lang.Integer;") {
					size = size - 1;
					array = (E[]) new Integer[size()];
					for(int j=0;j<size();j++)
						array[j] = (E) new Integer((Integer)myIter.get_array()[j]);
				}
				else{
					size = size - 1;
					array = (E[]) new String[size()];
					for(int j=0;j<size();j++)
						array[j] = (E) new String((String)myIter.get_array()[j]);
				}
				i = 0;
			}
		}
		Arrays.sort(array);
	}

	@Override
	public void removeAll(myCollection<E> c) throws Exception {
		for(int i=0;i<c.size();i++) {
			for(int j=0;j<size();j++) {
				if(c.get_array()[i].equals(array[j])== true) {
					remove(array[j]);
					j=0;
					i=0;
				}
			}
		}
		Arrays.sort(array);
	}

	@Override
	public void retainAll(myCollection<E> c) throws Exception {
		boolean control = false;
		for(int i=0;i<size();i++) {
			control = false;
			for(int j=0;j<c.size();j++) {
				if(array[i].equals(c.get_array()[j]))
					control = true;
			}
			if(control==false) 
				remove(array[i]);
		}
		Arrays.sort(array);
	}

	@Override
	public int size() {
		return size;
	}

	@Override
	public E[] get_array() {
		return array;
	}

	@Override
	public myIterator<E> iterator() throws Exception {
		myIterator<E> myIter = new myIterator<E>(this.get_array());
		return myIter;
	}

}
