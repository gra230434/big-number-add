//
//  main.cpp
//  intnumber
//
//  Created by WeiKevin on 2015/11/20.
//  Copyright © 2015年 WeiKevin. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int digit (char array[]){
    int digitnumber=0;
    while (array[digitnumber]!='\n') {
        digitnumber=digitnumber+1;
    }
    return digitnumber;
}

int digit_right (char array[],int digit) {
    int right_digit=0, count=0;
    right_digit=digit;
    while (array[count]=='0'&&right_digit>1) {
        right_digit--;
        count++;
    }
    return right_digit;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    const int buffer=120;
    char even[buffer]={0}, odd[buffer]={0};
    int even_int[buffer]={0}, odd_int[buffer]={0}, answer[buffer]={0};
    int digit_even=0, digit_odd=0, bigger_digit=0, temp=0;
    int digit_even_right=0, digit_odd_right=0;
    
    while (fgets(even, buffer, stdin)) {
        fgets(odd, buffer, stdin);
        
        //數入位數（具有含0位數）
        digit_even=digit(even);
        digit_odd=digit(odd);
        
        //輸入位數（不具有含0位數）
        digit_even_right=digit_right(even,digit_even);
        digit_odd_right=digit_right(odd,digit_odd);
        
        //資料轉錄，從char到int
        for (int j=0; j<buffer; j++) {
            if (j>=digit_even_right) {
                even_int[j] = 0;
            }else{
                even_int[j] = int(even[digit_even-digit_even_right+j])-48;
            }
        }

        for (int j=0; j<digit_odd; j++) {
            if (j>=digit_odd_right) {
                odd_int[j]=0;
            }else{
                odd_int[j] = int(odd[digit_odd-digit_odd_right+j])-48;
            }
        }
        
        //轉錄成功，加法繼續
        
        bigger_digit=digit_even_right>=digit_odd_right?digit_even_right:digit_odd_right;
        
        for (int j=0; j<bigger_digit+1; j++) {
            answer[j]=(even_int[digit_even_right-j-1]+odd_int[digit_odd_right-j-1]+temp)%10;
            
            if ((even_int[digit_even_right-j-1]+odd_int[digit_odd_right-j-1]+temp)>=10) {
                temp=(even_int[digit_even_right-j-1]+odd_int[digit_odd_right-j-1]+temp)/10;
            }else{
                temp=0;
            }
            
        }
        //結果顯示
        if (answer[bigger_digit]==0) {
            for (int i=bigger_digit-1; i>=0; i--) {
                cout<<answer[i];
            }
        }else{
            for (int i=bigger_digit; i>=0; i--) {
                cout<<answer[i];
            }
        }
        
        //init
        digit_even=digit_odd=temp=0;
        for (int j=0; j<buffer; j++) {answer[j]=0;}
        
        cout<<endl;
    }
    
    return 0;
}