//
// Created by Фёдор Захаров on 20.02.2022.
//

#ifndef TEXT_REDACTOR_DOCUMENT_CPP
#define TEXT_REDACTOR_DOCUMENT_CPP

#include "Document.h"


std::ostream & operator << (std::ostream & out, const Document& doc){
    for(auto it = doc.m_lines.begin(); it != --doc.m_lines.end(); ++it)
        out << *it << std::endl;

    return out;
}

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


bool operator != (Document::iterator iter_1, Document::iterator iter_2){
    return !(iter_1.m_Doc_ptr == iter_2.m_Doc_ptr && iter_1.m_line_it == iter_2.m_line_it && iter_1.m_char_it == iter_2.m_char_it);
}


////--------------------------------------|Document methods|----------------------------------------

typename Document::iterator Document::begin(){return iterator(m_lines.begin(), m_lines.begin()->begin(), this);}

typename Document::iterator Document::end(){
    auto m_fict_it = --m_lines.end();
    return iterator(m_fict_it, m_fict_it->end(), this);
}

typename Document::reverse_iterator Document::rbegin() {return reverse_iterator(end());}

typename Document::reverse_iterator Document::rend() {return reverse_iterator(begin());}


#endif
