// Creating Generic Dynamic Array

@SuppressWarnings({"unchecked","rawtypes"})
public class DynamicArray<T extends Comparable<T>>
{
	private Comparable[] array;
	private Boolean flag; // if flag is true mean  array store data in ascending order 

	public DynamicArray()
	{
		array = new Comparable[0];
		flag = true;
	}

	public void insert(T data)
	{
		this.resize();
		if (flag == true)
		{
			switch(array.length)
			{
				case 1:
					array[0] = data;
				break;
				default:
					int index = 0;
					for (; index <array.length-1 && array[index].compareTo(data) < 0; index++);
					
					if (array[index] != null)
					{
						for ( int count = array.length - 1; count > index ; array[count] = array[count - 1], count--);
						array[index] = data;
					}
					else
					{
						array[index] = data;
					}
				break;
			}

		}
		else
		{
			switch(array.length)
			{
				case 1:
					array[0] = data;
				break;

				default:
					int index = 0;
					for (; index <array.length-1 && array[index].compareTo(data) > 0; index++);

					if (array[index] != null)
					{
						for ( int count = array.length - 1; count > index ; array[count] = array[count - 1], count--);
						array[index] = data;
					}
					else
					{
						array[index] = data;
					}

				break;
			}
		}
	}

	@Override
	public String toString()
	{
		String str = "[";

		for (int index = 0; index <array.length ; index++)
		{
			if (index + 1 == array.length)
			{
				str +=array[index];
			}
			else str+=array[index]+",";
		}
		str+="]";
		return str;
	}

	public void reverse()
	{
		flag = !flag;

		for ( int i = 0, j = array.length-1 ; i < (array.length/2); i++,j--)
		{
			Comparable tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}

	public void resize()
	{
		Comparable[]  tmp = new Comparable[array.length+1];

		for (int index = 0; index < array.length; index++)
		{
			tmp[index] = array[index];
		}

		array = new Comparable[tmp.length];

		for (int index =0; index <tmp.length-1; index++)
		{
			array[index] = tmp[index];
		}
		array[array.length-1] = null;
	}

}
