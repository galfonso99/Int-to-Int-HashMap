#ifndef HASH_FUNCTION_H
#define HASH_FUNCTION_H

#include <stdint.h>
#include<stdio.h>
#include<string.h>
#include <math.h>

/* To count total digits in a integer*/
int count_digits(long long int key) {
    int count=0;
   while(key != 0) {

    key /= 10;
    ++count;
    }
return count;
}

int get_Nth_digit(long long int num, int pos) {
    long int digit=0,fraction=0, length;

    length = count_digits(num);
    fraction = num / (long int)pow(10, (length - pos));
    digit = fraction % 10;

    return digit;

}
/* For the getting the n digits from a given number*/
int get_digits_range(long long int num, int start_pos, int count) {
    int i, digit =0, length=0;
    long int number = 0;

    length = count_digits(num);

    if((start_pos + count)-1 <= length) {
        for (i=0; i < count; i++) {
        /* getting digit from position*/
        digit = get_Nth_digit(num,start_pos);
        start_pos ++;
        /*creating the number*/
        number = number * 10;
        number = number + digit;
        }
    }

    return (int) number;
}

int hashing_midsquare(long int key) {
    int hashvalue = 0;
    int keysquare_len=0;
    int mid_pos =0;

    //Need to take care of overflow in case of larger number
    long long int keysquare = key * key;

    keysquare_len = count_digits(keysquare);
    mid_pos = keysquare_len / 2;
    int size = (keysquare_len / 3) > 0 ? keysquare_len / 3 : 1;

    hashvalue = get_digits_range(keysquare,(mid_pos+1), size);
    return hashvalue;
}

#endif
