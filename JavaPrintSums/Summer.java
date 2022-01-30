package Ex2;
public class Summer {
    
    
    int a = 0;
    int b = 0;

    
    void cal1(){
        for (int i = 1; i <= 100; i++){
                a += i; 
            }
        System.out.println("The sum from 1 to 100 is : " +a);
    }

    void cal2(){
        for (int j = 100; j <= 1000; j++){
                b += j; 
            }
        System.out.println("The sum from 100 to 1000 is : " +b);


    }
}
