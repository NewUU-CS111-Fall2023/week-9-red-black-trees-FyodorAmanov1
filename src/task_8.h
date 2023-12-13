vector<int> findMissingNumbers(vector<int>& nums, int n) {
  vector<int> missing;
  unordered_map<int, int> hashTable(n + 1);

  for (int num : nums) {
    hashTable[num] = 1;
  }

  for (int i = 0; i <= n; ++i) {
    if (hashTable[i] == 0) {
      missing.push_back(i);
    }
  }

  return missing;
}