#include <bits/stdc++.h>
using namespace std;

FILE *fin, *fout, *fscr, *frep, *fstd;

const int MaxN = 500000;

int n;
int per[MaxN + 1];

int lis[MaxN + 1], lds[MaxN + 1];

bool mark[MaxN + 1];

inline void myassert(bool cond) {
  if (!cond) {
    printf("0\n");
    exit(0);
  }
}

int main(int argc, char **argv) {
  fin = fopen("input", "r");
  fout = fopen("user_out", "r");
  fstd = fopen("answer", "r");
  //fscr = fopen(argv[5], "w");
  //frep = fopen(argv[6], "w");

  fscanf(fin, "%d", &n);
  for (int i = 1; i <= n; ++i) {
    fscanf(fin, "%d", &per[i]);
  }

  int lis_a, lds_a, lis_b, lds_b;
  fscanf(fstd, "%d", &lis_a);
  if (lis_a == -1) {
    fscanf(fout, "%d", &lis_b);
    myassert(lis_b == -1);
  } else {
    fscanf(fstd, "%d", &lds_a);

    fscanf(fout, "%d", &lis_b);
    myassert(lis_a == lis_b);
    for (int i = 1; i <= lis_b; ++i) {
      fscanf(fout, "%d", &lis[i]);
      myassert(1 <= lis[i] && lis[i] <= n);
      mark[lis[i]] = true;
      if (i > 1) {
        myassert(lis[i] > lis[i - 1]);
        myassert(per[lis[i]] > per[lis[i - 1]]);
      }
    }

    fscanf(fout, "%d", &lds_b);
    myassert(lds_a == lds_b);
    for (int i = 1; i <= lds_b; ++i) {
      fscanf(fout, "%d", &lds[i]);
      myassert(1 <= lds[i] && lds[i] <= n);
      myassert(!mark[lds[i]]);
      if (i > 1) {
        myassert(lds[i] > lds[i - 1]);
        myassert(per[lds[i]] < per[lds[i - 1]]);
      }
    }
  }

  printf("100\n");

  return 0;
}
