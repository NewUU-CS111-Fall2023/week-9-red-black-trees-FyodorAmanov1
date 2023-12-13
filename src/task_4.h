int kthSmallest(const vector<vector<int>>& matrix, int k) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for (int i = 0; i < matrix.size(); ++i) {
    pq.push({matrix[i][0], i});
  }

  int kthElement;
  for (int i = 0; i < k; ++i) {
    auto topElement = pq.top(); pq.pop();
    kthElement = topElement.first;
    int col = topElement.second;
    if (col + 1 < matrix.size()) {
      pq.push({matrix[col][col + 1], col + 1});
    }
  }
  return kthElement;
}