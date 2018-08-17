#include <bits/stdc++.h>

using namespace std;

void removeExtraSpaces(string &line)
{
    auto new_end = unique(line.begin(), line.end(), [](const char& x, const char& y){
        return x == y && x == ' ';
    });
    line.erase(new_end, line.end());

    if(line[line.length() - 1] == ' ')
        line.pop_back();
    if(line[0] == ' ')
        line.erase(0, 1);
}

vector<string> tokenizeInput(string &line)
{
    vector<string> result;

    size_t pos = line.find(' ');
    size_t i = 0;

    while(pos != string::npos)
    {
        string data = line.substr(i, pos-i);
        std::transform(data.begin(), data.end(), data.begin(), ::tolower);
        result.push_back(data);
        i = pos + 1;
        pos = line.find(' ', i);
    }
    string data = line.substr(i, min(pos, line.length()) - i + 1);
    std::transform(data.begin(), data.end(), data.begin(), ::tolower);

    result.push_back(data);
    return result;
}

bool has_only_digits(const string s){
  return s.find_first_not_of( "0123456789" ) == string::npos;
}
int process(vector<string>& tokens)
{
    int result = 0;
    stack<int> st;
    size_t size = tokens.size();
    int i = 0;
    while( i < size )
    {
        if(tokens[i] == "pop")
        {
            cout<<"Pop:"<<st.top()<<endl;
            st.pop();
        }
        else if(tokens[i] == "add" || tokens[i] == "+")
        {
            int no1;
            int no2;
            if(!st.empty())
            {
                no1 = st.top();
                st.pop();
                if(!st.empty())
                {
                    no2 = st.top();
                    st.pop();
                    st.push(no1+no2);
                }
                else
                {
                    result = -1;
                    break;
                }
            }
            else
            {
                result = -1;
                break;
            }   
        }
        else if(tokens[i]== "sub" || tokens[i] == "-")
        {
            int no1;
            int no2;
            if(!st.empty())
            {
                no1 = st.top();
                st.pop();
                if(!st.empty())
                {
                    no2 = st.top();
                    st.pop();
                    cout<<"sub:no2"<<no2<<":no1"<<no1<<endl;
                    st.push(no1-no2);
                }
                else
                {
                    result = -1;
                    break;
                }
            }
            else
            {
                result = -1;
                break;
            }   
        }
        else if(tokens[i]== "dup")
        {
            if(!st.empty())
            {
                st.push(st.top());
            }
            else
            {
                cout<<"Nothing to duplicate, invalid operation.";
                result = -1;
                break;
            }
        }
        else if(has_only_digits(tokens[i]))
        {
            int data = stoi(tokens[i]);
            cout<<"Push:"<<data<<endl;
            st.push(data);
        }
        else
        {
            cout<<"Invalid Operation"<<endl;
            result = -1;
            break;
        }
        i++;
    }
    if(!st.empty() && result != -1)
    {
        result = st.top();
        st.pop();
    }
    return result;
}
int main()
{
    string line;
    cout<<"Enter the STACK operations in a line:";
    getline(cin, line);
    cout<<line<<endl;
    removeExtraSpaces(line);
    cout<<line<<endl;
    vector<string> tokens = tokenizeInput(line);

    for(auto x : tokens)
        cout<<x<<endl;

    int result = process(tokens);
    cout<<"Result:"<<result<<endl;
    return 0;
}
