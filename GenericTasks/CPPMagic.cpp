#include <iostream>

using namespace std;

static int x = []() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	return 0;
}();