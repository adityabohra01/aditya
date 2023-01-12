// // class test{
// //     public static void main(String [] args){
// //         long res = Integer.parseInt("987654321");
// //         System.out.println(res);
// //     }
// // }
// //explanation of big integer

// // Path: test.java
// import java.math.BigInteger;
// class test{
//     public static void main(String [] args){
//         BigInteger res = new BigInteger("987654321564276482882542558824827548254852854");
//         System.out.println(res);
//         //check type of res
//         System.out.println(res.getClass());
    
//     //converting biginteger to String
//     //String str = res.toString();
//     //add 1 in biginteger
//     res = res.add(BigInteger.ONE);
//     // conver biginteger to ARRAY OF INTEGERS
//     int [] arr = res.toString().chars().map(c -> c-'0').toArray();
//     //print array
//     for(int i=0;i<arr.length;i++){
//         System.out.print(arr[i]+" ");
//     }
// }
// //connect to database mysql
// // Path: test.java
import java.sql.*;
class test{
    public static void main(String [] args){
        try{
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/","kritibohra","kriti@23");
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery("select * from student");
            while(rs.next()){
                System.out.println(rs.getInt(1)+" "+rs.getString(2));
            }
            con.close();
        }catch(Exception e){
            System.out.println(e);
        }
    }
}

