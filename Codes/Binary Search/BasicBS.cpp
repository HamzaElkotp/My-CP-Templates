while(k--){
	int x;cin>>x;
	int l=0,r=n-1,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(s[mid]==x){
			ans=1;
			break;
		}
		else if(s[mid]>x)r=mid-1;
		else l=mid+1;
	}
	if(ans)cout<<"YES\n";
	else cout<<"NO\n";
}