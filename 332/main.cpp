

#include <cstdint>
#include <ostream>
#include <string>
#include <stdio.h>
#include <stack>
#include <unistd.h>
#include <memory.h>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <functional>
#include <algorithm>
#include <cmath>
#include <utility>
#include <numeric>
using namespace std;



class Solution {
public:
    vector<string> result;
    vector<vector<string>> preResult;

    vector<vector<string>> data;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //vector<bool> used=vector<bool>(tickets.size(), false);

        cout<<"tickets.size="<<tickets.size()<<endl;

        vector<bool> used(tickets.size(), false);
        cout<<"used.size="<<used.size()<<endl;

        backtracking(tickets,used);

        cout<<"find done"<<endl;
        for_each(preResult.begin(), preResult.end(), [this](auto m){
            showVector(m);
        });
        cout<<"show done"<<endl;
        sort(preResult.begin(), preResult.end(), [](auto m1, auto m2){
            for(int i=0;i<m1.size();i++){
                auto v1 = m1[i];
                auto v2 = m2[i];
                if (v1<v2)
                    return true;
                if (v1==v2)
                    continue;
                if (v1>v2)
                    return false;
            }
            return false;
        });
        if (preResult.empty()){
            cout<<"NO valid path"<<endl;
            return vector<string>();
        }
        return preResult[0];
    }

    void backtracking(vector<vector<string>>& tickets, vector<bool>& used){
        if (data.size() >= tickets.size()){
            cout<<"ssss1"<<endl;
            vector<string> tmpResult;
            tmpResult.push_back(data[0][0]);
            for (int i=0;i<data.size();i++){
                tmpResult.push_back(data[i][1]);
            }
            cout<<"find one result:";
            showVector(tmpResult);
            preResult.push_back(tmpResult);

            // for_each(data.begin(), data.end(), [this](auto v){
            //     // for_each(v.begin(), v.end(), [](auto m){
            //     //     cout<<m<<" -> ";
            //     // });
            //     // cout<<endl;
            //     showVector(v);
            // });
            // cout<<"=========="<<endl;
            /*
            result.push_back(data[0][0]);
            for (int i=0;i<data.size();i++){
                result.push_back(data[i][1]);
            }
            showVector(result);
            */
            return;
        }

        for (int i=0;i<tickets.size();i++){
            if (used[i])
                continue;
            
            auto ticket = tickets[i];


            if (data.size()>=1){
                auto last = data.back();
                if (last[1] != ticket[0])
                    continue;
            }
            if (data.empty()){
                if (ticket[0] != "JFK"){
                    continue;
                }
            }

            // string tag;
            // for (int j=0;j<used.size();j++){
            //     if (used[j])
            //         tag += " ";
            // }
            // showVector(tag, ticket);

            data.push_back(ticket);
            used[i] = true;
            backtracking(tickets, used);
            data.pop_back();
            used[i] = false;
        }
    }

    void showVector(string tag,vector<string>& m){
        cout<<tag;
        for_each(m.begin(), m.end(), [](auto v){
            cout<<v<<" -> ";
        });
        cout<<endl;
    }

    void showVector(vector<string>& m){
        for_each(m.begin(), m.end(), [](auto v){
            cout<<v<<" -> ";
        });
        cout<<endl;
    }
};

int main(){
    Solution s;
    //vector<vector<string>> tickets;
//     tickets.push_back(vector<string>({"JFK","ABC"}));
//     cout<<"##"<<endl;
//     tickets.push_back(vector<string>({"ABC","DEF"}));
//     tickets.push_back(vector<string>({"MNO","PQR"}));
//     tickets.push_back(vector<string>({"DEF","GHI"}));
//     tickets.push_back(vector<string>({"GHI","MNO"}));
// cout<<"##"<<endl;
//     s.findItinerary(tickets);


    
    //[["EZE","TIA"],["EZE","AXA"],["AUA","EZE"],
    // ["EZE","JFK"],["JFK","ANU"],["JFK","ANU"],
    // ["AXA","TIA"],["JFK","AUA"],["TIA","JFK"],
    // ["ANU","EZE"],["ANU","EZE"],["TIA","AUA"]]

    //vector<vector<string>> tickets{{"EZE","TIA"},{"EZE","AXA"},{"AUA","EZE"},{"EZE","JFK"},{"JFK","ANU"},{"JFK","ANU"},{"AXA","TIA"},{"JFK","AUA"},{"TIA","JFK"},{"ANU","EZE"},{"ANU","EZE"},{"TIA","AUA"}};
    
    vector<vector<string>> tickets{{"EZE","TIA"},{"EZE","HBA"},{"AXA","TIA"},{"JFK","AXA"},{"ANU","JFK"},{"ADL","ANU"},{"TIA","AUA"},{"ANU","AUA"},{"ADL","EZE"},{"ADL","EZE"},{"EZE","ADL"},{"AXA","EZE"},{"AUA","AXA"},{"JFK","AXA"},{"AXA","AUA"},{"AUA","ADL"},{"ANU","EZE"},{"TIA","ADL"},{"EZE","ANU"},{"AUA","ANU"}};

    s.findItinerary(tickets);

    return 0;
}