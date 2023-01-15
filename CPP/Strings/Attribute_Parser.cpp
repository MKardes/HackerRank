#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct t_html{
    string          _name;
    struct t_html   *_inside;
    struct t_html   *_next;
    int             _lst_idx;
    int             _fst_idx;
} html;

typedef struct t_link{
    string          _name;
    string          _word;
    struct t_link   *_next;
} link;

int get_close(html **ptr, int x, int i, string *lines);

html *create_html(string name, int i)
{
    html *ptr = new html;

    ptr->_name = name;
    ptr->_inside = NULL;
    ptr->_next = NULL;
    ptr->_fst_idx = i;
    ptr->_lst_idx = 0;
    
    return ptr; 
}

int get_next(html **ptr, int x, int i, string *lines)
{
    html *inside;
    html *next;
    get_close(&inside, x, i, lines);
    if (inside->_lst_idx + 1 != x)
    {
        get_next(&next, x, inside->_lst_idx + 1, lines);
        inside->_next = next;
    }
    (*ptr) = inside;
    return 0;
}

int get_close(html **ptr, int x, int i, string *lines)
{
    html *inside;
    html *next;
    int a = i + 1;
    int pos = lines[i].find(" ");
    if (pos == -1)
        pos = lines[i].find(">");
    string sub = lines[i].substr(1, pos - 1);
    *ptr = create_html(sub, i);
    while (a < x)
    {
        if (lines[a].substr(2, pos - 1) == sub)
        {
            (*ptr)->_lst_idx = a;
            /*if (i + 2 == x)
                break;*/
            if (a != i + 1)
            {
                get_close(&inside, a, i + 1, lines);
                if (inside->_lst_idx + 1 != a)
                {
                    get_next(&next, a, inside->_lst_idx + 1, lines);
                    inside->_next = next;
                }
                (*ptr)->_inside = inside;
                break;
            }
        }
        a++;
    }
    return a;
}

link * add_link(string name)
{
    link *ptr = new link;
    ptr->_name = name;
    ptr->_next = NULL;
    ptr->_word = ""; 
    return ptr;
}

void add_back(link **root, link *node)
{
    link *tmp = (*root);
    if (!node)
        return;
    if (!(*root))
    {
        *root = node;
        return;
    }
    while(tmp->_next)
    {
        tmp = tmp->_next;
    }
    tmp->_next = node;
}

link *link_create(string line)
{
    link *root = NULL;
    link *node = NULL;
    root = node;
    string tmp;
    int pos = line.find(".");
    while(pos != -1)
    {
        node = add_link(line.substr(0,pos));
        add_back(&root, node); 
        tmp = line.substr(pos + 1);
        pos = tmp.find(".");
        line = tmp;
    }
    pos = tmp.find("~");
    node = add_link(line.substr(0,pos));
    add_back(&root, node);
    tmp = line.substr(pos + 1);
    node->_word = tmp;
    return root;
}

int print_it(string line, string _word)
{
    int pos;
    //cout <<"L: [" << line << "] W: [" << word << "]  " ;
    string word = " ";
    word.append(_word);
    pos = line.find(word);
    if (pos != -1)
    {
        pos = line.find(word);
        line = line.substr(pos + word.length() + 4);
        pos = line.find("\"");
        cout << line.substr(0,pos) << endl;
        return 0;
    }
    return -1;
}

void find_one(string var, string word, html *root, string *lines)
{
    int pos;
    string line;
    while (root)
    {
        if (var == root->_name)
        {
            if (print_it(lines[root->_fst_idx], word) == 0)
                return ;
        }
        root = root ->_next;
    }
    cout << "Not Found!" << endl;
}

void    find_it(link *ptr, html *root, string *lines)
{
    while(ptr)
    {
        if (!root)
            break;
        if (root->_name == ptr->_name)
        {
            if (ptr->_word.empty() != true)
            { 
                if (print_it(lines[root->_fst_idx], ptr->_word) == 0)
                return ;
            }
            root = root ->_inside;
            ptr = ptr->_next;
            continue;
        }
        root = root->_next;
    }
    cout << "Not Found!" << endl;
}

int main() {
    int x;
    int y;
    cin >> x;
    cin >> y;
    string *lines = new string[x];
    getline(cin, lines[0]);
    int i = 0;
    while(i < x)
    {
        getline(cin, lines[i]);
        i++;
    }
    html *node;
    html *next;
    html *root;
    i = 0;
    i = get_close(&node, x, i, lines);
    if (node->_lst_idx + 1 != x)
    {
        get_next(&next, x, node->_lst_idx + 1, lines);
        node->_next = next;
    }
    root = node;
    
    
    /*while (root)
    {
        cout << "in " << root->_name << endl; 
        root = root->_inside;
    }
    cout << root->_name << endl;
        cout << "   " << root->_inside->_name << endl;
            cout << "      " << root->_inside->_inside->_name << endl;
            cout << "      " << root->_inside->_inside->_next->_name << endl;
        cout << "   " << root->_inside->_next->_name << endl;
            cout << "      " << root->_inside->_next->_inside->_name << endl;
            cout << "      " << root->_inside->_next->_inside->_next->_name << endl;
123
43.4
hello
Not Found!
Hello
Universe!
World!
New
Not Found!
Not Found!
34
9.845
Not Found!
Not Found!
    
    */
    // Okey !!!!!!!!!!
    
    i = 0;
    link *ptr;
    string line;
    string var;
    int pos;
    int pos1;
    int spc;
    while(i < y)
    {
        getline(cin, line);
        pos = line.find(".");
        if (pos == -1)
        {
            pos1 = line.find("~");
            if (pos1 == -1)
            {
                cout << "Not Found!" << endl;
            }
            else
            {
                var = line.substr(0,pos1);
                line = line.substr(pos1 + 1);
                spc = line.find(" ");
                find_one(var, line.substr(0,spc), root, lines);
            }
        }
        else
        {
            ptr = link_create(line);
            find_it(ptr,root,lines);
        }
        i++;
    }
    return 0;
}
