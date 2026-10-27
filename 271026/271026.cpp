#include <iostream>
#include <fstream>

#include <vector>
#include <climits>

using namespace std;

#define MAX 100
#define INF INT_MAX

int A[MAX][MAX];
int n;

void NHAP()
{
    ifstream file("Grap.txt");
    if(!file.is_open())
    {
        cout<<"Khong the mo file."<<endl;
        return;
    }

    file>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            file>>A[i][j];
    }

    file.close();
    cout<<"Nhap thanh cong."<<endl;
}

void XUAT()
{
    cout<<"--Ma tran trong so:"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<A[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void TIM_DUONG(int start, int end)
{
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    dist[start] = 0;

    for(int count = 0; count < n-1; count++)
    {
        int min = INF;
        int u=-1;
        for(int v=0; v<n; v++)
        {
            if(!visited[v] && dist[v] <= min)
            {
                min = dist[v];
                u=v;
            }
        }

        if(u==-1)
            break;
        visited[u] = true;

        for(int v=0; v<n; v++)
        {
            if(!visited[v] && A[u][v] != 0 && dist[u] != INF && dist[u] + A[u][v] < dist[v])
            {
                dist[v] = dist[u] + A[u][v];
                parent[v] = u;
            }
        }
    }

    cout<<"Duong ngan nhat: "<<endl;
    if(dist[end] == INF)
    {
        cout<<"Khong co duong."<<endl;
    }
    else
    {
        vector<int> path;
        for(int v = end; v != -1; v = parent[v])
        {
            path.push_back(v);
        }

        for(int i = path.size() - 1; i>=0; i--)
        {
            cout<<"V"<<path[i]+1;
            if(i>0)
                cout<<">>";
        }
        cout<<endl;
    }
}

int main()
{
    NHAP();
    if(n<=0)
        return 1;

    XUAT();

    int u=0;
    int v=5;
    TIM_DUONG(u, v);
}