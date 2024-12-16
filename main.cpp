#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <cfloat> // Include this for FLT_MAX
using namespace std;


const int V = 250; // Maximum vertices

// Global variables
string metro_list[V]; // Metro station names
int metro_no[V];      // Metro station IDs

// Function to calculate fare based on distance
void fare(float dis)
{
    cout << "Expected Metro Fare would be: Rs. ";
    if (dis <= 2.0)
    { // Fare for distance <= 2 km
        cout << 10.0 << endl;
    }
    else if (dis > 2.0 && dis <= 5.0)
    {
        cout << 20.0 << endl;
    }
    else if (dis > 5.0 && dis <= 12.0)
    {
        cout << 30.0 << endl;
    }
    else if (dis > 12.0 && dis <= 21.0)
    {
        cout << 40.0 << endl;
    }
    else if (dis > 21.0 && dis <= 32.0)
    {
        cout << 50.0 << endl;
    }
    else if (dis > 32.0)
    {
        cout << 60.0 << endl;
    }
    else
    {
        cout << "Not Known" << endl;
    }
    cout << endl;
}

// Function to find the vertex with the minimum distance
int minimumDistance(float dist[], bool sptSet[])
{
    float min = FLT_MAX;
    int min_index;

    for (int v = 0; v < V; v++)
    {
        if (!sptSet[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to output the path
void outputPath(int parent[], int j, int src, vector<int> &cnt)
{
    if (parent[j] == src || parent[j] <= 0)
    {
        if (parent[j] == src)
        {
            cnt.push_back(metro_no[j]);
            cout << " -->> " << metro_list[metro_no[j]];
        }
        return;
    }
    outputPath(parent, parent[j], src, cnt);
    cnt.push_back(metro_no[j]);
    cout << " -->> " << metro_list[metro_no[j]];
}

// Print distance and path
void printAnswer(float dist[], int src, int parent[], int dest, vector<int> &cnt)
{
    cout << "Distance between the two stations is: " << dist[dest] << " km" << endl;
    fare(dist[dest]);
    cout << metro_list[metro_no[src]];
    cnt.push_back(metro_no[src]);
    outputPath(parent, dest, src, cnt);
    cout << endl;
}

// Dijkstra's algorithm implementation
void dijkstra(float graph[][V], int src, int d, vector<int> &cnt)
{
    float dist[V];
    bool sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
        dist[i] = FLT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0.0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minimumDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printAnswer(dist, src, parent, d, cnt);
}

// Metro Lines and distances
string yellow_line[37] = {"Kalinga Hospital", "Utkal Children's Hospital", "Patrapada", "Kandhei", "Jagannath Vihar", "Biplab Nagar", "Badagada", "Jaydev Vihar", "Bhubaneswar University", "Odisha Assembly", "Acharya Vihar", "Ram Mandir Square", "Vani Vihar", "Acharya Vihar Square", "Biju Patnaik International Airport", "KIIT Square", "Nanda Vihar", "Rail Sadan", "District Centre", "Phulapokhari", "Trisulia Square", "Nandankanan Zoological Park", "AIIMS Bhubaneswar", "Baramunda", "Khordha", "Banaspati Nagar", "Jatni", "Naxalgarh", "Sundargarh", "Kendrapara", "Paradeep", "Jagatsinghpur", "Kalahandi", "Balangir", "Cuttack", "Khurda", "Puri"};
float yl[37] = {0.0, 0.8, 1.3, 1.3, 1.3, 1.5, 1.4, 1.4, 0.8, 1.0, 1.3, 1.1, 1.1, 1.0, 0.8, 1.1, 1.3, 0.9, 0.3, 1.6, 1.2, 1.3, 0.8, 1.0, 1.8, 1.7, 0.9, 1.7, 1.3, 1.6, 1.3, 1.7, 1.5, 1.0, 1.2, 1.1, 1.5};

// Graph initialization function
void initializeGraph(float graph[][V], int &n)
{
    n = 37; // Example for yellow line
    for (int i = 0; i < n; i++)
    {
        metro_list[i] = yellow_line[i];
        metro_no[i] = i;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                graph[i][j] = 0.0;
            else if (j == i + 1 || j == i - 1)
                graph[i][j] = yl[i];
            else
                graph[i][j] = FLT_MAX;
        }
    }
}

// Main function
int main()
{
    int src, dest, n;
    vector<int> path;
    float graph[V][V];

    initializeGraph(graph, n);

    cout << "Enter the source station (index 0-" << n - 1 << "): ";
    cin >> src;
    cout << "Enter the destination station (index 0-" << n - 1 << "): ";
    cin >> dest;

    cout << "\nCalculating shortest path...\n";
    dijkstra(graph, src, dest, path);

    return 0;
}
