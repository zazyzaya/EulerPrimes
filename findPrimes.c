// Find a prime larger than the input (using Euler's proof of infinite primes)

#include <stdio.h>
#include <math.h>

#define INT_SIZE 64

intSize = sizeof(int) * 8;  // So this isn't calculated every time

typedef struct {
    int len;                  // Defaults to 1 
    unsigned int value[INT_SIZE]; // Stores INT_SIZE * 4 byte sized int (Implied positive)
} veryLargeInt;

// Constant vli 
veryLargeInt ONE;
ONE.len = 1;
ONE.value[0] = 1;

typedef union {
  unsigned long l;
  unsigned int split[2];    // Should contain overflow bit
} overflowCatcher;

void shiftLeftByOne(veryLargeInt * vli) { // Treats array like very large integer. Quickly mults by 2
    unsigned int i, carrybit, oldCarrybit = 0;
    unsigned int * arr = vli->value;

    for (i = 0; i < vli->len; i++){
        carrybit = arr[i] >> (intSize - 1);  // Highest order bit to shift to next array (if needed)
        arr[i] = (arr[i] << 1) | oldCarrybit;// Add previous carry bit to end of this index if needed
        oldCarrybit = carrybit;              // Prepare carrybit for next iteration
    }

    if (carrybit) { // Adds new array if needed
        arr[i] = 1;
        vli->len++;
    }
}

void add(veryLargeInt * vli, veryLargeInt * other){
    int i, carry = 0;
    unsigned long thisNum, otherNum, overflow=0;
    overflowCatcher of;

    for (i = 0; (i < vli->len && i < other->len); i++) {    // For every element
        thisNum = vli->value[i];
        otherNum = other->value[i];

        of.l = overflow;        
        of.l += thisNum + otherNum;
        
        vli->value[i] = of.split[0];
        overflow = of.split[1];
    }
    if (overflow) {
        vli->value[i] = overflow;   // If there's still overflow after everything
        vli->len++;
    }
}

veryLargeInt clone(veryLargeInt * vli) {
    veryLargeInt ret;
    ret.len = vli->len;

    int i; 
    for(i = 0; i < vli->len; i++) {
        ret.value[i] = vli->value[i];
    }

    return ret;
}

veryLargeInt clone(veryLargeInt * vli) {
    veryLargeInt ret;
    ret.len = i.len;

    int i; 
    for(i = 0; i < vli->len; i++) {
        ret.value[i] = vli->value[i];
    }

    return ret;
}

veryLargeInt mult(veryLargeInt * p, veryLargeInt * q){ 
    veryLargeInt iter, ret, og;
    int i;

    og = clone(p);

    iter.len = 1;
    iter.value[0] = 0;

    ret.len = 1;
    ret.value[0] = 0;

    while (iter.len != q->len) {
        add(&ret, &og);
        add(&iter, &ONE);
    }

    for (i = iter.len; i >= 0; i--) {
        while (iter.value[i] != q->value[i]){
            add(&ret, &og);
            add(&iter, &ONE);
        }
    }

    return ret;
}

veryLargeInt factorial(veryLargeInt i) {
    veryLargeInt ret, iter;
    ret.len = 1;
    ret.value[0] = 1;   // 0! = 1

    iter.len = 1;
    iter.value[0] = 0;

    while ()
}