#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/construct-target-array-with-multiple-sums/description/

    Refer Video :- https://www.youtube.com/watch?v=-2_sXN4IkE4&t=2429s

*/

bool isPossible(vector<int> &target){

    // Max heap bnao orr target ke values daal do
    priority_queue<long long> p(target.begin(), target.end());

    // ek sum variable le lo
    long long sum = 0;

    // sum nikaalo target array ka
    for(int i = 0; i < target.size(); i++)
        sum += target[i];
    
    // Variables declare kro future use
    long long maxElement, remainingSum, element;

    // Hume tb tk chlana hai loop ko jb tk max heap ke top element me 1 na aa jaye

    // Iss se pta chlega ki max heap me ab sirf 1 present hai as maximum element
    while(p.top() != 1){

        // max element nikaalo max heap se
        maxElement = p.top(); p.pop();

        // Remaining Sum nikaalo, why? 
        // taki hume vo element mile jiske add hone se maximum element bna hai
        remainingSum = sum - maxElement;

        // Check kro ki remaining Sum kahi 0 se chota ya barabar to nhi or remaining sum kahi max element se bda yua equa to nhi

        // Hume remaining sum 0 and max element ke bich me chahiye
        if(remainingSum <= 0 || remainingSum >= maxElement)
            return 0;

        // ab hum element nikaal lete hai jo ki maxElement and remainingSum ka mod hai
        // mod kyo? Subtract kyo nhi? 
        // mod isliye because hum vo baar baar ka rhe hai ek hi remaining sum se, to uss se time complexity badh jayegi
        // so uss se bchne ke liye mod kr rhe hai taaki direct answer mil jaye
        
        element = maxElement % remainingSum;

        // ek edge case hai, jha par hume mod krne se 0 milega, to hum true tb hi return krenge jb remaining sum 1 hai orr tb mod 0 aa rha hai
        // vrna agar kisi bhi remaining sum se mod 0 aa rha hai to false return krenge kyoki uska answer hi nhi niklega ka kbhi isliye

        if(element == 0){
            if(remainingSum != 1) 
                return 0;
            else
                return 1;
        }

        // Sum ko update karo
        sum = remainingSum + element;

        // Push kar do element ko max heap pe
        p.push(element);
    }

    return 1;

}

int main(){

    vector<int> arr = {9, 3, 5};

    cout << "Is Possible ? " << isPossible(arr);

}