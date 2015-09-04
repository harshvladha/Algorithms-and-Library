int main(){
	char s[5];
	int n, t, pt;
	while(1){
		scanf("%s", s);
		n = 10*(s[0]-'0') + (s[1]-'0');
		t = s[3] - '0';
		if(n==0 && t==0)
			break;
		while(t--)
			n*=10;
		pt = 1; //power of two smaller or equal to n
		while(pt<=n)
			pt<<=1;
		printf("%d\n", ((n-(pt>>1))<<1)+1);
	}
	return 0;
}