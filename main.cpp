#include <bits/stdc++.h>
using namespace std;

template<size_t id, typename T>
struct tupleElement {
	T x;
	tupleElement(){}
	tupleElement(T x):x(x){}
};

template<size_t id, typename ...args>
struct tupleImpl;

template<size_t id>
struct tupleImpl<id> {

};
template<size_t id, typename Head, typename ...args>
struct tupleImpl<id, Head, args...>:
	public tupleElement<id, Head>, tupleImpl<id + 1, args...> {
	typedef Head typeValue; 
	typedef tupleElement<id, Head> element;
	typedef tupleImpl<id + 1, args...> next;
	tupleImpl<id, Head, args...>(){}
	tupleImpl<id, Head, args...>(const Head &x, const args &...xs):element(x), next(xs...) {}
};

template<size_t id,typename Head, typename ...args>
Head& getVal(tupleImpl<id, Head, args...>& tuple) {
	return tuple.tupleElement<id, Head>::x;
}

template<typename ...args>
using Tuple = tupleImpl<0, args...>;

int main() {
	// Tuple<int,double,long long> x(1, 1.1234, 1LL<<55);
	Tuple<int, float, std::string> tuple(5, 8.3, "Foo");
    // getVal<0>(tuple) = 5;
    // getVal<1>(tuple) = 8.3;
    // getVal<2>(tuple) = "Foo";
    std::cout << getVal<0>(tuple) << std::endl;
    std::cout << getVal<1>(tuple) << std::endl;
    std::cout << getVal<2>(tuple) << std::endl;
    return 0;
}