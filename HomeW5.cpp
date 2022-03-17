

#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <set>


template<typename IT>
void printWords(IT start, IT end)
{
    std::unordered_set<std::string> countWords(start, end);
    std::copy(countWords.begin(), countWords.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");


    std::vector<std::string> v{ "моя", " геройская ", "академия", "академия" };
    std::cout << "Вектор:";
    printWords(v.begin(), v.end());

    std::list<std::string> l(v.begin(), v.end());
    std::cout << "Список:";
    printWords(l.begin(), l.end());

    std::deque<std::string> d(v.begin(), v.end());
    std::cout << "Дек:";
    printWords(d.begin(), d.end());

    //==========================================================================================

    const auto stringCompare = [](const std::string& first, const std::string& second) {
        return first.size() < second.size();
    };

    std::set<std::string, decltype(stringCompare)> sentences(stringCompare);
    std::string sentence("not empty");


    while (std::getline(std::cin, sentence) && !sentence.empty())
    {
        typename std::string::size_type pos_start{}, pos_end{};
        while (pos_start != sentence.npos && pos_end != sentence.npos)
        {
            pos_end = sentence.find_first_of(".!?", pos_start);
            sentences.insert(sentence.substr(pos_start, pos_end - pos_start));
            pos_start = sentence.find_first_not_of(" .!?", pos_end);
        }
    }

    sentences.erase(std::string());

    for (auto& sent : sentences) {
        std::cout << sent << std::endl;
    }

    return 0;
}


