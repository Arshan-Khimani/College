// Import class to read text from files
import java.io.BufferedReader;

// Import class to read files
import java.io.FileReader;

// Import class to write to files
import java.io.FileWriter;

// Import class to handle input/output errors
import java.io.IOException;

// Import class to write formatted text to files
import java.io.PrintWriter;

// Import List  for storing multiple items
import java.util.List;

// Main class of the program
public class Main 
{

    // Main method where program starts
    public static void main(String[] args)
    {
        // Get flight data file name from arguments or use default
        String flightDataFile = (args.length >= 1) ? args[0] : "flightData.txt";
        
        // Get requested flights file name from arguments or use default
        String requestedFlightsFile = (args.length >= 2) ? args[1] : "requestedFlights.txt";
        
        // Get output file name from arguments or use default
        String outputFile = (args.length >= 3) ? args[2] : "output.txt";

        // Create a FlightGraph object to store flight routes
        FlightGraph planner = new FlightGraph();

        // Print message showing which files are being read
        System.out.println("Reading from " + flightDataFile + " and " + requestedFlightsFile + "...");

        // Try to read the flight data file
        try (BufferedReader br = new BufferedReader(new FileReader(flightDataFile))) 
        {
            // Read the first line 
            String line = br.readLine();
        
            // Check if file is not empty
            if (line != null) 
            {
                // Convert first line to number of records
                int numRecords = Integer.parseInt(line.trim()); 
                
                // Loop through all records
                for (int i = 0; i < numRecords; i++) 
                {
                    // Read next line
                    line = br.readLine();
                    
                    // Check if line is not empty
                    if (line != null)
                    {
                        // Split line into parts using |
                        String[] parts = line.split("\\|"); 
                        
                        // Get origin city
                        String origin = parts[0];
                        
                        // Get destination city
                        String dest = parts[1];
                        
                        // Convert cost to double
                        double cost = Double.parseDouble(parts[2]);
                        
                        // Convert time to integer
                        int time = Integer.parseInt(parts[3]);
   
                        // Get carrier or use default if missing
                        String carrier = parts.length > 4 ? parts[4] : "DefaultCarrier";
                        
                        // Get date or use default if missing
                        String date = parts.length > 5 ? parts[5] : "01-01-2026";
                        
                        // Get departure time or use default if missing
                        String depTime = parts.length > 6 ? parts[6] : "00:00";

                        // Add route to the graph
                        planner.addUndirectedRoute(origin, dest, cost, time, carrier, date, depTime);
                    }
                }
            }
        } 
        // Catch any file reading errors
        catch (IOException e) 
        {
            // Print error message
            System.err.println("Error reading flight data: " + e.getMessage());
        
            // Stop program if error occurs
            return;
        }

        // Try to read requested flights and write output
        try (BufferedReader br = new BufferedReader(new FileReader(requestedFlightsFile));
             PrintWriter writer = new PrintWriter(new FileWriter(outputFile))) 
        { 
             
            // Read first line 
            String line = br.readLine();
            
            // Check if file is not empty
            if (line != null) 
            {
                // Convert first line to number of requests
                int numRequests = Integer.parseInt(line.trim()); 
                
                // Loop through each request
                for (int i = 1; i <= numRequests; i++) 
                {
                    // Read next line
                    line = br.readLine();
                    
                    // Check if line is not empty
                    if (line != null)
                    {
                        // Split request line using |
                        String[] parts = line.split("\\|");
                        
                        // Get origin city
                        String origin = parts[0];
                        
                        // Get destination city
                        String dest = parts[1];
                        
                        // Check if sorting should be by time
                        boolean sortByTime = parts[2].trim().equalsIgnoreCase("T"); 

                        // Write request header to output file
                        writer.printf("Flight %d: %s, %s (%s)\n", i, origin, dest, sortByTime ? "Time" : "Cost");

                        // Find all possible paths between origin and destination
                        List<FlightPath> paths = planner.findAllPaths(origin, dest); 
                        
                        // If no paths found
                        if (paths.isEmpty()) 
                        {
                            // Write error message to output file
                            writer.println("Error: No flight plan could be created. A valid path does not exist."); 
                        } 
                        else 
                        {
                            // Sort paths based on time or cost
                            HeapSorter.sortPaths(paths, sortByTime); 
                            
                            // Limit output to maximum 3 results
                            int outputCount = Math.min(3, paths.size()); 
                            
                            // Loop through top results
                            for (int j = 0; j < outputCount; j++) 
                            {
                                // Write formatted path to file
                                writer.println(paths.get(j).getFormattedPath(j + 1));
                            }
                        }
                        
                        // Add blank line between results
                        writer.println();
                    }
                }
                
                // Print completion message
                System.out.println("Processing complete. Results written to " + outputFile);
            }
        } 
        // Catch file reading/writing errors
        catch (IOException e) 
        {
            // Print error message
            System.err.println("Error reading requested flights or writing output: " + e.getMessage());
        }
    }
}