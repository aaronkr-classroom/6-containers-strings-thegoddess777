// main.cpp
// �߰����, �⸻���, �׸��� ���� ���� ��� �ް�
// ������ ��� ��� ������ ����ϱ�.
#include <algorithm>
#include <fstream> // file ���
#include <ios>
#include <iomanip>
#include <iostream> // cin, cout ���
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using namespace std;

int main()
{
    // ���Ͻ�Ʈ�� ����� "txt" ������ �б�
    ifstream student_file("grades.txt");
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    //�л� �̸��� ��� ������ �о� �����ϰ� ���� �� �̸��� ã��.
    while (read(student_file, record)) { // cin �� ����ϸ� ���� ����� �Է¸� ���� �� �ִ�. student_file�� ifstream�̾ ���� �Է� ����
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // �л� ������ ���ĺ� ������ ����
    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        // �̸��� ������ ������ �����Ͽ� maxlen + 1���� ���ڸ� ���
        cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

        // ���� ������ ����� ����
        try {
            double final_grade = grade(students[i]);
            // ����� ���
            streamsize prec = cout.precision(); // ���� cout precision
            cout << "Final grade: " << setprecision(3)
                << final_grade << setprecision(prec) << endl;
        }
        catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }
    return 0;
} // main ��