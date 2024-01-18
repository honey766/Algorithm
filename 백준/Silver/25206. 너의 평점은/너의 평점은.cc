#include <iostream>
#include <string>
using namespace std;

double gradeNum(string s) {
    if (s == "A+") return 4.5;
    if (s == "A0") return 4;
    if (s == "B+") return 3.5;
    if (s == "B0") return 3;
    if (s == "C+") return 2.5;
    if (s == "C0") return 2;
    if (s == "D+") return 1.5;
    if (s == "D0") return 1;
    if (s == "F") return 0;
    return -1; //include "if s == "P""
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, grade;
    int totalCredit = 0;
    double credit, grade_num, totalGrade = 0;
    for(int i = 0; i < 20; i++){
        cin >> s >> credit >> grade;
        grade_num = gradeNum(grade);
        if (grade_num < 0) continue;
        totalCredit += (int)credit;
        totalGrade += credit * grade_num;
    }
    cout << totalGrade / totalCredit;
}