#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <ctype.h>

char stack[1000];
	 
int tepe=-1;

int kapasite = 0;


int isEmpty(){
	if(tepe==-1){ //tepe=kapasite-1
	return 1;
	}else{
	return 0;
	}	
}

void pop(){
if(!isEmpty()){
 tepe--;
 kapasite--;
}
}
void push (char a){
tepe++;
stack[tepe]=a;
kapasite++;
}
void yazdir(){
int i;
for(i=0;i<kapasite;i++)
printf("%c ",stack[i]);
}


int main(){

char girilendeger[1000];
scanf("%s" ,girilendeger);
int size = strlen(girilendeger);
for (int i = 0; i < size; i++)
    {
        // Sadece açılış parantezini ekliyoruz.
    	 if (girilendeger[i] == '(' || girilendeger[i] == '[' || girilendeger[i] == '{')
        {
            push(girilendeger[i]); // Stacke ekle.
        }  
		// Kapanış parantezi. 
         else if (girilendeger[i] == ')' )
        {
            if (stack[tepe] == '(')
            {
                pop();
            }
            else{
            	push(girilendeger[i]);
			}  
        }	
    } // Döngü sonunda stack boş kalmalı.
    if(isEmpty()){
    	printf("ifade dogru");
	}
	else{
		printf("ifade yanlis");
	}
	printf("/n Suanki stack : ");
	yazdir();
return 0;

}
