#include <iostream>
using namespace std;

int main() {

	int n1 = 1;
	int n2 = 1;
	int n;
	int n3;
	printf("c >> ");
	scanf("%d", &n);
	for (int i = 3; i <= n; i++) {
		n3 = n1 + n2;

		n1 = n2;
		n2 = n3;
	}
	
	printf("%d", n3);
	
	return 0;
}