//
// Created by Фёдор Захаров on 20.02.2022.
//

#ifndef TEXT_REDACTOR_DOCUMENT_H
#define TEXT_REDACTOR_DOCUMENT_H

#pragma once

#include <sstream>
#include <list>
#include <string>

namespace my_std{
    template <typename BidIter>
    class reverse_iterator{
    public:
        reverse_iterator(BidIter it): m_it(it) {}
        reverse_iterator& operator ++ () {
            --m_it;
            return *this;
        }
        reverse_iterator& operator -- () {
            ++m_it;
            return *this;
        }
        typename BidIter::reference operator * () {
            auto tmp_iter = m_it;
            return *(--tmp_iter);
        }
        template<typename BidIter1, typename BidIter2>
        friend bool operator != (reverse_iterator<BidIter1> r_iter_1, reverse_iterator<BidIter2> r_iter_2);
    private:
        BidIter m_it;
    };

    template<typename BidIter1, typename BidIter2>
    bool operator != (reverse_iterator<BidIter1> r_iter_1, reverse_iterator<BidIter2> r_iter_2){
        return (r_iter_1.m_it != r_iter_2.m_it);
    }
}//end of my_std

class Document {
public:
    class iterator;

    using reverse_iterator = my_std::reverse_iterator<iterator>;

    Document(){m_lines.push_back(std::string());}

    friend std::ostream & operator << (std::ostream & out, const Document& doc);

    friend std::istream & operator >> (std::istream & in, Document& doc);

    iterator begin();

    iterator end();

    reverse_iterator rbegin();

    reverse_iterator rend();
private:
    std::list<std::string> m_lines;
};

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

#endif //TEXT_REDACTOR_DOCUMENT_H
