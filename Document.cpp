//
// Created by Фёдор Захаров on 20.02.2022.
//

#ifndef TEXT_REDACTOR_DOCUMENT_CPP
#define TEXT_REDACTOR_DOCUMENT_CPP

#include "Document.h"

// вывод строки
std::ostream & operator << (std::ostream & out, const Document& doc){
    for(auto it = doc.m_lines.begin(); it != --doc.m_lines.end(); ++it)
        out << *it << std::endl;

    return out;
}

//ввод строки (создание новой с символами строки)
std::istream & operator >> (std::istream & in, Document& doc){
    std::string str;
    auto doc_iter = --doc.m_lines.end();
    while(std::getline(in, str))
        doc.m_lines.insert(doc_iter, str);


    return in;
}

////------------------------------------|Document::iterator|----------------------------------------

typename Document::iterator& Document::iterator:: operator ++ () {
    ++m_char_it;
    if(m_char_it == m_line_it->end()){
        ++m_line_it;
        m_char_it = m_line_it->begin();
    }
    return *this;
}

typename Document::iterator& Document::iterator:: operator -- () {
    if(m_char_it == m_line_it->begin()){
        --m_line_it;
        m_char_it = m_line_it->end();
    }
    --m_char_it;
    return *this;
}

// != для итераторов (не совпадение ссылки на документ
//или ссылки на строку или букву)
bool operator != (Document::iterator iter_1, Document::iterator iter_2){
    return !(iter_1.m_Doc_ptr == iter_2.m_Doc_ptr && iter_1.m_line_it == iter_2.m_line_it && iter_1.m_char_it == iter_2.m_char_it);
}

bool operator==(Document::iterator iter_1, Document::iterator iter_2) {
    return (iter_1.m_Doc_ptr == iter_2.m_Doc_ptr && iter_1.m_line_it == iter_2.m_line_it && iter_1.m_char_it == iter_2.m_char_it);
}
Document::iterator &Document::iterator::operator+=(const size_t & num) {
    for (int i = 0; i < num; ++i) {++(*this);}
    return *this;
}

Document::iterator &Document::iterator::operator-=(const size_t &num) {
    for (int i = 0; i < num; ++i) {--(*this);}
    return *this;
}

Document::iterator &Document::iterator::erase_line_for_it(const size_t & num, Document& doc) {
    lines_iterator a = m_line_it;
    for (int i = 0; i < num - 1; ++i) {++m_line_it;};//-1 тк отсчёт сточки идёт с первого элемента
    doc.m_lines.erase(m_line_it);
    return *this;
}




////--------------------------------------|Document methods|----------------------------------------

//итератор на начало
typename Document::iterator Document::begin(){return iterator(m_lines.begin(), m_lines.begin()->begin(), this);}

//итератор на конец
typename Document::iterator Document::end(){
    auto m_fict_it = --m_lines.end();
    return iterator(m_fict_it, m_fict_it->end(), this);
}

//обратный итератор на начало
typename Document::reverse_iterator Document::rbegin() {return reverse_iterator(end());}

//обратный итератор на конец
typename Document::reverse_iterator Document::rend() {return reverse_iterator(begin());}

void Document::erase_line(const size_t & num) {
    Document::iterator it = this->begin();

    it.erase_line_for_it(num, *this);

    return ;
}

Document::iterator &Document::find(const Document::iterator &iter_1, const Document::iterator &iter_2,std::string str) {
    using char_iterator = std::string::iterator;

    auto it = iter_1;
    char_iterator char_it = str.begin();

    int count = 0;
    for (;it != iter_2; ++it) {

        if (*it == *char_it){
            ++count;
            ++char_it;
        }
        else {
            if ((count > 0) && (it.m_char_it.operator->() != char_it.operator->())) {
                count = 0;
                char_it = str.begin();
            }
        }

        if (count == str.length()){
            it -= count-1;
            return it;
        }
    }
    return it;
}

#endif
