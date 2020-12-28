int mx_strncmp(const char *s1, const char *s2, int n) {
	if (n == 0)
		return 0;
	for (int i = 0; s1[i] == s2[i] && i < n - 1; i++) {
		if (s1[i] == '\0' && s2[i] == '\0') {
			s1++;
			s2++;
		}
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}
