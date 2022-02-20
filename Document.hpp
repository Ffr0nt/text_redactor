//
// Created by Фёдор Захаров on 20.02.2022.
//

#ifndef TEXT_REDACTOR_DOCUMENT_HPP
#define TEXT_REDACTOR_DOCUMENT_HPP

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
        friend bool operator != (reverse_iterator<BidIter1>& r_iter_1, reverse_iterator<BidIter2>& r_iter_2);

    private:
        BidIter m_it;
    };
}//end of my_std


    class Document {
    public:
        class iterator;

        using reverse_iterator = my_std::reverse_iterator<iterator>;

        Document() { m_lines.push_back(std::string()); }

        friend std::ostream &operator<<(std::ostream &out, const Document &doc);

        friend std::istream &operator>>(std::istream &in, Document &doc);

        iterator begin();

        iterator end();

        reverse_iterator rbegin();

        reverse_iterator rend();



    private:
        std::list<std::string> m_lines;
    };

#endif //TEXT_REDACTOR_DOCUMENT_HPP
