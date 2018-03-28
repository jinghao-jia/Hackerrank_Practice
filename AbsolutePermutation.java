/* The set has the abs permutation for k != 0 if and only if n is even and is
divisible by 2k. The operation is just loop through the set and add k to
element ai (ai < k) and subtract the ai + k term by k (basically swapping)
the abs permutation is always unique
*/
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int t = in.nextInt();
    for(int a0 = 0; a0 < t; a0++){
      int n = in.nextInt();
      int k = in.nextInt();
      if(k != 0 && n % (2 * k) != 0 || k > n / 2) {
        System.out.println(-1);
        continue;
      }
      int[] array = new int[n];
      boolean[] arrayb = new boolean[n];
      for(int i = 0; i < n; i++) {
        array[i] = i + 1;
        arrayb[i] = false;
      }
      if(k != 0) {
        for(int i = 0; i < n; i++) {
          if(!arrayb[i]) {
            int temp = array[i + k];
            array[i + k] = array[i];
            array[i] = temp;
            arrayb[i] = true;
            arrayb[i + k] = true;
          }
        }
      }
      for(int i = 0; i < n; i++) {
        System.out.print(array[i] + " ");
      }
      System.out.println();
    }
  }
}
