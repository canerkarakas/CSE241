import java.lang.reflect.Array;
import java.util.Iterator;

public class myIterator<E> {
	private E [] array;
	private int size;
	private int index = 0;
	private int capacity;
	
	
	public myIterator() throws Exception {
		array = null;
		set_size(0);
	}
	
	public myIterator(E arr[]) throws Exception {
		int count=0;
		if(arr.getClass().getName() == "[Ljava.lang.Integer;") {
			set_size(arr.length);
			array = (E[]) new Integer[arr.length];
			for(int i=0;i<get_size();i++)
				array[i] =  (E) new Integer((Integer)arr[i]);
			while(get_array()[count].getClass().getName() == Integer.class.getName()) {
				count++;
				if(count==get_size()) 
					break;
			}
		}
		if(arr.getClass().getName() == "[Ljava.lang.String;"){
			set_size(arr.length);
			array = (E[]) new String[arr.length];
			for(int i=0;i<get_size();i++)
				array[i] =  (E) new String((String)arr[i]);
			while(get_array()[count].getClass().getName() == String.class.getName()) {
				count++;
				if(count==get_size()) 
					break;
			}
		}
		set_capacity(get_size()-count);
	}

	public E [] get_array() {
		return array;
	}
/*
	public void set_array(E [] array) throws Exception{
		if(this.get_size() == array.length)
			this.array = array;
		else 
			new Exception();
	}*/

	public int get_size() {
		return size;
	}

	public void set_size(int s) throws Exception{
		if(s>0)
			this.size = s;
		else
			new Exception();
	}

	public int get_index() {
		return index;
	}

	public void set_index(int index) throws Exception{
		if(index<this.get_size() && index>=0)
			this.index = index;
		else
			new Exception();
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
	
	public boolean hasNext() {
		if(get_array()[get_index()+1]!=null)
			return true;
		return false;
	}
	
	public E next() throws Exception{
		if(hasNext())
			this.set_index(index+1);
		else 
			new Exception();
		return get_array()[index];
	}
	
	public E remove() {
		if(get_array().getClass().getName() == "[Ljava.lang.Integer;") {
			E temp =  (E) new Integer(0);
			temp = get_array()[get_index()];
			E [] tempArr = (E[]) new Integer[get_size()-1];
			for(int i=0;i<get_size()-1;i++) 
				tempArr[i] =  (E) new Integer(0);
			for(int i=0;i<get_index();i++)
				tempArr[i] = (E) new Integer((Integer)get_array()[i]);
			for(int i=index;i<get_size()-1;i++)
				tempArr[i] = (E) new Integer((Integer)get_array()[i+1]);
			array = (E[]) new Integer[get_size()-1];
			size = get_size()-1;
			for(int i=0;i<get_size();i++) {
				array[i] =  (E) new Integer((Integer)tempArr[i]);
			}
			return temp;
		}
		else{
			E temp =  (E) new String("");
			temp = get_array()[get_index()];
			E [] tempArr = (E[]) new String[get_size()-1];
			for(int i=0;i<get_size()-1;i++) 
				tempArr[i] =  (E) new String("");
			for(int i=0;i<get_index();i++)
				tempArr[i] = (E) new String((String)get_array()[i]);
			for(int i=index;i<get_size()-1;i++)
				tempArr[i] = (E) new String((String)get_array()[i+1]);
			array = (E[]) new String[get_size()-1];
			size = get_size()-1;
			for(int i=0;i<get_size();i++) {
				array[i] =  (E) new String((String)tempArr[i]);
			}
			return temp;
		}
	}
}
