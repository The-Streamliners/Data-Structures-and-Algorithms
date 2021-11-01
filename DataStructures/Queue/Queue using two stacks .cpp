////   Author: ABHINASH GIRI
#include "bits/stdc++.h"
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
typedef long long ll;
typedef vector<long long int> vll;
typedef pair<ll, ll> pll;
class Queue
{
public:
	stack<ll> a, b;
	ll dequeue()
	{
		if (a.empty() && b.empty())
		{
			cout << "Queue is Empty !\n";
			exit(0);
		}
		while (!a.empty())
		{
			b.push(a.top());
			a.pop();
		}
		ll t = b.top();
		b.pop();
		while (!b.empty())
		{
			a.push(b.top());
			b.pop();
		}
		return t;
	}
	void enqueue(ll x)
	{
		a.push(x);
	}
	bool isEmpty()
	{
		return a.empty();
	}
	ll back()
	{
		return a.top();
	}
	size_t size()
	{
		return a.size();
	}
	ll front()
	{
		ll d = dequeue();
		enqueue(d);
		return d;
	}
};

int main()
{
	fast;
	Queue q;
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(0);
	q.enqueue(1);
	cout << "Front element is " << q.front() << "\n";
	cout << "Back element is " << q.back() << "\n";
	if (q.isEmpty())
	{
		cout << "Queue is Empty\n";
	}
	while (!q.isEmpty())
	{
		cout << "Poping element --> " << q.dequeue() << "\n";
	}
	if (q.isEmpty())
	{
		cout << "Queue is Empty\n";
	}
	return 0;
}


