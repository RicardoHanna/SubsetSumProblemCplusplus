#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<int>vi;
typedef pair<int,int>ii;
    int T,N;
int G;



/*int maxValueRec(int i, int q){
    if(i>N)
        return 0;
    int l=0, r=0;
    if(dp[i][q]!=-1)
       return dp[i][q];
    if(q+w[i]<=W)
       l = p[i]+maxValueRec(i+1, q+w[i]);
    r = maxValueRec(i+1, q);
    return  dp[i][q]=max(l, r);

}*/

//Tp
void displayItems1(vector<vi>&opt, vector<int> &wt,int W) {//opt from iterative bottom-up
int n = opt.size();
	W = opt[0].size()-1;
	vector <bool> selected(n, false);
	int i = n-1, w = W;
	while(i>0 && w>0){
		if (opt[i][w] != opt[i-1][w]) {//we used wt[i], so w becomes w-wt[i]
			selected[i] = true;
			w = w - wt[i];
		}
		else {//we didn't use wt[i], so w remains the same.
			selected[i] = false;
		}
		i--;
	}
	cout << "Items weight selected: ";
	for (int i = 0; i < n; i++)
		if (selected[i])
			cout << wt[i] << " ";
	cout << endl;

}

int subsetsumRec(int i, int w,int W, vector<int>& wt,vector<int>&p ,vector<vi>&opt,int n){
    if(i>n)
        return 0;
    int l=0, r=0;
    if(opt[i][w]!=-1)
       return opt[i][w];
    if(w+wt[i]<=W)
       l = p[i]+subsetsumRec(i+1, w+wt[i],W,wt,p,opt,n);
    r = subsetsumRec(i+1, w,W,wt,p,opt,n);
    return  opt[i][w]=max(l,r);

}


int subsetsum(int W, vector<int>& wt,vector<int>&p ,vector<vi>&opt,int n) {


	for(int i=1;i<n;i++){
        for(int w=1;w<=W;w++){
            if(wt[i]>w)
                opt[i][w]=opt[i-1][w];
            else
                opt[i][w]=max(p[i]+opt[i-1][w-wt[i]],opt[i-1][w]);
        }
	}
	return opt[n-1][W];
}


// Returns the maximum value that can be put in a knapsack of capacity W
/*int knapsack(int W, vector<int>& wt, vector<int>& val, vector<vi>&opt) {
	int n = wt.size();

	// Build table opt[][] in bottom up manner
	for (int i = 1; i < n; i++) {
		for (int w = 1; w <= W; w++) {
			if (wt[i] > w)
				opt[i][w] = opt[i - 1][w];
			else
				opt[i][w] = max(val[i] + opt[i - 1][w - wt[i]], opt[i - 1][w]);
		}
	}
	return opt[n-1][W];
}

*/
int main(){
    ifstream fin;
    int n;
    fin.open("sessionI33412021.txt");
    if(!fin){
        cerr<<"Error:"<<endl;
        return 1;
    }
	//vector<int> val (arr1,arr1+l);//{ 0, 1, 6, 18, 22, 28 };//
	int W,sum;
	//int n = wt.size();
		vector<int> p;
	vector<int> wt;


fin>>T;
    while(T--){
vector<vi>opt;
fin>>n;

p.assign(n,0);
wt.assign(n,0);
for(int j=1;j<=n;j++){
fin>>p[j]>>wt[j];

}


fin>>G;
//n=wt.size();
sum=0;
	for(int k=1;k<=G;k++){
            fin>>W;
      opt.assign(n, vector<int>(W + 1, 0));
        sum+=subsetsum(W, wt,p,opt,n);
	}
    cout<<sum<<endl;
	//cout << "SubSetSum DP bottom-up: " << subsetsum(W, wt,p,opt) << endl;


   displayItems1(opt,wt,W);


opt.clear();
p.clear();
wt.clear();




	}


return 0;

}

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<int>vi;
typedef pair<int,int>ii;
    int T,N;
int G,W;

int w[1000],p[1000];
int dp[1000][1000];

int maxValueRec(int i, int q){
    if(i>N)
        return 0;
    int l=0, r=0;
    if(dp[i][q]!=-1)
       return dp[i][q];
    if(q+w[i]<=W)
       l = p[i]+maxValueRec(i+1, q+w[i]);
    r = maxValueRec(i+1, q);
    return  dp[i][q]=max(l, r);

}

int maxValue(){
for(int i=1;i<=N;i++){
    for(int j=1;j<=W;j++){

        if(w[i]>j)
            dp[i][j]=dp[i-1][j];
        else
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+p[i]);
    }
}
return dp[N][W];
}

int main()
{

    ifstream fin;
vector< pair <double,double> > v;
    fin.open("sessionI33412021.txt");
    if(!fin){
        cerr<<"Error:"<<endl;
        return 1;
    }

    fin>>T;
    while(T--){

fin>>N;

for(int j=1;j<=N;j++){
fin>>p[j]>>w[j];
//    sort(v[i].begin(),v[i].end());
}
fin>>G;
int sum=0;

for(int k=1;k<=G;k++){
     memset(dp, -1, sizeof(dp));
    fin>>W;
sum+=maxValueRec(1,0);

    }
cout<<sum<<endl;
    }
    return 0;

}

*/

