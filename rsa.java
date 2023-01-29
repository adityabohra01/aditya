import java.math.BigInteger;
import java.security.SecureRandom;
import java.util.Scanner;

class rsa{
    static BigInteger p, q, n, phi_n, e, d;
    static int bitlength = 64;
    static SecureRandom sr = new SecureRandom();

    static String encrypt(String msg){
        return new BigInteger(msg.getBytes()).modPow(e,n).toString();
    }
    static String decrypt(String msg){
        BigInteger DecryptedMsg = new BigInteger(msg).modPow(d,n);
        return new String(DecryptedMsg.toByteArray());
    }
    public static void main(String [] args){

        p = BigInteger.probablePrime(bitlength, sr);
        q = BigInteger.probablePrime(bitlength, sr);
        n = p.multiply(q);
        phi_n = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));
        e = BigInteger.probablePrime(bitlength/2, sr);
        while(phi_n.gcd(e).compareTo(BigInteger.ONE) !=0 && e.compareTo(phi_n) < 0){
            e.add(BigInteger.ONE);
        }
        d = e.modInverse(phi_n);
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the message to be encrypted: ");
        String msg = sc.nextLine();
        System.out.println("Encrypted message: "+encrypt(msg));
        System.out.println("Decrypted message: "+decrypt(encrypt(msg)));
        sc.close();
    }
}

