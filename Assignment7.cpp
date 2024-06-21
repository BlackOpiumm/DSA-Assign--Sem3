#include<iostream>
#define SIZE 20
#define INFINITY 99

using namespace std;

// Class definition for Minimum Spanning Tree
class MST {
private:
    int G[SIZE][SIZE], nodes;

public:
    // Constructor to initialize the graph with zeros
    MST() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                G[i][j] = 0;
            }
        }
    }

    // Function to perform Prim's algorithm for Minimum Spanning Tree
    void Prim() {
        int select[SIZE], i, j, k;
        int min_dist, v1, v2, total = 0;

        // Output a message indicating the start of the algorithm
        cout << "\nThe minimum spanning tree " << endl;

        // Initializing the selection array
        for (int i = 0; i < nodes; i++) {
            select[i] = 0;
            select[0] = 1;
        }

        // Loop to find the minimum spanning tree
        for (int k = 0; k < nodes - 1; k++) {
            min_dist = INFINITY;

            // Nested loops to find the minimum edge
            for (int i = 0; i < nodes; i++) {
                for (int j = 0; j < nodes - 1; j++) {
                    if (G[i][j] && ((select[i] && !select[j]) || (!select[i] && select[j]))) {
                        if (G[i][j] < min_dist) {
                            min_dist = G[i][j];
                            v1 = i;
                            v2 = j;
                        }
                    }
                }
            }

            // Output the selected edge and weight
            cout << "Edge " << v1 << " " << v2 << " and Weight = " << min_dist << "\n";

            // Mark the vertices as selected
            select[v1] = select[v2] = 1;

            // Update the total weight of the minimum spanning tree
            total = total + min_dist;
        }

        // Output the total path length of the minimum spanning tree
        cout << "\nTotal path length is " << total << endl;
    }

    // Function to get data from the user
    void get_data() {
        int v1, v2, length, n;

        // Prompt the user to enter the number of nodes in the graph
        cout << "\nEnter the total number of nodes in the graph : ";
        cin >> nodes;

        // Prompt the user to enter the total number of edges in the graph
        cout << "\nEnter the total number of edges in the graph : ";
        cin >> n;

        // Prompt the user to enter the edge and weight of the graph
        cout << "\nEnter the edge and weight of the graph : ";
        for (int i = 0; i < n; i++) {
            // Prompt the user to enter the edge in the form of v1, v2
            cout << "\nEnter the edge in the form of v1, v2 (e.g., if there is an edge between 0 and 1 then write 0 1)" << endl;
            cin >> v1 >> v2;

            // Prompt the user to enter the corresponding weight
            cout << "\nEnter corresponding weight : " << endl;
            cin >> length;

            // Assign the weight to the corresponding edges in the adjacency matrix
            G[v1][v2] = G[v2][v1] = length;
        }
    }
};

// Main function
int main() {
    // Create an object of the MST class
    MST obj;

    // Output a message indicating the start of Prim's Algorithm
    cout << "\nPrim's Algorithm\n";

    // Call the get_data function to get input from the user
    obj.get_data();

    // Output a space for better readability
    cout << " " << endl;

    // Call the Prim function to perform Prim's Algorithm and output the minimum spanning tree
    obj.Prim();

    // Return 0 to indicate successful execution
    return 0;
}





**************************************************************






#include <bits/stdc++.h>
#include<iostream>

using namespace std;

class kruskal {

private:
    int id[10000];  // Array to store parent information for each node
    pair<long long, pair<int, int>> p[10000];  // Array to store edges with weights
    int nodes;  // Number of nodes in the graph
    int edges;  // Number of edges in the graph

public:
    // Constructor to initialize the graph and sort the edges based on weights
    kruskal() {
        cout << "Enter the number of nodes:" << endl;
        cin >> nodes;
        cout << "Enter the number of edges:" << endl;
        cin >> edges;

        for (int i = 0; i < edges; i++) {
            int a, b, c;
            cout << "Enter both nodes:" << endl;
            cin >> a >> b;
            cout << "Enter the weight:" << endl;
            cin >> c;

            p[i] = make_pair(c, make_pair(a, b));
        }
        sort(p, p + edges);  // Sorting edges based on weights
    }

    // Function to display the edges with weights
    void checking() {
        for (int i = 0; i < edges; i++) {
            cout << p[i].first << " " << p[i].second.first << " " << p[i].second.second << endl;
        }
    }

    // Function to initialize the parent array
    void initialise() {
        for (int i = 0; i < 10000; i++) {
            id[i] = i;  // Each node is initially its own parent
        }
    }

    // Function to find the root (parent) of a node using path compression
    int root(int x) {
        while (id[x] != x) {
            id[x] = id[id[x]];  // Path compression by pointing each node directly to its root
            x = id[x];
        }
        return x;
    }

    // Function to perform union operation for Kruskal's algorithm
    void union_for_kruskal(int x, int y) {
        int p = root(x);
        int q = root(y);
        id[p] = id[q];  // Setting the root of x as the parent of y
    }

    // Function to find the Minimum Spanning Tree (MST) using Kruskal's algorithm
    void mst_kruskal() {
        int x, y;
        initialise();  // Initialize parent array
        long long cost = 0;  // Variable to store the total cost of MST
        long long mincost = 0;  // Variable to store the minimum cost of MST

        // Iterate through sorted edges
        for (int i = 0; i < edges; i++) {
            x = p[i].second.first;
            y = p[i].second.second;
            cost = p[i].first;

            // If including the edge (x, y) doesn't form a cycle, include it in MST
            if (root(x) != root(y)) {
                mincost += cost;
                union_for_kruskal(x, y);
            }
        }

        cout << "The minimum cost is " << mincost << endl;
    }
};

int main() {
    kruskal k;
    k.mst_kruskal();
    return 0;
}