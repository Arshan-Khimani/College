// Import ArrayList class for dynamic array
import java.util.ArrayList;

// Import List interface for storing cities
import java.util.List;

// Class representing a flight path
public class FlightPath 
{
    // List to store cities in the path
    private List<String> cities;
    
    // Variable to store total cost of the path
    private double totalCost;
    
    // Variable to store total time of the path
    private int totalTime;

    // Constructor to initialize path details
    public FlightPath(List<String> cities, double totalCost, int totalTime) 
    {
        this.cities = new ArrayList<>(cities); // Copy cities list
        this.totalCost = totalCost; // Assign total cost
        this.totalTime = totalTime; // Assign total time
    }

    // Method to get total cost
    public double getTotalCost() 
    { 
        return totalCost; // Return total cost
        
    }
    
    // Method to get total time
    public int getTotalTime() 
    { 
        return totalTime; // Return total time
        
    }

    // Method to return formatted path as a string
    public String getFormattedPath(int pathNum) 
    {
        return String.format("Path %d: %s. Time: %d Cost: %.2f", pathNum, String.join(" -> ", cities), totalTime, totalCost); // Format and return path string
    }
}