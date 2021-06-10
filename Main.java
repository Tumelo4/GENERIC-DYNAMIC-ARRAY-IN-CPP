public class Main{
	public static void main(String[] args) {
		DynamicArray<Integer> array = new  DynamicArray<Integer>();


		for (int i=0; i< 10; i++)array.insert(i);
		System.out.println(array);
		array.reverse();
		System.out.println(array);
		array.insert(10);
		System.out.println(array);
	}
} 
