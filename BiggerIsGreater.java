/* Always look for the increasing string starts from the end
Then switch the char right before the string with the minimum char
that is greater than it in the increasing string. Finally, sort the
modified increasing string.
*/
import java.io.*;
import java.util.*;


public class Solution {

  private static String noSol = "no answer";

  public static void main(String[] args) {
    boolean possible = false;

    //Scanner to read input;
    Scanner input = new Scanner(System.in);

    //Number of queries
    long strNum = input.nextInt();
    long num = 0;
    while(num++ < strNum) {
      possible = false;
      char charArr[] = input.next().toCharArray();
      int count = 1;
      char pre = charArr[charArr.length - 1];
      int i;
      for(i = charArr.length - 2; i >= 0; i--) {
        if(charArr[i] >= pre)
        count++;
        else
        break;
        pre = charArr[i];
      }
      if(count == charArr.length) {
        System.out.println(noSol);
        continue;
      }
      for(int j = charArr.length - 1; j >= 0; j--) {
        if(charArr[j] > charArr[i]) {
          char temp = charArr[j];
          charArr[j] = charArr[i];
          charArr[i] = temp;
          Arrays.sort(charArr, i + 1, charArr.length);
          break;
        }
      }
      System.out.println(new String(charArr));

    }

  }
}
