#include "Math.hpp"

bool Math::isdigit(char c){
    return c >= '0' && c <= '9';
}

String Math::getdigit(const String& str, int& index){
    String res;
    while(index < str.size() && isdigit(str[index])){
        res += str[index];
        index++;
    }
    index--;
    return res;
}

int Math::priority(char op){
    switch (op)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    default:
        return 0;
        break;
    }
}

int Math::calculate(int left, int right, char op){
    switch (op){
        case '+':
            return left + right;
            break;
        case '-':
            return left - right;
            break;
        case '*':
            return left * right;
            break;
        case '/':
            return left / right;
            break;
        default:
            return 0;
            break;
    }
}


String Math::getsuffix(const String& str){
    Stack<char> s;
    String res;
    for(int i = 0; i < str.size(); i++){
        if(isdigit(str[i])){
           res += getdigit(str, i);
           res += ' ';
        }
        else if(str[i] == '(' || str[i] == ')'){
            if(str[i] == '('){
                s.push(str[i]);
            }else{
                while(!s.empty() && s.top() != '('){
                    res += s.top();
                    s.pop();
                }
                if(s.top() == '('){
                    s.pop();
                }
             }
            }else{
                while(!s.empty() && s.top()!= '(' && priority(s.top()) >= priority(str[i])){
                    res += s.top();
                    s.pop();
                }
                s.push(str[i]);
            }
        }
         while(!s.empty()){
        res += s.top();
        s.pop();
    }
    return res;
 }


int Math::calculate(const String& suffix){
    Stack<int> s;
    int i = 0;
    while(i < suffix.size()){
        if(isdigit(suffix[i])){
            int num = 0;
            while(suffix[i] != ' '){
                num = num * 10 + suffix[i] - '0';
                i++;
            }
            i++;
            s.push(num);
        }else{
            int right = s.top();
            s.pop();
            int left = s.top();
            s.pop();
            s.push(calculate(left, right, suffix[i]));
            i++;
        }
    }
    return s.top();
}