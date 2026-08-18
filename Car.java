public class Car
{
    private String model;
    private String color;
    private int miles;
    private String vin;
    
    public Car(String model, String color, int miles, String vin)
    {
        this.model = model;
        this.color = color;
        this.miles = miles;
        this.vin = vin;
    }
    
    public void goVrom()
    {
        System.out.println("Vroom vroom");
    }
    
    public String toString()
    {
        return color +  " " + model + " with " + miles + " miles and VIN " + vin;
    }
}