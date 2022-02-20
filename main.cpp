#include <iostream>
#include <sstream>
#include "Document.cpp"

int main() {
    Document doc;
    std::cout << "> " << doc << std::endl; // Пустой документ т.е. ничего не выведет
    std::istringstream str(\
"Hello World!\
This is my great document!\n \
You are welcome!");
    str >> doc;
    std::cout << "> " << doc; // Выведет заполненный документ (с переходами на новые строки)
    std::cout << "> ";
    for (char ch : doc)
        std::cout << ch; // Выведет документ побуквенно (без переходов на новые строки)
    std::cout << std::endl;
    std::cout << "> ";
    for (auto r_it = doc.rbegin(); r_it != doc.rend(); ++r_it)
        std::cout << *r_it; // Выведет документ побуквенно задом на перёд
    std::cout << std::endl;
    doc.erase_line(1);
    std::cout << "> " << doc; // Выведет документ, у которого удалена первая строка)
    auto it = doc.find(doc.begin(), doc.end(), "!You");
    std::cout << "> ";
    for (; it != doc.end(); ++it)
        std::cout << *it; // Побуквенно выводит документ, начиная с "!You"
    std::cout << std::endl;
    it = doc.find(doc.begin(), doc.end(), "YOU");
    std::cout << "> " << std::boolalpha << (it == doc.end()) << std::endl;
// => true т.к. it совпадает с концом т.к. find ничего не нашёл
    system("pause");
    return 0;
}
