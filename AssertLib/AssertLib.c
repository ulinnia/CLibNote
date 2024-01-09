#include <assert.h>     //function use
#include <stdio.h>
int main () {           //main function
    int a;              //declare variable
    char str[50];       //declare char type(1byte) array capacity 50
	 
    printf("Enter an integer value: ");     //print hint
    scanf("%d", &a);                        //get the user input
    assert(a >= 10);                        //check whether variable a >= 10 (if false)print alert and exit
    printf("Integer entered is %d\n", a);   //print a
    
    printf("Enter string: ");               // print hint
    scanf("%s", str);                       //get the user input
    assert(str != NULL);                    //check whether str array is empty(if true)alert and exit
    printf("String entered is: %s\n", str); //print str

    return(0);                              
    /*function return 0 normal exit(return means the function is over exit the function)*/

}
/*
輸入一數，確認是否有大於等於十
輸入一個字串，確認有存入str
*/
