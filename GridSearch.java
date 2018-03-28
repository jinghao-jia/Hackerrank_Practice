/* Just use the brute force */
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
      boolean found = false;
      int R = in.nextInt();
      int C = in.nextInt();
      String[] G = new String[R];
      for(int G_i=0; G_i < R; G_i++){
        G[G_i] = in.next();
      }
      int r = in.nextInt();
      int c = in.nextInt();
      String[] P = new String[r];
      for(int P_i=0; P_i < r; P_i++){
        P[P_i] = in.next();
      }
      //Nested loop to traverse through the whole matrix
      for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {

          //If the first char matches and the matrix is still in bound
          if(G[i].charAt(j) == P[0].charAt(0) && i + r <= R && j + c <= C) {
            boolean fail = false; //Flag to indicator whether this is a successful match

            //Loop to check the whole possible area
            for(int ii = 0; ii < r; ii++) {

              //If not success, stop
              if(fail)
              break;
              for(int jj = 0; jj < c; jj++) {

                // If fails to match one element, stop and set flag
                if(G[i + ii].charAt(j + jj) != P[ii].charAt(jj)) {
                  fail = true;
                  break;
                }
                if(ii == r - 1 && jj == c - 1) {
                  found = true;
                }
              }
            }
          }
          if(found)
          break;
        }
        if(found)
        break;
      }
      if(found)
      System.out.println("YES");
      else
      System.out.println("NO");
    }
  }
}
