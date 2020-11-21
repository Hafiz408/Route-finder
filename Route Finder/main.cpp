#include<stdio.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<stdlib.h>
//#include<windows.h>
#include<fstream>

using namespace std;

#define V 20

int stringToIndex(string s)
{
    if(s == "wengen")return 0;
    else if(s == "gass")return 1;
    else if(s == "lupin_felt")return 2;
    else if(s == "blomster")return 3;
    else if(s == "rose_farm")return 4;
    else if(s == "iceborg")return 5;
    else if(s == "hot_spring")return 6;
    else if(s == "gronhus")return 7;
    else if(s == "crabgrass")return 8;
    else if(s == "aqueduct")return 9;
    else if(s == "helle")return 10;
    else if(s == "powerplant")return 11;
    else if(s == "holdhus")return 12;
    else if(s == "midstein")return 13;
    else if(s == "reeds")return 14;
    else if(s == "east_port")return 15;
    else if(s == "fiskerhus")return 16;
    else if(s == "waterfall")return 17;
    else if(s == "shipyard")return 18;
    else if(s == "lumber_yard")return 19;
}

string indexToString(int i)
{
    if(i == 0)return "wengen";
    else if(i == 1)return "gass";
    else if(i == 2)return "lupin_felt";
    else if(i == 3)return "blomster";
    else if(i == 4)return "rose farm";
    else if(i == 5)return "iceborg";
    else if(i == 6)return "hot_spring";
    else if(i == 7)return "gronhus";
    else if(i == 8)return "crabgrass";
    else if(i == 9)return "aqueduct";
    else if(i == 10)return "helle";
    else if(i == 11)return "powerplant";
    else if(i == 12)return "holdhus";
    else if(i == 13)return "midstein";
    else if(i == 14)return "reeds";
    else if(i == 15)return "east_port";
    else if(i == 16)return "fiskerhus";
    else if(i == 17)return "waterfall";
    else if(i == 18)return "shipyard";
    else if(i == 19)return "lumber_yard";
}

int minDistance(int dist[],bool sptSet[])
{
    int min = INT_MAX, min_index ;
    for(int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printPath(int parent[], int j)
{
    if (parent[j] == - 1)
        return;
    printPath(parent, parent[j]);
    cout<<" -> "<<indexToString(j);
}

int dijkstra(int graph[V][V],int src,int dest,string s,int choice=1)
{
    int dist[V];
    bool sptSet[V];
    int parent[V];
    for (int i = 0; i < V; i++)
    {
        parent[0] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
    if(choice==1)
    {
        cout<<endl<<"> > > > > > Calculating... < < < < < <";
        cout<<endl<<"Shortest distance :"<<dist[dest]<<endl<<"Shortest path : "<<s;
        printPath(parent,dest);
        cout<<endl;
        return 0;
    }
    else
    {
        if(choice==3)
        {
            return dist[dest];
        }
        else
        {
            printPath(parent,dest);
            return dist[dest];
        }

    }
}

void interchangeColumns(int m[][V],int n)
{
    int columns = n+1;
    for (int i = 0; i < V; i++) {
        int t = m[i][0];
        m[i][0] = m[i][columns - 1];
        m[i][columns - 1] = t;
    }
}

void interchangeRows(int m[][V],int n)
{
        int rows = n+1;
        for (int i = 0; i < V; i++)
        {
            int t = m[0][i];
            m[0][i] = m[rows - 1][i];
            m[rows - 1][i] = t;
        }
}

int main()
{
    int graph[V][V]={ {0, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {4, 0, 0, 0, 6, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {2, 0, 0, 2, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 2, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 6, 0, 0, 0, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0},
                    {0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0},
                    {0, 5, 6, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 3, 0, 0, 0, 4, 0, 7, 9, 5, 0, 6, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 5, 1, 0, 0, 4, 0, 6, 0, 0, 0, 0, 7},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 5, 6, 0, 0, 0, 0, 0, 0, 5, 4, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 4, 0, 0, 0},
                    {0, 0, 0, 0, 0, 7, 6, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 4, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 0, 8},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 3, 8, 0}  };

    /*int n;
    char x;
    ifstream fin;
    fin.open("E:\\Packages\\Route Finder\\map.txt");
    int i=0,j=0;
    while(!fin.eof())
    {
        fin.get(x);
        if(x!=',')
        {
            n=(int)x;
            graph[i][j]=n;
            j++;
            if(j==20)
            {
                i++;
                j=0;
            }
        }
    }*/
    int choice,control=0;
    do{
    cout<<"\n\t\tMENU\n\t\t`````\n\t 1. Shortest route\n\t 2. Touring path\n\n    Enter your choice ? ";
    cin>>choice;
    if(choice==1)
    {
        cout<<"\n\t\tROUTE FINDER\n\t\t`````````````\n";
        string source,destination;
        cout<<"\nEnter starting point :";
        cin>>source;
        cout<<"Enter destination :";
        cin>>destination;
        int s = stringToIndex(source);
        int d = stringToIndex(destination);
        interchangeColumns(graph,s);
        interchangeRows(graph,s);
        dijkstra(graph,0,d,source);
        interchangeColumns(graph,s);
        interchangeRows(graph,s);
    }
    else if(choice == 2)
    {
        cout<<"\n\t\tTOUR ROUTE FINDER\n\t\t``````````````````\n";
        string source;
        cout<<"\nEnter starting point :";
        cin>>source;
        int n;
        cout<<"Enter the number of visiting spots :";
        cin>>n;
        string spots[n];
        cout<<"Enter the visiting spots :\n";

        for(int i=0;i<n;i++)
            cin>>spots[i];

        bool visited[n]={false};
        int x=0,cx=0,td=0;
        while(cx!=n)
        {
            int s,d;
            if(x==0)
            {
                cout<<endl<<"> > > > > > Calculating... < < < < < <";
                cout<<"\nShortest touring path : "<<source;
                x++;
            }

            s = stringToIndex(source);
            interchangeColumns(graph,s);
            interchangeRows(graph,s);
            int dist=INT_MAX,fd,fs;
            string str;
            for(int i=0;i<n;i++)
            {
                if(visited[i]==false)
                {
                    d = stringToIndex(spots[i]);
                    int t = dijkstra(graph,0,d,source,3);
                    if(t<dist)
                    {
                        dist=t;
                        fd=d;
                        str=spots[i];
                        fs=i;
                    }
                }
            }

            td += dijkstra(graph,0,fd,source,choice);
            //cout<<" -> "<<str;
            source=str;
            visited[fs]=true;

            cx=0;
            for(int i=0;i<n;i++)
            {
                if(visited[i]==true)
                    cx++;
            }

            interchangeColumns(graph,s);
            interchangeRows(graph,s);
        }
        cout<<"\nTouring distance : "<<td;
    }
    else
    {
       cout<<">>>> ERROR : Enter correct option <<<<";
       control=1;
       //Sleep(2000);
       system("CLS");
    }
    }while(control);
    return 0;
}
