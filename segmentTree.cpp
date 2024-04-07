        
class Segtree {

vector<int> t;
public:

    /*
        follow 1-based index
        tl - tr -> array bound
    */

    Segtree(int N) {
        t.resize(4 * N + 1);
    }

    void build (int v, int tl, int tr, vector<int> &a) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build (v * 2 + 1, tl, tm, a);
            build (v * 2 + 2, tm + 1, tr, a);
            t[v] = t[v * 2 + 1] + t[v * 2 + 2];
        }
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2 + 1, tl, tm, pos, new_val);
            else
                update(v * 2 + 2, tm + 1, tr, pos, new_val);
            t[v] = t[v * 2 + 1] + t[v * 2 + 2];
        }
    }

    int sum(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        int left = sum(v * 2 + 1, tl, tm, l, min(r, tm));
        int right = sum(v * 2 + 2, tm + 1, tr, max(l, tm+1), r);
        return left + right;
    }
    
};
