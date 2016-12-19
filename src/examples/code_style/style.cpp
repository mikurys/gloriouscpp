#include <string>
#include <iostream>
#include <thread>

#include <glor/system/utils.hpp>

using namespace glor::system;

namespace glor {

namespace example {

using namespace std;

class c_entity { };

class c_human : public c_entity { } ;

int global_now_time; // but better to not use global

class c_man : public c_human {
    public:
		void foo();
		void bar(int x, int y);

		int m_beer;
		int m_money;
		string m_name;

	public:
		c_man(const string& name);
		c_man(const string& name, int age, int money, int luck);

		void drive_to(int max_speed);
		void print(string str);
};


// use shorter (one-line) or longer syntax (with newline, ident, and ending brace in newline)
// depending on size/complexity of the code

c_man::c_man(const string& name) : m_beer(0), m_name(name) { } // trivial = oneliner

c_man::c_man(const string& name, int age, int money, int luck) :
	m_beer( age + money*luck ),
	m_money(money),
	m_name(name)
{
	cout << "Created human (advanced)" << endl;

	if (age > 18) {
		foo();
		bar(age,luck);
	}

	if (age > 25) { m_money *= 2; } // even for simple one-line one-instruction if-then lines, use braces { }
	if (m_beer > 100) { m_money -= 100; }
}


void c_man::foo() { }

void c_man::bar(int x, int y) {
	int x_new = x;
	int c = x_new + y;
	_info("c = " << c);
}

void test() {
	_mark("Running the test.");
	c_man bob("Bob"), dave("Dave");
	c_man the_other_guy("James");
}

} // namespace
} // namespace


int main() {
	_erro("Test-error");
	return 0;

    _mark("This is mark");
    _info("This is info");
    return 0;

    _warn("This is warn");
    _erro("This is erro\n\n\nerro message continue");
    _fact("This is fact");
    _note("This is note");
    _dbg1("This is dbg1");
    _dbg2("This is dbg2");
    _dbg3("This is dbg3");

    glor::example::c_man jacek("Jacek");

    std::thread t1([&jacek](){jacek.bar(10, 15);});
    std::thread t2([](){_mark("This is mark");});
    std::thread t3([](){_info("This is info");});
    std::thread t4([](){_warn("This is warn");});
    std::thread t5([](){_erro("This is erro "<<"erro part 1 " << "erro part 2 " << "erro part 3 " << "erro part 4 " << "end erro");});
    std::thread t6([](){_fact("This is fact");});
    std::thread t7([](){_note("This is note");});
    std::thread t8([](){_dbg1("This is dbg1");});
    std::thread t9([](){_dbg2("This is dbg2");});
    std::thread t10([](){_dbg3("This is dbg3");});
    t10.join();
    t9.join();
    t8.join();
    t7.join();
    t6.join();
    t5.join();
    t4.join();
    t3.join();
    t1.join();
    t2.join();
	return 0;
}
