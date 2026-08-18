// Class representing a Flight object
public class Flight 
{
    // Variable to store destination city
    private String destination;
    
    // Variable to store cost of the flight
    private double cost;
    
    // Variable to store time of the flight
    private int time;
  
    // Variable to store airline carrier
    private String carrier;
    
    // Variable to store flight date
    private String date;
    
    // Variable to store departure time
    private String departureTime;

    // Constructor to initialize all flight details
    public Flight(String destination, double cost, int time, String carrier, String date, String departureTime) 
    {
        this.destination = destination; // Assign destination value
        this.cost = cost; // Assign cost value
        this.time = time; // Assign time value
        this.carrier = carrier; // Assign carrier value
        this.date = date; // Assign date value
        this.departureTime = departureTime; // Assign departure time value
    }

    // Method to get destination
    public String getDestination() 
    { 
        return destination; // Return destination
        
    }
    
    // Method to get cost
    public double getCost() 
    { 
        return cost; // Return cost
        
    }
    
    // Method to get time
    public int getTime() 
    { 
        return time; // Return time
    }
    
    // Method to get carrier
    public String getCarrier() 
    { 
        return carrier; // Return carrier
        
    }
    
    // Method to get date
    public String getDate() 
    { 
        return date; // Return date
        
    }
    
    // Method to get departure time
    public String getDepartureTime() 
    { 
        return departureTime; // Return departure time
        
    }

    // Override toString method to return destination
    @Override
    public String toString() 
    {
        return destination; // Return destination as string
    }
}