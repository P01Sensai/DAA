#include<bits/stdc++.h>
using namespace std;
  
void jobScheduling(vector<pair<int,pair<char,int>>> J, int n)
{
    sort(J.begin(), J.end(), greater<pair<int,pair<char,int>>>());
    vector<pair<int,pair<char,int>>> result;
    bool slot[n];
    for(int i = 0; i <n ;i++){
        slot[i] = false;
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j = min(n, J.at(i).second.second) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result.push_back(make_pair(J.at(i).first, make_pair(J.at(i).second.first, J.at(i).second.second)));
                //result.push_back(J[i].first,{J[i].second.first,J[i].second.second});
                slot[j] = true;
                //cout<<j<<endl;
                break;
            }
        }
    }
    //int c = 0;
    for(auto &task : result){
        char job = task.second.first;
        int profit = task.first;
        int deadline = task.second.second;
    
        cout<<job<<"   "<<profit<<"     "<<deadline<<endl;
        //cout<<job<<" "<<profit<<" "<<(c)<<"-"<<deadline<<endl;
        //c +=1;
    }
}
int main()
{
    vector<pair<int,pair<char,int>>>job;
    //map<char,pair<int,int>> job;
    char j;
    int deadline;
    int profit;
    int n;cin>>n;
    for(int i =0;i<n;++i){
        cin>>j>>deadline>>profit;
        job.push_back({profit,{j,deadline}});
        //job[i].insert(j,make_pair(deadline,profit));
    }
    cout<<"JOB"<<" "<<"PROFIT"<<" "<<"DEADLINE"<<endl;
    jobScheduling(job,n);
    return 0;
}