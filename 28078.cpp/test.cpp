#include <iostream>
#include <queue>
using namespace std;

deque<int> Deque;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	string query;
	string order;

	int wall = 0;
	bool isHorizon = true; //수평인가
	bool isReverse = false;

	//왼쪽이 뒤다 반대로 생각하자
	for (int i = 0; i < N; ++i)
	{
		cin >> query;

		if (query == "push")
		{
			cin >> order;
			if (order == "b") //큐의 뒤쪽(왼쪽)에 삽입
			{
				Deque.push_front(1);
			}
			else if (order == "w")
			{
				Deque.push_front(0);
				wall++;
			}
		}
		else if (query == "count")
		{
			cin >> order;
			if (order == "b")
			{
				cout << Deque.size() - wall<<'\n';
			}
			else if (order == "w")
			{
				cout << wall <<'\n';
			}
		}
		else if (query == "pop")
		{
			if (!Deque.empty()) //큐의 앞쪽(오른쪽)에서 꺼냄
			{
				int first = Deque.back();
				if (first == 0) wall--;
				Deque.pop_back();
			}
		}
		else if (query == "rotate")
		{
			cin >> order;
			if (order == "1")//반시계 방향으로 돌리면 뒤(왼쪽)가 밑으로 감
			{
				if (isHorizon) isReverse = !isReverse;
			}
			else if (order == "r")//시계 방향으로 돌리면 앞(오른쪽)이 밑으로 감
			{
				if(!isHorizon) isReverse = !isReverse;
			}
			isHorizon = !isHorizon; //회전마다 무조건 수평여부가 바뀜

		}

		//왼쪽이 뒤니까 디폴트는 앞에서 쏟아진다
		if (!isHorizon)//수직일때
		{
			if (!isReverse)//시계방향으로 수직이면
			{
				while (!Deque.empty())
				{
					int first = Deque.back();
					if (first == 0) break;
					Deque.pop_back();
				}
			}
			else//반시계방향으로 수직이면
			{
				while (!Deque.empty())
				{
					int first = Deque.front();
					if (first == 0) break;
					Deque.pop_front();
				}
			}
		}

	}
}