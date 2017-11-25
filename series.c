/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "series.h"

int MAX_RANDOM_VALUE = 10000;

Element* getElement(int index, Series* series){
    Element* curr = series->first;
    
    while (curr != NULL){
        if (curr->index == index){
            return curr;
        }
        curr = curr->next;
    }
    fprintf(stderr, "Fatal Error: not access index %d of series with length %d\n", index, series->length);
    exit(EXIT_FAILURE);
    return NULL;
}

SNode* getSNode(int index, SeriesList* seriesList){
    SNode* curr = seriesList->first;
    
    while (curr != NULL){
        if (curr->index == index){
            return curr;
        }
        curr = curr->next;
    }
    
    fprintf(stderr, "Fatal Error: not access index %d of series with length %d\n", index, seriesList->length);
    exit(EXIT_FAILURE);
    return NULL;
}

Series* newSeries(){
    Series* newObj = (Series*)malloc(sizeof(Series));
    
    newObj->first = NULL;
    newObj->last = NULL;
    newObj->length = 0;
    
    return newObj;
}

void appendToSeries(int value, Series* series){
    Element* newObj = (Element*)malloc(sizeof(Element));
    
    newObj->value = value;
    if (series->last == NULL){
        series->last = newObj;
        series->first = newObj;
        newObj->next = NULL;
        newObj->previous = NULL;
        newObj->index = 0;
        
    }
    else{
        newObj->index = (series->last->index)+1;
        newObj->next = NULL;
        newObj->previous = series->last;
        series->last->next = newObj;
        series->last = newObj;
    }
    
    series->length = (series->length) + 1;
    
}

Series* sliceSeries(Series* series, int start, int end){
    //Note to self: always use newSeries instead of a straight-up malloc to avoid having random junk in the slice
    //That was 20 minutes well spent...
    Series* slice = newSeries();
    if (series->length <= end || series->length <= start){
        return slice;
    }
    Element* curr = series->first;
    while (curr != NULL){
        if (curr->index >= start && curr->index <= end){
            appendToSeries(curr->value, slice);
        }
        curr = curr->next;
    }
    return slice;
    
}

SeriesList* newSeriesList(){
    SeriesList* newObj = (SeriesList*)malloc(sizeof(SeriesList));
    
    newObj->first = NULL;
    newObj->last = NULL;
    newObj->length = 0;
    
    return newObj;
}

void appendToSeriesList(Series* series, SeriesList* seriesList){
    SNode* newObj = (SNode*)malloc(sizeof(SNode));
    
    newObj->series = series;
    if (seriesList->last == NULL){
        seriesList->last = newObj;
        seriesList->first = newObj;
        newObj->next = NULL;
        newObj->previous = NULL;
        newObj->index = 0;
        
    }
    else{
        newObj->index = (seriesList->last->index)+1;
        newObj->next = NULL;
        newObj->previous = seriesList->last;
        seriesList->last->next = newObj;
        seriesList->last = newObj;
    }
    
    seriesList->length = (seriesList->length) + 1;
    
}    

void randomlyPopulateSeries(int n, Series* series){
    int counter = n;
    
    if (series->length > 0){
        fprintf(stderr, "Cannot populate a SeriesList which already contains elements.");
        exit(EXIT_FAILURE);
    }
    
    while(counter!=0){
        appendToSeries(rand() % MAX_RANDOM_VALUE, series);
        counter=counter-1;
    }
    
}

void randomlyPopulateSeriesList(int n, SeriesList* list){
    int counter = n;
    
    if (list->length > 0){
        fprintf(stderr, "Cannot populate a SeriesList which already contains elements.");
        exit(EXIT_FAILURE);
    }
    
    while(counter != 0){
        
        Series* series = newSeries();
        randomlyPopulateSeries(n, series);
        appendToSeriesList(series, list);
        
        counter =counter-1;
    }
}


void printSeries(Series* series){
    const int tmp_length = 512;
    char* tmp = (char*)malloc(tmp_length);
    
    if (series->length == 0){
        snprintf(tmp, tmp_length, "The list is empty.");

    }else{
        //initialise output buffer with an opening bracket
        snprintf(tmp, tmp_length, "\t( ");
        //traverse inventory list (forward)
        Element* current = series->first;
        while(current != NULL){
            
            snprintf(tmp, tmp_length, (current->next==NULL) ?"%s[%d]" : "%s[%d], ", tmp, current->value);
            current = current->next;
        }
        //Add closing bracket
        snprintf(tmp,tmp_length, "%s )", tmp);
    }
    
    printf("%s\n", tmp);
}

void printSeriesList(SeriesList* list){
    SNode* current = list->first;
        printf("Series List (length: %d) [\n", list->length);
    while(current!=NULL){
        printSeries(current->series);
        current=current->next;
    }
    printf("]\n");
}