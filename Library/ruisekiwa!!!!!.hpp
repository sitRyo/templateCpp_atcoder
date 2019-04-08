
  // 2次元累積和
  // n * nの盤面があるとする。
  
  vector< vector<int> > sum2(n+1, vector<int>(n+1, 0));

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      sum2[i][j] += sum2[i][j - 1] + data[i][j];
    }
  }

  for (int j = 1; j <= n; ++j) {
    for (int i = 1; i <= n; ++i) {
      sum2[i][j] += sum2[i - 1][j];
    }
  }

  // x, y(x < y) の間を得る。

  rep(i, q) {
    int x, y;
    cin >> x >> y;
    cout << sum2[y][y] + sum2[x-1][x-1] - sum2[x-1][y] - sum2[y][x-1] << endl;
  }

