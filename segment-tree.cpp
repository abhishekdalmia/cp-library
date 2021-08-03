class SegTree {
public:
    int n;
    vector <int> t;
    int combine(int a, int b) {
        // define the combine operation for the queries here
        return a+b;
    }

    void buildUtil(vector <int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            buildUtil(a, 2*v+1, tl, tm);
            buildUtil(a, 2*v+2, tm+1, tr);
            t[v] = combine(t[2*v+1], t[2*v+2]);
        }
    }
    void build(vector <int> &a) {
        // to build the segment tree for the array arr
        n = a.size();
        t.resize(4*n);
        buildUtil(a, 0, 0, a.size()-1);
    }

    int queryUtil(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return combine(queryUtil(2*v+1, tl, tm, l, min(r, tm))
                     , queryUtil(2*v+2, tm+1, tr, max(l, tm+1), r));
    }
    int query(int l, int r) {
        // range provided based on the original array size
        return queryUtil(0, 0, n-1, l, r);
    }

    void updateUtil(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                updateUtil(2*v+1, tl, tm, pos, new_val);
            }
            else {
                updateUtil(2*v+2, tm+1, tr, pos, new_val);
            }
            t[v] = combine(t[2*v+1], t[2*v+2]);
        }
    }
    void update(int pos, int new_val) {
        updateUtil(0, 0, n-1, pos, new_val);
    }
};