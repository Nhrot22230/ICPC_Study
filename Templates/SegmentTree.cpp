#include <vector>
#include <iostream>

using std::vector, std::max, std::min, std::cout;

typedef struct {
  int max1;
  int max2;
} Info;

const Info null_element = {-1, -1};

void debugInfo(Info inf) {
  cout << "{" << inf.max1 << ", " << inf.max2 << "}" << " -- ";
}

Info combine(Info l, Info r) {
  if (l.max1 > r.max1) return {l.max1, max(l.max2, r.max1)};
  return {r.max1, max(r.max2, l.max1)};
}

Info newInfo(int value) {
  return {value, -1};
}

int getMid(int l, int r) {
  //return l + (r - l)/2;
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
