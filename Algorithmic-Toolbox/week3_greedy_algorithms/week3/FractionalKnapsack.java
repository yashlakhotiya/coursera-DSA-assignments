import java.util.*;

public class FractionalKnapsack {
    private static double getOptimalValue(long capacity, long[] values, long[] weights) {
        double value = 0;
        double weight = capacity;
        //write your code here
        int n = values.length;
        double[] valuePerWeight = new double[n];
        for(int i = 0; i < n; i++){
            valuePerWeight[i] = values[i]/weights[i];
        }
        for(int i = 0;i < n;i++){
            
        }
        return value;
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long capacity = scanner.nextInt();
        long[] values = new long[n];
        long[] weights = new long[n];
        for (int i = 0; i < n; i++) {
            values[i] = scanner.nextInt();
            weights[i] = scanner.nextInt();
        }
        System.out.println(getOptimalValue(capacity, values, weights));
    }
} 
