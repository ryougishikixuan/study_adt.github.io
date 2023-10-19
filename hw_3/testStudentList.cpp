// #include "C.h"
// #include "SqList.h"
// #include "Func1_2.h"
// int main(){
//     SqList<Student> students;
//     //读取文件
//     ifstream testFile("test.txt");
   
//    InputFromFile(testFile,students);
//     testFile.close();
//     //输出所有学生信息
//     for (int i = 0; i < students.ListLength(); i++) {
//         Student student;
//         students.GetElem(i, student);
//         printStudent(student);
//     }
//     //查找学生
//     string sName;
//     cout << "请输入要查找的学生姓名: ";
//     cin >> sName;
//     int index = students.LocateElem(Student(sName, 0, 0, 0, 0),
//     equal);
//     if (index != -1) {
//         Student findStudent;
//         students.GetElem(index, findStudent);
//         cout << "找到了学生的信息：" << endl;
//         printStudent(findStudent);
//     } else {
//         cout << "没有找到学生的信息" << endl;
//     }



//     return 0;
// }