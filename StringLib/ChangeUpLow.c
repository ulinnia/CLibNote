#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char a[200];
    scanf("%s", a);

    while (strcmp(a,"END")!=0){
        for(int i=0; i<strlen(a); i++){
            if(isalpha(a[i])){
                if(isupper(a[i])){
                    a[i] = tolower(a[i]);
                }else{
                    a[i] = toupper(a[i]);
                }
            }
            if(a[i]=='\0'){
                break;
            }
        }
        if (getchar()!=' '){
            printf("%s\n",a);
        }else{
            printf("%s ",a);
        }
        scanf("%s", a);
    }
    return 0;
}