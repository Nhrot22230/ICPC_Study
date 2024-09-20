#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> tree[], int treeNode)
{
  int len1 = tree[2 * treeNode].size();
  int len2 = tree[2 * treeNode + 1].size();
  int index1 = 0, index2 = 0;
  while (index1 < len1 && index2 < len2) {
    if (tree[2 * treeNode][index1] > tree[2 * treeNode + 1][index2]) {
      tree[treeNode].push_back(
        tree[2 * treeNode + 1][index2]);
      index2++;
    }
    else {
      tree[treeNode].push_back(tree[2 * treeNode][index1]);
      index1++;
    }
  }
  while (index1 < len1) {
    tree[treeNode].push_back(tree[2 * treeNode][index1]);
    index1++;
  }
  while (index2 < len2) {
    tree[treeNode].push_back(
    tree[2 * treeNode + 1][index2]);
    index2++;
  }
}

void build(vector<int> tree[], int* arr, int start, int end, int treeNode)
{
  if (start == end) {
    tree[treeNode].push_back(arr[start]);
    return;
  }
  int mid = (start + end) / 2;
  build(tree, arr, start, mid, 2 * treeNode);
  build(tree, arr, mid + 1, end, 2 * treeNode + 1);
  merge(tree, treeNode);
  return;
}

int query(vector<int> tree[], int treeNode, int start, int end, int left, int right) {
  if (start > right || end < left) return 0;
  if (start >= left && end <= right) {
    return tree[treeNode].end() - upper_bound(
      tree[treeNode].begin(),
      tree[treeNode].end(),
      right);
  }

  int mid = (start + end) / 2;
  int op1 = query(tree, 2 * treeNode, start, mid, left,
    right);
  int op2 = query(tree, 2 * treeNode + 1, mid + 1, end,
    left, right);

  return op1 + op2;
}

int main(){
  int n;
  cin >> n;
  int arr[n];
  int next_right[n];

  for (int i=0; i<n; i++) cin >> arr[i];
  vector<int> tree[4 * n];
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
  build(tree, next_right, 0, n - 1, 1);

  int q; cin >> q;
  while (q--){
    int ans;
    int left1; cin >> left1;
    int right1; cin >> right1;
    left1--; right1--;
    ans = query(tree, 1, 0, n - 1, left1, right1);
    cout << ans << endl;
  }
  return 0;
}
