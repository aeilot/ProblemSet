#include <bits/stdc++.h>

using namespace std;

class Graph{
public:
    int size;
    vector<vector<int> > data;
    vector<int> in_degree;

    Graph(int size){
        this->size = size;
        this->data.resize(size);
        this->in_degree.resize(size,0);
    }

    void addNode(int a, int b){
        data.at(a).push_back(b);
        in_degree[b]++;
    }

    void BFS(int start){
        vector<int> Mark;
        Mark.resize(size, 0);
        queue<int> bfsQ;
        bfsQ.push(start);
        while(!bfsQ.empty()){
            int t = bfsQ.front();
            bfsQ.pop();
            cout << t << endl;
            Mark[t] = 1;
            for(int i : data[t])
                if(Mark[i]==0) bfsQ.push(i);
        }
    }

    void DFS(int start){
        vector<int> Mark2;
        Mark2.resize(size, 0);
        DFS2(start, Mark2);
    }

    void TOP_BFS(){
        vector<int> Mark;
        Mark.resize(size, 0);
        queue<int> bfsQ;
        for(int i = 0; i<size; i++){
            if(in_degree[i] == 0) bfsQ.push(i);
        }
        while(!bfsQ.empty()){
            int t = bfsQ.front();
            bfsQ.pop();
            cout << t << endl;
            Mark[t] = 1;
            for(int i : data[t]){
                in_degree[i]--;
                if(Mark[i]==0 && in_degree[i] == 0) bfsQ.push(i);
            }
        }
    }

protected:
    void DFS2(int start, vector<int> &Mark2){            
        Mark2[start] = 1;
        cout << start << endl;
        for(int i : data[start]){
            if(Mark2[i]!=0) continue;
            DFS(i);
        }
    }
};

int main(){
    Graph test(7);
    test.addNode(0,1);
    test.addNode(0,2);
    test.addNode(1,2);
    test.addNode(1,3);
    test.addNode(1,4);
    test.addNode(4,6);
    test.addNode(4,5);
    // test.BFS(2);
    test.TOP_BFS();
    return 0;
}