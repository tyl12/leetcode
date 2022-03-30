

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
private:
// unordered_map<出发机场, map<到达机场, 航班次数>> targets
unordered_map<string, map<string, int>> targets;
bool backtracking(int ticketNum, vector<string>& result) {
    if (result.size() == ticketNum+1) {
        return true;
    }
    for (pair<const string, int>& target : targets[result[result.size() - 1]]) {
        if (target.second > 0 ) { // 记录到达机场是否飞过了
            result.push_back(target.first);
            target.second--;
            if (backtracking(ticketNum, result)) return true;
            result.pop_back();
            target.second++;
        }
    }
    return false;
}
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        targets.clear();
        vector<string> result;
        for (const vector<string>& vec : tickets) {
            targets[vec[0]][vec[1]]++; // 记录映射关系
        }
        result.push_back("JFK"); // 起始机场
        backtracking(tickets.size(), result);
        return result;
    }
};

class Solution3 {
public:
    vector<string> result;
    vector<vector<string>> preResult;

    vector<vector<string>> data;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //vector<bool> used=vector<bool>(tickets.size(), false);

        //cout<<"tickets.size="<<tickets.size()<<endl;

        vector<bool> used(tickets.size(), false);
        //cout<<"used.size="<<used.size()<<endl;

        backtracking(tickets,used);

        //showVector(bestPath);
        return bestPath;
        // cout<<"find done"<<endl;
        // for_each(preResult.begin(), preResult.end(), [this](auto m){
        //     showVector(m);
        // });
        // cout<<"show done"<<endl;
        // sort(preResult.begin(), preResult.end(), [](auto m1, auto m2){
        //     for(int i=0;i<m1.size();i++){
        //         auto v1 = m1[i];
        //         auto v2 = m2[i];
        //         if (v1<v2)
        //             return true;
        //         if (v1==v2)
        //             continue;
        //         if (v1>v2)
        //             return false;
        //     }
        //     return false;
        // });
        // if (preResult.empty()){
        //     cout<<"NO valid path"<<endl;
        //     return vector<string>();
        // }
        // return preResult[0];
    }

    vector<string> bestPath;
    void backtracking(vector<vector<string>>& tickets, vector<bool>& used){
        if (data.size() >= tickets.size()){
            //cout<<"ssss1"<<endl;
            vector<string> tmpResult;
            tmpResult.push_back(data[0][0]);
            for (int i=0;i<data.size();i++){
                tmpResult.push_back(data[i][1]);
            }
            //cout<<"find one result:";
            //showVector(tmpResult);
            //preResult.push_back(tmpResult);

            if (bestPath.empty())
                bestPath = tmpResult;
            else{
                for(int i=0;i<tmpResult.size();i++){
                    if (bestPath[i] == tmpResult[i])
                        continue;
                    else if (bestPath[i] < tmpResult[i])
                        return;
                    else{
                        bestPath = tmpResult;
                        return;
                    }
                }
            }

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


            // sort(preResult.begin(), preResult.end(), [](auto m1, auto m2){
            //     for(int i=0;i<m1.size();i++){
            //         auto v1 = m1[i];
            //         auto v2 = m2[i];
            //         if (v1<v2)
            //             return true;
            //         if (v1==v2)
            //             continue;
            //         if (v1>v2)
            //             return false;
            //     }
            //     return false;
            // });

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

class Solution2 {
public:
    vector<string> result;
    vector<vector<string>> path;
    vector<vector<string>> _tickets;

    using TM = map<string, map<string, int>>;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        _tickets = tickets;

        TM ticketMap;// from, to, count

        for_each(tickets.begin(), tickets.end(), [&ticketMap, this](auto& t){
            //showVector(t);
            auto from = t[0];
            auto to = t[1];
            auto& existed = ticketMap[from];
            existed[to] = existed[to] + 1;
        });

        for (const auto& t:ticketMap){
            auto toCountMap = t.second;
            for (const auto& v:toCountMap){
                auto to = v.first;
                auto count = v.second;
                //cout<<t.first<< " - " << to << " - " << count <<endl;
            }
        }

        backtracking(ticketMap);
        return result;
    }

    bool backtracking(TM& tickets){
        if (path.size() == _tickets.size()){
            result.push_back(path[0][0]);
            for (auto p:path){
                result.push_back(p[1]);
            }
            showVector(result);
            return true;
        }

        decltype(tickets.begin()) itor;
        string last = "JFK";
        if (path.empty()){
            itor = tickets.find(last);
            if (itor == tickets.end()){
                printf("ERROR: no matching");
                return false;
            }
        }
        else if (path.size() >= 1){
            last = path.back()[1];
            itor = tickets.find(last);
            if (itor == tickets.end()){
                return false;
            }
        }
        {
            auto& toCount = (*itor).second;
            for (auto& v: toCount){
                auto to = v.first;
                auto count = v.second;
                if (count <= 0){
                    printf("skip: from %s, to %s, cnt %d\n", last.c_str(), to.c_str(), count);
                    continue;
                }
                printf("from %s, to %s, cnt %d\n", last.c_str(), to.c_str(), count);

                v.second--;
                vector<string> tmp;
                tmp.push_back(last);
                tmp.push_back(to);
                path.push_back(tmp);
                auto res = backtracking(tickets);
                if (res){
                    return true;
                }
                path.pop_back();
                v.second++;
            }
        }
        return false;
    }
    void showVector(const vector<string>& data){
        for_each(data.begin(), data.end(), [](const string& v){
            printf("%s -> ", v.c_str());
        });
        printf("\n");
    }
};

int main(){
    Solution2 s;
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