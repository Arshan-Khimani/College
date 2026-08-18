import java.util.Scanner;

public class Main
{
    public static void saySomethingNice(String name)
    {
        System.out.println("You look lovely today, " + name);
    }
    
    public static void collatz(int x)
    {
        System.out.println(x);
        
        if(x==1)
        {
            return;
        }
        
        if(x%2 == 0)
        {
            collatz(x/2);
            
        }
        else
        {
            collatz(3*x+1);
        }
    }
    
	public static void main(String[] args) 
	{
		System.out.println("Hello World");
		
		int x = 7;
		
		if(x%2 == 0)
		{
		    System.out.println(x + " is even");
		}
		else
		{
		    System.out.println(x + " is odd");
		}
		
		for(int i = 0; i<5; i++)
		{
		    System.out.println("i = "+i);
		}
		
		int j = 0;
		
		while(j < 5)
		{
		    System.out.println("j = "+j);
		    j++;
		}
		
		int k = 0;
		
		do
		{
		    System.out.println("k ="+k);
		    k++;
		}while(k<6);
		
		int h = 3;
		
		switch(h)
		{
		    case 0:
		        System.out.println("h = 0");
		        break;
		    case 1:
		        System.out.println("h = 1");
		        break;
		    default:
		        System.out.println("h is a weird number");
		        break;
		    
		}
		
		collatz(2134);
		Scanner input = new Scanner(System.in);
		
		System.out.print("Now enter your name: ");

		String name = input.nextLine();
	    
	    System.out.println("Thanks " + name);
	    
	    saySomethingNice(name);
	    
	    String vin;
	    String color;
	    int miles;
	    String model;
	    
	    System.out.println("Lets talk about cars. What model do you have? ");
	    
	    model = input.nextLine();
	    
	    System.out.println("Color? ");
	    
	    color = input.nextLine();
	    
	    System.out.println("miles? ");
	    
	    miles = input.nextInt();
	    input.nextLine();
	    
	    System.out.println("Vin? ");
	    
	    vin = input.nextLine();
	    
	    Car c1 = new Car(model, color, miles, vin);
	    System.out.println("Nice, I also have a " + c1);
	    
	    
	    c1.goVrom();
	    input.close();

	    
	}
}
