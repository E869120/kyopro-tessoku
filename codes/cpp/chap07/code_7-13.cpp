int GCD(int A, int B) {
	if (B == 0) return A;
	return GCD(B, A % B);
}
