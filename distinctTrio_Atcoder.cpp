    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<set>
    using namespace std;
    int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    long long ans = 0;
    for(int i = 1; i < n-1; i++){
        auto ubit = upper_bound(arr.begin(),arr.end(),arr[i]);
        int high = arr.end() - ubit;
        auto lbit = lower_bound(arr.begin(), arr.end(),arr[i]);
        int low = lbit - arr.begin();
        ans += 1LL * high * low;
        }
    cout<<ans<<endl;
    }