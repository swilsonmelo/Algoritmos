import java.util.Arrays;


public class MainExperimentalAnalisys {
	private static final int CORRECTNESS_EXP_COUNT = 30000;
	private static final int INCREMENT = 50000;
	private static final int MAX_SIZE = 2100000;
	private static final int MIN_SIZE = 2000000;
	private static final int EXPERIMENTS_BY_SIZE = 7;
	
	public static void main(String[] args) {
		/*
		for(int  i = 2800000; i <= 3100000; i+= 100000) {
			System.out.println(i+ " "+ experimentalEspectedTime(i));
		}
		int i;
		i = 2900000;
		System.out.println(i+ " "+ experimentalEspectedTime(i));
		// 6 segundos
		i = 5050000;
		System.out.println(i+ " "+ experimentalEspectedTime(i));
		
		*/
		experimentalCorrectness();
		experimentalComplexity();
		verifyExperimentalComplexity();
		int size = 131000;
		System.out.println(" Time for "+size);
		long times[] = runExperiment(size);
		System.out.println(size+"\t"+times[times.length/2]);
				

	}
	private static void verifyExperimentalComplexity() {
		for (int size = MIN_SIZE; size <= MAX_SIZE; size += INCREMENT)
			System.out.println(size+"\t"+experimentalEspectedTime(size));		
	}
	private static void experimentalComplexity() {

		for (int size = MIN_SIZE; size <= MAX_SIZE; size += INCREMENT)
		{
			long times[] = runExperiment(size);
			System.out.println(size+"\t"+times[times.length/2]);			
		}
	}
	private static long[] runExperiment(int size) {
		long times[] = new long[EXPERIMENTS_BY_SIZE];
		for (int i = 0; i < times.length; i++) {

			int from = Utilities.getRandomNumber(0, 10000);
			int to = from + Utilities.getRandomNumber(0, 10000);
			int a[] = Utilities.getRandomArray(size, from, to);
			long initTime = System.currentTimeMillis();
			QuickSort(a, 0, a.length-1);
			times[i] = System.currentTimeMillis()-initTime;
		}
		Arrays.sort(times);
		return times;
	}
	private static void experimentalCorrectness() {
		int errorCount = 0;
		for (int exp = 0; exp < CORRECTNESS_EXP_COUNT; exp++) {
			
			int size = Utilities.getRandomNumber(1, 100);
			int from = Utilities.getRandomNumber(0, 10000);
			int to = from + Utilities.getRandomNumber(0, 10000);

			int a[] = Utilities.getRandomArray(size, from, to);
			//System.out.println(Arrays.toString(a));
			int b[] = new int[a.length];
			System.arraycopy(a, 0, b, 0, a.length);

			//System.out.println(Arrays.toString(b));
			QuickSort(a,0,a.length-1);
			Arrays.sort(b);
			//System.out.println(Arrays.toString(a));

			//System.out.println(Arrays.toString(b));
			if( !Arrays.equals(a, b) )
				errorCount++;
		}
		System.out.println("Errors: "+errorCount);		
	}
	
	/**
	 * T(n) = 2 + n(2+2+3+n(4+3)+9)
	 * 		= 2 + 7n+7(n^2)+9n
	 * 		= 7n^2 + 16n + 2
	 * T(n) es O(n^2)
	 * @param a
	 * @returns a sorted
	 */
	/*
	public static void teacherSort( int a[] )
	{
		for (int i = 0; i < a.length; i++) {
			int indexLowest = i;
			for (int j = i+1; j < a.length; j++)
				if( a[j] < a[indexLowest])
					indexLowest = j;
			int tmp = a[i];
			a[i] = a[indexLowest];
			a[indexLowest] = tmp;
		}
	}
	*/
	public static long experimentalEspectedTime( int n )
	{
		long lineal = (long)((0.00034272727272727)*n-(122.86363636364));
		long cuadratica =(long)((4.834498834e-10)*n*n - 3.824475524e-4*n + 136.990676);
		//return (long)( (2.887331966e-7)*n*n + (9.524948735e-5)*n - 8.333333333e-2 );
		return (long)((lineal+cuadratica)/2);
		
	}
	
	public static int partition(int arr[], int low, int high) 
    { 
        int pivot = arr[high];  
        int i = (low-1); // index of smaller element 
        for (int j=low; j<high; j++) 
        { 
            // If current element is smaller than or 
            // equal to pivot 
            if (arr[j] <= pivot) 
            { 
                i++; 
  
                // swap arr[i] and arr[j] 
                int temp = arr[i]; 
                arr[i] = arr[j]; 
                arr[j] = temp; 
            } 
        } 
  
        // swap arr[i+1] and arr[high] (or pivot) 
        int temp = arr[i+1]; 
        arr[i+1] = arr[high]; 
        arr[high] = temp; 
  
        return i+1; 
    } 
	
	public static void QuickSort(int arr[], int low, int high) 
    { 
        if (low < high) 
        { 
            /* pi is partitioning index, arr[pi] is  
              now at right place */
            int pi = partition(arr, low, high); 
  
            // Recursively sort elements before 
            // partition and after partition 
            QuickSort(arr, low, pi-1); 
            QuickSort(arr, pi+1, high); 
        } 
    } 
}
