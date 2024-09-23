#include <bits/stdc++.h>
using namespace std;

typedef struct {
  vector<int> elements;
} Info;

const Info null_element = {{}};

void debugInfo(Info inf) {
  for (int x : inf.elements) cout << x << " ";
  cout << endl;
}

Info combine(Info l, Info r) {
    Info res;
    merge(l.elements.begin(), l.elements.end(), r.elements.begin(), r.elements.end(), back_inserter(res.elements));
    return res;
}
Info newInfo(int value) {
  return {};
}

int getMid(int l, int r) {
  return (r + l)/2;
}

class SegmentTree {
private:
  vector<int> v;
  vector<Info> tree;

  void buildUtil(int node, int tl, int tr) {
    if (tl == tr) {
      tree[node] = newInfo(v[tl]);
      return;
    }
    int tm = getMid(tl, tr);
    buildUtil(node*2 + 1, tl, tm);
    buildUtil(node*2 + 2, tm + 1, tr);
    tree[node] = combine(tree[node*2 + 1], tree[node*2 + 2]);
  }

  Info queryUtil(int node, int tl, int tr, int l, int r) {
    if (l > r) return null_element;
    if (l == tl && r == tr) return tree[node];
    int tm = getMid(tl, tr);
    Info res = combine(
      queryUtil(node*2 + 1, tl, tm, l, min(r, tm)),
      queryUtil(node*2 + 2, tm + 1, tr, max(l, tm + 1), r)
    );

    return res;
  }

  void updateUtil(int node, int tl, int tr, int idx, int value) {
    if (tl == tr) {
      tree[node] = newInfo(value);
      return;
    }
    int tm = getMid(tl, tr);
    if (idx <= tm) updateUtil(node*2 + 1, tl, tm, idx, value);
    else updateUtil(node*2 + 2, tm + 1, tr, idx, value);

    tree[node] = combine(tree[node*2 + 1], tree[node*2 + 2]);
  }

public:
  SegmentTree(vector<int> &nums) {
    v = nums;
    tree = vector<Info>(v.size() * 4, null_element);
    buildUtil(0, 0, v.size() - 1);
  }

  void update(int idx, int value) {
    updateUtil(0, 0, v.size() - 1, idx, value);
  }

  Info query(int l, int r){
    return queryUtil(0, 0, v.size() - 1, l, r);
  }
};

int main() {
  int n; cin >> n;
  vector<int> arr(n);
  vector<int> next_right(n);
  for(int i=0; i<n; i++) cin >> arr[i];

  unordered_map<int, int> ump;
  for (int i = n - 1; i >= 0; i--) {
    if (ump[arr[i]] == 0) {
      next_right[i] = n;
      ump[arr[i]] = i;
    }
    else {
      next_right[i] = ump[arr[i]];
      ump[arr[i]] = i;
    }
  }

  SegmentTree st(next_right);

  int q; cin >> q;
  while(q--) {
    cin >> q;
    int l, r; cin >> l >> r;
    l--; r--;
    st.query(l, r);
  }
}
