#include<iostream>
using namespace std;

int myLength(const char s[]){
    int len = 0;
    while(s[len]!='\0'){
        len++;

    }
    return len;
}

char* substring(char* s,int ip,int len,char*dest){
    
    cout << "pass\n";

    int count =0;
    int i = ip;
    while(count<len)
    {
        cout << "pass\n";

        dest[count++]=s[i++];
    }
    dest[count]='\0';
    cout<<"pass\n";
    return dest;

}
int main(){
    char s[] = "waqar wasif";
    char sub[8];
    cout << "pass\n";
    char* sub_string = substring(s,0,7,sub);
    cout << "pass\n";
    cout<<sub_string<<endl;
    
}