// Import Collections class 
import java.util.Collections;

// Import List interface
import java.util.List;

// Class for sorting FlightPath objects using heap sort
public class HeapSorter 
{
    
    // Method to sort paths based on time or cost
    public static void sortPaths(List<FlightPath> list, boolean sortByTime) 
    {
        int n = list.size(); // Get size of list

        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--) 
        {
            heapify(list, n, i, sortByTime); // Heapify subtree
        }

        // Extract elements from heap one by one
        for (int i = n - 1; i > 0; i--) 
        {
            Collections.swap(list, 0, i); // Move current root to end
            heapify(list, i, 0, sortByTime); // Heapify reduced heap
        }
    }

    // Method to maintain heap property
    private static void heapify(List<FlightPath> list, int n, int i, boolean sortByTime)
    {
        int largest = i; // Assume root is largest
        int left = 2 * i + 1; // Left child index
        int right = 2 * i + 2; // Right child index

        // Check if left child is larger
        if (left < n && compare(list.get(left), list.get(largest), sortByTime) > 0)
        {
            largest = left; // Update largest
        }

        // Check if right child is larger
        if (right < n && compare(list.get(right), list.get(largest), sortByTime) > 0) 
        {
            largest = right; // Update largest
        }

        // If largest is not root
        if (largest != i) 
        {
            Collections.swap(list, i, largest); // Swap root with largest
            heapify(list, n, largest, sortByTime); // Recursively heapify
        }
    }

    // Method to compare two FlightPath objects
    private static int compare(FlightPath p1, FlightPath p2, boolean sortByTime) 
    {
        if (sortByTime)
        {
            return Integer.compare(p1.getTotalTime(), p2.getTotalTime()); // Compare by time
        } 
        else
        {
            return Double.compare(p1.getTotalCost(), p2.getTotalCost()); // Compare by cost
        }
    }
}