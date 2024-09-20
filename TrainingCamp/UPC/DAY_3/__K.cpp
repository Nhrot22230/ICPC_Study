#include <bits/stdc++.h>
using namespace std;

typedef struct {
  int sum;
  bool ok;
  int l;
  int r;
} Info;

const Info null_element = {0, true};

void debugInfo(Info inf) {
  cout << "{" << inf.sum << ", ";
  if(inf.ok) cout << "YES";
  else cout << "NO";
  cout << "}" << " -- ";
}

Info combine(Info l, Info r) {
  return {
    l.sum + r.sum,
    (l.sum + r.sum) == 0 &&
    (l.l == 1) && (r.r == -1),
    l.l,
    r.r
  };
}

Info newInfo(int value) {
  return {
    value,
    false,
    value,
    value
  };
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
      //for(Info inf: tree) debugInfo(inf); cout << endl << endl;
    }

    void update(int idx, int value) {
      updateUtil(0, 0, v.size() - 1, idx, value);
    }

    Info query(int l, int r){
      return queryUtil(0, 0, v.size() - 1, l, r);
    }
};

void solve() {
  int n; scanf("%d", &n);
  getchar();
  vector<int> nums(n);
  for(int i=0; i<n; i++) {
    char c; scanf("%c", &c);
    nums[i] = (c == '(' ? 1 : -1);
  }
  SegmentTree st(nums);

  int m; scanf("%d", &m);
  while (m--) {
    int idx; scanf("%d", &idx);
    if(idx == 0) {
      Info res = st.query(0, n - 1);
      if(res.ok) printf("YES\n");
      else printf("NO\n");
      continue;
    }
    idx--;
    int val = nums[idx];
    nums[idx] = -1*val;
    st.update(idx, -1*val);
  }
}

int main() {
  int t=1;
  for(int i=1; i<=t; i++){
    printf("Test %d:\n", i);
    solve();
  }
  return 0;
}
