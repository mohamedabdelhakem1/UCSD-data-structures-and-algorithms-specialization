import java.util.*;
import java.io.*;

public class substring_equality {

static  long m1 = 1000000009;
static  long m2 = 1000000007 ;
static long power(long  x, long y, long p) 
{ 
   long res = 1;      
    x = x % p;  
    while (y > 0) 
    {  
        if((y & 1)==1) 
            res = (res * x) % p; 
        y = y >> 1;  
        x = (x * x) % p;  
    } 
    return res; 
} 

ArrayList<Long> precompute_hashes(String text, long  m,long  x ) {
	
    int n = text.length();
    ArrayList<Long> H = new ArrayList<>();
    H.add((long) 0);
    for (int i = 1 ; i <= n; i++) {
        H.add((((x *  H.get(i-1)) % m ) + text.charAt(i-1)) % m);
    }
    return H;
}
	public class Solver {
		private String s;
		ArrayList<Long> H1;
		ArrayList<Long> H2;
		long x;
		public Solver(String s) {
			this.s = s;
			x = 31;
			 H1 = precompute_hashes(s,m1,x);
		     H2 = precompute_hashes(s,m2,x);
		}
		public boolean ask(int a, int b, int l) {
			  long x_l_1 = power(x,l,m1);
		      long x_l_2 = power(x,l,m2);
		      x_l_1 *= -1;
		      x_l_2 *= -1;
		      long ha1 = (((m1 + x_l_1 * H1.get(a) ) % m1) + H1.get(a+l) ) % m1;
		      long hb1 = (((m1 + x_l_1 * H1.get(b) ) % m1) + H1.get(b+l)  )% m1;
		      long ha2 = (((m2 + x_l_2 * H2.get(a) ) % m2) + H2.get(a+l)  )% m2;
		      long hb2 = (((m2 + x_l_2 * H2.get(b) ) % m2) + H2.get(b+l)  )% m2;
		        return (ha1 == hb1) && (ha2 == hb2);
		}
	}

	public void run() throws IOException {
		FastScanner in = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		String s = in.next();
		int q = in.nextInt();
		Solver solver = new Solver(s);
		for (int i = 0; i < q; i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			int l = in.nextInt();
			out.println(solver.ask(a, b, l) ? "Yes" : "No");
		}
		out.close();
	}

	static public void main(String[] args) throws IOException {
	    new substring_equality().run();
	}

	class FastScanner {
		StringTokenizer tok = new StringTokenizer("");
		BufferedReader in;

		FastScanner() {
			in = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() throws IOException {
			while (!tok.hasMoreElements())
				tok = new StringTokenizer(in.readLine());
			return tok.nextToken();
		}
		int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
	}
}
