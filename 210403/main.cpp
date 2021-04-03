/*
사용자가 입력한 text를 통해서 이전에 입력된 단어를 추천하는 문제

구현 functions

void init()
TC 시작 전에 호출되면, 초기화한다.

void inputWord(const char mInput[20])
사용자가 단어를 사용. 해당 function을 통해서 추천할 수 있는 근거 생성

int recommand(const char mUser[20])
사용자가 글자를 입력했을 때 추천 단어의 길이를 return 한다.
만약에 입력된 글자를 포함하는 단어가 복수 일 경우 아래의 우선순위를 가진다.
1. 더 많이 호출된 단어 우선
2. 호출된 회수가 동일할 경우 최신 우선

void banWord(const char mUser[20])
사용자가 특정 단어에 대해서 Ban 한다.

제한

단어의 개수는 25,000개
모든 function의 호출 수는 100,000
입력되는 글자는 소문자 영어만 사용한다
입력되는 글자수는 NULL 포함하여 20개 이하
*/

#include<iostream>

using namespace std;

extern void init();
extern void inputWord(const char mInput[20]);
extern int recommand(const char mUser[20]);
extern void banWord(const char mUser[20]);

int main(){

    cout<<"Hello World"<<endl;
    return 0;
} 


void test1(){

}
