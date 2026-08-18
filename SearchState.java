// Import ArrayList for  list storage
import java.util.ArrayList;

// Import HashSet for storing unique visited cities
import java.util.HashSet;

// Import List interface
import java.util.List;

// Import Set interface
import java.util.Set;

// Class representing the state during search
public class SearchState 
{
    // Current city being visited
    public String currentCity;
    
    // List of cities visited so far
    public List<String> pathSoFar;
    
    // Set of visited cities to avoid cycles
    public Set<String> visited; 
    
    // Current total cost so far
    public double currentCost;
    
    // Current total time so far
    public int currentTime;

    // Constructor to initialize search state
    public SearchState(String currentCity, List<String> pathSoFar, Set<String> visited, double currentCost, int currentTime) 
    {
        this.currentCity = currentCity; // Set current city
        this.pathSoFar = new ArrayList<>(pathSoFar); // Copy path list
        this.visited = new HashSet<>(visited); // Copy visited set
        this.currentCost = currentCost; // Set current cost
        this.currentTime = currentTime; // Set current time
    }
}