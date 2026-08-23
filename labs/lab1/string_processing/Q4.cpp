#include <iostream>
using namespace std;

int myLength(const char s[])
{
    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }
    return len;
}

char *substring(char *s, int ip, int len, char *dest)
{


    int count = 0;
    int i = ip;
    while (count < len)
    {


        dest[count++] = s[i++];
    }
    dest[count] = '\0';

    return dest;
}
int main()
{
    char s[] = "waqar wasif";
    int ip,sub_len;
    char sub[8];
    int main_len = myLength(s);
    while(1){
       cout<<"Enter the starting position of the substring: ";
    cin>>ip;
    if(ip<0 || ip>=main_len){
        cout<<"Enter valid position\n";
        continue;
    } 
    break;
    }
    while(1){
        cout<<"Enter the length of the substring: ";
        cin>>sub_len;
        if(sub_len<0 || sub_len +ip>main_len){
            cout<<"Enter valid length\n";
            continue;
        } 
        break;
        }
    

    char *sub_string = substring(s, ip, sub_len, sub);
    
    cout << sub_string << endl;
}