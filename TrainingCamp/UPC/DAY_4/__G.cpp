#include <bits/stdc++.h>
using namespace std;

/* HINT: usar SQRT Decomp con checkpoint en sqrt(n) para correr las queries en n*sqrt(n) */

typedef struct {
  int val;
  int freq;
} RLE;

void reduce(vector<RLE> &nums, int n) {
  vector<RLE> aux;
  RLE temp = nums[0];
  for(int i=1; i<n; i++) {
    if (nums[i].val != temp.val) {
      aux.push_back(temp);
      temp = nums[i];
    }
    else temp.freq += nums[i].freq;
  }
  aux.push_back(temp);
  nums = aux;
}

void debugRLE(vector<RLE> &nums, int n) {
  cout << "[";
  for(int i=0; i < nums.size(); i++) {
    if(i!= 0) cout << ", ";
    cout << "(" << nums[i].val << ", " << nums[i].freq << ")";
  }
  cout << "]";
}

typedef struct {
  vector<RLE> nums;
  int sum;
} Info;

const Info null_element = {};

void debugInfo(Info inf) {
  cout << " { Sum: " << inf.sum << " -> ";
  debugRLE(inf.nums, inf.nums.size());
  cout << " }\n";
}

Info combine(Info l, Info r) {
  Info inf;
  if(l.nums.empty()) return r;
  if(r.nums.empty()) return l;

  int tSum = 0;
  int lMax = l.nums.back().val;
  int rMin = r.nums.front().val;

  if(lMax <= rMin) {
    l.nums.insert(l.nums.end(), r.nums.begin(), r.nums.end());
    reduce(l.nums, l.nums.size());
    inf.nums = l.nums;
    inf.sum = l.sum + r.sum;
    return inf;
  }
  for(int i=0; i < r.nums.size(); i++) {
    if(r.nums[i].val < lMax) {
      tSum += (lMax - r.nums[i].val)*r.nums[i].freq;
      r.nums[i].val = lMax;
    }
    else break;
  }

  l.nums.insert(l.nums.end(), r.nums.begin(), r.nums.end());
  reduce(l.nums, l.nums.size());
  inf.nums = l.nums;
  inf.sum = l.sum + r.sum + tSum;

  return inf;
}

Info newInfo(int value) {
  Info inf;
  inf.nums.push_back({value, 1});
  inf.sum = 0;
  return inf;
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
    printTree();
  }

  void printTree() {
    int cont = 0;
    for(auto inf: tree) {
      cout << "Node #" << cont << " ";
      debugInfo(inf);
      cont++;
    }
  }

  void update(int idx, int value) {
    updateUtil(0, 0, v.size() - 1, idx, value);
  }

  Info query(int l, int r){
    return queryUtil(0, 0, v.size() - 1, l, r);
  }
};


int main() {
  int n, q; cin >> n >> q;
  vector<int> nums(n);

  for(int i=0; i<n; i++) cin >> nums[i];

  SegmentTree st(nums);

  while (q--) {
    int l, r; cin >> l >> r;
    l--; r--;
    Info res = st.query(l, r);
    cout << res.sum << endl;
  }

  return 0;
}
