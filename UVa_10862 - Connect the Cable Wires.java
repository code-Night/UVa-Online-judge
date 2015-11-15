import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigInteger [] ps = new BigInteger [2010]; 
		BigInteger [] t = new BigInteger [2010];
		for(int i=0 ; i<2010 ; i++){
	        t[i]= new BigInteger("0");
	        ps[i]= new BigInteger("0");
	    }
		
		t[0] = BigInteger.valueOf(0);
		ps[0] = BigInteger.valueOf(0);
		t[1]=BigInteger.valueOf(1);
	    ps[1]=BigInteger.valueOf(1);
	    t[2]=BigInteger.valueOf(3);
	    ps[2]=BigInteger.valueOf(4);
	    
	    for(int i=3 ; i<=2000 ; i++){
	    	t[i] = t[i-1].multiply(BigInteger.valueOf(2));
	    	t[i] = t[i].add(ps[i-2]);
	    	t[i] = t[i].add(BigInteger.ONE);
	        ps[i]=ps[i].add(t[i]);
	        ps[i]=ps[i].add(ps[i-1]);
	    }
	    Scanner input = new Scanner(System.in);
	    int ind = input.nextInt();
	    while(ind != 0){
	    	System.out.println(t[ind]);
	    	ind = input.nextInt();
	    }
	}
}
