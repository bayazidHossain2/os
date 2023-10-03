#include <bits/stdc++.h>
using namespace std;

int main()
{
	
    freopen("001output.txt","w",stdout);
	// Two random prime numbers
	double p = 3,q=7;
	double n = p * q;
	int e = 2;
	double phi = (p - 1) * (q - 1);
	while (e < phi) {
		if (__gcd(e, (int)phi) == 1)
			break;
		else
			e++;
	}
	int k = 2;
	double d = (1 + (k * phi)) / e;

	// Message to be encrypted
	double msg = 12;

	printf("Message data = %lf", msg);

	// Encryption c = (msg ^ e) % n
	double c = pow(msg, e);
	c = fmod(c, n);
	printf("\nEncrypted data = %lf", c);

	// Decryption m = (c ^ d) % n
	double m = pow(c, d);
	m = fmod(m, n);
	printf("\nOriginal Message Sent = %lf", m);

	return 0;
}
// This code is contributed by Akash Sharan.
