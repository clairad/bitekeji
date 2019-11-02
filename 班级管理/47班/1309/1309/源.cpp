#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Player
{
public:
	int m_id;
	int m_score;
	int m_ability;

	bool operator < (const Player &o)
	{
		return m_score > o.m_score || m_score == o.m_score && m_id < o.m_id;
	}

	bool operator > (const Player &o)
	{
		return m_score < o.m_score || m_score == o.m_score && m_id > o.m_id;
	}
};

int main()
{
	int n, r, q;

	cin >> n >> r >> q;

	vector<Player> vp(n * 2);
	int i;

	for (i = 0; i < n * 2; i++)
	{
		vp[i].m_id = i + 1;
		cin >> vp[i].m_score;
	}

	for (i = 0; i < n * 2; i++)
	{
		cin >> vp[i].m_ability;
	}

	sort(vp.begin(), vp.end());

	int j;
	vector<Player> vtf;
	vector<Player> vtw;

	for (i = 0; i < r; i++)
	{
		for (j = 0; j < vp.size(); j += 2)
		{
			if (vp[j].m_ability < vp[j + 1].m_ability)
			{
				vp[j + 1].m_score++;
				vtf.push_back(vp[j]);
				vtw.push_back(vp[j + 1]);
			}
			else
			{
				vp[j].m_score++;
				vtf.push_back(vp[j + 1]);
				vtw.push_back(vp[j]);
			}
		}
		merge(vtf.begin(), vtf.end(), vtw.begin(), vtw.end(), vp.begin());
		vtf.clear();
		vtw.clear();
	}

	cout << vp[q - 1].m_id;
	return 0;
}