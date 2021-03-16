

import java.util.Queue;

public interface myQueue<E> extends myCollection<E> {
	public abstract E element();
	public abstract E poll() throws Exception;
	public abstract void offer(E e);

}
