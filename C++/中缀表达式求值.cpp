#include <bits/stdc++.h>
using namespace std;
using ld = long double;

// 判断是否是运算符或函数名
bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/" || s == "^";
}

// 判断是否是函数
bool isFunction(const string& s) {
    return s == "sqrt" || s == "pow" || s == "abs" ||
    s == "sin" || s == "cos" || s == "tan";
}

// 获取操作符的优先级
int precedence(const string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    if (op == "^") return 3;
    return 0;
}

// 处理函数和操作符优先级，支持负数
vector<string> tokenize(const string& expr) {
    vector<string> tokens;
    string num = "", func = "";
    for (size_t i = 0; i < expr.size(); ++i) {
        char c = expr[i];
        if (isspace(c)) continue;

        if (isdigit(c) || c == '.') {
            num += c;
        } else {
            if (!num.empty()) {
                tokens.push_back(num);
                num.clear();
            }

            if (isalpha(c)) {
                func += c;
                while (i + 1 < expr.size() && isalpha(expr[i + 1]))
                    func += expr[++i];
                tokens.push_back(func);
                func.clear();
            } else if (c == '-' && (tokens.empty() || tokens.back() == "(" || isOperator(tokens.back()))) {
                // 处理负数标记
                num += c;
            } else if (c == '(' || c == ')' || c == ',' || isOperator(string(1, c))) {
                tokens.emplace_back(1, c);
            } else {
                throw runtime_error(string("非法字符: ") + c);
            }
        }
    }
    if (!num.empty()) tokens.push_back(num);
    return tokens;
}

// 中缀转后缀表达式
vector<string> toPostfix(const vector<string>& tokens) {
    vector<string> output;
    stack<string> opStack;

    for (const string& token : tokens) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1 && isdigit(token[1]))) {
            output.push_back(token);
        } else if (isFunction(token)) {
            opStack.push(token);
        } else if (token == ",") {
            while (!opStack.empty() && opStack.top() != "(") {
                output.push_back(opStack.top());
                opStack.pop();
            }
        } else if (isOperator(token)) {
            while (!opStack.empty() &&
                ((isOperator(opStack.top()) && precedence(opStack.top()) >= precedence(token)) ||
                    isFunction(opStack.top()))) {
                output.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(token);
        } else if (token == "(") {
            opStack.push(token);
        } else if (token == ")") {
            while (!opStack.empty() && opStack.top() != "(") {
                output.push_back(opStack.top());
                opStack.pop();
            }
            if (opStack.empty()) throw runtime_error("括号不匹配");
            opStack.pop();
            if (!opStack.empty() && isFunction(opStack.top())) {
                output.push_back(opStack.top());
                opStack.pop();
            }
        }
    }

    while (!opStack.empty()) {
        if (opStack.top() == "(" || opStack.top() == ")") throw runtime_error("括号不匹配");
        output.push_back(opStack.top());
        opStack.pop();
    }

    return output;
}

// 计算函数/操作符
ld applyOp(const string& op, ld a, ld b = 0) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) throw runtime_error("除以零");
        return a / b;
    }
    if (op == "^") return pow(a, b);
    if (op == "pow") return pow(a, b);
    throw runtime_error("未知操作符: " + op);
}

ld applyFunc(const string& func, ld x) {
    if (func == "sqrt") return sqrt(x);
    if (func == "abs") return abs(x);
    if (func == "sin") return sin(x * M_PI / 180.0);
    if (func == "cos") return cos(x * M_PI / 180.0);
    if (func == "tan") return tan(x * M_PI / 180.0);
    throw runtime_error("未知函数: " + func);
}

// 后缀表达式求值
ld evalPostfix(const vector<string>& postfix) {
    stack<ld> stk;
    for (const string& token : postfix) {
        if (isOperator(token)) {
            if (stk.size() < 2) throw runtime_error("表达式不完整");
            ld b = stk.top(); stk.pop();
            ld a = stk.top(); stk.pop();
            stk.push(applyOp(token, a, b));
        } else if (isFunction(token)) {
            if (token == "pow") {
                if (stk.size() < 2) throw runtime_error("pow 参数不足");
                ld b = stk.top(); stk.pop();
                ld a = stk.top(); stk.pop();
                stk.push(pow(a, b));
            } else {
                if (stk.empty()) throw runtime_error("函数参数不足");
                ld x = stk.top(); stk.pop();
                stk.push(applyFunc(token, x));
            }
        } else {
            stk.push(stold(token));
        }
    }
    if (stk.size() != 1) throw runtime_error("表达式不完整");
    return stk.top();
}

int main() {
    cout << "请输入表达式（支持负数、小数、sqrt、pow、abs、sin、cos、tan）：\n> ";
    string expr;
    getline(cin, expr);
    try {
        vector<string> tokens = tokenize(expr);
        vector<string> postfix = toPostfix(tokens);
        ld result = evalPostfix(postfix);
        cout << "结果为: " << fixed << setprecision(10) << result << "\n";
    } catch (exception& e) {
        cerr << "错误: " << e.what() << "\n";
    }
    return 0;
}
