### Electric Grid Optimization Program

---

#### **Introduction**
This program demonstrates an implementation of **Kruskal's Algorithm** to find the Minimum Spanning Tree (MST) of an electrical grid. It calculates the minimum cost of connecting all nodes (representing locations or components) in the grid while ensuring no cycles are formed.

The program utilizes various data structures to efficiently represent the graph, process connections, and implement union-find logic.

---

#### **Data Structures Used**

1. **Vector (`vector`):**
     - Stores edges of the graph and other related data.
     - Dynamic resizing and efficient traversal make it ideal for storing graph edges.

2. **Struct (`Edge`):**
     - Represents a connection (edge) in the graph with its start node (`st`), destination node (`dest`), and weight (`weight`).
     - Encapsulates all attributes of an edge in a single object.
     - Overloaded the `<` operator for sorting edges by weight, as required in Kruskal's algorithm.

3. **Disjoint Set (Union-Find):**
     - Tracks connected components in the graph to avoid cycles during MST construction.
   - **Components:**
     - **Parent Array:** Indicates the root of each component.
     - **Rank Array:** Optimizes union operations by keeping tree heights minimal.
   - **Operations:**
     - **Find:** Determines the root of a component.
     - **Union:** Merges two components if they belong to different sets.

4. **Sort Functionality:**
     - Sorts edges in non-decreasing order of weight.
     - Ensures edges are processed in the correct order to construct the MST.

---

#### **Explanation of Algorithm**

1. **Graph Representation:**
   - Each connection between two nodes (an edge) is stored in the `edges` vector.

2. **Kruskal's Algorithm:**
   - **Step 1:** Sort all edges by weight.
   - **Step 2:** Initialize a disjoint set for all nodes.
   - **Step 3:** Iterate through the sorted edges:
     - If the start and destination nodes of an edge belong to different sets:
       - Add the edge to the MST.
       - Merge the sets using union operation.
   - **Step 4:** Repeat until all nodes are connected.

3. **Output:**
   - Displays the edges included in the MST and the total cost of connecting all nodes.

---

#### **How to Run**

1. Compile the program using a C++ compiler:
   ```bash
   g++ -o ElectricGrid Electric_grid.cpp
   ```
2. Run the executable:
   ```bash
   ./ElectricGrid
   ```
3. Follow the prompts to:
   - Enter the number of nodes.
   - Input connections (edges) with their weights.
   - Terminate input by entering `-1 -1` for nodes.

---

#### **Sample Output**

```
Enter Number of nodes: 5

Enter -1 -1 when connections are over!

Enter node numbers to be connected: 0 1
Enter length of the connection: 2
Enter node numbers to be connected: 0 3
Enter length of the connection: 6
Enter node numbers to be connected: 1 3
Enter length of the connection: 8
Enter node numbers to be connected: 1 2
Enter length of the connection: 3
Enter node numbers to be connected: 1 4
Enter length of the connection: 5
Enter node numbers to be connected: 2 4
Enter length of the connection: 7
Enter node numbers to be connected: -1 -1

Minimum cost connections:

Connect node 0 to node 1 with length 2
Connect node 1 to node 2 with length 3
Connect node 1 to node 4 with length 5
Connect node 0 to node 3 with length 6

Total minimum length: 16
```
