#ifndef UNITTEST_H_INCLUDED
#define UNITTEST_H_INCLUDED

#include <iostream>
#include <string>
#include <typeinfo>

//���� ������

// -- ����������� ������ -- ������ ����� dotest() --
#define check(cond) dotest(cond, #cond, __FILE__, __LINE__)
// -- ������ - ����� ��������� �� ������ --
// -- ������ ������� dofail() ������� �������� --
#define error(str) dofail(str, __FILE__, __LINE__)

namespace UnitTest {		// -- �������� ������������ ���� -�
using std::cout;
using std::endl;
using std::string;
// -- ������� ����������� �������� ����� --
class Test {
    size_t nPass = 0;            // -- ���������� ���������� ������ --
    size_t nFail = 0;            // -- ���������� ����������� ������ --
    // -- ��� ������������-������������ ��������� �� ���� --
    Test(const Test &)  = delete;
    Test(const Test &&) = delete;
    Test& operator=(const Test &)  = delete;
    Test& operator=(const Test &&) = delete;
    // -- �������� ������ ��� ���� ��  typeid().name() � ����������� g++ ??? --
    string getTypeName(const string &t) const {
        size_t k = 0;
        stoi(t, &k);            // -- ��������� �� ����� - ����� ������ k --
        string s = t.substr(k); // -- �������� ��������� ����� --
        return s;
    }
  public:
    Test(): nPass(0), nFail(0) {} // -- ����������� ����������� --
    virtual void run() = 0;       // -- ������������ � �������-����������� �� ����� --
    void report() const {         // -- ����� ����������� ������������ --
        string name = typeid(*this).name();		// -- ��� ������ --
        cout << "-----\n";
        cout  << "Testing <" << getTypeName(name) << ">\n"
              << "All tests    = " << (nPass + nFail) << ";\n"
              << "Passed tests = " << nPass << ";\n"
              << "Failed tests = " << nFail << ";\n"
              << "-----\n";
    }
    void reset() {
        nPass = nFail = 0;    // ��� ������� ��������� --
    }
    void success() {
        ++nPass;    // -- ������ ���� ���������� �
    }
    void fail()   {
        ++nFail;    // -- ������ ���� ���������� �
    }
  protected:		// -- ����������� ���������� ������
    // -- �������� cond - ��� � ���� �������� --
    void dotest(bool cond, const string &message, const char *filename, long nline) {
        if(cond) ++nPass;         // -- ���� ������ --
        else {                    // -- ���� �� ������ --
            ++nFail;
            dofail(message, filename, nline);	// -- �������, ���� � ������ �����
        }
    }
    // -- ����� ����������� ����� --
    void dofail(const string &message, const char *filename, long nline) {
        // -- �������� ��� ����� �� ������� ����� filename --
        auto f = [](const string &name)-> string {
            auto idx = name.rfind("\\");
            return name.substr(idx + 1);
        };
        string name = typeid(*this).name();
        cout  << "<" << getTypeName(name) << ">\n"
              << "Failure: (" << message << ") \n"
              << "File: " << f(string(filename)) << "; line = " << nline
              << endl;
    }
};
}   // -- end namespace --
#endif // UNITTEST_H_INCLUDED
