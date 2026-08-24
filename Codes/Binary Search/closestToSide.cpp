void closestToRight(){
   int s[n+1];
   for(int i=1;i<=n;i++)cin>>s[i];
   while(k--){
      int x;cin>>x;
      int l=1,r=n,ans=0;
      while(l<=r){
         int mid=l+r>>1;
         if(s[mid]>x)r=mid-1;
         else ans=mid,l=mid+1;
      }
      cout<<ans<<'\n';
   }
}

void closestToLeft(){
   int s[n+1];
   for(int i=1;i<=n;i++)cin>>s[i];
   while(k--){
      int x;cin>>x;
      int l=1,r=n,ans=n+1;
      while(l<=r){
         int mid=l+r>>1;
         if(s[mid]>=x)ans=mid,r=mid-1;
         else l=mid+1;
      }
      cout<<ans<<'\n';
   }
}