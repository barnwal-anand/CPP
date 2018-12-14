// Discards/clear the input buffer.
cin.sync();

cout << endl  : Inserts a new line and flushes the stream
cout << "\n"  : Only inserts a new line.

// Input: "blablabla 25"
// Output: Value read : 25
scanf("%*s %d", &a);
printf("Input value read : a=%d",a);

// A Method that returns multiple values using tuple in C++.
tuple<int, int, char> foo(int n1, int n2)
{
    // Packing values to return a tuple
    return make_tuple(n2, n1, 'a');
}
int main()
{
    int a,b;
    char cc;
    // Unpack the elements returned by foo
    tie(a, b, cc) = foo(5, 10);
}

Parsing of string:
------------------
In C:
char str[] = "Geeks for Geeks";
char *token;
char *rest = str;

while ((token = strtok_r(rest, " ", &rest)))
    printf("%s\n", token);

In C++:
string line = "GeeksForGeeks is a must try";
vector <string> tokens;
stringstream check1(line);
string word;
// Tokenizing w.r.t. space ' '
while(getline(check1, word, ' '))
{
    tokens.push_back(word);
}

or
while (check1 >> word)
    tokens.push_back(word);
