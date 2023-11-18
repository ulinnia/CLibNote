#include <stdio.h>
#include <ctype.h>

char var[5];        //declare a Array called var

void PrintFunction(){       //PrintFunction function
    for (int i=0; i<5; i++){        //case 0~case 4
        for (int j=0; j<5; j++){    //try every var value,totally 5 declare at main function
            switch(i){
                case 0:             //Check whether the value is alphabet or number,print then break switch loop
                    (isalnum(var[j]))? printf("|%c| is alpha or num.",var[j]):printf("|%c| isn't alpha or num.",var[j]);
                    break;
                case 1:             //Check whether the value is alphabet,print then break switch loop
                    (isalpha(var[j]))? printf("|%c| is alpha.",var[j]):printf("|%c| isn't alpha.",var[j]);
                    break;
                case 2:             //Check whether the value is control character,print then break switch loop
                    (iscntrl(var[j]))? printf("|%c| is control.",var[j]):printf("|%c| isn't control.",var[j]);
                    break;
                case 3:             //Check whether the value is white-space character,print then break switch loop
                    (isspace(var[j]))? printf("|%c| is space.",var[j]):printf("|%c| isn't space.",var[j]);
                    break;
                case 4:             //Check whether the value is lowercase character,print then break switch loop
                    (islower(var[j]))? printf("|%c| is lowercase character.",var[j]):printf("|%c| isn't lowercase character.",var[j]);
                    break;
            }
            printf("\n");           //newline
        }
        printf("\n");               //newline
    }
}

int main(){
    var[0] = 'd';    //save d charactor into var[0]
    var[1] = '2';    //save 2 charactor into var[1]
    var[2] = '\t';   //save \t charactor into var[2]
    var[3] = ' ';    //save space charactor into var[3]
    var[4] = 'D';    //save D charactor into var[4]
    PrintFunction(); //call the PrintFunction
}
