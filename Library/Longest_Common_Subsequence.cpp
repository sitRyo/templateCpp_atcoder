

for(int i = 0; i < n; ++i)for (int j = 0; j < m; ++j) {
  if (s[i] == t[j]) dp[i+1][j+1] = dp[i][j] + 1;
  else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
}