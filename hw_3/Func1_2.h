//Func1-2.h ����ģ��<T>��ʵ��Student�������I/O����
struct Student
{
	string name;
	int english;
    int math;
    int physics;
    int biology;
    int total;
    //���캯��
    Student()=default;
    Student(string n, int e, int m, int p, int b)
        : name(n), english(e), math(m), physics(p), biology(b), total(e + m + p + b) {}
	
 	bool operator <(const Student &s)const
	{
		return total<s.total;
	}
	bool operator >(const Student &s)const
	{
		return total>s.total;
	}
};
  inline void printStudent(const Student& student) {
    cout << "ѧ������:" << student.name << endl;
    cout << "Ӣ��:" << student.english << endl;
    cout << "��ѧ:" << student.math << endl;
    cout << "����:" << student.physics << endl;
    cout << "����:" << student.biology << endl;
    cout << "�ܷ�:" << student.total << endl;
    }
inline void printName(Student &c)
{
	cout<<c.name;
}
bool equal(Student c1, Student c2)
{
	return c1.name==c2.name;
}
void InputFromFile(ifstream &f,SqList<Student> &students)
{
	string Sname;
    int english,math,physics,biology;

	while (f >> Sname >> english >> math >> physics >> biology) {
        Student student(Sname, english, math, physics, biology);
        students.ListInsert(students.ListLength(), student);
    }
}



