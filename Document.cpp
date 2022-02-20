//
// Created by Фёдор Захаров on 20.02.2022.
//

#include "Document.hpp"

template<typename BidIter1, typename BidIter2>
bool operator != (my_std::reverse_iterator<BidIter1>& r_iter_1, my_std::reverse_iterator<BidIter2>& r_iter_2){
    return (r_iter_1.m_it != r_iter_2.m_it);
}

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

//------------------------------------|Document::iterator|----------------------------------------

class Document::iterator {
public:
    using value_type = char;
    using reference = char&;
    using difference_type = std::size_t;
    using pointer = char*;
    using iterator_category = std::bidirectional_iterator_tag;

    using lines_iterator = std::list<std::string>::iterator;
    using char_iterator = std::string::iterator;

    iterator (lines_iterator line_it, char_iterator char_it, Document *Doc_ptr)
            :m_line_it(line_it), m_char_it(char_it), m_Doc_ptr(Doc_ptr) {}

    char& operator *() {return *m_char_it;}

    iterator& operator ++ ();

    iterator& operator -- ();

    friend bool operator != (Document::iterator iter_1, Document::iterator iter_2);

private:
    lines_iterator m_line_it;
    char_iterator m_char_it;
    Document* m_Doc_ptr;
};

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

//--------------------------------------|Document methods|----------------------------------------

typename Document::iterator Document::begin(){return iterator(m_lines.begin(), m_lines.begin()->begin(), this);}

typename Document::iterator Document::end(){
    auto m_fict_it = --m_lines.end();
    return iterator(m_fict_it, m_fict_it->end(), this);
}

typename Document::reverse_iterator Document::rbegin() {return reverse_iterator(end());}

typename Document::reverse_iterator Document::rend() {return reverse_iterator(begin());}

