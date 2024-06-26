// main.cpp
// 중간고사, 기말고사, 그리고 과제 점수 몇개를 받고
// 마지막 평균 결과 점수를 계산하기.
#include <algorithm>
#include <fstream> // file 사용
#include <ios>
#include <iomanip>
#include <iostream> // cin, cout 사용
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using namespace std;

int main()
{
    // 파일스트림 만들고 "txt" 파일을 읽기
    ifstream student_file("grades.txt");
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    //학생 이름과 모든 점수를 읽어 저장하고 가장 긴 이름을 찾음.
    while (read(student_file, record)) { // cin 을 사용하면 직접 사용자 입력만 받을 수 있다. student_file은 ifstream이어서 파일 입력 가능
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // 학생 정보를 알파벳 순으로 정렬
    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        // 이름과 오른족 공백을 포함하여 maxlen + 1개의 문자를 출력
        cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

        // 종합 점수를 계산해 생성
        try {
            double final_grade = grade(students[i]);
            // 결과를 출력
            streamsize prec = cout.precision(); // 지금 cout precision
            cout << "Final grade: " << setprecision(3)
                << final_grade << setprecision(prec) << endl;
        }
        catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }
    return 0;
} // main 끝