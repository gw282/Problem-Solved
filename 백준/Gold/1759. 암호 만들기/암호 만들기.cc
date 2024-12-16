//=====================================================================
//   1759번:    암호 만들기                   
//   @date:   2024-12-16              
//   @link:   https://www.acmicpc.net/problem/1759  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int l,c;
int arr[16];  // 선택된 문자의 인덱스를 저장할 배열
char s[16];   // 입력된 문자들을 저장할 배열

bool isVowel(char t) {
  return t=='a' || t=='e' || t=='i' || t=='o' || t=='u';
}

void func(int count, int st) {
  if(count==l){
    bool flag = false;
    int vo = 0, co = 0;
    for(int i=0;i<l;i++){
      if(isVowel(s[arr[i]])) vo++;
      else co++;
    }

    if(vo>=1 && co>=2) flag = true;

    if(flag){
      for(int i=0;i<l;i++) {
        cout << s[arr[i]]; // 선택된 문자 출력
      }
      cout << "\n";
    }
  }

  for(int i=st;i<c;i++){
      arr[count] = i; // 선택된 문자의 인덱스를 기록
      func(count+1, i+1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> l >> c;

  for(int i=0;i<c;i++) {
    cin >> s[i];
  }
  sort(s,s+c);

  func(0,0);
  
  return 0;
}
