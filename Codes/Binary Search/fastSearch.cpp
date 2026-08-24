int a,b;cin>>a>>b;;
cout<<(upper_bound(s,s+n,b)-s)-(lower_bound(s,s+n,a)-s)<<' ';