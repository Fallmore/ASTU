#ifndef UNITTEST_H_INCLUDED
#define UNITTEST_H_INCLUDED

#include <iostream>
#include <string>
#include <typeinfo>

//Áðþñ Ýêêåëü

// -- ïðîâåðÿþùèé ìàêðîñ -- ñìîòðè ìåòîä dotest() --
#define check(cond) dotest(cond, #cond, __FILE__, __LINE__)
// -- ìàêðîñ - âûâîä ñîîáùåíèÿ îá îøèáêå --
// -- èìåííî ïîýòîìó dofail() ñäåëàíà îòäåëüíî --
#define error(str) dofail(str, __FILE__, __LINE__)

namespace UnitTest {		// -- òåñòîâîå ïðîñòðàíñòâî èìåí -–
using std::cout;
using std::endl;
using std::string;
// -- áàçîâûé àáñòðàêòíûé òåñòîâûé êëàññ --
class Test {
    size_t nPass = 0;            // -- êîëè÷åñòâî ïðîéäåííûõ òåñòîâ --
    size_t nFail = 0;            // -- êîëè÷åñòâî ïðîâàëåííûõ òåñòîâ --
    // -- ýòè êîíñòðóêòîðû-ïðèñâàèâàíèÿ ñîçäàâàòü íå íàäî --
    Test(const Test &)  = delete;
    Test(const Test &&) = delete;
    Test& operator=(const Test &)  = delete;
    Test& operator=(const Test &&) = delete;
    // -- âûðåçàåì ÷èñòîå èìÿ òèïà èç  typeid().name() – îñîáåííîñòü g++ ??? --
    string getTypeName(const string &t) const {
        size_t k = 0;
        stoi(t, &k);            // -- ðåçóëüòàò íå íóæåí - íóæåí èíäåêñ k --
        string s = t.substr(k); // -- îòðåçàåì íà÷àëüíóþ äëèíó --
        return s;
    }
  public:
    Test(): nPass(0), nFail(0) {} // -- òðèâèàëüíûé êîíñòðóêòîð --
    virtual void run() = 0;       // -- îïðåäåëÿåòñÿ â êëàññàõ-íàñëåäíèêàõ îò òåñòà --
    void report() const {         // -- âûâîä ðåçóëüòàòîâ òåñòèðîâàíèÿ --
        string name = typeid(*this).name();		// -- èìÿ êëàññà --
        cout << "-----\n";
        cout  << "Testing <" << getTypeName(name) << ">\n"
              << "All tests    = " << (nPass + nFail) << ";\n"
              << "Passed tests = " << nPass << ";\n"
              << "Failed tests = " << nFail << ";\n"
              << "-----\n";
    }
    void reset() {
        nPass = nFail = 0;    // äëÿ áóäóùèõ ðàñèðåíèé --
    }
    void success() {
        ++nPass;    // -- òîëüêî ðàäè èñêëþ÷åíèé –
    }
    void fail()   {
        ++nFail;    // -- òîëüêî ðàäè èñêëþ÷åíèé –
    }
  protected:		// -- íàñëåäóåìûå çàùèùåííûå ìåòîäû
    // -- ïàðàìåòð cond - ýòî è åñòü ïðîâåðêà --
    void dotest(bool cond, const string &message, const char *filename, long nline) {
        if(cond) ++nPass;         // -- òåñò ïðîøåë --
        else {                    // -- òåñò ÍÅ ïðîøåë --
            ++nFail;
            dofail(message, filename, nline);	// -- óñëîâèå, ôàéë è ñòðîêà ôàéëà
        }
    }
    // -- âûâîä ïðîâàëüíîãî òåñòà --
    void dofail(const string &message, const char *filename, long nline) {
        // -- âûðåçàåì èìÿ ôàéëà èç ïîëíîãî èìåíè filename --
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
