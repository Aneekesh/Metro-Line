#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int V = 250;
string metro_list[V];
int metro_no[V];
void fare(float dis)
{
    cout << "Expected Metro Fare would be: Rs. ";
    if (dis <= 2.0)
    { // expected metro fare for shortest route distance <= 2 km.
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

int minimumDistance(float dist[], bool sptSet[])
{
    float min = 1000.0;
    int min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}
void outputPath(int parent[], int j, int src, vector<int> &cnt)
{
    if (parent[j] == src || parent[j] <= 0)
    {
        if (parent[j] == src)
        {
            cnt.push_back(metro_no[j]);
            cout << " -->>" << metro_list[metro_no[j]];
        }
        return;
    }
    outputPath(parent, parent[j], src, cnt);
    cnt.push_back(metro_no[j]);
    cout << " -->> " << metro_list[metro_no[j]];
}

void printAnswer(float dist[], int src, int parent[], int dest, vector<int> &cnt)
{
    cout << "Distance between two station is: " << dist[dest] << " km " << endl;
    fare(dist[dest]);
    cout << metro_list[metro_no[src]];
    cnt.push_back(metro_no[src]);
    outputPath(parent, dest, src, cnt);
}

void dijkstra(float graph[][V], int src, int d, vector<int> &cnt)
{
    float dist[V];
    bool sptSet[V];
    int parent[V];
    for (int i = 0; i < V; i++)
    {
        parent[0] = -1;
        dist[i] = 1000.0;
        sptSet[i] = false;
    }

    dist[src] = 0.0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minimumDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
    printAnswer(dist, src, parent, d, cnt);
}

string yellow_line[37] = {"Kalinga Hospital", "Utkal Children's Hospital", "Patrapada", "Kandhei", "Jagannath Vihar", "Biplab Nagar", "Badagada", "Jaydev Vihar", "Bhubaneswar University", "Odisha Assembly", "Acharya Vihar", "Ram Mandir Square", "Vani Vihar", "Acharya Vihar Square", "Biju Patnaik International Airport", "KIIT Square", "Nanda Vihar", "Rail Sadan", "District Centre", "Phulapokhari", "Trisulia Square", "Nandankanan Zoological Park", "AIIMS Bhubaneswar", "Baramunda", "Khordha", "Banaspati Nagar", "Jatni", "Naxalgarh", "Sundargarh", "Kendrapara", "Paradeep", "Jagatsinghpur", "Kalahandi", "Balangir", "Cuttack", "Khurda", "Puri"};
float yl[37] = {0.0, 0.8, 1.3, 1.3, 1.3, 1.5, 1.4, 1.4, 0.8, 1.0, 1.3, 1.1, 1.1, 1.0, 0.8, 1.1, 1.3, 0.9, 0.3, 1.6, 1.2, 1.3, 0.8, 1.0, 1.8, 1.7, 0.9, 1.7, 1.3, 1.6, 1.3, 1.7, 1.5, 1.0, 1.2, 1.1, 1.5};

string red_line[21] = {"Bharati Vihar", "Kalinga Vihar", "Purusottama Park", "Bheemunipatna", "Biju Patnaik Park", "Nayapalli", "Gopabandhu Park", "Samrat Ashoka Market", "Kharvel Nagar", "Bansidhar Panigrahi Road", "Dhauli", "Khandagiri", "Khurda Road", "Laxmi Sagar", "Kachiguda", "Nayagarh", "Rourkela", "Sambalpur", "Cuttack", "Puri", "Jatni"};
float rl[21] = {0.0, 0.9, 1.1, 1.1, 1.2, 1.1, 1.6, 2.2, 1.1, 0.9, 0.8, 1.7, 1.2, 1.2, 0.8, 1.2, 1.1, 1.0, 0.8, 1.3, 1.0};

string blue_line[51] = {"Delta Colony 21", "Delta Colony 8", "Delta Colony 9", "Delta Colony 9", "Delta Colony 10", "Delta Colony 11", "Delta Colony 12", "Delta Colony 13", "Delta Colony 14", "Delta", "Delta Mor", "Cuttack Road", "Sahu Nagar", "Patia", "Nayapalli", "Saheed Nagar", "Khandagiri", "Niladri Vihar", "Santaragadia", "Mayur Vihar", "Maharaja Vihar", "Ghatikia", "Nayapalli Housing Board Colony", "Kalinga Nagar", "Unit-8", "Unit-6", "Unit-3", "Unit-2", "Master Canteen", "Asoka Hotel", "Laxmisagar", "Unit-1", "Exhibition Ground", "Bhubaneswar Railway Station", "Kuakhai River", "Lingaraj Temple", "Mayur Vihar", "Mayur Vihar Phase-2", "Ashoka Nagar", "Government Colony", "Government Colony", "Government Colony", "Ekamrakanan", "Bhubaneswar Golf Course", "Ghatikia", "Government Colony", "Government Colony", "Government Colony", "Government Colony", "Government Colony", "Infocity"};
float bl[51] = {0.0, 1.7, 1.0, 1.1, 1.0, 1.0, 0.9, 0.9, 1.5, 1.1, 1.2, 1.0, 1.0, 1.3, 1.0, 1.0, 0.9, 0.9, 1.1, 1.0, 1.2, 1.0, 0.7, 1.3, 0.9, 1.0, 1.2, 1.0, 1.2, 0.7, 1.0, 0.8, 0.8, 1.8, 1.3, 1.8, 1.2, 0.9, 1.0, 1.1, 1.1, 1.1, 1.2, 1.3, 0.8, 1.3, 1.4, 1.1, 1.0, 1.2};

string orange_line[6] = {"Biju Patnaik International Airport", "Kalinga  Stadium", "Dhaula Kuan", "Damana", "Pandra", "Delta Colony 21"};
float ol[6] = {0.0, 1.9, 6.4, 6.2, 3.4, 2.9};

string green_line[21] = {"Indira Nagar", "Ashok Nagar", "Sikh Nagar", "Shivaji Nagar", "Madhipur", "Patia", "Nayapalli", "Peragarh", "Industrial Estate", "Kalinga Stadium", "Nangloi", "Nangloi Railway Station", "Rajdhani Estate", "Mundua", "Mundua Industrial Estate", "Gheua Metro Station", "Tikri", "Tikri Border", "Pandit Shriram Nagar", "Bhubaneswar City", "Brigadier Hoshiar Singh Nagar"};
float gl[21] = {0.0, 1.4, 0.9, 1.6, 1.1, 0.7, 1.0, 0.9, 1.2, 0.7, 0.8, 0.9, 0.2, 1.3, 1.3, 2.1, 1.7, 1.3, 1.3, 1.5, 1.8};

string rapid_line[11] = {"Colony 55-66", "Colony 54 Chowk", "Colony 53-54", "Colony 42-43", "DLF Phase 1", "Saliyasahi", "DLF Phase 2", "Vodaphone Belvedere Towers", "Indus Bank Cyber City", "Micromax Moulsari", "DLF Phase 3"};
float rapl[11] = {0.0, 1.1, 1.5, 1.3, 1.6, 1.1, 0.7, 0.7, 0.6, 0.6, 0.8};

string voilet_line[34] = {"Kashmiri Gate", "Lal Quila", "Jama Masjid", "Sailashree Vihar", "ITO", "IRC Village", "Janpath", "A G Colony", "Ganga Nagar", "KIIT Stadium", "Jangpura", "Delta Colony", "Moolchand", "Kailash Colony", "VSS Nagar", "Kalkaji Mandir", "Govind Puri", "Okhla", "Jasola", "Sarita Vihar", "Mohan Estate", "Rasulgarh", "Badarpur", "Sarai", "NHPC Chowk", "Mewala Maharajpur", "Dumuduma", "Badkal Mor", "KIIT KP9", "Neelam Chowk Ajronda", "Bata Chowk", "Escorts chowk", "Sant Surdas-Sihi", "Raja Nahar Singh"};
float vl[34] = {0.0, 1.5, 0.8, 1.4, 1.3, 0.8, 1.4, 1.3, 2.1, 1.4, 0.9, 1.5, 0.7, 1.3, 1.0, 0.8, 0.7, 1.1, 0.9, 1.2, 1.2, 1.9, 1.1, 2.5, 1.6, 0.9, 1.2, 1.7, 1.2, 1.6, 1.3, 1.8, 1.7, 1.7};

string magenta_line[25] = {"Janak Puri West", "Dabri Mor", "Dashrath Puri", "Palam", "Sadar Bazaar Cantonment", "BBS Airport", "Shankar Vihar", "Vasant Vihar", "Munirka", "RK Puram", "IIIT Bhubaneswar ", "Hauz Khas", "Panchsheel Park", "Chirag Bhubaneshwar", "Greater Kailash", "Nehru Enclave", "Kalkaji Mandir", "Okhla NHIC", "Sukhdev Vihar", "Jamia Milia Islamia", "Okhla Vihar", "Jasola Vihar Shaheen Bagh", "Kalindi Kunj", "Okhla Bird Sanctuary", "Rose Garden"};
float ml[25] = {0.0, 2.0, 1.1, 1.5, 2.6, 1.7, 1.8, 2.1, 1.2, 1.4, 0.9, 1.2, 1.5, 0.9, 0.9, 1.3, 0.9, 0.8, 1.1, 1.2, 0.5, 1.8, 1.4, 1.6, 1.7};

string pink_line[38] = {"Surya Nagar", "Madhusudan Nagar", "Shalimar Bagh", "Ganga Nagar", "Shakurpur", "ISKON", "KIIMS Hospital", " Garden", "Maya Puri", "Naraina Vihar", "Ashok Nagar", "Durgabai Deshmukh South Campus", "Raghunathpur", "Bhikaji Cama Place", "Sarojini Nagar", "INA", "South Extension", "Acharya Vihar", "Vinobapuri", "Ashram", "Hazrat Nizamuddin", "Mayur Vihar Phase-1", "Mayur Vihar Pocket I", "Trilokpuri Sanjay Lake", "Vinod Nagar East", "Mandawali - West Vinod Nagar", "IP Extension", "Anand Vihar", "Karkar Duma", "Karkarduma Court", "Krishna Nagar", "East Azad Nagar", "Welcome", "Jaffrabad", "Maujpur", "Gokulpuri", "Johri Enclave", "Shiv Vihar"};
float pl[38] = {0.0, 2.1, 1.6, 1.4, 1.2, 1.4, 2.5, 1.1, 1.5, 1.5, 1.8, 3.6, 1.3, 1.6, 1.2, 1.1, 1.2, 1.6, 1.4, 1.2, 1.9, 3.6, 0.8, 1.3, 0.8, 0.6, 1.0, 1.6, 1.0, 1.1, 0.7, 1.0, 1.1, 1.2, 1.1, 1.3, 1.3, 0.9};

string blue_line2[8] = {"BJB Nagar", "Laxmi Nagar", "Nirman Vihar", "Preet Vihar", "Karkar Duma", "Anand Vihar", "Kaushambi", "Vaishali"};
float bl2[8] = {0.0, 1.3, 1.1, 1.0, 1.2, 1.1, 0.8, 1.6};

string green_line2[3] = {"Ashok Park Main", "Satguru Ram Singh Marg", "Kirti Nagar"};
float gl2[3] = {0.0, 1.1, 1.0};

string aqua_line[22] = {"AG Colony", "AG", "Madhusudan Nagar", "Saheed Nagar", "Master Canteen", "Keshari Nagar", "NSEZ AG", "Ekamra Vihar", "Lingaraj Nagar", "Kapileswar", "Gouri Nagar", "CRPF", "Baramunda", "Gopabandhu Nagar", "Delta Colony", "Kalinga Nagar", "Knowledge Park II", "Pari Chowk Greater AG", "Alpha 1 Greater AG", "Delta 1 Greater AG", "GNIDA Office", "Depot Greater AG"};
float al[22] = {0.0, 0.3, 1.3, 1.0, 1.1, 0.9, 2.0, 1.1, 1.5, 1.6, 1.0, 1.4, 1.2, 1.7, 1.5, 1.6, 1.5, 1.1, 0.9, 1.5, 1.3, 0.9};

void print_response()
{
    cout << endl
         << endl
         << endl
         << endl;
    cout << "-------------------------------------------" << endl;
    cout << "\t--- BHUBANESHWAR METRO LINE  --- \t\t" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "For finding shortest route,please enter 1. " << endl;
    cout << "For Ticketing and Token information,please enter 2." << endl;
    cout << "For Bhubaneshwar Metro Stations,please enter 3." << endl;
    cout << "For Exit, please enter any other key." << endl;
    cout << "Enter Your Response: ";
}

void print_ticket()
{
    cout << endl
         << endl;
    cout << "----------TOKEN---------" << endl;
    cout << "1. Only One way permitted" << endl;
    cout << "2. Validity One day" << endl;
    cout << "3. Refund with in 60 min" << endl;
    cout << "4. Exit within 170 min, penalty Rs 10 per hour, subject to maximum Rs 50" << endl;

    cout << endl
         << endl;
    cout << "----------TRAVEL CARD---------" << endl;
    cout << "1. First Time Rs 150 ( including Rs 50 refundable security" << endl;
    cout << "2. Next recharge Rs 200 to Rs 2000" << endl;
    cout << "3. Validity - 1 year after every recharge, max 10 years" << endl;
    cout << "4. Same station entry/exit Rs 10 charged with in 20 min" << endl;
    cout << endl
         << endl;

    cout << "----------TOURIST CARD---------" << endl;
    cout << "1. Specially for a single day travel" << endl;
    cout << "2. Purchase a card word Rs100 and travel whole day to any station on the Bhubaneshwar Metro" << endl;
    cout << "3. 1 day Rs 200 (Rs 150 + Rs 50 refundable security)" << endl;
    cout << "4. 3 Days Rs 500 (Rs. 450 + Rs 50 refundable security)" << endl;
    cout << endl
         << endl;
}

int main()
{
    map<string, int> metro;

    float graph[V][V];
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            graph[i][j] = 0.0;
        }
    }
    int count = 0;

    for (int i = 0; i < 37; i++)
    {
        if (!metro[yellow_line[i]])
        {
            metro[yellow_line[i]] = count;
            count++;
        }
    }
    for (int i = 0; i < 21; i++)
    {
        if (!metro[red_line[i]])
        {
            metro[red_line[i]] = count;
            count++;
        }
    }
    for (int i = 0; i < 51; i++)
    {
        if (!metro[blue_line[i]])
        {
            metro[blue_line[i]] = count;
            count++;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        if (!metro[orange_line[i]])
        {
            metro[orange_line[i]] = count;
            count++;
        }
    }
    for (int i = 0; i < 21; i++)
    {
        if (!metro[green_line[i]])
        {
            metro[green_line[i]] = count;
            count++;
        }
    }
    for (int i = 0; i < 11; i++)
    {
        if (!metro[rapid_line[i]])
        {
            metro[rapid_line[i]] = count;
            count++;
        }
    }
    for (int i = 0; i < 34; i++)
    {
        if (!metro[voilet_line[i]])
        {
            metro[voilet_line[i]] = count;
            count++;
        }
    }
    for (int i = 0; i < 25; i++)
    {
        if (!metro[magenta_line[i]])
        {
            metro[magenta_line[i]] = count;
            count++;
        }
    }
    for (int i = 0; i < 38; i++)
    {
        if (!metro[pink_line[i]])
        {
            metro[pink_line[i]] = count;
            count++;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (!metro[blue_line2[i]])
        {
            metro[blue_line2[i]] = count;
            count++;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (!metro[green_line2[i]])
        {
            metro[green_line2[i]] = count;
            count++;
        }
    }
    for (int i = 0; i < 22; i++)
    {
        if (!metro[aqua_line[i]])
        {
            metro[aqua_line[i]] = count;
            count++;
        }
    }

    for (int i = 0; i < 36; i++)
    {
        int m = metro[yellow_line[i]];
        int n = metro[yellow_line[i + 1]];
        graph[m][n] = yl[i + 1];
        graph[n][m] = yl[i + 1];
    }
    for (int i = 0; i < 20; i++)
    {
        int m = metro[red_line[i]];
        int n = metro[red_line[i + 1]];
        graph[m][n] = rl[i + 1];
        graph[n][m] = rl[i + 1];
    }
    for (int i = 0; i < 50; i++)
    {
        int m = metro[blue_line[i]];
        int n = metro[blue_line[i + 1]];
        graph[m][n] = bl[i + 1];
        graph[n][m] = bl[i + 1];
    }
    for (int i = 0; i < 5; i++)
    {
        int m = metro[orange_line[i]];
        int n = metro[orange_line[i + 1]];
        graph[m][n] = ol[i + 1];
        graph[n][m] = ol[i + 1];
    }
    for (int i = 0; i < 20; i++)
    {
        int m = metro[green_line[i]];
        int n = metro[green_line[i + 1]];
        graph[m][n] = gl[i + 1];
        graph[n][m] = gl[i + 1];
    }
    for (int i = 0; i < 10; i++)
    {
        int m = metro[rapid_line[i]];
        int n = metro[rapid_line[i + 1]];
        graph[m][n] = rapl[i + 1];
        graph[n][m] = rapl[i + 1];
    }
    for (int i = 0; i < 33; i++)
    {
        int m = metro[voilet_line[i]];
        int n = metro[voilet_line[i + 1]];
        graph[m][n] = vl[i + 1];
        graph[n][m] = vl[i + 1];
    }
    for (int i = 0; i < 24; i++)
    {
        int m = metro[magenta_line[i]];
        int n = metro[magenta_line[i + 1]];
        graph[m][n] = ml[i + 1];
        graph[n][m] = ml[i + 1];
    }
    for (int i = 0; i < 37; i++)
    {
        int m = metro[pink_line[i]];
        int n = metro[pink_line[i + 1]];
        graph[m][n] = pl[i + 1];
        graph[n][m] = pl[i + 1];
    }
    for (int i = 0; i < 7; i++)
    {
        int m = metro[blue_line2[i]];
        int n = metro[blue_line2[i + 1]];
        graph[m][n] = bl2[i + 1];
        graph[n][m] = bl2[i + 1];
    }
    for (int i = 0; i < 2; i++)
    {
        int m = metro[green_line[i]];
        int n = metro[green_line[i + 1]];
        graph[m][n] = gl2[i + 1];
        graph[n][m] = gl2[i + 1];
    }
    for (int i = 0; i < 21; i++)
    {
        int m = metro[aqua_line[i]];
        int n = metro[aqua_line[i + 1]];
        graph[m][n] = al[i + 1];
        graph[n][m] = al[i + 1];
    }
    int k = 0;
    for (auto i : metro)
    {
        metro_list[k] = i.first;
        metro_no[i.second] = k;
        k++;
    }

    int src;
    int dt;
    string response;
    while (true)
    {
        print_response();

        cin >> response;
        cout << endl;

        if (response == "1")
        {
            vector<int> cnt;

            cout << "Enter starting station :";
            cin >> src;
            cout << endl
                 << "Enter ending station :";
            cin >> dt;

            cout << endl
                 << "Starting Station is " << metro_list[metro_no[src]] << " and Ending Station is " << metro_list[metro_no[dt]] << endl;

            dijkstra(graph, int(src), int(dt), cnt);

            cout << "\n\nNumber of station in between these two staions are : " << cnt.size() << endl;
        }
        else if (response == "2")
        {
            print_ticket();
        }
        else if (response == "3")
        {
            cout << "STATION"
                 << "                  "
                 << "CODE" << endl;
            for (auto i : metro)
            {
                cout << i.first << "   :  " << i.second << endl;
            }
        }
        else
        {

            return 0;
        }
    }

    return 0;
}