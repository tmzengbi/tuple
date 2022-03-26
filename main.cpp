#include <bits/stdc++.h>
using namespace std;

template<typename ...T>
class Tuple;

template<typename T>
class Tuple<T> {
	constexpr static int id = 0;
	T x;
	public:
	Tuple<T>(T x):x(x) {

	}
	virtual void print() {
		cout << x << endl;
	}
};

template<typename T, typename ...Ts> 
class Tuple<T, Ts...> : Tuple<Ts...> {
	constexpr static int id = sizeof...(Ts);
	T x;
	public:
	Tuple<T, Ts...>(T x, Ts... xs):x(x), Tuple<Ts...>(xs...) {

	}
	virtual void print() {
		cout << x << endl;
		Tuple<Ts...>::print();
	}
};

int main() {
	Tuple<int,double,long long> x(1, 1.1234, 1LL<<55);
	x.print();
}