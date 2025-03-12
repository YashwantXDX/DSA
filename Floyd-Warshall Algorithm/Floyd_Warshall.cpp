#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

    Refer Video :- https://www.youtube.com/watch?v=h6o6kC5oG2A

    Important Note :- 

    How Floyd Warshall Algorithm detects Negetive Cycle?

    Agar Diagonal me koi bhi negetive weight present ho mtlb usme negetive cycle hai

    0 1 5
    4 0 6  ==> Ye hai Normal Graph
    6 7 0
    
    0 9 8
    6 -7 9  ==> Ye hai negetive cycle wala graph
    8 5 0

    Hum dekh skte hai ki Diagonals ko all 0 hona chahiye tha but hume negetive mila hai
    mtlb vha cycle present hai


    Time Complexity :- O(V^3)
    Space Complexity :- O(1)
    
*/

// When changing -1 to INT_MAX and then INT_MAX to -1
void shortestDistance(vector<vector<int>>& mat) {
    
    // -1 wale weight ko INT_MAX bna do humare logic ke hisaab se
    int size = mat.size();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(mat[i][j] == -1)
                mat[i][j] = INT_MAX;
        }
    }

    // Intermediate Nodes wala loop
    for(int k = 0; k < size; k++){

        // First Node ko pdko
        for(int i = 0; i < size; i++){

            // uss se Second node ka path dhundo with help of Intermediate node
            for(int j = 0; j < size; j++){

                // Agar i se k ya phir k se j wala path INT_MAX hota hai to vo wala part skip kro
                if(mat[i][k] == INT_MAX || mat[k][j] == INT_MAX)
                    continue;

                // current path se chota dhundhne ki koshish karo with the help of intermediate node
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    // Ab aakhir me jis kisi ka bhi path nhi mila usme INT_MAX hoga
    // Use dobara se -1 karo do
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(mat[i][j] == INT_MAX)
                mat[i][j] = -1;
        }
    }

}

// Without Changing the -1 to INT_MAX
void shortestDistance2(vector<vector<int>>& mat) {

    int size = mat.size();

    // Intermediate Nodes wala loop
    for(int k = 0; k < size; k++){

        // First Node ko pdko
        for(int i = 0; i < size; i++){

            // uss se Second node ka path dhundo with help of Intermediate node
            for(int j = 0; j < size; j++){

                /*
                    Dekho ki kahi :-

                    i. I or K barabar to nhi
                    ii. K or J barabar to nhi
                    iii. I or J barabar to nhi
                    iv. mat[I][K] -1 to nhi
                    v. mat[K][J] -1 to nhi

                    Agar hai to ignore karo

                
                */
                if(i == k || k == j || i == j || mat[i][k] == -1 || mat[k][j] == -1)
                    continue;
                
                else{

                    //Check kro ki path abhi tk nhi mila kya mat[i][j] ka
                    // -1 hoga to nhi mila hai to jo current smallest mila hai usi se update kr do
                    if(mat[i][j] == -1)
                        mat[i][j] = mat[i][k] + mat[k][j];
                    
                    // Vrna normal chlo
                    // Chota dhundhne wala
                    else
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);

                }

            }
        }
    }

}


int main(){
    vector<vector<int>> adj = {
        {0,1,43},
        {1,0,6},
        {-1,-1,0},
    };

    shortestDistance2(adj);

    for(int i = 0; i < adj.size(); i++){
        for(int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}