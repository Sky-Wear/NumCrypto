#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
std::string padStart(const std::string& str, size_t num, char ch) {
    std::string result = str;
    if (num > str.size()) {
        result.insert(0, num - str.size(), ch);
    }
    return result;
}
string a(string str) {
    int i = std::stoi(str.substr(0, 2));
    int i2 = std::stoi(str.substr(2, 2));
    int i3 = std::stoi(str.substr(4, 2));
    int i4 = std::stoi(str.substr(6, 2));
    int i5 = std::stoi(str.substr(8));

    int i6 = i4 ^ i3;
    int i7 = i5 ^ i3;
    int i8 = i3 ^ (i6 + i7);
    int i9 = i ^ i7;
    int i10 = i2 ^ i7;
    return padStart(std::to_string(i9), 2, '0') +
           padStart(std::to_string(i10), 2, '0') +
           padStart(std::to_string(i6), 2, '0') +
           padStart(std::to_string(i7), 2, '0') +
           padStart(std::to_string(i8), 2, '0');
}
string b(string str) {
     int i = std::stoi(str.substr(0, 2));
    int i2 = std::stoi(str.substr(2, 2));
    int i3 = std::stoi(str.substr(4, 2));
    int i4 = std::stoi(str.substr(6, 2));
    int i5 = std::stoi(str.substr(8));

    int i6 = i5 ^ (i3 + i4);
    int i7 = i4 ^ i6;
    int i8 = i3 ^ i6;
    int i9 = i ^ i6;
    int i10 = i2 ^ i6;
    return padStart(std::to_string(i9), 2, '0') +
           padStart(std::to_string(i10), 2, '0') +
           padStart(std::to_string(i8), 2, '0') +
           padStart(std::to_string(i7), 2, '0') +
           padStart(std::to_string(i6), 2, '0');
}

string c(string str){
    int i = std::stoi(str.substr(0, 2));
    int i2 = std::stoi(str.substr(2, 2));
    int i3 = std::stoi(str.substr(4));

    int i5 = i3 ^ (i + i2);
    int i6 = i ^ i5;
    int i4 = i2 ^ i5;

    return padStart(std::to_string(i6), 2, '0') +
           padStart(std::to_string(i4), 2, '0') +
           padStart(std::to_string(i5), 2, '0');
}

string d(string str){
    int i = std::stoi(str.substr(0, 2));
    int i2 = std::stoi(str.substr(2, 2));
    int i3 = std::stoi(str.substr(4));

    int i5 = i2 ^ i;
    int i6 = i3 ^ i;
    int i4 = i ^ (i5 + i6);

    return padStart(std::to_string(i5), 2, '0') +
           padStart(std::to_string(i6), 2, '0') +
           padStart(std::to_string(i4), 2, '0');
}

void middle(string str,char fill)
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bInfo;
    GetConsoleScreenBufferInfo(hOutput, &bInfo);
    int dwSizeX=bInfo.dwSize.X,dwSizey=bInfo.dwSize.Y;
    int len=str.length();
	int x=dwSizeX/2-len/2;
	for(int i=0;i<x;i++){
		cout<<fill;
	}
	
	cout<<str;
	for(int i=x+len;i<dwSizeX;i++){
		cout<<fill;
	}
	cout<<endl;
}

int main(){
	int mode;
	middle("ENCODE",'=');
	middle("Dev. by cmc",' ') ;
	cout<<"Input Mode:";
	cin>>mode;
	if(mode==1){
		middle("ADB",'=');
		cout<<"Input code:";
		string s;
		cin>>s;
		middle("RESULT",' ') ;
		middle(a(b(s)),' ') ;
	}else{
		middle("SELFTEST",'=');
		cout<<"Input code:";
		string s;
		cin>>s;
		string R1=c(s);
		middle("RESULT",' ') ;
		middle(d(R1),' ') ;
	}
	system("pause");
	return 0;
} 
