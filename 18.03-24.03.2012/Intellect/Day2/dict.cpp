#include <iostream>
#include <cstdio>
#include <list>
#include <string>

using namespace std;

list<string> dict;
int cur;

inline int is_denied(char ch)
{
    if( (ch >= '0' && ch <= '9' ) || (ch == '_') )
        return 1;
    else
        return 0;
}

inline int is_term(char ch)
{
    if( (ch >= 'a' && ch <= 'z') ||
        is_denied(ch) )
        return 1;
    else
        return 0;
}

inline int check_cand(string s)
{
    for(string::iterator it = s.begin(); it != s.end(); it++)
    {
        if(is_denied(*it)) return 0;
    }
    return 1;
}

int main()
{
    int ch, len, count = 1;
    list<string>::iterator next;
    string candidate;
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    while(!feof(stdin))
    {
        ch = tolower(fgetc(stdin));
        if(is_term(ch))
        {
            candidate += ch;
        } else {
            if(!candidate.empty() && check_cand(candidate))
            {
                dict.push_back(candidate);
            }
            candidate.clear();
        }
    }
    dict.sort();
    len = dict.size();
    dict.push_back(string(""));
    for(list<string>::iterator it = dict.begin(); it != dict.end(); it++)
    {
        if(it->empty()) break;
        next = it;
        next++;
        if(*next == *it)
        {
            count++;
        } else {
            if(count == 1)
                printf("%s\n", it->c_str());
            else
                printf("%s %d\n", it->c_str(), count);
            count = 1;
        }
    }
    return 0;
}
