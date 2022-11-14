import java.util.*;
import java.io.*;

class JavaLoopsII{
    public static void main(String []argh){
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        int res;
        for(int i=0;i<t;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            for (int x = 0; x < n; x++)
            {
                res = a;
                for (int y = 0; y <= x; y++)
                    res += Math.pow(2, y) * b;
                System.out.print(res + " ");
            }
            System.out.print("\n");
        }
        in.close();
    }
}
