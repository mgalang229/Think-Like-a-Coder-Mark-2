#include <bits/stdc++.h>

using namespace std;

// Galang, Mark Jason T.
// 201910574

void test_case() {
    int r, c;
    cin >> r >> c;
    bool p[r+1][c+1];
    memset(p, false, sizeof(p));
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cin >> p[i][j];
        }
    }
    vector<int> n, s, e, w;
    int cnt = 0;
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c - 1; ++j) {
            if(p[i][j] == true) {
                if(p[i-1][j] == false && p[i][j-1] == false && p[i+1][j] == false) {
                    cout << ".";
                    n.push_back(cnt);
                    s.push_back(cnt);
                    e.push_back(0);
                    w.push_back(cnt);
                }
                else if(p[i][j+1] == false && p[i][j-1] == false && p[i+1][j] == false) {
                    cout << ".";
                    n.push_back(0);
                    s.push_back(cnt);
                    e.push_back(cnt);
                    w.push_back(cnt);
                }
                else if(p[i-1][j] == false && p[i][j+1] == false && p[i+1][j] == false) {
                    cout << ".";
                    n.push_back(cnt);
                    s.push_back(0);
                    e.push_back(cnt);
                    w.push_back(cnt);
                }
                else if(p[i][j-1] == false && p[i-1][j] == false) {
                    cout << "/";
                    n.push_back(cnt);
                    s.push_back(0);
                    e.push_back(0);
                    w.push_back(cnt);
                }
                else if(p[i][j+1] == false && p[i-1][j] == false) {
                    cout << "\\";
                    n.push_back(cnt);
                    s.push_back(0);
                    e.push_back(cnt);
                    w.push_back(0);
                }
                else if(p[i][j-1] == false && p[i+1][j] == false) {
                    cout << "\\";
                    n.push_back(0);
                    s.push_back(cnt);
                    e.push_back(0);
                    w.push_back(cnt);
                }
                else if(p[i][j+1] == false && p[i+1][j] == false) {
                    cout << "/";
                    n.push_back(0);
                    s.push_back(cnt);
                    e.push_back(cnt);
                    w.push_back(0);
                }
                else if(p[i-1][j] == false) {
                    cout << "-";
                    n.push_back(cnt);
                    s.push_back(0);
                    e.push_back(0);
                    w.push_back(0);
                }
                else if(p[i][j-1] == false) {
                    cout << "|";
                    n.push_back(0);
                    s.push_back(0);
                    e.push_back(0);
                    w.push_back(cnt);
                }
                else if(p[i][j+1] == false) {
                    cout << "|";
                    n.push_back(0);
                    s.push_back(0);
                    e.push_back(cnt);
                    w.push_back(0);
                }
                else if(p[i+1][j] == false) {
                    cout << "_";
                    n.push_back(0);
                    s.push_back(cnt);
                    e.push_back(0);
                    w.push_back(0);
                } 
                else {
                    cout << " ";
                }
            } 
            else {
                cout << " ";
                n.push_back(0);
                s.push_back(0);
                e.push_back(0);
                w.push_back(0);
            }
            cnt++;
        }
        cnt++;
        cout << "\n";
    }
    int distance = 0, tmp = 0;
    bool ok = false;
    for(int i = 0; i < (int) n.size(); ++i) {
        if(n[i] != 0 && !ok) {
            tmp = n[i];
            ok = true;
        }
        if(distance == c && n[i] != 0) {
            tmp = n[i];
            distance = 0;
        }
        else if(distance < c && n[i] != 0) {
            n[i] = tmp;
            distance = 0;
        }
        if(ok) distance++;
    }
    distance = tmp = 0;
    ok = false;
    for(int i = 0; i < (int) s.size(); ++i) {
        if(s[i] != 0 && !ok) {
            tmp = s[i];
            ok = true;
        }
        if(distance == c && s[i] != 0) {
            tmp = s[i];
            distance = 0;
        }
        else if(distance < c && s[i] != 0) {
            s[i] = tmp;
            distance = 0;
        }
        if(ok) distance++;
    }
    distance = tmp = 0;
    ok = false;
    for(int i = 0; i < (int) e.size(); ++i) {
        if(e[i] != 0 && !ok) {
            tmp = e[i];
            ok = true;
        }
        if(distance == c && e[i] != 0) {
            tmp = e[i];
            distance = 0;
        }
        else if(distance < c && e[i] != 0) {
            e[i] = tmp;
            distance = 0;
        }
        if(ok) distance++;
    }
    distance = tmp = 0;
    ok = false;
    for(int i = 0; i < (int) w.size(); ++i) {
        if(w[i] != 0 && !ok) {
            tmp = w[i];
            ok = true;
        }
        if(distance == c && w[i] != 0) {
            tmp = w[i];
            distance = 0;
        }
        else if(distance < c && w[i] != 0) {
            w[i] = tmp;
            distance = 0;
        }
        if(ok) distance++;
    }
    for(int i = 0; i < (int) n.size(); ++i) {
        if(n[i] == 0 && s[i] == 0 && e[i] == 0 && w[i] == 0) {
            continue;
        }
        cout << n[i] << " " << s[i] << " " << e[i] << " " << w[i] << "\n";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    test_case();
    return 0;
}
