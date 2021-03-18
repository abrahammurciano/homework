#!/usr/bin/awk -f
BEGIN	{
	FS = "[^0-9]*";
}
{
	for (i = 1; i <= NF; ++i) {
		if (prime($i) == 1) {
			print $i;
		}
	}
}

## returns 1 if n is an integer and is prime, 0 otherwise.
function prime(n,		i) {
	for (i = 2; i <= n / 2; ++i) {
		if (n % i == 0) {
			return 0;
		}
	}
	return n ~ /^[0-9]+$/;
}