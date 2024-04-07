class DSU {
vector<int> par, sz;
public:

    DSU (int N) {
        par.resize(N + 1);
        sz.resize(N + 1, 1);
        iota(all(par), 0);
    }
    

    int find(int Node) {
        //Union by Size 
        if(par[Node] == Node) return Node;
        return par[Node] = find(par[Node]);
    }
    
    void Union (int A, int B) {
        A = find(A);
        B = find(B);
        if(A != B) {
            if(sz[A] < sz[B]) swap(A,B);
            par[B] = A;
            sz[A] += sz[B];
        }
    }   
    
};
