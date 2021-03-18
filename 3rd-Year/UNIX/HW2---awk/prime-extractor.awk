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
	if (n <= 3) {
        return n > 1; # true for 2 and 3, false for anything less
	}
    if (!(n~"^[0-9]+$") || n % 2 == 0 || n % 3 == 0) {
        return 0; # false for multiples of 2, 3, and non-numbers
	}
	# only numbers next to multiples of 6 can be prime (except 2 and 3)
    for(i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
		}
	}
    return 1;
}