// #include "C.h"
// #include "SqList.h"
// #include "Func1_2.h"
// int main(){
//     SqList<Student> students;
//     //��ȡ�ļ�
//     ifstream testFile("test.txt");
   
//    InputFromFile(testFile,students);
//     testFile.close();
//     //�������ѧ����Ϣ
//     for (int i = 0; i < students.ListLength(); i++) {
//         Student student;
//         students.GetElem(i, student);
//         printStudent(student);
//     }
//     //����ѧ��
//     string sName;
//     cout << "������Ҫ���ҵ�ѧ������: ";
//     cin >> sName;
//     int index = students.LocateElem(Student(sName, 0, 0, 0, 0),
//     equal);
//     if (index != -1) {
//         Student findStudent;
//         students.GetElem(index, findStudent);
//         cout << "�ҵ���ѧ������Ϣ��" << endl;
//         printStudent(findStudent);
//     } else {
//         cout << "û���ҵ�ѧ������Ϣ" << endl;
//     }



//     return 0;
// }