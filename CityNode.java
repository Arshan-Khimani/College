// Import LinkedList class for storing flights
import java.util.LinkedList;

// Class representing a city node in the graph
public class CityNode 
{
    // Variable to store the name of the city
    private String cityName;
    
    // LinkedList to store flights from this city
    private LinkedList<Flight> flights; 

    // Constructor to initialize city name and flight list
    public CityNode(String cityName) 
    {
        this.cityName = cityName; // Assign city name
        this.flights = new LinkedList<>(); // Create empty list of flights
    }

    // Method to get the city name
    public String getCityName() 
    { 
        return cityName; // Return city name
        
    }
    
    // Method to get list of flights
    public LinkedList<Flight> getFlights() 
    { 
        return flights; // Return flights list
        
    }

    // Method to add a flight to the list
    public void addFlight(Flight flight) 
    {
        this.flights.add(flight); // Add flight to list
    }
}