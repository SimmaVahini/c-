#include <iostream>
using namespace std;

template <bool... bits>
int reversed_binary_value() {
    int result = 0;
    int power = 0;
    
    // Using an initializer list trick to expand the parameter pack
    // in the order they appear.
    int _[] = { (result += (bits << power++), 0)... };
    
    // The line above is a hack to iterate through the pack. 
    // It says: for each bit in bits, shift it by 'power', 
    // add to 'result', then increment 'power'.
    
    (void)_; // Suppress unused variable warning
    return result;
}



template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
    	int z = reversed_binary_value<digits...>();
    	std::cout << (z+64*y==x);
  	}
};

int main()
{
  	int t; std::cin >> t;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	CheckValues<6>::check(x, y);
    	cout << "\n";
  	}
}
