import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
public class D {
  public static HashMap<BigInteger, BigInteger> cache = new HashMap<BigInteger, BigInteger>();
  public static BigInteger[][] c = new BigInteger[100][100];
  public static boolean[] flags = new boolean[1000];
  public static ArrayList<BigInteger> primes = new ArrayList<BigInteger>();
  public static int count[] = new int[100];
  public static BigInteger biggest;
  public static void init() {
    primes.clear();
    for (int i = 0; i < flags.length; i ++) flags[i] = false;
    for (int i = 2; i < flags.length; i ++) {
      if (!flags[i]) {
        primes.add(new BigInteger(Integer.toString(i)));
        for (int j = i * i; j < flags.length; j += i) flags[j] = true;
      }
    }

    for (int i = 0; i < c.length; i ++) {
      c[i][0] = new BigInteger("1");
      for (int j = 1; j <= i; j ++) {
        c[i][j] = new BigInteger("0");
        if (i > 0 && j > 0 && c[i - 1][j - 1] != null)
          c[i][j] = c[i][j].add(c[i -1][j - 1]);
        if (i > 0 && c[i - 1][j] != null)
          c[i][j] = c[i][j].add(c[i - 1][j]);
      }
    }
  }
  public static void dfs(int deep, BigInteger now, int max, int n) {
    if (max == 0) {
      if (now.compareTo(biggest.ONE) < 1)
        return;
      BigInteger total = new BigInteger("1");
      for (int i = 0; i < deep; i ++) {
        total = total.multiply(c[n][count[i]]);
        if (total.compareTo(biggest) > 0)
          return;
        n -= count[i];
      }

      if (!cache.containsKey(total) || cache.get(total).compareTo(now) > 0)
        cache.put(total, now);
      return;
    }
    BigInteger num = new BigInteger("1");
    BigInteger tmp = null;
    for (int i = 0; i <= max; i ++) {
      tmp = now.multiply(num);
      if (tmp.compareTo(biggest) <= 0) {
        count[deep] = i;
        dfs(deep + 1, tmp, i, n + i);
      } else {
        break;
      }
      num = num.multiply(primes.get(deep));
    }
  }
  public static void main(String[] args) {
    init();
    biggest = new BigInteger(Long.toString(Long.MAX_VALUE));
    dfs(0, BigInteger.ONE, 66, 0);
    Scanner scanner = new Scanner(System.in);
    BigInteger k = null;
    while (scanner.hasNext()) {
      k = new BigInteger(scanner.next());
      System.out.print(k);
      System.out.print(" ");
      System.out.println(cache.get(k));
    }
  }
}
