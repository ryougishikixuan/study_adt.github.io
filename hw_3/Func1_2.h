//Func1-2.h 定义模板<T>的实参Student及对其的I/O操作
struct Student
{
	string name;
	int english;
    int math;
    int physics;
    int biology;
    int total;
    //构造函数
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
    cout << "学生姓名:" << student.name << endl;
    cout << "英语:" << student.english << endl;
    cout << "数学:" << student.math << endl;
    cout << "物理:" << student.physics << endl;
    cout << "生物:" << student.biology << endl;
    cout << "总分:" << student.total << endl;
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



