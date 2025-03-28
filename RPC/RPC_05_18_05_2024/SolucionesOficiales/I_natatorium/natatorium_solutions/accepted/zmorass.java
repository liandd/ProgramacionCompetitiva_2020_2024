import java.util.Scanner;

public class zmorass {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long d = scanner.nextLong();
        long n = scanner.nextInt();
        int[] numbers = new int[2];
        int I=0, a;
        for(int i=0; i<n; i++){
            a = scanner.nextInt();
            if ( d % a == 0){
                numbers[I] = a;
                I++;
            }
        }
        String result = numbers[0] + " " + numbers[1];
        if(numbers[0] > numbers[1]){
            result = numbers[1] + " " + numbers[0];
        }
        System.out.println(result);
        scanner.close();
    }
}
