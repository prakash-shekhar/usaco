#include <bits/stdc++.h>

using namespace std;

ifstream fin ("checker.in");
ofstream fout ("checker.out");

int ans = 0;
int aim, N;
int a[20] = {0};

bool dfs(int row,
              int ld,
              int rd, int i)
{// row、ld和rd，分别表示在 纵列和两个对角线方向的限制条件下这一行的哪些地方不能放
    int p, pos;
	if (row != aim)
	{
		pos = aim&(~(row|ld|rd));
		while (pos!=0)
		{
			p = pos & (pos^(pos-1));
			pos -= p;
			if (ans<3)
			{
				int l=1, k=p;
				while(k!=1)
				{
					k=k>>1;
					l++;
				}
				a[i]=l;
			}
			dfs(row|p,(ld|p)<<1,(rd|p)>>1,i+1);
		}
	}
	else
	{
		ans++;
		if(ans<=3)
		{
			fout << a[1];
			for(int k=2; k<=N; k++)
				fout << " " << a[k];
			fout << endl;
		}
	}
}


int main()
{
    fin >> N;
    aim = (1 << N) - 1;
    dfs(0, 0, 0, 1);
    fout << ans << endl;
    return 0;
}