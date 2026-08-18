// Import ArrayList for dynamic arrays
import java.util.ArrayList;

// Import HashSet for unique elements
import java.util.HashSet;

// Import LinkedList for adjacency list
import java.util.LinkedList;

// Import List interface
import java.util.List;

// Import Set interface
import java.util.Set;

// Import Stack for DFS traversal
import java.util.Stack;

// Class representing the flight graph
public class FlightGraph 
{
    // Adjacency list storing city nodes
    private LinkedList<CityNode> adjacencyList; 

    // Constructor to initialize adjacency list
    public FlightGraph() 
    {
        this.adjacencyList = new LinkedList<>(); // Create empty list
    }

    // Method to find a city node by name
    private CityNode getCityNode(String cityName) 
    {
        // Loop through all city nodes
        for (CityNode node : adjacencyList) 
        {
            // Check if city name matches
            if (node.getCityName().equals(cityName)) 
            {
                return node; // Return matching node
            }
        }
        
        return null; // Return null if not found
    }

    // Method to add a directed route
    public void addRoute(String from, String to, double cost, int time, String carrier, String date, String depTime)
    {
        CityNode fromNode = getCityNode(from); // Get starting city node
        
        if (fromNode == null) 
        {
            fromNode = new CityNode(from); // Create new node if not exists
            adjacencyList.add(fromNode); // Add to list
        }
        
        CityNode toNode = getCityNode(to); // Get destination city node
        
        if (toNode == null) 
        {
            toNode = new CityNode(to); // Create new node if not exists
            adjacencyList.add(toNode); // Add to list
        }

        fromNode.addFlight(new Flight(to, cost, time, carrier, date, depTime)); // Add flight edge
    }

    // Method to add route in both directions
    public void addUndirectedRoute(String a, String b, double cost, int time, String carrier, String date, String depTime) 
    {
        addRoute(a, b, cost, time, carrier, date, depTime); // Add route a to b
        addRoute(b, a, cost, time, carrier, date, depTime); // Add route b to a
    }

    // Method to find all paths between two cities
    public List<FlightPath> findAllPaths(String origin, String destination) 
    {
        List<FlightPath> allPaths = new ArrayList<>(); // List to store all paths
        CityNode startNode = getCityNode(origin); // Get start node
        
        if (startNode == null || getCityNode(destination) == null) 
        {
            return allPaths; // Return empty list if invalid cities
        }

        Stack<SearchState> stack = new Stack<>(); // Stack for DFS
        
        List<String> initialPath = new ArrayList<>(); // Initial path list
        initialPath.add(origin); // Add starting city
        Set<String> initialVisited = new HashSet<>(); // Track visited cities
        initialVisited.add(origin); // Mark origin as visited
        
        stack.push(new SearchState(origin, initialPath, initialVisited, 0.0, 0)); // Push initial state

        while (!stack.isEmpty()) 
        {
            SearchState state = stack.pop(); // Get current state

            if (state.currentCity.equals(destination)) 
            {
                allPaths.add(new FlightPath(state.pathSoFar, state.currentCost, state.currentTime)); // Add completed path
               
                continue; // Skip further exploration
            }

            CityNode currentNode = getCityNode(state.currentCity); // Get current node
            
            if (currentNode != null) 
            {
                // Loop through all flights from current city
                for (Flight flight : currentNode.getFlights()) 
                {
                    // Check if destination not yet visited
                    if (!state.visited.contains(flight.getDestination())) 
                    {
                        List<String> newPath = new ArrayList<>(state.pathSoFar); // Copy current path
                        newPath.add(flight.getDestination()); // Add next city
                        
                        Set<String> newVisited = new HashSet<>(state.visited); // Copy visited set
                        newVisited.add(flight.getDestination()); // Mark new city visited
                        
                        stack.push(new SearchState(flight.getDestination(), newPath, newVisited, state.currentCost + flight.getCost(), state.currentTime + flight.getTime())); // Push new state
                    }
                }
            }
        }
        
        return allPaths; // Return all found paths
    }
}