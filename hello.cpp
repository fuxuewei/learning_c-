#include <iostream>
using namespace std;
void func()
{
    //必须重新声明
    using namespace std;
    cout << "http://c.biancheng.net" << endl;
}
int sum(int n)
{
    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        total += i;
    }
    return total;
}

//内联函数，交换两个数的值
inline void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// *表示指针类型变量
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 类 首字母大写
// 一个类必须有构造函数
class Student
{
    // 成员变量 public 公有的、protected 受保护的、private 私有的：只能修饰类的成员，不能修饰类；C++中的类没有共有私有之分

private: //私有的
    char *m_name;
    int m_age;
    float m_score;

public: //共有的
    //构造函数
    Student();
    Student(char *name, int age, float score);
    char *name;
    int age;
    float score;
    //const成员函数
    int getage() const;
    //成员函数 ，在类体中定义 自动成为内联函数（inline），不推荐
    void say()
    {
        cout << name << "的年龄是" << age << ",成绩是" << score << endl;
    };
    void say1(); //内联函数声明，可以增加 inline 关键字，但编译器会忽略

public:
    friend void show(Student *pstu); //将show()声明为友元函数
};

int Student::getage() const
{
    return m_age;
}
Student::Student()
{
    m_name = NULL;
    m_age = 0;
    m_score = 0.0;
}
Student::Student(char *name, int age, float score)
{
    m_name = name;
    m_age = age;
    m_score = score;
}
//函数定义
inline void Student::say1()
{
    cout << name << "的年龄是" << age << ",成绩是" << score << endl;
};
Student liLei;       //创建单个对象
Student allStu[100]; //创建对象数组  拥有100个元素，每个元素都是 Student 类型的对象

//非成员函数
void show(Student *pstu)
{
    cout << pstu->m_name << "的年龄是 " << pstu->m_age << "，成绩是 " << pstu->m_score << endl;
}
int main()
{

    int a, b;
    bool flag; //定义布尔变量
    cin >> a >> b;
    flag = a > b;
    cout << "flag = " << flag << endl;
    cout << "Input a interge: ";
    int n;
    cin >> n;
    cout << "total:" << sum(n) << endl;

    int m1, n1;
    cin >> m1 >> n1;
    cout << m1 << ", " << n1 << endl;
    swap(&m1, &n1);
    cout << m1 << ", " << n1 << endl;

    //在栈上创建对象
    Student stu;
    stu.name = "小明";
    stu.age = 15;
    stu.score = 92.5f;
    stu.say();

    //在堆上创建对象，分配了内存，但没有名字， 需要使用 new 关键字，使用指针变量来接收指针
    Student *pStu = new Student;
    pStu->name = "可可宝贝";
    pStu->age = 3;
    pStu->score = 100;
    pStu->say();
    delete pStu; //删除对象

    return 0;
}

/**
 * 堆内存：必须手动释放  new
 * 
 * 
 * 
 * **/

/** <iostream>  是 Input Output Stream 的缩写，意思是“输入输出流”
 * cin 标准输入 >>
 * cout 标准输出 <<
 * cerr 标准错误
 * endl 换行  end of line
 * new 用来动态分配内存  int *p = new int[10];  //分配10个int型的内存空间
 * delete 用来释放内存  delete[] p;  //new[] 分配的内存需要用 delete[] 释放，它们是一一对应的
 * 内联函数（Inline Function）：使用内联函数的缺点也是非常明显的
 *      编译后的程序会存在多份相同的函数拷贝
 *      如果被声明为内联函数的函数体非常大，那么编译后的程序体积也将会变得很大
 *      所以再次强调，一般只将那些短小的、频繁调用的函数声明为内联函数。
 *      编译器会忽略函数声明处的 inline
 * 函数的重载（Function Overloading）重载就是在一个作用范围内（同一个类、同一个命名空间等）有多个名称相同但参数不同的函数。重载的结果是让一个函数名拥有了多种用途
 * 
 * 类：只是一个模板（Template）编译后不占用内存空间，故定义类时不能对成员变量进行初始化，创建对象后给成员变量分配内存后，才可以赋值
 * 友元friend：友元函数不同于类的成员函数，在友元函数中不能直接访问类的成员，必须要借助对象
 *      友元的关系是单向的，且关系不能传递
 *      一般不建议吧整个类声明为友元类，而只将某些成员函数声明为友元函数，这样更安全一些
 * 继承 & 派生 ：基类，派生类   由于 private 和 protected 继承方式会改变基类成员在派生类中的访问权限，导致继承关系复杂，所以实际开发中我们一般使用 public。
 * 
 * **/