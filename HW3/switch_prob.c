

long switch_prob(long x, long n) {

	long result = x;
	switch(n){

	case 0:
	case 2:
		result = x*8;
		break;
	case 1:
		result = 0x4b + x;
		break;
	case 3:
		result = rdi >> 3;
		break;
	case 4:
		result = x-(x << 4);
	case 5:
		result = result*result;
	default:
		result += 0x4b;
		break;
	}
	return result;
		
