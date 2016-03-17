//
//  main.c
//  15 - H
//
//  Created by Erica Correa on 2/2/16.
//  Copyright © 2016 Turn to Tech. All rights reserved.
//

int stringLength (char string[]) {
    int length = 0;
    while (string[length] != '\0') {
        length++;
    }
    return length;
}

void addStringElement (char string[], int startingPoint, int element) {
    int n = startingPoint;
    while (string[n] != '\0') {
        n++;
    }
    string[n++] = element;
    string[n] = '\0';
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {

    char myQuote[] = "\"Mr. Fay, is this going to be a battle of wits?\"\n\"If it is,\" was the indifferent retort, \"you have come unarmed!\"\n";
    
    char oldString[] = "indifferent";
    char newString[] = "nonchallant";
    char *updatedString;
    
    int size = stringLength(myQuote) + stringLength(newString) - stringLength(oldString);
    
    updatedString = (char *) malloc(size);
    
    int j = 0;
    
    for (int i = 0; i < stringLength(myQuote); i++) {
        if (myQuote[i] == oldString[j]) {
            if (j + 1 == stringLength(oldString)) {
                for (int k = 0; k <= i - stringLength(oldString); k++) {
                    addStringElement(updatedString, 0, myQuote[k]);
                }
                for (int l = 0; l <= stringLength(newString); l++) {
                    addStringElement(updatedString, stringLength(updatedString), newString[l]);
                }
                for (int m = i + 1; m <= stringLength(myQuote); m++) {
                    addStringElement(updatedString, stringLength(updatedString), myQuote[m]);
                }
                printf("Your updated string is:\n\n%s\n", updatedString);
                break;
            }
            else {
                j++;
            }
        }
        else {
            j = 0;
        }
    }
    
    free(updatedString);
    
    return 0;
}
