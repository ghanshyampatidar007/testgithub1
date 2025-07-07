#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void sort_word(char *str){
    char *k,*p,*q,*r,*l;
    char temp[10]={0};
    
    int n,m,x;
    p=str;
    k=str+strlen(str);
    while(p=strtok(p," ")){
        n=strlen(p);
        x=n;
        l=p;
       // puts(p);
        if(p+n<k){
            q=p+n+1;
        }
        else{
            q=p+n;
        }
        while(q=strtok(q," ")){
            m=strlen(q);
            if(m<x){
                l=q;
                x=m;
            }
            if(q+m<k){
                *(q+m)=' ';
            }
            q=NULL;
        }
        if(p+n<k){
            *(p+n)=' ';
        }
        
        if(p!=l){
           // puts(p);
        //    puts(l);
         //   printf("p-%d  l-%d\n",n,x);
            strncpy(temp,l,x);
            //puts(temp);
            memmove(l+n,l+x,strlen(l+x)+1);
            strncpy(l,p,n);
            
            memmove(p+x,p+n,strlen(p+n)+1);
            strncpy(p,temp,x);
            p=p+x;
        }
        else{
         if(p+n<k){
            p=p+n+1;
        }
        else{
            p=p+n;
        }
        }
    }
}

int main(){
    
    char str[100];
    printf("enter the string- \n");
    fgets(str,100,stdin);
    str[strlen(str)-1]=0;
    
    sort_word(str);
    printf("output-  ");
    puts(str);
    
    
    return 0;
}
