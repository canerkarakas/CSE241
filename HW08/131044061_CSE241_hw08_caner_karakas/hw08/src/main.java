
public class main {


	static void test() throws Exception{
		System.out.println("*********TEST*********");
		System.out.println("**********************");
		Integer [] i = new Integer[3];
		Integer [] i1 = new Integer[3];
		String [] str = new String[2];
		String [] str1 = new String[2];
		i[0] = new Integer(3);
		i[1] = new Integer(2);
		i[2] = new Integer(1);
		i1[0] = new Integer(5);
		i1[1] = new Integer(6);
		i1[2] = new Integer(9);
		str[0] = new String("abcde");
		str[1] = new String("abc");
		str1[0] = new String("abcdeasd");
		str1[1] = new String("abcasdasd");
		
		
		myHashSet<Integer> tempInt = new myHashSet<Integer>(i1);
		myHashSet<String> tempStr = new myHashSet<String>(str1);
		myHashSet<Integer> myHashInt = new myHashSet<Integer>(i);
		myHashSet<String> myHashStr = new myHashSet<String>(str);
		System.out.println("HashInt and HashStr before add ");
		myHashInt.print();
		myHashStr.print();
		System.out.println("-----------");
		myHashInt.add(3);
		myHashInt.add(5);
		myHashStr.add("abc");
		myHashStr.add("abcdefg");
		System.out.println("HashInt and HashStr after add ");
		myHashInt.print();
		myHashStr.print();
		System.out.println("-----------");
		System.out.println("HashInt and HashStr before addAll ");
		myHashInt.addAll(tempInt);
		myHashStr.addAll(tempStr);
		System.out.println("-----------");
		System.out.println("HashInt and HashStr after addAll ");
		myHashInt.print();
		myHashStr.print();
		System.out.println("-----------");
		System.out.println("HashInt and HashStr before contains ");
		myHashInt.print();
		myHashStr.print();
		System.out.println("-----------");
		System.out.println("HashInt contains " + 3 + "  result = " + myHashInt.contains(3));
		System.out.println("HashInt contains " + 9 + "  result = " + myHashInt.contains(9));
		System.out.println("HashStr contains " + "a " + "  result = " + myHashStr.contains("a"));
		System.out.println("HashStr contains " + " abcasdasd " + "  result = " + myHashStr.contains("abcasdasd"));
		System.out.println("-----------");
		System.out.println("HashInt and HashStr before containsAll ");
		myHashInt.print();
		myHashStr.print();
		System.out.println("-----------");
		System.out.println("HashInt containsAll tempInt  result = " + myHashInt.containsAll(tempInt));
		System.out.println("HashInt containsAll HashInt  result = " + myHashInt.containsAll(myHashInt));
		System.out.println("HashStr containsAll tempStr  result = " + myHashStr.containsAll(tempStr));
		System.out.println("HashStr containsAll HashStr  result = " + myHashStr.containsAll(myHashStr));
		System.out.println("-----------");
		System.out.println("HashInt and HashStr before isEmpty ");
		myHashInt.print();
		myHashStr.print();
		System.out.println("-----------");
		System.out.println("HashInt isEmpty = " + myHashInt.isEmpty());
		System.out.println("HashStr isEmpty = " + myHashStr.isEmpty());
		System.out.println("-----------");
		System.out.println("HashInt and HashStr before remove ");
		myHashInt.print();
		myHashStr.print();
		System.out.println("-----------");
		myHashInt.remove(3);
		myHashStr.remove("abcasdasd");
		System.out.println("HashInt and HashStr after remove ");
		myHashInt.print();
		myHashStr.print();
		System.out.println("-----------");
		System.out.println("HashInt and HashStr before removeAll ");
		myHashInt.print();
		myHashStr.print();
		System.out.println("-----------");
		myHashInt.removeAll(tempInt);
		myHashStr.removeAll(tempStr);
		System.out.println("HashInt and HashStr after removeAll ");
		myHashInt.print();
		myHashStr.print();
		System.out.println("-----------");
		System.out.println("HashInt and HashStr before retainAll ");
		myHashInt.addAll(tempInt);
		myHashStr.addAll(tempStr);
		myHashInt.print();
		myHashStr.print();
		System.out.println("-----------");
		myHashInt.retainAll(tempInt);
		myHashStr.retainAll(tempStr);
		System.out.println("HashInt and HashStr after retainAll ");
		myHashInt.print();
		myHashStr.print();
		System.out.println("-----------");
		System.out.println("HashInt size = " + myHashInt.size());
		System.out.println("HashStr size = " + myHashStr.size());
		System.out.println("-----------");
		System.out.println("HashInt and HashStr before clear ");
		myHashInt.print();
		myHashStr.print();
		System.out.println("-----------");
		myHashInt.clear();
		myHashStr.clear();
		System.out.println("HashInt and HashStr after clear ");
		System.out.println("-----------");
		myHashInt.print();
		myHashStr.print();
		System.out.println("-----------");
		System.out.println("-----------");

		
		
		
		myLinkList<Integer> myLinkInt = new myLinkList<Integer>(i);
		myLinkList<String> myLinkStr = new myLinkList<String>(str);
		System.out.println("myLinkInt and myLinkStr before add ");
		myLinkInt.print();
		myLinkStr.print();
		System.out.println("-----------");
		myLinkInt.add(3);
		myLinkInt.add(5);
		myLinkStr.add("abc");
		myLinkStr.add("abcdefg");
		System.out.println("myLinkInt and myLinkStr after add ");
		myLinkInt.print();
		myLinkStr.print();
		System.out.println("-----------");
		System.out.println("myLinkInt and myLinkStr before addAll ");
		myLinkInt.addAll(tempInt);
		myLinkStr.addAll(tempStr);
		System.out.println("-----------");
		System.out.println("myLinkInt and myLinkStr after addAll ");
		myLinkInt.print();
		myLinkStr.print();
		System.out.println("-----------");
		System.out.println("myLinkInt and myLinkStr before contains ");
		myLinkInt.print();
		myLinkStr.print();
		System.out.println("-----------");
		System.out.println("myLinkInt contains " + 3 + "  result = " + myLinkInt.contains(3));
		System.out.println("myLinkInt contains " + 9 + "  result = " + myLinkInt.contains(9));
		System.out.println("myLinkStr contains " + "a " + "  result = " + myLinkStr.contains("a"));
		System.out.println("myLinkStr contains " + " abcasdasd " + "  result = " + myLinkStr.contains("abcasdasd"));
		System.out.println("-----------");
		System.out.println("myLinkInt and myLinkStr before containsAll ");
		myLinkInt.print();
		myLinkStr.print();
		System.out.println("-----------");
		System.out.println("myLinkInt containsAll tempInt  result = " + myLinkInt.containsAll(tempInt));
		System.out.println("myLinkInt containsAll HashInt  result = " + myLinkInt.containsAll(myLinkInt));
		System.out.println("myLinkStr containsAll tempStr  result = " +myLinkStr.containsAll(tempStr));
		System.out.println("myLinkStr containsAll HashStr  result = " +myLinkStr.containsAll(myLinkStr));
		System.out.println("-----------");
		System.out.println("myLinkInt and HashStr before isEmpty ");
		myLinkInt.print();
		myLinkStr.print();
		System.out.println("-----------");
		System.out.println("myLinkInt isEmpty = " + myLinkInt.isEmpty());
		System.out.println("myLinkStr isEmpty = " + myLinkStr.isEmpty());
		System.out.println("-----------");
		System.out.println("myLinkInt and myLinkStr before remove ");
		myLinkInt.print();
		myLinkStr.print();
		System.out.println("-----------");
		myLinkInt.remove(3);
		myLinkStr.remove("abcasdasd");
		System.out.println("myLinkInt and myLinkStr after remove ");
		myLinkInt.print();
		myLinkStr.print();
		System.out.println("-----------");
		System.out.println("myLinkInt and myLinkStr before removeAll ");
		myLinkInt.print();
		myLinkStr.print();
		System.out.println("-----------");
		myLinkInt.removeAll(tempInt);
		myLinkStr.removeAll(tempStr);
		System.out.println("myLinkInt and myLinkStr after removeAll ");
		myLinkInt.print();
		myLinkStr.print();
		System.out.println("-----------");
		System.out.println("myLinkInt and myLinkStr before retainAll ");
		myLinkInt.addAll(tempInt);
		myLinkStr.addAll(tempStr);
		myLinkInt.print();
		myLinkStr.print();
		System.out.println("-----------");
		myLinkInt.retainAll(tempInt);
		myLinkStr.retainAll(tempStr);
		System.out.println("myLinkInt and myLinkStr after retainAll ");
		myLinkInt.print();
		myLinkStr.print();
		System.out.println("-----------");
		System.out.println("myLinkInt size = " + myLinkInt.size());
		System.out.println("HashStr size = " + myLinkStr.size());
		System.out.println("------------------------------------");
		System.out.println("myLinkInt element = " + myLinkInt.element());
		System.out.println("myLinkStr element = " + myLinkStr.element());
		System.out.println("myLinkInt and myLinkStr before offer ");
		myLinkInt.print();
		myLinkStr.print();
		System.out.println("-----------");
		myLinkInt.offer(3);
		myLinkInt.offer(5);
		myLinkStr.offer("abc");
		myLinkStr.offer("abcdefg");
		System.out.println("myLinkInt and myLinkStr after offer ");
		myLinkInt.print();
		myLinkStr.print();
		System.out.println("-----------");
		System.out.println("myLinkInt and myLinkStr before poll ");
		System.out.println("myLinkInt poll = " + myLinkInt.poll());
		System.out.println("myLinkStr poll = " + myLinkStr.poll());
		System.out.println("myLinkInt and myLinkStr after poll ");
		myLinkInt.print();
		myLinkStr.print();
		System.out.println("myLinkInt and myLinkStr before clear ");
		myLinkInt.print();
		myLinkStr.print();
		System.out.println("-----------");
		myLinkInt.clear();
		myLinkStr.clear();
		System.out.println("myLinkInt and myLinkStr after clear ");
		System.out.println("-----------");
		myLinkInt.print();
		myLinkStr.print();
		System.out.println("-----------");
		System.out.println("-----------");
		
		
		
		myArrayList<Integer> myArrayInt = new myArrayList<Integer>(i);
		myArrayList<String> myArrayStr = new myArrayList<String>(str);
		System.out.println("myArrayInt and myArrayStr before add ");
		myArrayInt.print();
		myArrayStr.print();
		System.out.println("-----------");
		myArrayInt.add(3);
		myArrayInt.add(5);
		myArrayStr.add("abc");
		myArrayStr.add("abcdefg");
		System.out.println("myArrayInt and myArrayStr after add ");
		myArrayInt.print();
		myArrayStr.print();
		System.out.println("-----------");
		System.out.println("myArrayInt and myArrayStr before addAll ");
		myArrayInt.print();
		myArrayStr.print();
		myArrayInt.addAll(tempInt);
		myArrayStr.addAll(tempStr);
		System.out.println("-----------");
		System.out.println("myArrayInt and myArrayStr after addAll ");
		myArrayInt.print();
		myArrayStr.print();
		System.out.println("-----------");
		System.out.println("myArrayInt and myArrayStr before contains ");
		myArrayInt.print();
		myArrayStr.print();
		System.out.println("-----------");
		System.out.println("myArrayInt contains " + 3 + "  result = " + myArrayInt.contains(3));
		System.out.println("myArrayInt contains " + 9 + "  result = " + myArrayInt.contains(9));
		System.out.println("myArrayStr contains " + "a " + "  result = " + myArrayStr.contains("a"));
		System.out.println("myArrayStr contains " + " abcasdasd " + "  result = " + myArrayStr.contains("abcasdasd"));
		System.out.println("-----------");
		System.out.println("myArrayInt and myArrayStr before containsAll ");
		myArrayInt.print();
		myArrayStr.print();
		System.out.println("-----------");
		System.out.println("myArrayInt containsAll tempInt  result = " + myArrayInt.containsAll(tempInt));
		System.out.println("myArrayInt containsAll myArrayInt  result = " + myArrayInt.containsAll(myArrayInt));
		System.out.println("myArrayStr containsAll tempStr  result = " + myArrayStr.containsAll(tempStr));
		System.out.println("myArrayStr containsAll myArrayStr  result = " + myArrayStr.containsAll(myArrayStr));
		System.out.println("-----------");
		System.out.println("myArrayInt and myArrayStr before isEmpty ");
		myArrayInt.print();
		myArrayStr.print();
		System.out.println("-----------");
		System.out.println("myArrayInt isEmpty = " + myArrayInt.isEmpty());
		System.out.println("myArrayStr isEmpty = " + myArrayStr.isEmpty());
		System.out.println("-----------");
		System.out.println("myArrayInt and myArrayStr before remove ");
		myArrayInt.print();
		myArrayStr.print();
		System.out.println("-----------");
		myArrayInt.remove(3);
		myArrayStr.remove("abcasdasd");
		System.out.println("myArrayInt and myArrayStr after remove ");
		myArrayInt.print();
		myArrayStr.print();
		System.out.println("-----------");
		System.out.println("myArrayInt and myArrayStr before removeAll ");
		myArrayInt.print();
		myArrayStr.print();
		System.out.println("-----------");
		myHashInt.removeAll(tempInt);
		myHashStr.removeAll(tempStr);
		System.out.println("myArrayInt and myArrayStr after removeAll ");
		myArrayInt.print();
		myArrayStr.print();
		System.out.println("-----------");
		System.out.println("myArrayInt and myArrayStr before retainAll ");
		myArrayInt.addAll(tempInt);
		myArrayStr.addAll(tempStr);
		myArrayInt.print();
		myArrayStr.print();
		System.out.println("-----------");
		myArrayInt.retainAll(tempInt);
		myArrayStr.retainAll(tempStr);
		System.out.println("myArrayInt and myArrayStr after retainAll ");
		myArrayInt.print();
		myArrayStr.print();
		System.out.println("-----------");
		System.out.println("myArrayInt size = " + myArrayInt.size());
		System.out.println("myArrayStr size = " + myArrayStr.size());
		System.out.println("-----------");
		System.out.println("myArrayInt and HashStr before clear ");
		myArrayInt.print();
		myArrayStr.print();
		System.out.println("-----------");
		myHashInt.clear();
		myHashStr.clear();
		System.out.println("myArrayInt and myArrayStr after clear ");
		System.out.println("-----------");
		myArrayInt.print();
		myArrayStr.print();
		System.out.println("-----------");
		System.out.println("-----------");
		
		System.out.println("-----------");
	}
	
	public static void test_Iterator() throws Exception {
		System.out.println("*******************************");
		System.out.println("*******************************");
		System.out.println("*********test_Iterator*********");
		System.out.println("*******************************");
		System.out.println("*******************************");
		Integer [] i = new Integer[3];
		Integer [] i1 = new Integer[3];
		String [] str = new String[2];
		String [] str1 = new String[2];
		i[0] = new Integer(3);
		i[1] = new Integer(2);
		i[2] = new Integer(1);
		i1[0] = new Integer(5);
		i1[1] = new Integer(6);
		i1[2] = new Integer(9);
		str[0] = new String("abcde");
		str[1] = new String("abc");
		str1[0] = new String("abcdeasd");
		str1[1] = new String("abcasdasd");
		
		
		myHashSet<Integer> myHashInt = new myHashSet<Integer>(i1);
		myHashSet<String> myHashStr = new myHashSet<String>(str1);
		
		myLinkList<Integer> myLinkInt = new myLinkList<Integer>(i);
		myLinkList<String> myLinkStr = new myLinkList<String>(str);
		
		myArrayList<Integer> myArrayInt = new myArrayList<Integer>(i);
		myArrayList<String> myArrayStr = new myArrayList<String>(str);
		
		myIterator<Integer> myIterHashInt = new myIterator<Integer>(myHashInt.get_array());
		myIterator<String> myIterHashStr = new myIterator<String>(myHashStr.get_array());
		
		myIterator<Integer> myIterLinkInt = new myIterator<Integer>(myLinkInt.get_array());
		myIterator<String> myIterLinkStr = new myIterator<String>(myLinkStr.get_array());
		
		myIterator<Integer> myIterArrayInt = new myIterator<Integer>(myArrayInt.get_array());
		myIterator<String> myIterArrayStr = new myIterator<String>(myArrayStr.get_array());
		
		System.out.println("myIterHashInt hasNext == " + myIterHashInt.hasNext());
		System.out.println("myIterHashInt next == " + myIterHashInt.next());
		System.out.println("myIterHashInt hasNext == " + myIterHashInt.hasNext());
		System.out.println("myIterHashInt next == " + myIterHashInt.next());
		//System.out.println("myIterHashInt hasNext == " + myIterHashInt.hasNext());
		
		System.out.println("myIterHashStr hasNext == " + myIterHashStr.hasNext());
		System.out.println("myIterHashStr next == " + myIterHashStr.next());
		//System.out.println("myIterHashStr hasNext == " + myIterHashStr.hasNext());
		//System.out.println("myIterHashStr next == " + myIterHashStr.next());
		//System.out.println("myIterHashInt hasNext == " + myIterHashInt.hasNext());
		
		System.out.println("myIterLinkInt hasNext == " + myIterLinkInt.hasNext());
		System.out.println("myIterLinkInt next == " + myIterLinkInt.next());
		System.out.println("myIterLinkInt hasNext == " + myIterLinkInt.hasNext());
		System.out.println("myIterLinkInt next == " + myIterLinkInt.next());
		//System.out.println("myIterHashInt hasNext == " + myIterHashInt.hasNext());
		
		System.out.println("myIterLinkStr hasNext == " + myIterLinkStr.hasNext());
		System.out.println("myIterLinkStr next == " + myIterLinkStr.next());
		//System.out.println("myIterLinkStr hasNext == " + myIterLinkStr.hasNext());
		//System.out.println("myIterLinkStr next == " + myIterLinkStr.next());
		//System.out.println("myIterLinkStr hasNext == " + myIterLinkStr.hasNext());
		
		System.out.println("myIterArrayInt hasNext == " + myIterArrayInt.hasNext());
		System.out.println("myIterArrayInt next == " + myIterArrayInt.next());
		System.out.println("myIterArrayInt hasNext == " + myIterArrayInt.hasNext());
		System.out.println("myIterArrayInt next == " + myIterArrayInt.next());
		//System.out.println("myIterArrayInt hasNext == " + myIterArrayInt.hasNext());
		
		System.out.println("myIterArrayStr hasNext == " + myIterArrayStr.hasNext());
		System.out.println("myIterArrayStr next == " + myIterArrayStr.next());
		//System.out.println("myIterArrayStr hasNext == " + myIterArrayStr.hasNext());
		//System.out.println("myIterArrayStr next == " + myIterArrayStr.next());
		//System.out.println("myIterArrayStr hasNext == " + myIterArrayStr.hasNext());
		System.out.println("*******************************");
		System.out.println("*******************************");
		System.out.println("*********test_Iterator*********");
		System.out.println("*******************************");
		System.out.println("*******************************");
		
	}

	public static void main(String[] args) {
		try {
			test();
			test_Iterator();
			
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

}
