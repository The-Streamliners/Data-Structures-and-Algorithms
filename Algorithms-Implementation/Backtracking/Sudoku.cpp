// Title - Sudoku solver
// Statement - It will solve a given sudoku if it is valid, else will return invalid sudoku.

#include<bits/stdc++.h>
using namespace std;

bool isAcceptable(vector<vector<char>> &A, char c, int x, int y){
    for (int i=0; i<9; i++){
        if (A[i][y]==c) return false;
    }
    for (int j=0; j<9; j++){
        if (A[x][j]==c) return false;
    }
    int minx=(x/3)*3, miny=(y/3)*3;
    for (int i=minx; i<minx+3; i++){
        for (int j=miny; j<miny+3; j++){
            if (A[i][j]==c) return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>> &A, vector<pair<int, int>> &blanks, int start){
    if (start==blanks.size()) return true;

    for (int i=1; i<10; i++){
        if (isAcceptable(A, i+'0', blanks[start].first, blanks[start].second)){
            A[blanks[start].first][blanks[start].second] = i+'0';
            if(solve(A,blanks,start+1)) return true;
            else A[blanks[start].first][blanks[start].second] = '.';
        }
    }
    return false;
}

int main() {
    cout<<"Enter 9*9 incomplete sudoku with '.' at blank spaces"<<endl;
    vector<vector<char>> sudoku(9);
    vector<pair<int, int>> blanks;
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            char c; cin>>c;
            sudoku[i].push_back(c);
            if (c=='.'){
                blanks.push_back(make_pair(i, j));
            }
        }
    }
    bool solved = solve(sudoku,blanks,0);
    if (!solved) cout<<"Invalid Sudoku";
    else{
        cout<<"Solved Sudoku :-"<<endl;
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                cout<<sudoku[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}

// Name: Chirag Dalmia
// Github ID: chiru-cd