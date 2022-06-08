#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

struct node
{
    int cost;
    int through;
};

void msg(vector<int> numVertice, int stages)
{
    int totalVertex = accumulate(numVertice.begin(), numVertice.end(), 0);

    int graph[totalVertex][totalVertex];

    cout << "\n\nEnter the adjacency matrix :   (-1 for no path) \n";

    for (int i = 0; i < totalVertex; i++)
    {
        for (int j = 0; j < totalVertex; j++)
        {
            int temp;
            cin >> temp;
            if (temp == -1)
                graph[i][j] = 1000;
            else
                graph[i][j] = temp;
        }
    }

    int curr = 0;
    int startVertex[stages];
    startVertex[0] = 0;

    for (int i = 1; i < stages; i++)
    {
        startVertex[i] = curr + 1;
        curr = curr + numVertice[i];
    }

    struct node array[totalVertex];

    int lastinx = totalVertex - 1;
    array[lastinx].cost = 0;
    array[lastinx].through = lastinx;

    int mincost, minthrough, currVertex, vertexNextStage, currcost;

    for (int i = stages - 2; i >= 0; i--)
    {
        for (int j = 0; j < numVertice[i]; j++)
        {
            mincost = INT_MAX;
            for (int k = 0; k < numVertice[i + 1]; k++)
            {
                currVertex = j + startVertex[i];
                vertexNextStage = k + startVertex[i + 1];
                currcost = graph[currVertex][vertexNextStage] + array[vertexNextStage].cost;
                if (currcost < mincost)
                {
                    mincost = currcost;
                    minthrough = vertexNextStage;
                }
            }
            array[currVertex].cost = mincost;
            array[currVertex].through = minthrough;
        }
    }

    cout << "\n\nThe shortest path from first stage to last is : 0";

    int ptr = 0;
    while(ptr != (totalVertex - 1))
    {
        cout << " -> " << array[ptr].through;
        ptr = array[ptr].through;
    }
    
    cout << "\nAnd it's total cost is : " << array[0].cost;
    cout << "\n\n";
}

int main()
{
    int stages = 5;

    cout << "Enter the number of stages : ";
    cin >> stages;

    vector<int> numVertice;

    
    for(int i = 0; i < stages; i++)
    {
        cout << "\nEnter the number of vertices in stage " << i + 1 << " : ";
        int temp;
        cin >> temp;
        numVertice.push_back(temp);
    }

    msg(numVertice, stages);

    return 0;
}