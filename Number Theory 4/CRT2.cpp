#include<iostream>

using namespace std;

long long extendedGCD(long long a , long long b , long long& x , long long& y){

	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}

	long long x1 , y1 , g;

	g = extendedGCD(b , a % b , x1 , y1);

	x = y1;
	y = x1 - (a / b) * y1;

	return g;
}

long long applyCRT(long long nums[] , long long rems[] , int n , long long P){

	long  long a = 0;


	for(int i=0;i<n;i++){

		long long temp = (rems[i] * (P / nums[i])) % P;
		long long x , y;
		long long g = extendedGCD(P/nums[i] , nums[i] , x , y);

		x = ((x % nums[i]) + nums[i]) % nums[i];

		temp = (temp * x) % P;

		a = (a + temp) % P;
	}

	return a;
}

int main(){

	int t , n;

	cin>>t;

	while(t--){
		cin>>n;

		long long nums[n];
		long long rems[n];
		long long P = 1;

		for(int i=0;i<n;i++) {
			cin>>nums[i];
			P = P * nums[i];
		}

		for(int i=0;i<n;i++) cin>>rems[i];

		long long a = applyCRT(nums , rems , n , P);

		for(int i=0;i<n;i++){
			cout<<a<<" % "<<nums[i]<<" = "<<a % nums[i]<<endl;
		}
	}

}
