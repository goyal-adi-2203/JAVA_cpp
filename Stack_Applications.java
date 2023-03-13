import java.util.*;
import java.lang.*;
import java.io.*;

public class Stack_Applications {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        System.out.println("number of testcases:");
        int t = sc.nextInt();
        while (t-- > 0) {
            Solution s = new Solution();

            // CHECKING IF THE EXPRESSION HAS BALANCED PARANTHESES OR NOT
            System.out.println("Expression to check for balanced parantheses or not :");
            String str = sc.next();
            if (s.ispar(str) == true)
                System.out.println("balanced");
            else
                System.out.println("not balanced");

            // INFIX TO POSTFIX CONVERSION
            System.out.println("Infix expression to convert in postfix :");
            str = sc.next();
            System.out.println(s.infixToPostfix(str));

            // EVALUATION OF POSTFIX EXPRESSION
            System.out.println("Expression to evaluate :");
            str = sc.next();
            System.out.println(s.evaluatePostFix(str));
        }
    }
}

class Solution {

    // EVALUATION OF POSTFIX EXPRESSION
    public static int evaluatePostFix(String S) {

        Stack<Integer> s = new Stack<>();

        int n = S.length();

        for (int i = 0; i < n; i++) {
            char ch = S.charAt(i);

            // if operand then push onto stack
            if (Character.isDigit(ch)) {
                s.push(ch - '0');
            }

            // if operaor is encountered
            else {
                int num1 = s.pop();
                int num2 = s.pop();

                switch (ch) {
                    case '+':
                        s.push(num2 + num1);
                        break;
                    case '-':
                        s.push(num2 - num1);
                        break;
                    case '*':
                        s.push(num2 * num1);
                        break;
                    case '/':
                        s.push(num2 / num1);
                        break;

                    default:
                        break;
                }
            }
        }

        return s.pop();
    }

    // INFIX TO POSTFIX CONVERSION
    // function to assign precedence
    public int Prec(char ch) {
        switch (ch) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            case '^':
                return 3;
        }
        return -1;
    }

    // Function to convert an infix expression to a postfix expression.
    public String infixToPostfix(String exp) {
        int n = exp.length();
        String res = "";
        Stack<Character> s = new Stack<>();
        for (int i = 0; i < n; i++) {
            char ch = exp.charAt(i);
            // append in result if letter or digit
            if (Character.isLetterOrDigit(ch)) {
                res += ch;
            }
            // if opening parantheses push onto stack
            else if (ch == '(') {
                s.push(ch);
            }
            // if closing parantheses output untill '(' is encountered
            else if (ch == ')') {
                while (!s.empty() && s.peek() != '(') {
                    res += s.peek();
                    s.pop();
                }
                s.pop();
            }
            // if operand is encountered
            else {
                while (!s.empty() && Prec(ch) <= Prec(s.peek())) {
                    res += s.peek();
                    s.pop();
                }
                s.push(ch);
            }
        }
        while (!s.empty()) {
            if (s.peek() == '(') {
                return "Invalid";
            }

            res += s.peek();
            s.pop();
        }
        return res;
    }

    // CHECKING IF THE EXPRESSION HAS BALANCED PARANTHESES OR NOT
    public boolean ispar(String x) {
        Stack<Character> s = new Stack<>();

        for (int i = 0; i < x.length(); i++) {
            char ch = x.charAt(i);

            // System.out.println(ch);
            if ((ch == '(') || (ch == '{') || (ch == '[')) {
                s.push(ch);
                continue;
            } else {
                if (s.empty()) {
                    return false;
                }
                char temp = s.pop();
                switch (ch) {
                    case ')':
                        if (temp != '(')
                            return false;
                        break;
                    case ']':
                        if (temp != '[')
                            return false;
                        break;
                    case '}':
                        if (temp != '{')
                            return false;
                        break;

                    default:
                        break;
                }
            }
        }
        return s.empty();
    }
}