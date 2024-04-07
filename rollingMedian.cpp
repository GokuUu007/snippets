class rollingMedian {
    int k;
    multiset<int> l, r;
public:

    rollingMedian (int N) {
        k = N;
    }

    void add (int x) {
        if ((int)l.size() < (k + 1)/ 2) {
            l.insert(x);
        } else {
            if (x < *l.rbegin()) {
                r.insert(*l.rbegin());
                l.erase(l.find(*l.rbegin()));
                l.insert(x);
            } else {
                r.insert(x);
            }
        }
    }

    void remove (int x) {
        if (l.find(x) != l.end()) {
            l.erase(l.find(x));
            if (!r.empty()) {
                l.insert(*r.begin());
                r.erase(r.begin());
            }
        } else {
            r.erase(r.find(x));
        }
    }
    
    int getMedian () {
        return *l.rbegin();
    }
    
};
