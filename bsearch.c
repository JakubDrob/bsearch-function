#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compare)(const void *, const void *));

int compareString(const void* key, const void* element);

int compare(const void* key, const void* value);


int main()
{
    char key[20] = "sensu";
    char ciag[][20] = {"przykladowy","pozbawiony", "wiekszego", "sensu", "string"};
    qsort (ciag, 5, 20, (int(*)(const void*,const void*)) strcmp);

    if( bsearch(key, ciag, 5, 20, compareString))
        printf ("The element \"%s\" was found\n", key);
    else
        printf("The element \"%s\" was NOT found in the array\n", key);


    return 0;
}

void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compare)(const void *, const void *)) {
    size_t beginningPoint = 0, middlePoint;
    int valueOfCompare;
    const void *temporaryElement;

    while(beginningPoint <= nmemb) {
        middlePoint = beginningPoint + (nmemb - beginningPoint) / 2;
        temporaryElement = (const char*)base + (middlePoint * size);
        valueOfCompare = (*compare)(key, temporaryElement);
        if(valueOfCompare < 0) {
            nmemb = middlePoint - 1;
        }
        else if(valueOfCompare > 0) {
            beginningPoint = middlePoint + 1;
        }
        else {
            return (int *)temporaryElement;
        }
    }
    return NULL;
}

int compareString(const void* key, const void* element) {
    return strcmp((char *)key, (char *)element);
}

int compare(const void* key, const void* value) {
    if( * (char*)key < * (char *)value ){
        return - 1;
    }

    if( * (char*)key > * (char*)value ){
        return 1;
    }

    return 0;
}

