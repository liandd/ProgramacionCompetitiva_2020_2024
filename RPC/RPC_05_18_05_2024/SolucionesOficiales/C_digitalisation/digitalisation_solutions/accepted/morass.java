import java.util.Scanner;

public class morass {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int C = scanner.nextInt();
        int X=0, Y=0, a, b;
        int[] A = new int[M + N + 1];
        for(int i=0; i<N; ++i){
            a = scanner.nextInt();
            b = scanner.nextInt();
            if(A[a]<C){
                A[a]++;
                X++;
            }else if(A[b]<C){
                A[b]++;
                Y++;
            }
        }
        System.out.println(X + " " + Y);
        scanner.close();
    }
}
