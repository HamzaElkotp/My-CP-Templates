int x = 5328; // 00000000000000000001010011010000
has_single_bit(x); // check if power of 2

// 19 => number of zeros at the beginning of the number 
__builtin_clzll(x);

// 4 => number of zeros at the end of the number 
__builtin_ctzll(x);

// 5 => number of ones in the number 
__builtin_popcountll(x);

// 1 => parity (even or odd) of the number of ones
__builtin_parityll(x);

// 4 => finds the index of the first (most right) set bit
__builtin_ffsll(x);


//////////// Only for cpp20

// highest bit position (x) such that 2^x <= n
bit_width(n) - 1;

// checks if the number is a power of two
has_single_bit((unsigned int) n);

// round up to the next power of two
bit_ceil((unsigned int) n);

// round down to the next power of two
bit_floor((unsigned int) n);

// shift to left by k bits
rotl((unsigned int) n, k);

// shift to right by k bits
rotr((unsigned int) n, k); 


// count the leading/trailing zeros/ones
countl_zero/countr_zero/countl_one/countr_one
